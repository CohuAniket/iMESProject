#include "iMESMainForm.h"
#include "Basic.h"
#include "IngredientsLabel.h"
#include "SaveMachineStatusClass.h"
#include "Global_MachineStatus.h"
#include "WebService.h"
#include "WipEntityLogFileStreamWriter.h"

using namespace System;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Windows::Forms;

using namespace System::IO::Packaging;
using namespace System::Web;

using namespace SccService;
//using namespace Compression;

//FlawFile Path
extern std::string global_FlawFileZipDescriptionFilePath;
extern std::string global_FlawFileServerPath;
extern std::string global_FlawFileTestPlayerPath;

//scan board
extern std::string global_BarCode;
extern std::string global_WipEntity;

//Test
extern std::vector<TestedBoardInfo> global_TestedBoards;

//Machine Status
extern std::string global_MachineStatusFileDirectory;


extern std::string global_EXEBasicDirectory;
//ini file
extern std::string global_INIFileDirectory;
extern std::string global_INIFileVersion;

//parameters in iMES Setup
extern std::string global_MachineID;
extern std::string global_iMESURL;
extern std::string global_TestProgramMainDirectroy;
extern std::string global_TransportCartAID;
extern std::string global_TransportCartBID;
extern int global_AGVButtonAging;
extern int global_CommunicationTimeout;
extern int global_Flag_SaveOriginFlawFile;
extern int global_Flag_SaveChangedFlawFile;

//AGV
extern int global_Flag_CallAgv;

//HeartBeat
extern int global_Flag_EnabelHeartbeat;
extern std::string global_HeartbeatContent;
extern std::string global_HeartbeatServerURL;
extern std::string global_HeartbeatPort;
extern int global_HeartbeatFrequency;
extern int global_Flag_HeartbeatMessageBox;
extern int global_Flag_HeartbeatWorking;

//alarm
extern int global_Flag_AlarmMessageBox;
//Wip Entity
extern int global_Flag_WipEntityMessageBox;
//Output
extern int global_Flag_OutputFileMessageBox;
//INI File
extern int global_Flag_INIFileMessageBox;

//ingredients
extern std::string global_TestPlayerIngredientsPath;
extern std::string global_GetIngredientsTime;
extern std::vector<IngredientsLabel> global_IngredientsLabel;
//ingredients detail
extern std::string global_SerialNumber;
extern std::string global_JobID;
extern std::string global_StripCount;
extern std::string global_Continuity;
extern std::string global_Insulation;
extern std::string global_TestProgramWholeDirectory;
extern int global_DoubleAllTestCount;
extern int global_DoubleAllowNGCount;
//other need
extern int global_DoubleRestTestCount;

//Access Level
extern std::string global_EmployeeID;
extern int global_Flag_AccessLevel;

namespace iMES {
	using namespace System::Runtime::Serialization;
	using namespace SccService::Scc;


