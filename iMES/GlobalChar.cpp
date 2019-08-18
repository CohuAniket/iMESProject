#include <msclr/marshal_cppstd.h>
#include <vector>
#include "IngredientsLabel.h"
#include "TestedBoardInfo.h"

//Chinese English Version, 0: English, 1: Chinese
int global_Flag_ChineseEnglishVersion = 0;

//Parameter Server Command
int global_Flag_CommandNextTest = -1;

//FlawFile Path
std::string global_FlawFileZipDescriptionFilePath = "INI\\[Content_Types].xml";
std::string global_FlawFileServerPath = "";
std::string global_OriginFlawFileLocalPath = "";
std::string global_FlawFileTestPlayerPath = "";

//Machine Status
std::string global_MachineStatusFileDirectory = "MachineStatus\\MachineStatus.ini";

//Testing Parameter
std::vector<TestedBoardInfo> global_TestedBoards;
////scan board
std::string global_BarCode;
//if testing
int global_Flag_Testing = 0; //3 third testing; 2 second testing; 1 first testing; 0 not testing
//reset
int global_Flag_Reset = 0; //1 reset is clicked

//Flaw File
int global_Flag_FlawFileMode = -1;

//AGV
int global_Flag_CallAgv = 0;
int global_ShowLoadAHour = 0;
int global_ShowLoadAMinite = 0;
int global_ShowLoadASecond = 0;
int global_ShowLoadBHour = 0;
int global_ShowLoadBMinite = 0;
int global_ShowLoadBSecond = 0;

//Login
int global_Flag_IfLogin = 0;
//Employee
std::string global_EmployeeID;
std::string global_EmployeePassword;
//Access Level
int global_Flag_AccessLevel = 2;//0-Operator; 1->Engineer; 2->Admin

//iMESMode
int global_Flag_iMESMode = 1; //1 on; 0 off

//ini file
std::string global_EXEBasicDirectory = "";
std::string global_INIFileDirectory = "INI\\iMESSetup.ini";
std::string global_INIFileVersion;


//ERROR
//alarm
int global_Flag_AlarmMessageBox = 0;
//Wip Entity
int global_Flag_WipEntityMessageBox = 0;
//Output File
int global_Flag_OutputFileMessageBox = 0;
//INI File
int global_Flag_INIFileMessageBox = 0;

//parameters in iMES Setup
//Basic
std::string global_MachineID;
std::string global_iMESURL;
std::string global_TestProgramMainDirectroy;
std::string global_TransportCartAID;
std::string global_TransportCartBID;
int global_AGVButtonAging = 60;
int global_CommunicationTimeout = 10;
int global_Flag_SaveOriginFlawFile = 1;
int global_Flag_SaveChangedFlawFile = 1;
//HeartBeat
int global_Flag_HeartbeatWorking = 0;
int global_Flag_HeartbeatMessageBox = 0;
int global_Flag_EnabelHeartbeat;//1 on; 0 off
std::string global_HeartbeatContent;
std::string global_HeartbeatServerURL;
std::string global_HeartbeatPort;
int global_HeartbeatFrequency;
std::string global_HeartbeatEndWord = "[E]\n\r";
//ingredients
std::vector<IngredientsLabel> global_IngredientsLabel;
std::string global_GetIngredientsTime;
std::string global_TestPlayerIngredientsPath;
int global_Flag_UseLocalIngredients = 0;
//ingredients detail
std::string global_SerialNumber;
std::string global_JobID;
std::string global_WipEntity;
std::string global_StripCount;
std::string global_Continuity;
std::string global_Insulation;
std::string global_TestProgramWholeDirectory;
int global_DoubleAllTestCount = 90;
int global_DoubleAllowNGCount;
//other need
int global_DoubleRestTestCount = 90;

//form window
int global_FormWindowHeightOnline = 283;
int global_FormWindowHeightOffline = 404;

