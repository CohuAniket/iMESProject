#pragma once
#include <sstream>
#include <msclr\marshal_cppstd.h>
#include "WebService.h"
#include "TestedBoardInfo.h"

using namespace SccService;

template <class T>
void convertFromString(T &, const std::string &);

template <class T>
void convertFromString(T &value, const std::string &s) {
	std::stringstream ss(s);
	ss >> value;
}

//all define in basic.cpp
namespace iMES {
	void ShowMessageToMESHistory(System::String^ strSendMessage);
	void ShowMessageToMESHistory(System::String^ strSendMessage, bool NoService);

	//alarm
	int SendAlarmMessage(System::String^ alarmMessageFromTestPlayer);
	void AlarmMessageBoxControl(System::String^ ErrorShowing);

	//all for initial or disable buttons and parameters
	void AllParameterInitial();
	void AllGlobalFileDirectoryInitial();
	void AllInterfaceShowingForOldWipEntityInitial();
	void AllButtonInitial();
	void AllButtonDisabled();
	void NewLoginAccessLevelButtonInitial();
	void EnableTheMainIMESInterface();

	//heartbeat
	void HeartbeatMessageBoxControl();
	void HeartbeatInitialize();
	void HeartbeatSendInformation();


	//in Basic.cpp
	void ReadINIFile();
	void INIFileErrorMessageBoxControl(System::String^ ErrorShowing);

	//Read login ini file from Test Player, 0 success, -1 fail
	int ReadLoginFromTestPlayer(System::String^ LoginFilePath);

	//Machine status
	void ReadMachineStatusFile();
	void WriteMachineStatusFile(int tempChangeStatus);
	int CheckTheHighestStatus();
	void SendMachineStatusToServer();
	void MachineStatusChange(int tempChangeStatusNumber, int ChangetoStatus);

	//Downloade
	int DownloadFileFromServer(System::String^ URLFromServer, System::String^ FileName);
	//Zip/Unzip
	int PackageFolder(System::String^ folderName, System::String^ compressedFileName, bool overrideExisting);
	int PackageFile(System::String^ fileName, System::String^ compressedFileName, bool overrideExisting);
	int UncompressFile(System::String^ folderName, System::String^ compressedFileName, bool overrideExisting);


	//Bar code scanning
	int GetBarCodeFromHandBarCodeScanningGun(System::String^ strBarCode);
	int GetFlawFileForFP(System::String^ strBarCode);
	int GetFlawFileSavedPathFromFP(System::String^ strPath);

	void WipEntityMessageBoxControl(System::String^ ErrorShowing);
	void OutPutIniFileErrorMessageBoxControl(System::String^ ErrorShowing);

	//Result of each board
	int NewTestedBoardFinish(TestedBoardInfo tempTestedBoard);
	//Result of each board
	int GetResultFileFromFP(System::String^ tempPath);

	//FlawFile
	int SendFlawFileFinish();
	int UploadFileToServer(System::String^ URLFromServer, System::String^ FileName);

	void EmptyDirectory(System::String^ directory);
}