	//Basic
	void ShowMessageToMESHistory(System::String^ strSendMessage) {
		iMESMainForm::global_iMESMainForm->tbxMESHistory->AppendText(
			strSendMessage
			+ WebService::SCCReturn->errorCodek__BackingField + "\r\n"
			+ WebService::SCCReturn->errorMsgk__BackingField + "\r\n"
			+ (WebService::SCCReturn->resultDatak__BackingField == "" ? "" : WebService::SCCReturn->resultDatak__BackingField + "\r\n")
			+ (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss") + "\r\n\r\n");
	}
	void ShowMessageToMESHistory(System::String^ strSendMessage, bool NoService) {
		if (NoService == true) {
			iMESMainForm::global_iMESMainForm->tbxMESHistory->AppendText(
				strSendMessage
				+ (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss") + "\r\n\r\n");
		}
		else {
			iMESMainForm::global_iMESMainForm->tbxMESHistory->AppendText(
				strSendMessage
				+ WebService::SCCReturn->errorCodek__BackingField + "\r\n"
				+ WebService::SCCReturn->errorMsgk__BackingField + "\r\n"
				+ (WebService::SCCReturn->resultDatak__BackingField == "" ? "" : WebService::SCCReturn->resultDatak__BackingField + "\r\n")
				+ (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss") + "\r\n\r\n");
		}
	}

	//return 0 OK; -1 fail
	int SendAlarmMessage(System::String^ alarmMessageFromTestPlayer) {
		SccService::item^ TempItem = gcnew item();
		TempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1001";
		TempItem->tagValue = "7934058";
		TempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
		System::Collections::Generic::List<SccService::item^>^ tempListItem = gcnew System::Collections::Generic::List<SccService::item^>();
		tempListItem->Add(TempItem);

		if (global_Flag_EnabelHeartbeat == 1 && global_Flag_HeartbeatWorking == 0) {
			HeartbeatMessageBoxControl();
			return -1;
		}
		WebService::SCCReturn =
			WebService::SCCWebService->AlarmUpload(gcnew System::String(global_MachineID.c_str()), "ALARM_001", alarmMessageFromTestPlayer, (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss"), tempListItem);
		ShowMessageToMESHistory("AlarmUpload " + alarmMessageFromTestPlayer + "\r\n");

		if (WebService::SCCReturn->errorCodek__BackingField == "0") {
			return 0;
		}
		else if (WebService::SCCReturn->errorCodek__BackingField == "-1") {
			return -1;
		}
		else if (WebService::SCCReturn->errorCodek__BackingField == "999" || WebService::SCCReturn->errorCodek__BackingField == "998") {
			//TODO
			return -1;
		}
		else {
			return -1;
		}
		return 0;
	}
	void AlarmMessageBoxControl(System::String^ ErrorShowing) {
		if (global_Flag_AlarmMessageBox == 0) {
			global_Flag_AlarmMessageBox = -1;
			if (MessageBox::Show(ErrorShowing) == System::Windows::Forms::DialogResult::OK) {
				global_Flag_AlarmMessageBox = 0;
			}
		}
	}



	//basic functions for initial or disable all buttons and parameters
	void AllParameterInitial() {
		//wip entity log file
		WipEntityLogFileStreamWriter::global_flagIfWipEntityFinish = -1;

		//if testing
		global_Flag_Testing = 0;
		//reset
		global_Flag_Reset = 0;
	}
	void AllGlobalFileDirectoryInitial() {
		System::String^ tempBasicEXEPath = Process::GetCurrentProcess()->MainModule->FileName;
		tempBasicEXEPath = tempBasicEXEPath->Substring(0, tempBasicEXEPath->LastIndexOf('\\') + 1);
		global_EXEBasicDirectory = msclr::interop::marshal_as<std::string>(tempBasicEXEPath);
		
		global_INIFileDirectory = global_EXEBasicDirectory + global_INIFileDirectory;
		global_FlawFileZipDescriptionFilePath = global_EXEBasicDirectory + global_FlawFileZipDescriptionFilePath;
		global_MachineStatusFileDirectory = global_EXEBasicDirectory + global_MachineStatusFileDirectory;
	}


	void AllInterfaceShowingForOldWipEntityInitial() {
		iMESMainForm::global_iMESMainForm->tbxBarCode->Text = "";
		iMESMainForm::global_iMESMainForm->tbxWipEntity->Text = "";
		iMESMainForm::global_iMESMainForm->tbxJobID->Text = "";
		iMESMainForm::global_iMESMainForm->tbxTestCountAll->Text = "";
		iMESMainForm::global_iMESMainForm->tbxTestCountNow->Text = "";
		iMESMainForm::global_iMESMainForm->dtgrdvwIngredients->ClearSelection();
		iMESMainForm::global_iMESMainForm->dtgrdvwIngredients->Rows->Clear();
	}
	void AllButtonInitial() {
		NewLoginAccessLevelButtonInitial();

		iMESMainForm::global_iMESMainForm->btnlEmployeeLogoff->Enabled = TRUE;
		iMESMainForm::global_iMESMainForm->btnLoadA->Enabled = TRUE;
		iMESMainForm::global_iMESMainForm->btnLoadB->Enabled = TRUE;
		iMESMainForm::global_iMESMainForm->btnUnload->Enabled = FALSE;
		iMESMainForm::global_iMESMainForm->btnReturn->Enabled = FALSE;
		iMESMainForm::global_iMESMainForm->btnChangeMachineStatus->Enabled = TRUE;
		iMESMainForm::global_iMESMainForm->btnTestFinish->Enabled = FALSE;
		iMESMainForm::global_iMESMainForm->btnReset->Enabled = TRUE;
		iMESMainForm::global_iMESMainForm->btnApplyChangedIngredients->Enabled = FALSE;
	}
	void AllButtonDisabled() {
		NewLoginAccessLevelButtonInitial();

		iMESMainForm::global_iMESMainForm->btnlEmployeeLogoff->Enabled = TRUE;
		iMESMainForm::global_iMESMainForm->btnLoadA->Enabled = FALSE;
		iMESMainForm::global_iMESMainForm->btnLoadB->Enabled = FALSE;
		iMESMainForm::global_iMESMainForm->btnUnload->Enabled = FALSE;
		iMESMainForm::global_iMESMainForm->btnReturn->Enabled = FALSE;
		iMESMainForm::global_iMESMainForm->btnChangeMachineStatus->Enabled = FALSE;
		iMESMainForm::global_iMESMainForm->btnTestFinish->Enabled = FALSE;
		iMESMainForm::global_iMESMainForm->btnReset->Enabled = FALSE;
	}
	void NewLoginAccessLevelButtonInitial() {
		if (global_Flag_AccessLevel >= 1) {
			iMESMainForm::global_iMESMainForm->btnModeSwitching->Enabled = TRUE;
		}
		else {
			iMESMainForm::global_iMESMainForm->btnModeSwitching->Enabled = FALSE;
		}

		if (global_Flag_AccessLevel >= 2) {
			iMESMainForm::global_iMESMainForm->btnCalliMESSetup->Visible = TRUE;
		}
		else {
			iMESMainForm::global_iMESMainForm->btnCalliMESSetup->Visible = FALSE;
		}
	}
	void EnableTheMainIMESInterface() {
		iMESMainForm::global_iMESMainForm->Enabled = TRUE;
		Global_MachineStatus::global_MachineStatusForm->Enabled = TRUE;
	}


	//heartbeat
	void HeartbeatMessageBoxControl() {
		if (global_Flag_EnabelHeartbeat == 1) {
			if (global_Flag_HeartbeatMessageBox == 0) {
				global_Flag_HeartbeatMessageBox = -1;
				if (MessageBox::Show("Please check heartbeat first, before use any web service function! ") == System::Windows::Forms::DialogResult::OK) {
					global_Flag_HeartbeatMessageBox = 0;
				}
			}
		}
	}
	void HeartbeatInitialize() {
		WebService::SccHeartbeat = gcnew SccToolchain::HeartbeatClient(gcnew System::String(global_HeartbeatServerURL.c_str()), gcnew System::String(global_HeartbeatPort.c_str()));
		iMESMainForm::global_iMESMainForm->TimerHeartbeat->Interval = global_HeartbeatFrequency;
		HeartbeatSendInformation();
		iMESMainForm::global_iMESMainForm->TimerHeartbeat->Start();
	}
	void HeartbeatSendInformation() {
		WebService::SccHeartbeat->Send(gcnew System::String(global_MachineID.c_str()), gcnew System::String(global_HeartbeatEndWord.c_str()));
		System::String^ tempstr = WebService::SccHeartbeat->GetLastServerResponseMessage();

		if (WebService::SccHeartbeat->GetLastOperationConnectStatus() == TRUE) {
			iMESMainForm::global_iMESMainForm->lblHeartbeatShow->BackColor = Color::Green;
			global_Flag_HeartbeatWorking = 1;
		}
		else {
			iMESMainForm::global_iMESMainForm->lblHeartbeatShow->BackColor = Color::Red;
			global_Flag_HeartbeatWorking = 0;

			HeartbeatMessageBoxControl();
		}
	}



	//ini file
	void ReadINIFile() {
		if (File::Exists(gcnew String(global_INIFileDirectory.c_str()))) {
			try {
				FileStream^ fs = gcnew FileStream(gcnew System::String(global_INIFileDirectory.c_str()), FileMode::Open, FileAccess::Read);
				StreamReader^ srCFG = gcnew StreamReader(fs, Encoding::UTF8);

				System::String^ rStr;
				std::string tempStr;
				System::String^ tempStrParent;
				global_IngredientsLabel.clear();
				int col;
				int formI;

				while ((rStr = srCFG->ReadLine()) != nullptr) {
					if (rStr[0] == ';' || rStr[0] == '#') {
						//move on
						continue;
					}
					else {
						if (rStr[0] == '{') {
							rStr = rStr->Substring(1, rStr->Length - 2);
							if (rStr == "EOF") {
								break;
							}
							else if (rStr->Substring(0, 4) == "VERS" || rStr->Substring(0, 7) == "vers" || rStr->Substring(0, 7) == "Vers") {
								global_INIFileVersion = msclr::interop::marshal_as<std::string>(rStr);
							}
						}
						else if (rStr[0] == '<') {
							rStr = rStr->Substring(1, rStr->Length - 2);
							if (rStr->Substring(0, 5) == "param") {
								int flagCCount = 0;
								int startPosition = 10;
								for (int i = startPosition; i < rStr->Length; i++) {
									if (rStr[i] == '\"') {
										flagCCount++;
										if (flagCCount == 1) {
											tempStrParent = rStr->Substring(startPosition, i - startPosition - 1);
											startPosition = i + 1;
										}
										else if (flagCCount == 2) {
											tempStr = msclr::interop::marshal_as<std::string>(rStr->Substring(startPosition, i - startPosition));
											startPosition = i + 1;

											if (tempStrParent == "MachineID") {
												global_MachineID = tempStr;
											}
											else if (tempStrParent == "iMESURL") {
												global_iMESURL = tempStr;
											}
											else if (tempStrParent == "TestProgramMainDirectory") {
												global_TestProgramMainDirectroy = tempStr;
											}
											else if (tempStrParent == "TransportAID") {
												global_TransportCartAID = tempStr;
											}
											else if (tempStrParent == "TransportBID") {
												global_TransportCartBID = tempStr;
											}
											else if (tempStrParent == "AGVButtonAging") {
												convertFromString(global_AGVButtonAging, tempStr);
											}
											else if (tempStrParent == "CommunicationTimeout") {
												convertFromString(global_CommunicationTimeout, tempStr);
											}
											else if (tempStrParent == "SaveOriginFlawFile") {
												if (tempStr == "yes" || tempStr == "YES" || tempStr == "Yes" || tempStr == "1") {
													global_Flag_SaveOriginFlawFile = 1;
												}
												else {
													global_Flag_SaveOriginFlawFile = 0;
												}
											}
											else if (tempStrParent == "SaveChangedFlawFile") {
												if (tempStr == "yes" || tempStr == "YES" || tempStr == "Yes" || tempStr == "1") {
													global_Flag_SaveChangedFlawFile = 1;
												}
												else {
													global_Flag_SaveChangedFlawFile = 0;
												}
											}

											break;
										}
									}
								}
							}
							else if (rStr->Substring(0, 5) == "heart") {
								int flagCCount = 0;
								int startPosition = 10;
								for (int i = startPosition; i < rStr->Length; i++) {
									if (rStr[i] == '\"') {
										flagCCount++;
										if (flagCCount == 1) {
											tempStrParent = rStr->Substring(startPosition, i - startPosition - 1);
											startPosition = i + 1;
										}
										else if (flagCCount == 2) {
											tempStr = msclr::interop::marshal_as<std::string>(rStr->Substring(startPosition, i - startPosition));
											startPosition = i + 1;

											if (tempStrParent == "EnableHeartbeat") {
												if (tempStr == "yes" || tempStr == "YES" || tempStr == "Yes" || tempStr == "1") {
													global_Flag_EnabelHeartbeat = 1;
												}
												else {
													global_Flag_EnabelHeartbeat = 0;
												}
											}
											else if (tempStrParent == "HeartbeatContent") {
												global_HeartbeatContent = tempStr;
											}
											else if (tempStrParent == "HeartbeatServerURL") {
												global_HeartbeatServerURL = tempStr;
											}
											else if (tempStrParent == "HeartbeatPort") {
												global_HeartbeatPort = tempStr;
											}
											else if (tempStrParent == "HeartbeatFrequency") {
												convertFromString(global_HeartbeatFrequency, tempStr);
											}
										}
									}
								}
							}
							else if (rStr->Substring(0, 5) == "ingre") {
								int flagCCount = 0;
								int startPosition = 11;
								IngredientsLabel tempIngredient;
								for (int i = startPosition; i < rStr->Length; i++) {
									if (rStr[i] == '\"') {
										flagCCount++;
										if (flagCCount == 1) {
											tempStrParent = rStr->Substring(startPosition, i - startPosition - 1);
											startPosition = i + 1;
										}
										else if (flagCCount == 2) {
											tempStr = msclr::interop::marshal_as<std::string>(rStr->Substring(startPosition, i - startPosition));
											startPosition = i + 2;

											if (tempStrParent == "SerialNumber") {
												convertFromString(tempIngredient.SerialNumber, tempStr);
											}
											else if (tempStrParent == "Label") {
												tempIngredient.LabelID = tempStr;
											}
											else if (tempStrParent == "Description") {
												tempIngredient.Description = tempStr;
											}
										}
										else if (flagCCount == 3) {
											tempStrParent = rStr->Substring(startPosition, i - startPosition - 1);
											startPosition = i + 1;
										}
										else if (flagCCount == 4) {
											tempStr = msclr::interop::marshal_as<std::string>(rStr->Substring(startPosition, i - startPosition));
											startPosition = i + 2;

											if (tempStrParent == "SerialNumber") {
												convertFromString(tempIngredient.SerialNumber, tempStr);
											}
											else if (tempStrParent == "Label") {
												tempIngredient.LabelID = tempStr;
											}
											else if (tempStrParent == "Description") {
												tempIngredient.Description = tempStr;
											}
										}
										else if (flagCCount == 5) {
											tempStrParent = rStr->Substring(startPosition, i - startPosition - 1);
											startPosition = i + 1;
										}
										else if (flagCCount == 6) {
											tempStr = msclr::interop::marshal_as<std::string>(rStr->Substring(startPosition, i - startPosition));
											startPosition = i + 2;

											if (tempStrParent == "SerialNumber") {
												convertFromString(tempIngredient.SerialNumber, tempStr);
											}
											else if (tempStrParent == "Label") {
												tempIngredient.LabelID = tempStr;
											}
											else if (tempStrParent == "Description") {
												tempIngredient.Description = tempStr;
											}

											break;
										}
									}
								}

								tempIngredient.ParameterValue = "";
								global_IngredientsLabel.push_back(tempIngredient);
							}
						}
					}
				}

				srCFG->Close();
				delete srCFG;
				delete rStr;
				delete tempStrParent;
			}
			catch (Exception^ e) {
				throw gcnew Exception(e->Message + e->StackTrace);
			}
		}
		else {
			INIFileErrorMessageBoxControl("Please put ini file into the right directory!\r\n" + gcnew System::String(global_INIFileDirectory.c_str()));
		}
	}
	void INIFileErrorMessageBoxControl(System::String^ ErrorShowing) {
		if (global_Flag_INIFileMessageBox == 0) {
			global_Flag_INIFileMessageBox = -1;
			if (MessageBox::Show(ErrorShowing) == System::Windows::Forms::DialogResult::OK) {
				global_Flag_INIFileMessageBox = 0;
			}
		}
	}


	//Read login ini file from Test Player, 0 success, -1 fail
	int ReadLoginFromTestPlayer(System::String^ LoginFilePath) {
		System::String^ strEmployee = LoginFilePath->Substring(0, LoginFilePath->IndexOf(' '));
		global_EmployeeID = msclr::interop::marshal_as<std::string>(strEmployee);
		iMESMainForm::global_iMESMainForm->tbxEmployeeID->Text = strEmployee;

		System::String^ strAccesslevel = LoginFilePath->Substring(LoginFilePath->IndexOf(' ') + 1, LoginFilePath->Length - LoginFilePath->IndexOf(' ') - 1);
		if (strAccesslevel->Substring(0, 3) == "Adm" || strAccesslevel->Substring(0, 3) == "ADM" || strAccesslevel->Substring(0, 3) == "adm") {
			global_Flag_AccessLevel = 2;
		}
		else if (strAccesslevel->Substring(0, 3) == "Eng" || strAccesslevel->Substring(0, 3) == "ENG" || strAccesslevel->Substring(0, 3) == "eng") {
			global_Flag_AccessLevel = 1;
		}
		else {
			global_Flag_AccessLevel = 0;
		}
		iMES::NewLoginAccessLevelButtonInitial();

		global_Flag_IfLogin = 1;
		iMESMainForm::global_iMESMainForm->Enabled = TRUE;
		Global_MachineStatus::global_MachineStatusForm->Enabled = TRUE;
		return 0;
	}


	//Machine Status
	//-1 initial all Status
	void WriteMachineStatusFile(int tempChangeStatus) {
		if (tempChangeStatus == -1) {
			SaveMachineStatusClass::global_Flag_MachineStatus_Down = 0;
			SaveMachineStatusClass::global_Flag_MachineStatus_Maintenance = 0;
			SaveMachineStatusClass::global_Flag_MachineStatus_Repair = 0;
			SaveMachineStatusClass::global_Flag_MachineStatus_Standby = 1;
			SaveMachineStatusClass::global_Flag_MachineStatus_Testing = 0;

			SaveMachineStatusClass::global_MachineStatus_Down_Time = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
			SaveMachineStatusClass::global_MachineStatus_Maintenance_Time = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
			SaveMachineStatusClass::global_MachineStatus_Repair_Time = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
			SaveMachineStatusClass::global_MachineStatus_Standby_Time = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
			SaveMachineStatusClass::global_MachineStatus_Testing_Time = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
		}

		StreamWriter^ swMSFile;
		swMSFile = File::CreateText(gcnew System::String(global_MachineStatusFileDirectory.c_str()));

		swMSFile->WriteLine("#Hash will allow you to put notes in. First line is always the version");
		swMSFile->WriteLine("#Please spell all the parameters the same as the example ini file");
		swMSFile->WriteLine("#All the columns are separated by exactly one space ");
		swMSFile->WriteLine("#If this file is first created, the machine status will be standby");
		swMSFile->WriteLine("#End with {EOF}");


		swMSFile->WriteLine("<status Down=\"" + SaveMachineStatusClass::global_Flag_MachineStatus_Down + "\" Timestamp=\"" + SaveMachineStatusClass::global_MachineStatus_Down_Time + "\" />");
		swMSFile->WriteLine("<status Maintenance=\"" + SaveMachineStatusClass::global_Flag_MachineStatus_Maintenance + "\" Timestamp=\"" + SaveMachineStatusClass::global_MachineStatus_Maintenance_Time + "\" />");
		swMSFile->WriteLine("<status Repair=\"" + SaveMachineStatusClass::global_Flag_MachineStatus_Repair + "\" Timestamp=\"" + SaveMachineStatusClass::global_MachineStatus_Repair_Time + "\" />");
		swMSFile->WriteLine("<status Standby=\"" + SaveMachineStatusClass::global_Flag_MachineStatus_Standby + "\" Timestamp=\"" + SaveMachineStatusClass::global_MachineStatus_Standby_Time + "\" />");
		swMSFile->WriteLine("<status Testing=\"" + SaveMachineStatusClass::global_Flag_MachineStatus_Testing + "\" Timestamp=\"" + SaveMachineStatusClass::global_MachineStatus_Testing_Time + "\" />");

		swMSFile->WriteLine("{EOF}");

		swMSFile->Close();
		delete swMSFile;
	}

	void ReadMachineStatusFile() {
		if (File::Exists(gcnew System::String(global_MachineStatusFileDirectory.c_str()))) {
			try {
				Global_MachineStatus::global_MachineStatusForm->Visible = FALSE;
				StreamReader^ srCFG = File::OpenText(gcnew System::String(global_MachineStatusFileDirectory.c_str()));
				System::String^ rStr;
				std::string tempStr;
				System::String^ tempStrParent;
				int col;
				int formI;

				while ((rStr = srCFG->ReadLine()) != nullptr) {
					if (rStr[0] == ';' || rStr[0] == '#') {
						//move on
						continue;
					}
					else {
						if (rStr[0] == '{') {
							rStr = rStr->Substring(1, rStr->Length - 2);
							if (rStr == "EOF") {
								break;
							}
						}
						else if (rStr[0] == '<') {
							rStr = rStr->Substring(1, rStr->Length - 2);
							if (rStr->Substring(0, 6) == "status" || rStr->Substring(0, 6) == "Status" || rStr->Substring(0, 6) == "STATUS") {
								int flagCCount = 0;
								int startPosition = 7;
								for (int i = startPosition; i < rStr->Length; i++) {
									if (rStr[i] == '\"') {
										flagCCount++;
										if (flagCCount == 1) {
											tempStrParent = rStr->Substring(startPosition, i - startPosition - 1);
											startPosition = i + 1;
										}
										else if (flagCCount == 2) {
											tempStr = msclr::interop::marshal_as<std::string>(rStr->Substring(startPosition, i - startPosition));
											startPosition = i + 1;

											if (tempStrParent == "down" || tempStrParent == "DOWN" || tempStrParent == "Down") {
												if (tempStr == "1") {
													SaveMachineStatusClass::global_Flag_MachineStatus_Down = 1;
													Global_MachineStatus::global_MachineStatusForm->btnMachineDown->BackColor = Color::Red;
													Global_MachineStatus::global_MachineStatusForm->Visible = TRUE;
													iMESMainForm::global_iMESMainForm->Enabled = FALSE;
												}
												else {
													SaveMachineStatusClass::global_Flag_MachineStatus_Down = 0;
													Global_MachineStatus::global_MachineStatusForm->btnMachineDown->BackColor = Color::LightGray;
												}
											}
											else if (tempStrParent == "maintenance" || tempStrParent == "Maintenance" || tempStrParent == "MAINTENANCE") {
												if (tempStr == "1") {
													SaveMachineStatusClass::global_Flag_MachineStatus_Maintenance = 1;
													Global_MachineStatus::global_MachineStatusForm->btnMaintenance->BackColor = Color::Red;
													Global_MachineStatus::global_MachineStatusForm->Visible = TRUE;
													iMESMainForm::global_iMESMainForm->Enabled = FALSE;
												}
												else {
													SaveMachineStatusClass::global_Flag_MachineStatus_Maintenance = 0;
													Global_MachineStatus::global_MachineStatusForm->btnMaintenance->BackColor = Color::LightGray;
												}
											}
											else if (tempStrParent == "repair" || tempStrParent == "Repair" || tempStrParent == "REPAIR") {
												if (tempStr == "1") {
													SaveMachineStatusClass::global_Flag_MachineStatus_Repair = 1;
													Global_MachineStatus::global_MachineStatusForm->btnUnderRepair->BackColor = Color::Red;
													Global_MachineStatus::global_MachineStatusForm->Visible = TRUE;
													iMESMainForm::global_iMESMainForm->Enabled = FALSE;
												}
												else {
													SaveMachineStatusClass::global_Flag_MachineStatus_Repair = 0;
													Global_MachineStatus::global_MachineStatusForm->btnUnderRepair->BackColor = Color::LightGray;
												}
											}
											else if (tempStrParent == "standby" || tempStrParent == "Standby" || tempStrParent == "STANDBY") {
												if (tempStr == "1") {
													SaveMachineStatusClass::global_Flag_MachineStatus_Standby = 1;
												}
												else {
													SaveMachineStatusClass::global_Flag_MachineStatus_Standby = 0;
												}
											}
											else if (tempStrParent == "testing" || tempStrParent == "Testing" || tempStrParent == "TESTING") {
												if (tempStr == "1") {
													SaveMachineStatusClass::global_Flag_MachineStatus_Testing = 1;
												}
												else {
													SaveMachineStatusClass::global_Flag_MachineStatus_Testing = 0;
												}
											}
										}
										else if (flagCCount == 3) {
											startPosition = i + 1;
										}
										else if (flagCCount == 4) {
											tempStr = msclr::interop::marshal_as<std::string>(rStr->Substring(startPosition, i - startPosition));

											if (tempStrParent == "down" || tempStrParent == "DOWN" || tempStrParent == "Down") {
												SaveMachineStatusClass::global_MachineStatus_Down_Time = rStr->Substring(startPosition, i - startPosition);
											}
											else if (tempStrParent == "maintenance" || tempStrParent == "Maintenance" || tempStrParent == "MAINTENANCE") {
												SaveMachineStatusClass::global_MachineStatus_Maintenance_Time = rStr->Substring(startPosition, i - startPosition);
											}
											else if (tempStrParent == "repair" || tempStrParent == "Repair" || tempStrParent == "REPAIR") {
												SaveMachineStatusClass::global_MachineStatus_Repair_Time = rStr->Substring(startPosition, i - startPosition);
											}
											else if (tempStrParent == "standby" || tempStrParent == "Standby" || tempStrParent == "STANDBY") {
												SaveMachineStatusClass::global_MachineStatus_Standby_Time = rStr->Substring(startPosition, i - startPosition);
											}
											else if (tempStrParent == "testing" || tempStrParent == "Testing" || tempStrParent == "TESTING") {
												SaveMachineStatusClass::global_MachineStatus_Testing_Time = rStr->Substring(startPosition, i - startPosition);
											}

											startPosition = i + 2;
											break;
										}
									}
								}
							}
						}
					}
				}

				srCFG->Close();
				delete srCFG;
				delete rStr;
				delete tempStrParent;
			}
			catch (Exception^ e) {
				throw gcnew Exception(e->Message + e->StackTrace);
			}
		}
		else {
			WriteMachineStatusFile(-1);
		}
	}

	int CheckTheHighestStatus() {
		if (SaveMachineStatusClass::global_Flag_MachineStatus_Down == 1) {
			return 16;
		}
		else if (SaveMachineStatusClass::global_Flag_MachineStatus_Maintenance == 1) {
			return 8;
		}
		else if (SaveMachineStatusClass::global_Flag_MachineStatus_Repair == 1) {
			return 4;
		}
		else if (SaveMachineStatusClass::global_Flag_MachineStatus_Standby == 1) {
			return 2;
		}
		else if (SaveMachineStatusClass::global_Flag_MachineStatus_Testing == 1) {
			return 1;
		}
		else {
			SaveMachineStatusClass::global_Flag_MachineStatus_Standby = 1;
			return 2;
		}
	}
	void SendMachineStatusToServer() {
		SccService::item^ TempItem = gcnew item();
		TempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_016";
		TempItem->tagValue = "" + CheckTheHighestStatus();
		TempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
		System::Collections::Generic::List<SccService::item^>^ tempListItem = gcnew System::Collections::Generic::List<SccService::item^>();
		tempListItem->Add(TempItem);

		WebService::SCCReturn =
			WebService::SCCWebService->DataUpload(gcnew System::String(global_MachineID.c_str()), gcnew System::String(global_WipEntity.c_str()), tempListItem);
		ShowMessageToMESHistory("DataUpload " + TempItem->tagValue + "\r\n");

		if (WebService::SCCReturn->errorCodek__BackingField == "0") {
		}
		else if (WebService::SCCReturn->errorCodek__BackingField == "-1") {
			
		}
		else if (WebService::SCCReturn->errorCodek__BackingField == "999" || WebService::SCCReturn->errorCodek__BackingField == "998") {
		}
		else {
		}
	}

	//down 16; maintenace 8; repair 4; standby 2; testing 1
	void MachineStatusChange(int tempChangeStatusNumber, int ChangetoStatus) {
		int tempFlagForServer = 0;
		int tempFlagForFile = 0;

		if (tempChangeStatusNumber == 16) {
			if (SaveMachineStatusClass::global_Flag_MachineStatus_Down == ChangetoStatus) {
				tempFlagForFile = 2;
			}
			else {
				SaveMachineStatusClass::global_Flag_MachineStatus_Down = ChangetoStatus;
				SaveMachineStatusClass::global_MachineStatus_Down_Time = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");

				if (ChangetoStatus == 1) {
					Global_MachineStatus::global_MachineStatusForm->btnMachineDown->BackColor = Color::Red;
				}
				else {
					Global_MachineStatus::global_MachineStatusForm->btnMachineDown->BackColor = Color::LightGray;
				}
			}
		}
		else {
			if (SaveMachineStatusClass::global_Flag_MachineStatus_Down == 1) {
				tempFlagForServer = 1;
			}

			if (tempChangeStatusNumber == 8) {
				if (SaveMachineStatusClass::global_Flag_MachineStatus_Maintenance == ChangetoStatus) {
					tempFlagForFile = 2;
				}
				else {
					SaveMachineStatusClass::global_Flag_MachineStatus_Maintenance = ChangetoStatus;
					SaveMachineStatusClass::global_MachineStatus_Maintenance_Time = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
				}

				if (ChangetoStatus == 1) {
					Global_MachineStatus::global_MachineStatusForm->btnMaintenance->BackColor = Color::Red;
				}
				else {
					Global_MachineStatus::global_MachineStatusForm->btnMaintenance->BackColor = Color::LightGray;
				}
			}
			else {
				if (SaveMachineStatusClass::global_Flag_MachineStatus_Maintenance == 1) {
					tempFlagForServer = 1;
				}
				
				if (tempChangeStatusNumber == 4) {
					if (SaveMachineStatusClass::global_Flag_MachineStatus_Repair == ChangetoStatus) {
						tempFlagForFile = 2;
					}
					else {
						SaveMachineStatusClass::global_Flag_MachineStatus_Repair = ChangetoStatus;
						SaveMachineStatusClass::global_MachineStatus_Repair_Time = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");

						if (ChangetoStatus == 1) {
							Global_MachineStatus::global_MachineStatusForm->btnUnderRepair->BackColor = Color::Red;
						}
						else {
							Global_MachineStatus::global_MachineStatusForm->btnUnderRepair->BackColor = Color::LightGray;
						}
					}
				}
				else {
					if (SaveMachineStatusClass::global_Flag_MachineStatus_Repair == 1) {
						tempFlagForServer = 1;
					}

					if (tempChangeStatusNumber == 2) {
						if (SaveMachineStatusClass::global_Flag_MachineStatus_Standby == ChangetoStatus) {
							tempFlagForFile = 2;
						}
						else {
							SaveMachineStatusClass::global_Flag_MachineStatus_Standby = ChangetoStatus;
							SaveMachineStatusClass::global_MachineStatus_Standby_Time = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
						}
					}
					else {
						if (SaveMachineStatusClass::global_Flag_MachineStatus_Standby == 1) {
							tempFlagForServer = 1;
						}

						if (tempChangeStatusNumber == 1) {
							if (SaveMachineStatusClass::global_Flag_MachineStatus_Testing == ChangetoStatus) {
								tempFlagForFile = 2;
							}
							else {
								SaveMachineStatusClass::global_Flag_MachineStatus_Testing = ChangetoStatus;
								SaveMachineStatusClass::global_MachineStatus_Testing_Time = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
							}
						}
						else {
							tempFlagForFile = -1;
						}
					}
				}
			}
		}

		if (tempFlagForFile == 0) {
			WriteMachineStatusFile(1);

			if (tempFlagForServer == 0) {
				if (global_Flag_EnabelHeartbeat == 1 && global_Flag_HeartbeatWorking == 0) {
					HeartbeatMessageBoxControl();
					return;
				}
				SendMachineStatusToServer();
			}
		}
		else if (tempFlagForFile == -1) {
		}
	}


	//Download
	int DownloadFileFromServer(System::String^ URLFromServer, System::String^ FileName) {
		try {
			System::Net::WebClient^ TwebCilent = gcnew System::Net::WebClient();
			TwebCilent->DownloadFile(URLFromServer, FileName);

			delete TwebCilent;
			return 0;
		}
		catch (System::Exception^ e) {
			return -1;
		}
	}


	//Zip/Unzip
	int PackageFolder(System::String^ folderName, System::String^ compressedFileName, bool overrideExisting)
	{
		if (folderName->EndsWith("\\"))
			folderName = folderName->Remove(folderName->Length - 1);
		int result = -1;
		if (!System::IO::Directory::Exists(folderName))
		{
			return result;
		}

		if (!overrideExisting && System::IO::File::Exists(compressedFileName))
		{
			return result;
		}
		try
		{
			Package^ packExam = Package::Open(compressedFileName, FileMode::Create);
			System::Collections::Generic::IEnumerable<System::String^>^ fileList = Directory::EnumerateFiles(folderName, "*", SearchOption::AllDirectories);

			for each(System::String^ fileName in fileList)
			{
				//The path in the package is all of the subfolders after folderName
				System::String^ pathInPackage;
				pathInPackage = Path::GetDirectoryName(fileName)->Replace(folderName, System::String::Empty) + "/" + Path::GetFileName(fileName);

				Uri^ partUriDocument = PackUriHelper::CreatePartUri(gcnew Uri(pathInPackage, UriKind::Relative));
				PackagePart^ packagePartDocument = packExam->CreatePart(partUriDocument, "", CompressionOption::Maximum);
				FileStream^ fileStream = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
				fileStream->CopyTo(packagePartDocument->GetStream());

				delete pathInPackage;
				delete partUriDocument;
				delete packagePartDocument;
				delete fileStream;
			}

			result = 0;
			packExam->Close();
			delete packExam;
		}
		catch (Exception^ e)
		{
			throw gcnew Exception("Error zipping folder " + folderName, e);
		}

		return result;
	}
	
	int PackageFile(System::String^ fileName, System::String^ compressedFileName, bool overrideExisting)
	{
		int result = -1;

		if (!File::Exists(fileName))
		{
			return result;
		}

		if (!overrideExisting && File::Exists(compressedFileName))
		{
			return result;
		}

		try
		{
			Uri^ partUriDocument = PackUriHelper::CreatePartUri(gcnew Uri(Path::GetFileName(fileName), UriKind::Relative));

			Package^ package = Package::Open(compressedFileName, FileMode::OpenOrCreate);
			if (package->PartExists(partUriDocument))
			{
				package->DeletePart(partUriDocument);
			}

			PackagePart^ packagePartDocument = package->CreatePart(partUriDocument, "", CompressionOption::Maximum);
			FileStream^ fileStream = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
			fileStream->CopyTo(packagePartDocument->GetStream());
			result = 0;

			fileStream->Close();
		}
		catch (Exception^ e)
		{
			throw gcnew Exception("Error zipping file " + fileName, e);
		}

		return result;
	}
	void ExtractPart(PackagePart^ packagePart, System::String^ targetDirectory, bool overrideExisting)
	{
		System::String^ stringPart = targetDirectory + HttpUtility::UrlDecode(packagePart->Uri->ToString())->Replace('\\', '/');

		if (!Directory::Exists(Path::GetDirectoryName(stringPart)))
			Directory::CreateDirectory(Path::GetDirectoryName(stringPart));

		if (!overrideExisting && File::Exists(stringPart))
			return;
		FileStream^ fileStream = gcnew FileStream(stringPart, FileMode::Create);
		packagePart->GetStream()->CopyTo(fileStream);

		delete stringPart;
		delete fileStream;
	}
	int UncompressFile(System::String^ folderName, System::String^ compressedFileName, bool overrideExisting)
	{
		int result = 0;
		try
		{
			if (!File::Exists(compressedFileName))
			{
				return result;
			}

			if (!overrideExisting && File::Exists(compressedFileName))
			{
				return result;
			}

			DirectoryInfo^ directoryInfo = gcnew DirectoryInfo(folderName);
			if (!directoryInfo->Exists)
				directoryInfo->Create();

			Package^ package = Package::Open(compressedFileName, FileMode::Open, FileAccess::Read);
			
			try {
				PackagePartCollection^ tempCollection = package->GetParts();

				for each(PackagePart^ packagePart in tempCollection)
				{
					ExtractPart(packagePart, folderName, overrideExisting);
				}

				delete tempCollection;
			}
			catch (Exception^ e)
			{
				throw gcnew Exception("Error unzipping file " + compressedFileName, e);
			}

			delete directoryInfo;
			delete package;
			result = 1;
		}
		catch (Exception^ e)
		{
			throw gcnew Exception("Error unzipping file " + compressedFileName, e);
		}

		return result;
	}

	//Bar code scanning
	void WipEntityMessageBoxControl(System::String^ ErrorShowing) {
		if (global_Flag_WipEntityMessageBox == 0) {
			global_Flag_WipEntityMessageBox = -1;
			if (MessageBox::Show(ErrorShowing) == System::Windows::Forms::DialogResult::OK) {
				global_Flag_WipEntityMessageBox = 0;
			}
		}
	}

	//Output ini file error
	void OutPutIniFileErrorMessageBoxControl(System::String^ ErrorShowing) {
		if (global_Flag_OutputFileMessageBox == 0) {
			global_Flag_OutputFileMessageBox = -1;
			if (MessageBox::Show(ErrorShowing) == System::Windows::Forms::DialogResult::OK) {
				global_Flag_OutputFileMessageBox = 0;
			}
		}
	}

	int GetBarCodeFromHandBarCodeScanningGun(System::String^ strBarCode) {//Task Control & Ingredients
		if (global_Flag_CallAgv == 0 && global_Flag_iMESMode == 1) {
			return -99;
		}

		global_TestedBoards.clear();
		System::String^ tempBarCode = strBarCode->Substring(0, strBarCode->IndexOf(' '));
		
		System::String^ strTempWipEntity = strBarCode->Substring(0, 8);

		System::String^ strPath = strBarCode->Substring(strBarCode->IndexOf(' ') + 1, strBarCode->Length - strBarCode->IndexOf(' ') - 1);
		System::String^ strIngredientsPath = "";
		
		for (int i = 0;i < strPath->Length - 1;i++) {
			if (strPath[i] == '\\') {
				strIngredientsPath += "\\";
			}
			strIngredientsPath += strPath[i];
		}
		strIngredientsPath->Replace("\n", "");
		global_TestPlayerIngredientsPath = msclr::interop::marshal_as<std::string>(strIngredientsPath + "\\\\Ingredients.ini");
		//initial global parameter
		global_BarCode = msclr::interop::marshal_as<std::string>(tempBarCode);
		global_SerialNumber = "";
		global_JobID = "";
		global_Continuity = "";
		global_Insulation = "";
		global_StripCount = "";
		global_TestProgramWholeDirectory = "";
		global_DoubleAllTestCount = 0;
		global_DoubleRestTestCount = global_DoubleAllTestCount;
		global_DoubleAllowNGCount = 0;

		//initial interface
		iMESMainForm::global_iMESMainForm->tbxBarCode->Text = tempBarCode;
		iMESMainForm::global_iMESMainForm->tbxWipEntity->Text = "";
		iMESMainForm::global_iMESMainForm->tbxJobID->Text = "";
		iMESMainForm::global_iMESMainForm->tbxTestCountNow->Text = "";
		iMESMainForm::global_iMESMainForm->tbxTestCountAll->Text = "";
		iMESMainForm::global_iMESMainForm->dtgrdvwIngredients->ClearSelection();
		iMESMainForm::global_iMESMainForm->dtgrdvwIngredients->Rows->Clear();


		FileStream^ fileIngre = gcnew FileStream(strIngredientsPath + "\\\\Ingredients.ini", FileMode::Create);
		StreamWriter^ swIngredients = gcnew StreamWriter(fileIngre);
		swIngredients->WriteLine("[CurrentIngredientsCredentials]");
		int flag_swIngredients = 0;


		if (global_Flag_iMESMode == 0) {
			if (iMESMainForm::global_iMESMainForm->tbxOfflineModeJobID->Text != "") {
				global_JobID = msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeJobID->Text);
				iMESMainForm::global_iMESMainForm->tbxJobID->Text = iMESMainForm::global_iMESMainForm->tbxOfflineModeJobID->Text;
			}
			if (iMESMainForm::global_iMESMainForm->tbxOfflineModeWipEntity->Text != "") {
				global_WipEntity = msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeWipEntity->Text);
				iMESMainForm::global_iMESMainForm->tbxWipEntity->Text = iMESMainForm::global_iMESMainForm->tbxOfflineModeWipEntity->Text;
			}
			if (iMESMainForm::global_iMESMainForm->tbxOfflineModeProgramDirectory->Text != "") {
				global_TestProgramWholeDirectory = msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeProgramDirectory->Text);
			}
			if (iMESMainForm::global_iMESMainForm->tbxOfflineModeTestCount->Text != "") {
				iMESMainForm::global_iMESMainForm->tbxTestCountAll->Text = iMESMainForm::global_iMESMainForm->tbxOfflineModeTestCount->Text;
				iMESMainForm::global_iMESMainForm->tbxTestCountNow->Text = iMESMainForm::global_iMESMainForm->tbxOfflineModeTestCount->Text;

				convertFromString(global_DoubleAllTestCount, msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeTestCount->Text));
				global_DoubleRestTestCount = global_DoubleAllTestCount;
			}
			if (iMESMainForm::global_iMESMainForm->tbxOfflineModeAllowNGCount->Text != "") {
				convertFromString(global_DoubleAllowNGCount, msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeAllowNGCount->Text));
			}

			swIngredients->WriteLine("Machine ID=" + gcnew String(global_MachineID.c_str()));
			swIngredients->WriteLine("Serial ID=" + gcnew String(global_SerialNumber.c_str()));
			swIngredients->WriteLine("Job ID=" + gcnew String(global_JobID.c_str()));
			swIngredients->WriteLine("Wip Entity=" + gcnew String(global_WipEntity.c_str()));
			swIngredients->WriteLine("Continuity=" + gcnew String(global_Continuity.c_str()));
			swIngredients->WriteLine("Insulation=" + gcnew String(global_Insulation.c_str()));
			swIngredients->WriteLine("Strip Count=" + gcnew String(global_StripCount.c_str()));
			swIngredients->WriteLine("Test Program directory=" + gcnew String(global_TestProgramWholeDirectory.c_str()));
			swIngredients->WriteLine("Test Count=" + global_DoubleAllTestCount);
			swIngredients->WriteLine("NG Count=" + global_DoubleAllowNGCount);

			flag_swIngredients = 1;
			swIngredients->Close();
		}


		if (global_Flag_EnabelHeartbeat == 1 && global_Flag_HeartbeatWorking == 0 && global_Flag_iMESMode == 1) {
			HeartbeatMessageBoxControl();
			return -1;
		}

		
		WebService::SCCReturn =
			WebService::SCCWebService->TaskControl(gcnew System::String(global_MachineID.c_str()), gcnew System::String(global_BarCode.c_str()));
		ShowMessageToMESHistory("TaskControl\r\n");

		if (WebService::SCCReturn->errorCodek__BackingField == "0") {
			if (global_Flag_EnabelHeartbeat == 1 && global_Flag_HeartbeatWorking == 0 && global_Flag_iMESMode == 1) {
				HeartbeatMessageBoxControl();
				return -1;
			}
			WebService::SCCReturn =
				WebService::SCCWebService->Ingredients(gcnew System::String(global_MachineID.c_str()), gcnew System::String(global_BarCode.c_str()));
			ShowMessageToMESHistory("Ingredients\r\n");

			if (WebService::SCCReturn->errorCodek__BackingField == "0") {
				global_GetIngredientsTime = msclr::interop::marshal_as<std::string>((DateTime::Now).ToString("yyyyMMddHHmmss"));
				if (WebService::SCCReturn->items != nullptr) {
					if (!Directory::Exists(Path::GetDirectoryName(strIngredientsPath)))
						Directory::CreateDirectory(Path::GetDirectoryName(strIngredientsPath));

					for each (item^ tempItem in WebService::SCCReturn->items)
					{
						System::String^ tempIDFromMES = tempItem->tagCode;
						tempIDFromMES = tempIDFromMES->Substring(tempIDFromMES->IndexOf('_') + 1, tempIDFromMES->Length - tempIDFromMES->IndexOf('_') - 1);
						System::String^ tempValue = tempItem->tagValue;
						System::String^ tempCode = "";

						for (int i = 0; i < global_IngredientsLabel.size(); i++) {
							if (global_IngredientsLabel[i].LabelID == msclr::interop::marshal_as<std::string>(tempIDFromMES)) {
								//for ingredients
								DataGridViewRow^ tempRow = gcnew DataGridViewRow();
								int RowIndex = iMESMainForm::global_iMESMainForm->dtgrdvwIngredients->Rows->Add(tempRow);
								tempCode = gcnew System::String(global_IngredientsLabel[i].Description.c_str());
								iMESMainForm::global_iMESMainForm->dtgrdvwIngredients->Rows[RowIndex]->Cells[0]->Value = tempCode;
								iMESMainForm::global_iMESMainForm->dtgrdvwIngredients->Rows[RowIndex]->Cells[1]->Value = tempValue;
								iMESMainForm::global_iMESMainForm->dtgrdvwIngredients->Rows[RowIndex]->Cells[2]->Value = tempIDFromMES;

								//for interface
								if (tempIDFromMES == "1000") {
									global_WipEntity = msclr::interop::marshal_as<std::string>(tempValue);
									iMESMainForm::global_iMESMainForm->tbxWipEntity->Text = tempValue;
								}
								else if (tempIDFromMES == "1001") {
									iMESMainForm::global_iMESMainForm->tbxJobID->Text = tempValue;
									global_JobID = msclr::interop::marshal_as<std::string>(tempValue);
								}
								else if (tempIDFromMES == "1002") {
									global_SerialNumber = msclr::interop::marshal_as<std::string>(tempValue);
								}
								else if (tempIDFromMES == "1003") {
									global_StripCount = msclr::interop::marshal_as<std::string>(tempValue);
								}
								else if (tempIDFromMES == "1010") {
									global_Continuity = msclr::interop::marshal_as<std::string>(tempValue);
								}
								else if (tempIDFromMES == "1011") {
									global_Insulation = msclr::interop::marshal_as<std::string>(tempValue);
								}
								else if (tempIDFromMES == "1012") {
									global_TestProgramWholeDirectory = msclr::interop::marshal_as<std::string>(tempValue);
								}
								else if (tempIDFromMES == "1013") {
									iMESMainForm::global_iMESMainForm->tbxTestCountAll->Text = tempValue;
									iMESMainForm::global_iMESMainForm->tbxTestCountNow->Text = tempValue;

									convertFromString(global_DoubleAllTestCount, msclr::interop::marshal_as<std::string>(tempValue));
									global_DoubleRestTestCount = global_DoubleAllTestCount;
								}
								else if (tempIDFromMES == "1014") {
									convertFromString(global_DoubleAllowNGCount, msclr::interop::marshal_as<std::string>(tempValue));
								}

								//save to global
								global_IngredientsLabel[i].ParameterValue = msclr::interop::marshal_as<std::string>(tempValue);

								break;
							}
						}
					}

					if (global_Flag_iMESMode == 0) {
						if (iMESMainForm::global_iMESMainForm->tbxOfflineModeJobID->Text != "") {
							global_JobID = msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeJobID->Text);
							iMESMainForm::global_iMESMainForm->tbxJobID->Text = iMESMainForm::global_iMESMainForm->tbxOfflineModeJobID->Text;
						}
						if (iMESMainForm::global_iMESMainForm->tbxOfflineModeWipEntity->Text != "") {
							global_WipEntity = msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeWipEntity->Text);
							iMESMainForm::global_iMESMainForm->tbxWipEntity->Text = iMESMainForm::global_iMESMainForm->tbxOfflineModeWipEntity->Text;
						}
						if (iMESMainForm::global_iMESMainForm->tbxOfflineModeProgramDirectory->Text != "") {
							global_TestProgramWholeDirectory = msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeProgramDirectory->Text);
						}
						if (iMESMainForm::global_iMESMainForm->tbxOfflineModeTestCount->Text != "") {
							iMESMainForm::global_iMESMainForm->tbxTestCountAll->Text = iMESMainForm::global_iMESMainForm->tbxOfflineModeTestCount->Text;
							iMESMainForm::global_iMESMainForm->tbxTestCountNow->Text = iMESMainForm::global_iMESMainForm->tbxOfflineModeTestCount->Text;

							convertFromString(global_DoubleAllTestCount, msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeTestCount->Text));
							global_DoubleRestTestCount = global_DoubleAllTestCount;
						}
						if (iMESMainForm::global_iMESMainForm->tbxOfflineModeAllowNGCount->Text != "") {
							convertFromString(global_DoubleAllowNGCount, msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeAllowNGCount->Text));
						}
					}
					

					if (flag_swIngredients == 1) {
						swIngredients = gcnew StreamWriter(fileIngre);
						swIngredients->WriteLine("[CurrentIngredientsCredentials]");
						flag_swIngredients = 0;
					}

					if (strTempWipEntity == "12345678") {
						swIngredients->WriteLine("Machine ID=" + gcnew String(global_MachineID.c_str()));
						swIngredients->WriteLine("Serial ID=");
						swIngredients->WriteLine("Job ID=SCC_Job_01");
						swIngredients->WriteLine("Wip Entity=12345678");
						swIngredients->WriteLine("Continuity=");
						swIngredients->WriteLine("Insulation=");
						swIngredients->WriteLine("Strip Count=");
						swIngredients->WriteLine("Test Program directory=E:\\SCC_Server\\SCC_Job_01");
						swIngredients->WriteLine("Test Count=" + global_DoubleAllTestCount);
						swIngredients->WriteLine("NG Count=" + global_DoubleAllowNGCount);

						global_WipEntity = "12345678";
					}
					else if (strTempWipEntity == "87654321") {
						swIngredients->WriteLine("Machine ID=" + gcnew String(global_MachineID.c_str()));
						swIngredients->WriteLine("Serial ID=");
						swIngredients->WriteLine("Job ID=SCC_Job_02");
						swIngredients->WriteLine("Wip Entity=87654321");
						swIngredients->WriteLine("Continuity=");
						swIngredients->WriteLine("Insulation=");
						swIngredients->WriteLine("Strip Count=");
						swIngredients->WriteLine("Test Program directory=E:\\SCC_Server\\SCC_Job_02");
						swIngredients->WriteLine("Test Count=" + global_DoubleAllTestCount);
						swIngredients->WriteLine("NG Count=" + global_DoubleAllowNGCount);

						global_WipEntity = "87654321";
					}
					else {
						swIngredients->WriteLine("Machine ID=" + gcnew String(global_MachineID.c_str()));
						swIngredients->WriteLine("Serial ID=" + gcnew String(global_SerialNumber.c_str()));
						swIngredients->WriteLine("Job ID=" + gcnew String(global_JobID.c_str()));
						swIngredients->WriteLine("Wip Entity=" + gcnew String(global_WipEntity.c_str()));
						swIngredients->WriteLine("Continuity=" + gcnew String(global_Continuity.c_str()));
						swIngredients->WriteLine("Insulation=" + gcnew String(global_Insulation.c_str()));
						swIngredients->WriteLine("Strip Count=" + gcnew String(global_StripCount.c_str()));
						swIngredients->WriteLine("Test Program directory=" + gcnew String(global_TestProgramWholeDirectory.c_str()));
						swIngredients->WriteLine("Test Count=" + global_DoubleAllTestCount);
						swIngredients->WriteLine("NG Count=" + global_DoubleAllowNGCount);
					}
					flag_swIngredients = 1;
					swIngredients->Close();

					return 0;
				}
				else {
					return -1;
				}
			}
			else if (WebService::SCCReturn->errorCodek__BackingField == "-1") {
				return 1;
			}
			else if (WebService::SCCReturn->errorCodek__BackingField == "-2") {
				iMESMainForm::global_iMESMainForm->btnReturn->Enabled = TRUE;

				return 2;
			}
			else if (WebService::SCCReturn->errorCodek__BackingField == "999" || WebService::SCCReturn->errorCodek__BackingField == "998") {
				//TODO
				return -1;
			}
			else {
				return -1;
			}
		}
		else if (WebService::SCCReturn->errorCodek__BackingField == "-1") {
			iMESMainForm::global_iMESMainForm->btnReturn->Enabled = TRUE;

			return 2;
		}
		else if (WebService::SCCReturn->errorCodek__BackingField == "999" || WebService::SCCReturn->errorCodek__BackingField == "998") {
			return -1;
		}
		else {
			return -1;
		}

		if (global_Flag_iMESMode == 0 && flag_swIngredients == 0) {
			if (iMESMainForm::global_iMESMainForm->tbxOfflineModeJobID->Text != "") {
				global_JobID = msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeJobID->Text);
				iMESMainForm::global_iMESMainForm->tbxJobID->Text = iMESMainForm::global_iMESMainForm->tbxOfflineModeJobID->Text;
			}
			if (iMESMainForm::global_iMESMainForm->tbxOfflineModeWipEntity->Text != "") {
				global_WipEntity = msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeWipEntity->Text);
				iMESMainForm::global_iMESMainForm->tbxWipEntity->Text = iMESMainForm::global_iMESMainForm->tbxOfflineModeWipEntity->Text;
			}
			if (iMESMainForm::global_iMESMainForm->tbxOfflineModeProgramDirectory->Text != "") {
				global_TestProgramWholeDirectory = msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeProgramDirectory->Text);
			}
			if (iMESMainForm::global_iMESMainForm->tbxOfflineModeTestCount->Text != "") {
				iMESMainForm::global_iMESMainForm->tbxTestCountAll->Text = iMESMainForm::global_iMESMainForm->tbxOfflineModeTestCount->Text;
				iMESMainForm::global_iMESMainForm->tbxTestCountNow->Text = iMESMainForm::global_iMESMainForm->tbxOfflineModeTestCount->Text;

				convertFromString(global_DoubleAllTestCount, msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeTestCount->Text));
				global_DoubleRestTestCount = global_DoubleAllTestCount;
			}
			if (iMESMainForm::global_iMESMainForm->tbxOfflineModeAllowNGCount->Text != "") {
				convertFromString(global_DoubleAllowNGCount, msclr::interop::marshal_as<std::string>(iMESMainForm::global_iMESMainForm->tbxOfflineModeAllowNGCount->Text));
			}
		}
		swIngredients->Close();
		return 0;
	}

	int GetFlawFileForFP(System::String^ strBarCode) {
		System::String^ strPath = "";
		System::String^ strTempWipEntity = gcnew String(global_WipEntity.c_str());
		SccService::item^ TempItem = gcnew item();
		TempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1001";
		TempItem->tagValue = strBarCode;
		TempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
		System::Collections::Generic::List<SccService::item^>^ tempListItem = gcnew System::Collections::Generic::List<SccService::item^>();
		tempListItem->Add(TempItem);

		if (global_Flag_iMESMode == 0) {
			if (iMESMainForm::global_iMESMainForm->tbxOfflineModeFlawFIleDirectory->Text != "") {
				strPath = iMESMainForm::global_iMESMainForm->tbxOfflineModeFlawFIleDirectory->Text;
			}
		}
		DownloadFileFromServer(strPath, gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\" + gcnew String(global_WipEntity.c_str()) + "_ORI.zip");
		global_FlawFileServerPath = msclr::interop::marshal_as<std::string>(strPath);


		if (global_Flag_EnabelHeartbeat == 1 && global_Flag_HeartbeatWorking == 0 && global_Flag_iMESMode == 1) {
			HeartbeatMessageBoxControl();
			return -1;
		}
		WebService::SCCReturn =
			WebService::SCCWebService->FindFlawFile(gcnew System::String(global_MachineID.c_str()), gcnew System::String(global_WipEntity.c_str()), tempListItem);
		ShowMessageToMESHistory("FindFlawFile\r\n");

		if (WebService::SCCReturn->errorCodek__BackingField == "0") {
			global_Flag_FlawFileMode = 0;

			if (strTempWipEntity == "12345678") {
				strPath = iMESMainForm::global_iMESMainForm->tbxOfflineModeFlawFIleDirectory->Text;
				DownloadFileFromServer(strPath, gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\12345678_ORI.zip");
			}
			else if (strTempWipEntity == "87654321") {
				strPath = iMESMainForm::global_iMESMainForm->tbxOfflineModeFlawFIleDirectory->Text;
				DownloadFileFromServer(strPath, gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\87654321_ORI.zip");
			}
			else if(strTempWipEntity == "11213818") {
				strPath = iMESMainForm::global_iMESMainForm->tbxOfflineModeFlawFIleDirectory->Text;
				DownloadFileFromServer(strPath, gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\112138182_ORI.zip");
			}
			else {
				strPath = WebService::SCCReturn->filePath/* + "\\Strip" + gcnew String(global_WipEntity.c_str()) + ".zip"*/;

				if (global_Flag_iMESMode == 0) {
					if (iMESMainForm::global_iMESMainForm->tbxOfflineModeFlawFIleDirectory->Text != "") {
						strPath = iMESMainForm::global_iMESMainForm->tbxOfflineModeFlawFIleDirectory->Text;
					}
				}
				
				DownloadFileFromServer(strPath, gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\" + gcnew String(global_WipEntity.c_str()) + "_ORI.zip");
			}

			global_FlawFileServerPath = msclr::interop::marshal_as<std::string>(strPath);

			return 0;
		}
		else if (WebService::SCCReturn->errorCodek__BackingField == "1") {
			global_Flag_FlawFileMode = 1;
			if (strTempWipEntity == "12345678") {
				strPath = "E:\\SCC_Server\\FlawFile\\12345678.zip";
				DownloadFileFromServer("E:\\SCC_Server\\FlawFile\\12345678.zip", gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\12345678_ORI.zip");
			}
			else if (strTempWipEntity == "87654321") {
				strPath = "E:\\SCC_Server\\FlawFile\\87654321.zip";
				DownloadFileFromServer("E:\\SCC_Server\\FlawFile\\87654321.zip", gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\87654321_ORI.zip");
			}
			else if (strTempWipEntity == "11213818") {
				strPath = "E:\\SCC_Server\\FlawFile\\11213818.zip";
				DownloadFileFromServer("E:\\SCC_Server\\FlawFile\\112138182.zip", gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\112138182_ORI.zip");
			}
			else {
				strPath = WebService::SCCReturn->filePath;

				if (global_Flag_iMESMode == 0) {
					if (iMESMainForm::global_iMESMainForm->tbxOfflineModeFlawFIleDirectory->Text != "") {
						strPath = iMESMainForm::global_iMESMainForm->tbxOfflineModeFlawFIleDirectory->Text;
					}
				}

				DownloadFileFromServer(strPath, gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\" + gcnew String(global_WipEntity.c_str()) + "_ORI.zip");
			}

			global_FlawFileServerPath = msclr::interop::marshal_as<std::string>(strPath);

			return 1;
		}
		else if (WebService::SCCReturn->errorCodek__BackingField == "-1") {
			return -1;
		}
		else if (WebService::SCCReturn->errorCodek__BackingField == "999" || WebService::SCCReturn->errorCodek__BackingField == "998") {
			return -1;
		}
		else {
			return -1;
		}

		delete strPath;
		delete strTempWipEntity;
		delete TempItem;
		return 0;
	}

	int GetFlawFileSavedPathFromFP(System::String^ strPath) {//Xout Files
		System::String^ strFlawFilePath = "";
		for (int i = 0;i < strPath->Length - 1;i++) {
			if (strPath[i] == '\\') {
				strFlawFilePath += "\\";
			}
			strFlawFilePath += strPath[i];
		}
		strFlawFilePath->Replace("\n", "");

		if (strPath != "")
		{
			global_FlawFileTestPlayerPath = msclr::interop::marshal_as<std::string>(strPath->Substring(0, strPath->Length - 1));
		}
		
		System::String^ strTempWipEntity = gcnew System::String(global_WipEntity.c_str());

		if (strTempWipEntity == "12345678") {
			try {
				System::IO::Compression::ZipFile::ExtractToDirectory(gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\12345678_ORI.zip", strFlawFilePath);
			}
			catch (Exception^ e) {
				ShowMessageToMESHistory(e->StackTrace + " " + e->Message + "\r\n", true);
			}
		}
		else if (strTempWipEntity == "87654321") {
			try {
				System::IO::Compression::ZipFile::ExtractToDirectory(gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\87654321_ORI.zip", strFlawFilePath);
			}
			catch (Exception^ e) {
				ShowMessageToMESHistory(e->StackTrace + " " + e->Message + "\r\n", true);
			}
		}
		else if (strTempWipEntity == "11213818") {
			try {
				System::IO::Compression::ZipFile::ExtractToDirectory(gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\112138182_ORI.zip", strFlawFilePath);
			}
			catch (Exception^ e) {
				ShowMessageToMESHistory(e->StackTrace + " " + e->Message + "\r\n", true);
			}
		}
		else {
			try {
				if (!Directory::Exists(strFlawFilePath)) {
					Directory::CreateDirectory(Path::GetDirectoryName(strFlawFilePath));
				}
				else {
					EmptyDirectory(strFlawFilePath);
				}
				System::IO::Compression::ZipFile::ExtractToDirectory(gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\" + gcnew String(global_WipEntity.c_str()) + "_ORI.zip", strFlawFilePath);
			}
			catch (Exception^ e) {
				ShowMessageToMESHistory(e->StackTrace + " " + e->Message + "\r\n", true);
			}
		}

		if (File::Exists(strFlawFilePath + "\\[Content_Types].xml")) {
			File::Delete(strFlawFilePath + "\\[Content_Types].xml");
		}

		delete strPath;
		delete strTempWipEntity;
		delete strFlawFilePath;
		return 0;
	}


	//Result of each board
	int NewTestedBoardFinish(TestedBoardInfo tempTestedBoard) {
		int tempFlag = 0;
		TestedBoardInfo SameTestedBoard;

		for (int i = 0;i < global_TestedBoards.size();i++) {
			if (global_TestedBoards[i].BoardBarCode == tempTestedBoard.BoardBarCode) {
				tempFlag = 1;
				SameTestedBoard.BoardBarCode = global_TestedBoards[i].BoardBarCode;
				SameTestedBoard.BadUnitCount = global_TestedBoards[i].BadUnitCount;
				SameTestedBoard.GoodUnitCount = global_TestedBoards[i].GoodUnitCount;
				SameTestedBoard.TestUnitCount = global_TestedBoards[i].TestUnitCount;

				global_TestedBoards[i].BadUnitCount = tempTestedBoard.BadUnitCount;
				global_TestedBoards[i].GoodUnitCount = tempTestedBoard.GoodUnitCount;
				global_TestedBoards[i].TestUnitCount = tempTestedBoard.TestUnitCount;
				global_TestedBoards[i].PressureSmall = tempTestedBoard.PressureSmall;
				global_TestedBoards[i].SoftLanding = tempTestedBoard.SoftLanding;

				break;
			}
		}

		if (tempFlag == 0) {
			if (global_DoubleRestTestCount > tempTestedBoard.GoodUnitCount + tempTestedBoard.BadUnitCount) {
				global_DoubleRestTestCount = global_DoubleRestTestCount - tempTestedBoard.GoodUnitCount - tempTestedBoard.BadUnitCount;
				iMESMainForm::global_iMESMainForm->tbxTestCountNow->Text = "" + global_DoubleRestTestCount;
			}
			else {
				global_DoubleRestTestCount = 0;
				iMESMainForm::global_iMESMainForm->tbxTestCountNow->Text = "" + global_DoubleRestTestCount;

				iMESMainForm::global_iMESMainForm->btnTestFinish->Enabled = TRUE;
				iMESMainForm::global_iMESMainForm->Activate();
			}

			global_TestedBoards.push_back(tempTestedBoard);
		}
		else {
			global_DoubleRestTestCount = global_DoubleRestTestCount + SameTestedBoard.GoodUnitCount + SameTestedBoard.BadUnitCount;

			global_DoubleRestTestCount = global_DoubleRestTestCount - tempTestedBoard.GoodUnitCount - tempTestedBoard.BadUnitCount;
			if (global_DoubleRestTestCount > 0) {
				iMESMainForm::global_iMESMainForm->tbxTestCountNow->Text = "" + global_DoubleRestTestCount;
			}
			else {
				global_DoubleRestTestCount = 0;
				iMESMainForm::global_iMESMainForm->tbxTestCountNow->Text = "" + global_DoubleRestTestCount;
				 
				iMESMainForm::global_iMESMainForm->btnTestFinish->Enabled = TRUE;
				iMESMainForm::global_iMESMainForm->Activate();
			}
		}

		return 0;
	}

	int GetResultFileFromFP(System::String^ tempPath) {
		System::String^ ResultFilePath = "";
		for (int i = 0;i < tempPath->Length - 1;i++) {
			if (tempPath[i] == '\\') {
				ResultFilePath += "\\";
			}
			ResultFilePath += tempPath[i];
		}
		ResultFilePath->Replace("\n", "");

		if (File::Exists(ResultFilePath)) {
			try {
				StreamReader^ srCFG = File::OpenText(ResultFilePath);
				System::String^ rStr;
				std::string tempStr;
				int tempCount = 0;
				System::String^ tempStrParent;
				TestedBoardInfo tempTestedBoard;

				while ((rStr = srCFG->ReadLine()) != nullptr) {
					if (rStr[0] == ';' || rStr[0] == '#' || rStr[0] == '[') {
						continue;
					}
					else {
						tempStrParent = rStr->Substring(0, rStr->IndexOf('='));
						tempStr = msclr::interop::marshal_as<std::string>(rStr->Substring(rStr->IndexOf('=') + 1, rStr->Length - rStr->IndexOf('=') - 1));
						if (tempStrParent == "Test count") {
							convertFromString(tempCount, tempStr);
							tempTestedBoard.TestUnitCount = tempCount;
						}
						else if (tempStrParent == "NG count") {
							convertFromString(tempCount, tempStr);
							tempTestedBoard.BadUnitCount = tempCount;
						}
						else if (tempStrParent == "Soft Landing") {
							tempTestedBoard.SoftLanding = tempStr;
						}
						else if (tempStrParent == "Pressure small") {
							tempTestedBoard.PressureSmall = tempStr;
						}
						else if (tempStrParent == "Barcode") {
							tempTestedBoard.BoardBarCode = tempStr;
						}
						else if (tempStrParent == "Speed") {
							tempTestedBoard.TestingSpeed = tempStr;
						}
						else if (tempStrParent == "Height") {
							tempTestedBoard.ArmHeight = tempStr;
						}
					}
				}

				tempTestedBoard.GoodUnitCount = tempTestedBoard.TestUnitCount - tempTestedBoard.BadUnitCount;
				NewTestedBoardFinish(tempTestedBoard);

				srCFG->Close();
				delete srCFG;
				delete rStr;
				delete tempStrParent;
			}
			catch (Exception^ e) {
				throw gcnew Exception(e->Message + e->StackTrace);
				return -1;
			}
		}
		else {
			OutPutIniFileErrorMessageBoxControl("Error got testing result!\r\nMissing file" + ResultFilePath);
		}

		delete ResultFilePath;
		return 0;
	}

	//flaw file
	int SendFlawFileFinish() {
		System::Collections::Generic::List<SccService::item^>^ tempListItem = gcnew System::Collections::Generic::List<SccService::item^>();
		System::String^ tempString = "";
		SccService::item^ TempItem = gcnew item();
		TempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1002";
		TempItem->tagValue = "ET";
		TempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");

		tempListItem->Add(TempItem);
		tempString += TempItem->tagValue + " ";

		for (int i = 0; i < global_TestedBoards.size(); i++) {
			if (global_TestedBoards[i].BadUnitCount > 0) {
				TempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1001";
				TempItem->tagValue = gcnew System::String(global_TestedBoards[i].BoardBarCode.c_str());
				TempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");

				tempListItem->Add(TempItem);
				tempString += TempItem->tagValue + " ";
			}
		}
		
		if (global_Flag_EnabelHeartbeat == 1 && global_Flag_HeartbeatWorking == 0) {
			HeartbeatMessageBoxControl();
			return -1;
		}
		WebService::SCCReturn =
			WebService::SCCWebService->FlawFileFinish(gcnew System::String(global_MachineID.c_str()), gcnew String(global_WipEntity.c_str()), tempListItem);
		ShowMessageToMESHistory("FlawFileFinish " + tempString + "\r\n");

		if (WebService::SCCReturn->errorCodek__BackingField == "0") {
			return 0;
		}
		else if (WebService::SCCReturn->errorCodek__BackingField == "-1") {
			return -1;
		}
		else if (WebService::SCCReturn->errorCodek__BackingField == "999" || WebService::SCCReturn->errorCodek__BackingField == "998") {
			return -1;
		}
		else {
			return -1;
		}
		return 0;
	}
	int UploadFileToServer(System::String^ URLFromServer, System::String^ FileName) {
		try {
			System::Net::WebClient^ TwebCilent = gcnew System::Net::WebClient();
			TwebCilent->UploadFile(URLFromServer, FileName);

			delete TwebCilent;
			return 0;
		}
		catch (System::Exception^ e) {
			return -1;
		}
	}

	void EmptyDirectory(System::String^ directory)
	{
		System::IO::DirectoryInfo^ tempDirectory = gcnew DirectoryInfo(directory);
		for each(System::IO::FileInfo^ file in tempDirectory->GetFiles()) file->Delete();
		for each(System::IO::DirectoryInfo^ subDirectory in tempDirectory->GetDirectories()) subDirectory->Delete(true);
	}
}