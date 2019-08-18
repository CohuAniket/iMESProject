#pragma once
#define _WINSOCKAPI_
#include <windows.h>
#include <iostream>
#include <WinSock2.h>  
#include <WS2tcpip.h>  

#pragma comment(lib,"ws2_32.lib")

public ref class ParameterServerSocket {
static SOCKET clientSocket;
public: static bool isCreateSocket = false;
public: static bool isConnectSocket = false;
public: static bool isSendDataOK = false;
public: static bool isReceiveDataOK = false;

		// ��1��ini
		static bool initWinSockC()
		{
			WORD verision = MAKEWORD(2, 2);
			WSADATA lpData;
			int intEr = WSAStartup(verision, &lpData); // initialize
			if (intEr != 0)
			{
				return false;
			}
			return true;
		}

		// ��2��create
		static bool createSocketC()
		{
			// create listen socket  
			clientSocket = socket(AF_INET, SOCK_STREAM, 0);
			if (clientSocket == INVALID_SOCKET)
			{
				return false;
			}
			return true;
		}

		// ��3��connect
		static bool connectSocketC(const std::string ip, const unsigned short port)
		{
			// address
			sockaddr_in hostAddr;
			hostAddr.sin_family = AF_INET;
			hostAddr.sin_port = htons(port);//ת���������ֽ���  
											//hostAddr.sin_addr.S_un.S_addr = inet_addr(SERVERIP);//ת���������ֽ���  
											//cout << "net IP:" << hostAddr.sin_addr.S_un.S_addr << endl;  
											/*
											inet_addr()�汾̫�ͣ�������ʹ��inet_pton(Э���壬�ַ���IP��ַ��voidĿ��in_addr*)
											ͷ�ļ���WS2tcpip.h
											*/
			in_addr addr;
			inet_pton(AF_INET, ip.c_str(), (void*)&addr);
			hostAddr.sin_addr = addr;

			// connect
			int err = connect(clientSocket, (sockaddr*)&hostAddr, sizeof(sockaddr));
			if (err == INVALID_SOCKET)
			{
				return false;
			}
			return true;
		}

		// ��4��send
		static bool sendDataC(const std::string &data)
		{
			int err = send(clientSocket, data.c_str(), data.size(), 0);
			if (err == SOCKET_ERROR)
			{
				return false;
			}
			return true;
		}

		// ��5��receive
		static bool receiveDataC(std::string &data)
		{
			// ͨ���ѽ������ӵ��׽��֣��������� �趨����1024�ֽ�
			char buf[1024] = "\0";
			// flags������ʽ��0�������ݣ�MSG_PEEDϵͳ�����������ݸ��Ƶ����ṩ�Ľ��ջ������ڣ�ϵͳ����������δɾ����MSG_OOB����������ݣ�ͨ���ò���0���ɣ�
			int buflen = recv(clientSocket, buf, 1024, 0);
			if (buflen == SOCKET_ERROR)
			{
				return false;
			}
			// һ����������ʾ��������
			data = std::string(buf);
			return true;
		}

public:
	static bool IfConnected() {
	}

public:
	/*ParameterServerSocket(std::string serverIp, int serverPort) {
		if (initWinSockC()) {
			if (createSocketC()) {
				isCreateSocket = true;
				if (connectSocketC(serverIp, serverPort)) {
					isConnectSocket = true;
				}
				else {
					isConnectSocket = false;
				}
			}
			else {
				isCreateSocket = false;
			}
		}
	}*/

	/*String^ GetLastServerResponseMessage() {
		String ^ tempStr;
		std::string temp = "";
		receiveDataC(temp);
		tempStr = gcnew String(temp.c_str());
		return tempStr;
	}*/
public:
	/*void Connect() {
	if (clientSocket.c)
	}*/
};