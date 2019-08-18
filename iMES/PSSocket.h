#pragma once
#include <windows.h>
#include "Basic.h"
#include "iMESMainForm.h"

//Flaw File
extern int global_Flag_FlawFileMode;

extern int global_Flag_iMESMode;
//Parameter Server Command
extern int global_Flag_CommandNextTest;

//scan board
extern std::string global_BarCode;
extern std::string global_WipEntity;

extern int global_DoubleRestTestCount;

//Login
extern int global_Flag_IfLogin;
//Employee
extern std::string global_EmployeeID;
extern std::string global_EmployeePassword;
//Access Level
extern int global_Flag_AccessLevel;


using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Diagnostics;
using namespace System::Threading;


public ref class PSSocket {
public:
	static Socket^ global_PSSocket;
	static String^ SendMessage = "WebService.Cmd?\n";

	static String^ ReceiveMessage = "";


public:

	static void ParameterServerReceive(String^ tempRece) {
		if (tempRece[tempRece->IndexOf('=') + 1] == '1') {
			int tempStartPosition = tempRece->IndexOf('=') + 3;
			String^ tempStr = tempRece->Substring(tempStartPosition, tempRece->Length - tempStartPosition);
			String^ parentStr = "";
			String^ childStr = "";
			int tempreturn;

			if (tempStr->IndexOf(' ') != -1) {
				parentStr = tempStr->Substring(0, tempStr->IndexOf(' '));
				childStr = tempStr->Substring(tempStr->IndexOf(' ') + 1, tempStr->Length - tempStr->IndexOf(' ') - 1);
			}
			else {
				parentStr = tempStr;
			}
			
			try {
				if (parentStr == "ScanBarcodeHandScanner"){
					int flag_Flaw = 0;

					global_BarCode = msclr::interop::marshal_as<std::string>(childStr->Substring(0, childStr->IndexOf(' ')));
					tempreturn = iMES::GetBarCodeFromHandBarCodeScanningGun(childStr);

					if (tempreturn == -1 || tempreturn == 1) {
						//iMES communication with MES has some problem
						//iMES failed to get Ingredients

						socketSendMessage("WebService.Cmd=0\n");
					}
					else if (tempreturn == 2) {
						//no ingredients
						socketSendMessage("WebService.Cmd=0\n");
					}
					else if (tempreturn == 0) {
						//success
						tempreturn = iMES::GetFlawFileForFP(gcnew String(global_BarCode.c_str()));
						flag_Flaw = 1;
						socketSendMessage("WebService.Cmd=0\n");
					}
					else if(tempreturn ==-99) {
						socketSendMessage("WebService.Cmd=0\n");
						MessageBox::Show("Need to Call AGV before scanning!");
					}
					else {
						socketSendMessage("WebService.Cmd=0\n");
					}

					if (flag_Flaw == 0 && global_Flag_iMESMode == 0) {
						tempreturn = iMES::GetFlawFileForFP(gcnew String(global_BarCode.c_str()));
					}
				}
				else if (parentStr == "SendPathFlawFileFolder") {
					
					tempreturn = iMES::GetFlawFileSavedPathFromFP(childStr);

					if (tempreturn != 0) {
						socketSendMessage("WebService.Cmd=0\n");
					}
					else {
						socketSendMessage("WebService.Cmd=" + global_Flag_FlawFileMode + "\n");
					}
				}
				else if (parentStr == "SendLoginAttributes") {
					
					if (iMES::ReadLoginFromTestPlayer(childStr) != 0) {
						//send TestPlayer Error Message!!
						socketSendMessage("Webservice.Cmd=2 SendLoginAttributeFile Error\n");
					}
					else {
						socketSendMessage("WebService.Cmd=0\n");
					}
				}
				else if (parentStr == "SendPathTestResultFile") {
					
					tempreturn = iMES::GetResultFileFromFP(childStr);

					socketSendMessage("WebService.Cmd=0\n");
				}
				else if (parentStr == "GetResponceNextTest\n") {
					
					if (global_DoubleRestTestCount > 0) {
						socketSendMessage("WebService.Cmd=0\n");
						global_Flag_CommandNextTest = -1;
					}
					else {
						global_Flag_CommandNextTest = 1;
					}
				}
				else if (parentStr == "SendErrorAlarmMessage") {
					
					int tempreturn = iMES::SendAlarmMessage(childStr);

					if (tempreturn == 0) {

					}
					else {
						iMES::AlarmMessageBoxControl("Fail to send alarm message: \n " + childStr);
					}

					socketSendMessage("WebService.Cmd=0\n");
				}
			}
			catch (Exception^ e)
			{
				Trace::WriteLine("ArgumentNULLException caught!!!");
				Trace::Write("Source : ");
				Trace::WriteLine(e->Source);
				Trace::Write("Message : ");
				Trace::WriteLine(e->Message);
				socketSendMessage("WebService.Cmd=0\n");
				iMES::ShowMessageToMESHistory(e->Source + "\r\n" + e->Message + "\r\n", true);
			}

			delete tempStr;
			delete parentStr;
			delete childStr;
		}
	}

	static bool SocketConnect(String^ server, int port) {
		Encoding^ ASCII = Encoding::ASCII;
		array<Byte>^ ByteGet = ASCII->GetBytes(SendMessage);

		try {
			IPEndPoint^ hostEndPoint;
			IPAddress^ hostAddress = nullptr;

			// Get DNS host information.
			IPHostEntry^ hostInfo = Dns::Resolve(server);
			// Get the DNS IP addresses associated with the host.
			array<IPAddress^>^IPaddresses = hostInfo->AddressList;
			hostAddress = IPaddresses[0]; 

			hostEndPoint = gcnew IPEndPoint(hostAddress, port);

			// Creates the Socket to send data over a TCP connection.
			global_PSSocket = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);

			// Connect to the host using its IPEndPoint.
			global_PSSocket->Connect(hostEndPoint);
			if (!global_PSSocket->Connected)
			{
				// Connection failed, try next IPaddress.
				return false;
			}

			return true;
		}
		catch (SocketException^ e)
		{
			Trace::WriteLine("SocketException caught!!!");
			Trace::Write("Source : ");
			Trace::WriteLine(e->Source);
			Trace::Write("Message : ");
			Trace::WriteLine(e->Message);

			return false;
		}
		catch (ArgumentNullException^ e)
		{
			Trace::WriteLine("ArgumentNULLException caught!!!");
			Trace::Write("Source : ");
			Trace::WriteLine(e->Source);
			Trace::Write("Message : ");
			Trace::WriteLine(e->Message);

			return false;
		}
		catch (NullReferenceException^ e)
		{
			Trace::WriteLine("NULLReferenceException caught!!!");
			Trace::Write("Source : ");
			Trace::WriteLine(e->Source);
			Trace::Write("Message : ");
			Trace::WriteLine(e->Message);

			return false;
		}
		catch (Exception^ e)
		{
			Trace::WriteLine("Exception caught!!!");
			Trace::Write("Source : ");
			Trace::WriteLine(e->Source);
			Trace::Write("Message : ");
			Trace::WriteLine(e->Message);

			return false;
		}
	}

	//send and receive message with server
	static bool socketSendMessage(String^ strMessage) {
		try {
			//Set up variables and String to write to the server.
			Encoding^ ASCII = Encoding::ASCII;
			array<Byte>^ ByteGet;
			array<Byte>^ RecvBytes = gcnew array<Byte>(256);
			String^ strRetPage = nullptr;
			String^ tempStr;

			ByteGet = ASCII->GetBytes(strMessage + "");

			if (global_PSSocket->Connected) {
				int aaa = global_PSSocket->Send(ByteGet, ByteGet->Length, SocketFlags::None);
				int bb = aaa + 1;
			}
			else {
				return false;
			}

			tempStr = "Send!	" + "Time: " + (DateTime::Now).ToString("yyyMMddHHmmss") + "	" + strMessage;
			Trace::WriteLine(tempStr);

			delete tempStr;
			return true;
		}
		catch (SocketException^ e)
		{
			Trace::WriteLine("SocketException caught!!!");
			Trace::Write("Source : ");
			Trace::WriteLine(e->Source);
			Trace::Write("Message : ");
			Trace::WriteLine(e->Message);

			return false;
		}
		catch (ArgumentNullException^ e)
		{
			Trace::WriteLine("ArgumentNULLException caught!!!");
			Trace::Write("Source : ");
			Trace::WriteLine(e->Source);
			Trace::Write("Message : ");
			Trace::WriteLine(e->Message);

			return false;
		}
		catch (NullReferenceException^ e)
		{
			Trace::WriteLine("NULLReferenceException caught!!!");
			Trace::Write("Source : ");
			Trace::WriteLine(e->Source);
			Trace::Write("Message : ");
			Trace::WriteLine(e->Message);

			return false;
		}
		catch (Exception^ e)
		{
			Trace::WriteLine("Exception caught!!!");
			Trace::Write("Source : ");
			Trace::WriteLine(e->Source);
			Trace::Write("Message : ");
			Trace::WriteLine(e->Message);

			return false;
		}
	}

	static bool KeepReceiveSocketMessage() {
		try {
			array<Byte>^ RecvBytes = gcnew array<Byte>(256);
			Encoding^ ASCII = Encoding::ASCII;

			if (global_PSSocket->Connected) {
				StringBuilder^ builder = gcnew StringBuilder();
				int startTickCount = Environment::TickCount;

				do
				{
					if (Environment::TickCount > startTickCount + 3) {
						throw gcnew Exception("Timeout for receiving!");
					}
					try {
						int bytes = global_PSSocket->Receive(RecvBytes);

						Trace::WriteLine("Receiving: " + RecvBytes);
						builder->Append(Encoding::UTF8->GetString(RecvBytes, 0, bytes));
					}
					catch (SocketException^ se) {
						if (se->SocketErrorCode == SocketError::WouldBlock ||
							se->SocketErrorCode == SocketError::IOPending ||
							se->SocketErrorCode == SocketError::NoBufferSpaceAvailable)
						{
							// socket buffer is probably empty, wait and try again
							Sleep(30);
						}
						else
							throw se;  // any serious error occurr
					}
				} while (global_PSSocket->Available > 0);

				ReceiveMessage = builder->ToString();
			}
			else {
				return false;
			}

			Trace::WriteLine(ReceiveMessage);
			return true;
		}
		catch (ArgumentNullException^ e)
		{
			Trace::WriteLine("ArgumentNULLException caught!!!");
			Trace::Write("Source : ");
			Trace::WriteLine(e->Source);
			Trace::Write("Message : ");
			Trace::WriteLine(e->Message);

			return false;
		}
		catch (NullReferenceException^ e)
		{
			Trace::WriteLine("NULLReferenceException caught!!!");
			Trace::Write("Source : ");
			Trace::WriteLine(e->Source);
			Trace::Write("Message : ");
			Trace::WriteLine(e->Message);

			return false;
		}
		catch (Exception^ e)
		{
			Trace::WriteLine("Exception caught!!!");
			Trace::Write("Source : ");
			Trace::WriteLine(e->Source);
			Trace::Write("Message : ");
			Trace::WriteLine(e->Message);

			return false;
		}
	}
};
