#pragma once
//#include "ParameterServerSocket.h"


#include "iMESSetup.h"
#include "WebService.h"
#include "IngredientsLabel.h"
#include "TestedBoardInfo.h"
#include "Global_MachineStatus.h"
#include "LotDataUpload.h"


#include "PSSocket.h"
#include "WipEntityLogFileStreamWriter.h"

//form window
extern int global_FormWindowHeightOnline;
extern int global_FormWindowHeightOffline;

//Chinese English Version, 0: English, 1: Chinese
extern int global_Flag_ChineseEnglishVersion;

extern std::string global_EXEBasicDirectory;
//FlawFile Path
extern std::string global_FlawFileServerPath;
extern std::string global_FlawFileTestPlayerPath;

//Testing Parameter
extern std::vector<TestedBoardInfo> global_TestedBoards;
//scan board
extern std::string global_WipEntity;
extern std::string global_BarCode;
//if testing
extern int global_Flag_Testing;
//reset
extern int global_Flag_Reset;

//Flaw File
extern int global_Flag_FlawFileMode;


//parameters in iMES Setup
//Basic
extern std::string global_MachineID;
extern std::string global_iMESURL;
extern std::string global_TestProgramMainDirectroy;
extern std::string global_TransportCartAID;
extern std::string global_TransportCartBID;
extern int global_AGVButtonAging;
extern int global_CommunicationTimeout;
extern int global_Flag_SaveOriginFlawFile;
extern int global_Flag_SaveChangedFlawFile;
//HeartBeat
extern int global_Flag_HeartbeatMessageBox;
extern int global_Flag_HeartbeatWorking;
extern int global_Flag_EnabelHeartbeat;//1 on; 0 off
extern std::string global_HeartbeatContent;
extern std::string global_HeartbeatServerURL;
extern std::string global_HeartbeatPort;
extern int global_HeartbeatFrequency;
extern std::string global_HeartbeatEndWord;
//ingredients
extern std::string global_GetIngredientsTime;
extern std::vector<IngredientsLabel> global_IngredientsLabel;
extern int global_Flag_UseLocalIngredients;
extern std::string global_TestPlayerIngredientsPath;

////ingredients detail
extern std::string global_SerialNumber;
extern std::string global_JobID;
extern std::string global_StripCount;
extern std::string global_Continuity;
extern std::string global_Insulation;
extern std::string global_TestProgramWholeDirectory;
extern int global_DoubleAllTestCount;
extern int global_DoubleAllowNGCount;
////other need
extern int global_DoubleRestTestCount;


//AGV
extern int global_Flag_CallAgv;
extern int global_ShowLoadAHour;
extern int global_ShowLoadAMinite;
extern int global_ShowLoadASecond;
extern int global_ShowLoadBHour;
extern int global_ShowLoadBMinite;
extern int global_ShowLoadBSecond;


//iMESMode
extern int global_Flag_iMESMode;


//Login
extern int global_Flag_IfLogin;
//Employee
extern std::string global_EmployeeID;
extern std::string global_EmployeePassword;
//Access Level
extern int global_Flag_AccessLevel;



namespace iMES {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Threading;

	using namespace SccService;
	using namespace System::Runtime::Serialization;
	using namespace SccToolchain;


	/// <summary>
	/// Summary for TestInterface
	/// </summary>
	public ref class TestInterface : public System::Windows::Forms::Form
	{
	public:
		TestInterface(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TestInterface()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  lblEmployeeID;
	public: System::Windows::Forms::TextBox^  tbxEmployeeID;
	public: System::Windows::Forms::TextBox^  tbxBarCode;
	protected:

	protected:




	public: System::Windows::Forms::Label^  lblBarCode;
	public: System::Windows::Forms::TextBox^  tbxWipEntity;


	public: System::Windows::Forms::Label^  lblWipEntity;
	public: System::Windows::Forms::TextBox^  tbxJobID;


	public: System::Windows::Forms::Label^  lblJobID;
	public: System::Windows::Forms::Label^  lblTestCount;
	public: System::Windows::Forms::TextBox^  tbxTestCountNow;
	public: System::Windows::Forms::Label^  lblIngredients;





	public: System::Windows::Forms::Button^  btnlEmployeeLogoff;
	public: System::Windows::Forms::Button^  btnLoadA;
	public: System::Windows::Forms::Button^  btnLoadB;
	public: System::Windows::Forms::Button^  btnUnload;
	public: System::Windows::Forms::Button^  btnReturn;






	public: System::Windows::Forms::Label^  lblAGVAAging;
	public: System::Windows::Forms::Label^  lblAGVBAging;

	public: System::Windows::Forms::GroupBox^  grpbxMESHistory;






	public: System::Windows::Forms::Label^  lblHeartbeatShow;
	public: System::Windows::Forms::Button^  btnTestFinish;
	public: System::Windows::Forms::Button^  btnReset;





	public: System::Windows::Forms::Label^  lblTestCount2;
	public: System::Windows::Forms::TextBox^  tbxTestCountAll;


	public: System::Windows::Forms::Button^  btnModeSwitching;

	public: System::Windows::Forms::Label^  lblModeSwitching;

	public: System::Windows::Forms::Button^  btnCalliMESSetup;
	public: System::Windows::Forms::Timer^  TimerA;
	public: System::Windows::Forms::Timer^  TimerB;
	public: System::Windows::Forms::TextBox^  tbxMESHistory;

	public: System::Windows::Forms::Button^  btnChangeMachineStatus;
	public: System::Windows::Forms::DataGridView^  dtgrdvwIngredients;


































public: System::Windows::Forms::Timer^  TimerHeartbeat;

public:

public: System::Windows::Forms::Timer^  TimerParameterServer;

public: System::Windows::Forms::Label^  lblOfflineModeNGCount;


public: System::Windows::Forms::TextBox^  tbxOfflineModeAllowNGCount;
public: System::Windows::Forms::Label^  lblOfflineModeProgramDirectory;



public: System::Windows::Forms::TextBox^  tbxOfflineModeProgramDirectory;
public: System::Windows::Forms::Label^  lblOfflineModeJobID;




public: System::Windows::Forms::TextBox^  tbxOfflineModeJobID;
public: System::Windows::Forms::Label^  lblOfflineModeWipEntity;


public: System::Windows::Forms::TextBox^  tbxOfflineModeWipEntity;
public: System::Windows::Forms::Label^  lblOfflineModeTestCount;


public: System::Windows::Forms::TextBox^  tbxOfflineModeTestCount;

public: System::Windows::Forms::Button^  btnMESHistorySave;
public: System::Windows::Forms::Button^  btnMESHistoryClear;


public:


public: System::Windows::Forms::Label^  lblOfflineModeFlawFileDirectory;

public: System::Windows::Forms::TextBox^  tbxOfflineModeFlawFIleDirectory;

public: System::Windows::Forms::Button^  btnApplyChangedIngredients;

public: System::Windows::Forms::DataGridViewTextBoxColumn^  dtgrdvwclmnIngredientsName;
public:
public: System::Windows::Forms::DataGridViewTextBoxColumn^  dtgrdvwclmnIngredientsValue;
public: System::Windows::Forms::DataGridViewTextBoxColumn^  dtgrdvwclmnIngredientsLabel;

public:

public: System::Windows::Forms::Button^  btnChineseEnglish;


private: System::Windows::Forms::GroupBox^  grpbxOfflineMode;
private: System::Windows::Forms::GroupBox^  grpbxAGV;
public:
private: System::ComponentModel::IContainer^  components;
public:
public:

public:


public:
public:




public:
public:


public:


public:

public:














	public:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lblEmployeeID = (gcnew System::Windows::Forms::Label());
			this->tbxEmployeeID = (gcnew System::Windows::Forms::TextBox());
			this->tbxBarCode = (gcnew System::Windows::Forms::TextBox());
			this->lblBarCode = (gcnew System::Windows::Forms::Label());
			this->tbxWipEntity = (gcnew System::Windows::Forms::TextBox());
			this->lblWipEntity = (gcnew System::Windows::Forms::Label());
			this->tbxJobID = (gcnew System::Windows::Forms::TextBox());
			this->lblJobID = (gcnew System::Windows::Forms::Label());
			this->lblTestCount = (gcnew System::Windows::Forms::Label());
			this->tbxTestCountNow = (gcnew System::Windows::Forms::TextBox());
			this->lblIngredients = (gcnew System::Windows::Forms::Label());
			this->btnlEmployeeLogoff = (gcnew System::Windows::Forms::Button());
			this->btnLoadA = (gcnew System::Windows::Forms::Button());
			this->btnLoadB = (gcnew System::Windows::Forms::Button());
			this->btnUnload = (gcnew System::Windows::Forms::Button());
			this->btnReturn = (gcnew System::Windows::Forms::Button());
			this->lblAGVAAging = (gcnew System::Windows::Forms::Label());
			this->lblAGVBAging = (gcnew System::Windows::Forms::Label());
			this->grpbxMESHistory = (gcnew System::Windows::Forms::GroupBox());
			this->tbxMESHistory = (gcnew System::Windows::Forms::TextBox());
			this->lblHeartbeatShow = (gcnew System::Windows::Forms::Label());
			this->btnTestFinish = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->lblTestCount2 = (gcnew System::Windows::Forms::Label());
			this->tbxTestCountAll = (gcnew System::Windows::Forms::TextBox());
			this->btnModeSwitching = (gcnew System::Windows::Forms::Button());
			this->lblModeSwitching = (gcnew System::Windows::Forms::Label());
			this->btnCalliMESSetup = (gcnew System::Windows::Forms::Button());
			this->TimerA = (gcnew System::Windows::Forms::Timer(this->components));
			this->TimerB = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnChangeMachineStatus = (gcnew System::Windows::Forms::Button());
			this->dtgrdvwIngredients = (gcnew System::Windows::Forms::DataGridView());
			this->dtgrdvwclmnIngredientsName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dtgrdvwclmnIngredientsValue = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dtgrdvwclmnIngredientsLabel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TimerHeartbeat = (gcnew System::Windows::Forms::Timer(this->components));
			this->TimerParameterServer = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblOfflineModeNGCount = (gcnew System::Windows::Forms::Label());
			this->tbxOfflineModeAllowNGCount = (gcnew System::Windows::Forms::TextBox());
			this->lblOfflineModeProgramDirectory = (gcnew System::Windows::Forms::Label());
			this->tbxOfflineModeProgramDirectory = (gcnew System::Windows::Forms::TextBox());
			this->lblOfflineModeJobID = (gcnew System::Windows::Forms::Label());
			this->tbxOfflineModeJobID = (gcnew System::Windows::Forms::TextBox());
			this->lblOfflineModeWipEntity = (gcnew System::Windows::Forms::Label());
			this->tbxOfflineModeWipEntity = (gcnew System::Windows::Forms::TextBox());
			this->lblOfflineModeTestCount = (gcnew System::Windows::Forms::Label());
			this->tbxOfflineModeTestCount = (gcnew System::Windows::Forms::TextBox());
			this->btnMESHistorySave = (gcnew System::Windows::Forms::Button());
			this->btnMESHistoryClear = (gcnew System::Windows::Forms::Button());
			this->lblOfflineModeFlawFileDirectory = (gcnew System::Windows::Forms::Label());
			this->tbxOfflineModeFlawFIleDirectory = (gcnew System::Windows::Forms::TextBox());
			this->btnApplyChangedIngredients = (gcnew System::Windows::Forms::Button());
			this->btnChineseEnglish = (gcnew System::Windows::Forms::Button());
			this->grpbxOfflineMode = (gcnew System::Windows::Forms::GroupBox());
			this->grpbxAGV = (gcnew System::Windows::Forms::GroupBox());
			this->grpbxMESHistory->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgrdvwIngredients))->BeginInit();
			this->grpbxOfflineMode->SuspendLayout();
			this->grpbxAGV->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblEmployeeID
			// 
			this->lblEmployeeID->AutoSize = true;
			this->lblEmployeeID->Location = System::Drawing::Point(3, 44);
			this->lblEmployeeID->Name = L"lblEmployeeID";
			this->lblEmployeeID->Size = System::Drawing::Size(73, 13);
			this->lblEmployeeID->TabIndex = 1;
			this->lblEmployeeID->Text = L"Employee ID: ";
			// 
			// tbxEmployeeID
			// 
			this->tbxEmployeeID->BackColor = System::Drawing::SystemColors::ControlDark;
			this->tbxEmployeeID->Location = System::Drawing::Point(99, 41);
			this->tbxEmployeeID->Name = L"tbxEmployeeID";
			this->tbxEmployeeID->ReadOnly = true;
			this->tbxEmployeeID->Size = System::Drawing::Size(162, 20);
			this->tbxEmployeeID->TabIndex = 3;
			// 
			// tbxBarCode
			// 
			this->tbxBarCode->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->tbxBarCode->Location = System::Drawing::Point(99, 74);
			this->tbxBarCode->Name = L"tbxBarCode";
			this->tbxBarCode->ReadOnly = true;
			this->tbxBarCode->Size = System::Drawing::Size(162, 20);
			this->tbxBarCode->TabIndex = 5;
			// 
			// lblBarCode
			// 
			this->lblBarCode->Location = System::Drawing::Point(3, 77);
			this->lblBarCode->Name = L"lblBarCode";
			this->lblBarCode->Size = System::Drawing::Size(61, 17);
			this->lblBarCode->TabIndex = 4;
			this->lblBarCode->Text = L"Bar Code: ";
			// 
			// tbxWipEntity
			// 
			this->tbxWipEntity->BackColor = System::Drawing::SystemColors::ControlDark;
			this->tbxWipEntity->Location = System::Drawing::Point(99, 107);
			this->tbxWipEntity->Name = L"tbxWipEntity";
			this->tbxWipEntity->ReadOnly = true;
			this->tbxWipEntity->Size = System::Drawing::Size(162, 20);
			this->tbxWipEntity->TabIndex = 7;
			// 
			// lblWipEntity
			// 
			this->lblWipEntity->AutoSize = true;
			this->lblWipEntity->Location = System::Drawing::Point(3, 110);
			this->lblWipEntity->Name = L"lblWipEntity";
			this->lblWipEntity->Size = System::Drawing::Size(61, 13);
			this->lblWipEntity->TabIndex = 6;
			this->lblWipEntity->Text = L"Wip Entity: ";
			// 
			// tbxJobID
			// 
			this->tbxJobID->BackColor = System::Drawing::SystemColors::ControlDark;
			this->tbxJobID->Location = System::Drawing::Point(99, 140);
			this->tbxJobID->Name = L"tbxJobID";
			this->tbxJobID->ReadOnly = true;
			this->tbxJobID->Size = System::Drawing::Size(162, 20);
			this->tbxJobID->TabIndex = 9;
			// 
			// lblJobID
			// 
			this->lblJobID->AutoSize = true;
			this->lblJobID->Location = System::Drawing::Point(3, 143);
			this->lblJobID->Name = L"lblJobID";
			this->lblJobID->Size = System::Drawing::Size(44, 13);
			this->lblJobID->TabIndex = 8;
			this->lblJobID->Text = L"Job ID: ";
			// 
			// lblTestCount
			// 
			this->lblTestCount->AutoSize = true;
			this->lblTestCount->Location = System::Drawing::Point(3, 199);
			this->lblTestCount->Name = L"lblTestCount";
			this->lblTestCount->Size = System::Drawing::Size(65, 13);
			this->lblTestCount->TabIndex = 10;
			this->lblTestCount->Text = L"Test Count: ";
			// 
			// tbxTestCountNow
			// 
			this->tbxTestCountNow->BackColor = System::Drawing::Color::Peru;
			this->tbxTestCountNow->Font = (gcnew System::Drawing::Font(L"Times New Roman", 35, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->tbxTestCountNow->Location = System::Drawing::Point(99, 179);
			this->tbxTestCountNow->Multiline = true;
			this->tbxTestCountNow->Name = L"tbxTestCountNow";
			this->tbxTestCountNow->Size = System::Drawing::Size(143, 55);
			this->tbxTestCountNow->TabIndex = 11;
			this->tbxTestCountNow->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lblIngredients
			// 
			this->lblIngredients->AutoSize = true;
			this->lblIngredients->Location = System::Drawing::Point(345, 8);
			this->lblIngredients->Name = L"lblIngredients";
			this->lblIngredients->Size = System::Drawing::Size(65, 13);
			this->lblIngredients->TabIndex = 12;
			this->lblIngredients->Text = L"Ingredients: ";
			// 
			// btnlEmployeeLogoff
			// 
			this->btnlEmployeeLogoff->Location = System::Drawing::Point(277, 39);
			this->btnlEmployeeLogoff->Name = L"btnlEmployeeLogoff";
			this->btnlEmployeeLogoff->Size = System::Drawing::Size(51, 22);
			this->btnlEmployeeLogoff->TabIndex = 13;
			this->btnlEmployeeLogoff->Text = L"Logoff";
			this->btnlEmployeeLogoff->UseVisualStyleBackColor = true;
			this->btnlEmployeeLogoff->Visible = false;
			this->btnlEmployeeLogoff->Click += gcnew System::EventHandler(this, &TestInterface::btnlEmployeeLogoff_Click);
			// 
			// btnLoadA
			// 
			this->btnLoadA->Location = System::Drawing::Point(20, 14);
			this->btnLoadA->Name = L"btnLoadA";
			this->btnLoadA->Size = System::Drawing::Size(81, 35);
			this->btnLoadA->TabIndex = 15;
			this->btnLoadA->Text = L"Load A";
			this->btnLoadA->UseVisualStyleBackColor = true;
			this->btnLoadA->Click += gcnew System::EventHandler(this, &TestInterface::btnLoadA_Click);
			// 
			// btnLoadB
			// 
			this->btnLoadB->Location = System::Drawing::Point(129, 14);
			this->btnLoadB->Name = L"btnLoadB";
			this->btnLoadB->Size = System::Drawing::Size(81, 35);
			this->btnLoadB->TabIndex = 16;
			this->btnLoadB->Text = L"Load B";
			this->btnLoadB->UseVisualStyleBackColor = true;
			this->btnLoadB->Click += gcnew System::EventHandler(this, &TestInterface::btnLoadB_Click);
			// 
			// btnUnload
			// 
			this->btnUnload->Location = System::Drawing::Point(20, 79);
			this->btnUnload->Name = L"btnUnload";
			this->btnUnload->Size = System::Drawing::Size(190, 35);
			this->btnUnload->TabIndex = 17;
			this->btnUnload->Text = L"Unload";
			this->btnUnload->UseVisualStyleBackColor = true;
			this->btnUnload->Click += gcnew System::EventHandler(this, &TestInterface::btnUnload_Click);
			// 
			// btnReturn
			// 
			this->btnReturn->Location = System::Drawing::Point(20, 125);
			this->btnReturn->Name = L"btnReturn";
			this->btnReturn->Size = System::Drawing::Size(190, 35);
			this->btnReturn->TabIndex = 18;
			this->btnReturn->Text = L"Return";
			this->btnReturn->UseVisualStyleBackColor = true;
			this->btnReturn->Click += gcnew System::EventHandler(this, &TestInterface::btnReturn_Click);
			// 
			// lblAGVAAging
			// 
			this->lblAGVAAging->AutoSize = true;
			this->lblAGVAAging->Location = System::Drawing::Point(28, 55);
			this->lblAGVAAging->Name = L"lblAGVAAging";
			this->lblAGVAAging->Size = System::Drawing::Size(67, 13);
			this->lblAGVAAging->TabIndex = 19;
			this->lblAGVAAging->Text = L"00：00：00";
			// 
			// lblAGVBAging
			// 
			this->lblAGVBAging->AutoSize = true;
			this->lblAGVBAging->Location = System::Drawing::Point(137, 55);
			this->lblAGVBAging->Name = L"lblAGVBAging";
			this->lblAGVBAging->Size = System::Drawing::Size(67, 13);
			this->lblAGVBAging->TabIndex = 20;
			this->lblAGVBAging->Text = L"00：00：00";
			// 
			// grpbxMESHistory
			// 
			this->grpbxMESHistory->Controls->Add(this->tbxMESHistory);
			this->grpbxMESHistory->Location = System::Drawing::Point(843, 7);
			this->grpbxMESHistory->Name = L"grpbxMESHistory";
			this->grpbxMESHistory->Size = System::Drawing::Size(308, 216);
			this->grpbxMESHistory->TabIndex = 21;
			this->grpbxMESHistory->TabStop = false;
			this->grpbxMESHistory->Text = L"MES History";
			// 
			// tbxMESHistory
			// 
			this->tbxMESHistory->BackColor = System::Drawing::Color::Peru;
			this->tbxMESHistory->Location = System::Drawing::Point(6, 19);
			this->tbxMESHistory->Multiline = true;
			this->tbxMESHistory->Name = L"tbxMESHistory";
			this->tbxMESHistory->ReadOnly = true;
			this->tbxMESHistory->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tbxMESHistory->Size = System::Drawing::Size(296, 191);
			this->tbxMESHistory->TabIndex = 0;
			// 
			// lblHeartbeatShow
			// 
			this->lblHeartbeatShow->BackColor = System::Drawing::SystemColors::ControlDark;
			this->lblHeartbeatShow->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lblHeartbeatShow->Location = System::Drawing::Point(249, 7);
			this->lblHeartbeatShow->Name = L"lblHeartbeatShow";
			this->lblHeartbeatShow->Size = System::Drawing::Size(79, 21);
			this->lblHeartbeatShow->TabIndex = 22;
			this->lblHeartbeatShow->Text = L"S";
			// 
			// btnTestFinish
			// 
			this->btnTestFinish->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btnTestFinish->Location = System::Drawing::Point(725, 202);
			this->btnTestFinish->Name = L"btnTestFinish";
			this->btnTestFinish->Size = System::Drawing::Size(110, 35);
			this->btnTestFinish->TabIndex = 23;
			this->btnTestFinish->Text = L"Test Finish";
			this->btnTestFinish->UseVisualStyleBackColor = false;
			this->btnTestFinish->Click += gcnew System::EventHandler(this, &TestInterface::btnTestFinish_Click);
			// 
			// btnReset
			// 
			this->btnReset->Location = System::Drawing::Point(777, 179);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(45, 20);
			this->btnReset->TabIndex = 24;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &TestInterface::btnReset_Click);
			// 
			// lblTestCount2
			// 
			this->lblTestCount2->AutoSize = true;
			this->lblTestCount2->Location = System::Drawing::Point(244, 199);
			this->lblTestCount2->Name = L"lblTestCount2";
			this->lblTestCount2->Size = System::Drawing::Size(34, 13);
			this->lblTestCount2->TabIndex = 26;
			this->lblTestCount2->Text = L"out of";
			// 
			// tbxTestCountAll
			// 
			this->tbxTestCountAll->BackColor = System::Drawing::SystemColors::ControlDark;
			this->tbxTestCountAll->Location = System::Drawing::Point(283, 196);
			this->tbxTestCountAll->Name = L"tbxTestCountAll";
			this->tbxTestCountAll->ReadOnly = true;
			this->tbxTestCountAll->Size = System::Drawing::Size(46, 20);
			this->tbxTestCountAll->TabIndex = 27;
			// 
			// btnModeSwitching
			// 
			this->btnModeSwitching->FlatAppearance->BorderColor = System::Drawing::Color::Aqua;
			this->btnModeSwitching->Location = System::Drawing::Point(99, 8);
			this->btnModeSwitching->Name = L"btnModeSwitching";
			this->btnModeSwitching->Size = System::Drawing::Size(74, 22);
			this->btnModeSwitching->TabIndex = 30;
			this->btnModeSwitching->Text = L"Online";
			this->btnModeSwitching->UseVisualStyleBackColor = true;
			this->btnModeSwitching->Click += gcnew System::EventHandler(this, &TestInterface::btnModeSwitching_Click);
			// 
			// lblModeSwitching
			// 
			this->lblModeSwitching->AutoSize = true;
			this->lblModeSwitching->Location = System::Drawing::Point(3, 13);
			this->lblModeSwitching->Name = L"lblModeSwitching";
			this->lblModeSwitching->Size = System::Drawing::Size(89, 13);
			this->lblModeSwitching->TabIndex = 29;
			this->lblModeSwitching->Text = L"Mode Switching: ";
			// 
			// btnCalliMESSetup
			// 
			this->btnCalliMESSetup->Location = System::Drawing::Point(348, 205);
			this->btnCalliMESSetup->Name = L"btnCalliMESSetup";
			this->btnCalliMESSetup->Size = System::Drawing::Size(96, 29);
			this->btnCalliMESSetup->TabIndex = 31;
			this->btnCalliMESSetup->Text = L"iMES Setup";
			this->btnCalliMESSetup->UseVisualStyleBackColor = true;
			this->btnCalliMESSetup->Click += gcnew System::EventHandler(this, &TestInterface::btnCalliMESSetup_Click);
			// 
			// TimerA
			// 
			this->TimerA->Interval = 1000;
			this->TimerA->Tick += gcnew System::EventHandler(this, &TestInterface::TimerA_Tick);
			// 
			// TimerB
			// 
			this->TimerB->Interval = 1000;
			this->TimerB->Tick += gcnew System::EventHandler(this, &TestInterface::TimerB_Tick);
			// 
			// btnChangeMachineStatus
			// 
			this->btnChangeMachineStatus->Location = System::Drawing::Point(478, 205);
			this->btnChangeMachineStatus->Name = L"btnChangeMachineStatus";
			this->btnChangeMachineStatus->Size = System::Drawing::Size(130, 29);
			this->btnChangeMachineStatus->TabIndex = 33;
			this->btnChangeMachineStatus->Text = L"Change Machine Status";
			this->btnChangeMachineStatus->UseVisualStyleBackColor = true;
			this->btnChangeMachineStatus->Click += gcnew System::EventHandler(this, &TestInterface::btnChangeMachineStatus_Click);
			// 
			// dtgrdvwIngredients
			// 
			this->dtgrdvwIngredients->AllowUserToDeleteRows = false;
			this->dtgrdvwIngredients->AllowUserToResizeColumns = false;
			this->dtgrdvwIngredients->AllowUserToResizeRows = false;
			this->dtgrdvwIngredients->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtgrdvwIngredients->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dtgrdvwclmnIngredientsName,
					this->dtgrdvwclmnIngredientsValue, this->dtgrdvwclmnIngredientsLabel
			});
			this->dtgrdvwIngredients->Location = System::Drawing::Point(348, 34);
			this->dtgrdvwIngredients->Name = L"dtgrdvwIngredients";
			this->dtgrdvwIngredients->ReadOnly = true;
			this->dtgrdvwIngredients->RowHeadersVisible = false;
			this->dtgrdvwIngredients->Size = System::Drawing::Size(260, 160);
			this->dtgrdvwIngredients->TabIndex = 34;
			// 
			// dtgrdvwclmnIngredientsName
			// 
			this->dtgrdvwclmnIngredientsName->HeaderText = L"Ingredients Name";
			this->dtgrdvwclmnIngredientsName->Name = L"dtgrdvwclmnIngredientsName";
			this->dtgrdvwclmnIngredientsName->ReadOnly = true;
			// 
			// dtgrdvwclmnIngredientsValue
			// 
			this->dtgrdvwclmnIngredientsValue->HeaderText = L"Ingredients Value";
			this->dtgrdvwclmnIngredientsValue->Name = L"dtgrdvwclmnIngredientsValue";
			this->dtgrdvwclmnIngredientsValue->ReadOnly = true;
			this->dtgrdvwclmnIngredientsValue->Width = 155;
			// 
			// dtgrdvwclmnIngredientsLabel
			// 
			this->dtgrdvwclmnIngredientsLabel->HeaderText = L"Label";
			this->dtgrdvwclmnIngredientsLabel->Name = L"dtgrdvwclmnIngredientsLabel";
			this->dtgrdvwclmnIngredientsLabel->ReadOnly = true;
			this->dtgrdvwclmnIngredientsLabel->Visible = false;
			// 
			// TimerHeartbeat
			// 
			this->TimerHeartbeat->Interval = 10000;
			this->TimerHeartbeat->Tick += gcnew System::EventHandler(this, &TestInterface::TimerHeartbeat_Tick);
			// 
			// TimerParameterServer
			// 
			this->TimerParameterServer->Interval = 200;
			this->TimerParameterServer->Tick += gcnew System::EventHandler(this, &TestInterface::TimerParameterServer_Tick);
			// 
			// lblOfflineModeNGCount
			// 
			this->lblOfflineModeNGCount->AutoSize = true;
			this->lblOfflineModeNGCount->Location = System::Drawing::Point(583, 56);
			this->lblOfflineModeNGCount->Name = L"lblOfflineModeNGCount";
			this->lblOfflineModeNGCount->Size = System::Drawing::Size(57, 13);
			this->lblOfflineModeNGCount->TabIndex = 47;
			this->lblOfflineModeNGCount->Text = L"NG Count:";
			// 
			// tbxOfflineModeAllowNGCount
			// 
			this->tbxOfflineModeAllowNGCount->Location = System::Drawing::Point(692, 53);
			this->tbxOfflineModeAllowNGCount->Name = L"tbxOfflineModeAllowNGCount";
			this->tbxOfflineModeAllowNGCount->Size = System::Drawing::Size(137, 20);
			this->tbxOfflineModeAllowNGCount->TabIndex = 46;
			// 
			// lblOfflineModeProgramDirectory
			// 
			this->lblOfflineModeProgramDirectory->AutoSize = true;
			this->lblOfflineModeProgramDirectory->Location = System::Drawing::Point(11, 85);
			this->lblOfflineModeProgramDirectory->Name = L"lblOfflineModeProgramDirectory";
			this->lblOfflineModeProgramDirectory->Size = System::Drawing::Size(97, 13);
			this->lblOfflineModeProgramDirectory->TabIndex = 45;
			this->lblOfflineModeProgramDirectory->Text = L"Program Directory: ";
			// 
			// tbxOfflineModeProgramDirectory
			// 
			this->tbxOfflineModeProgramDirectory->Location = System::Drawing::Point(120, 82);
			this->tbxOfflineModeProgramDirectory->Name = L"tbxOfflineModeProgramDirectory";
			this->tbxOfflineModeProgramDirectory->Size = System::Drawing::Size(438, 20);
			this->tbxOfflineModeProgramDirectory->TabIndex = 44;
			// 
			// lblOfflineModeJobID
			// 
			this->lblOfflineModeJobID->AutoSize = true;
			this->lblOfflineModeJobID->Location = System::Drawing::Point(11, 27);
			this->lblOfflineModeJobID->Name = L"lblOfflineModeJobID";
			this->lblOfflineModeJobID->Size = System::Drawing::Size(41, 13);
			this->lblOfflineModeJobID->TabIndex = 53;
			this->lblOfflineModeJobID->Text = L"Job ID:";
			// 
			// tbxOfflineModeJobID
			// 
			this->tbxOfflineModeJobID->Location = System::Drawing::Point(120, 24);
			this->tbxOfflineModeJobID->Name = L"tbxOfflineModeJobID";
			this->tbxOfflineModeJobID->Size = System::Drawing::Size(137, 20);
			this->tbxOfflineModeJobID->TabIndex = 52;
			// 
			// lblOfflineModeWipEntity
			// 
			this->lblOfflineModeWipEntity->AutoSize = true;
			this->lblOfflineModeWipEntity->Location = System::Drawing::Point(11, 56);
			this->lblOfflineModeWipEntity->Name = L"lblOfflineModeWipEntity";
			this->lblOfflineModeWipEntity->Size = System::Drawing::Size(58, 13);
			this->lblOfflineModeWipEntity->TabIndex = 55;
			this->lblOfflineModeWipEntity->Text = L"Wip Entity:";
			// 
			// tbxOfflineModeWipEntity
			// 
			this->tbxOfflineModeWipEntity->Location = System::Drawing::Point(120, 53);
			this->tbxOfflineModeWipEntity->Name = L"tbxOfflineModeWipEntity";
			this->tbxOfflineModeWipEntity->Size = System::Drawing::Size(137, 20);
			this->tbxOfflineModeWipEntity->TabIndex = 54;
			// 
			// lblOfflineModeTestCount
			// 
			this->lblOfflineModeTestCount->AutoSize = true;
			this->lblOfflineModeTestCount->Location = System::Drawing::Point(583, 27);
			this->lblOfflineModeTestCount->Name = L"lblOfflineModeTestCount";
			this->lblOfflineModeTestCount->Size = System::Drawing::Size(62, 13);
			this->lblOfflineModeTestCount->TabIndex = 57;
			this->lblOfflineModeTestCount->Text = L"Test Count:";
			// 
			// tbxOfflineModeTestCount
			// 
			this->tbxOfflineModeTestCount->Location = System::Drawing::Point(692, 24);
			this->tbxOfflineModeTestCount->Name = L"tbxOfflineModeTestCount";
			this->tbxOfflineModeTestCount->Size = System::Drawing::Size(137, 20);
			this->tbxOfflineModeTestCount->TabIndex = 56;
			// 
			// btnMESHistorySave
			// 
			this->btnMESHistorySave->Location = System::Drawing::Point(1092, 214);
			this->btnMESHistorySave->Name = L"btnMESHistorySave";
			this->btnMESHistorySave->Size = System::Drawing::Size(40, 20);
			this->btnMESHistorySave->TabIndex = 58;
			this->btnMESHistorySave->Text = L"Save";
			this->btnMESHistorySave->UseVisualStyleBackColor = true;
			this->btnMESHistorySave->Click += gcnew System::EventHandler(this, &TestInterface::btnMESHistorySave_Click);
			// 
			// btnMESHistoryClear
			// 
			this->btnMESHistoryClear->Location = System::Drawing::Point(1037, 214);
			this->btnMESHistoryClear->Name = L"btnMESHistoryClear";
			this->btnMESHistoryClear->Size = System::Drawing::Size(40, 20);
			this->btnMESHistoryClear->TabIndex = 59;
			this->btnMESHistoryClear->Text = L"Clear";
			this->btnMESHistoryClear->UseVisualStyleBackColor = true;
			this->btnMESHistoryClear->Click += gcnew System::EventHandler(this, &TestInterface::btnMESHistoryClear_Click);
			// 
			// lblOfflineModeFlawFileDirectory
			// 
			this->lblOfflineModeFlawFileDirectory->AutoSize = true;
			this->lblOfflineModeFlawFileDirectory->Location = System::Drawing::Point(583, 85);
			this->lblOfflineModeFlawFileDirectory->Name = L"lblOfflineModeFlawFileDirectory";
			this->lblOfflineModeFlawFileDirectory->Size = System::Drawing::Size(99, 13);
			this->lblOfflineModeFlawFileDirectory->TabIndex = 61;
			this->lblOfflineModeFlawFileDirectory->Text = L"Flaw File Directory: ";
			// 
			// tbxOfflineModeFlawFIleDirectory
			// 
			this->tbxOfflineModeFlawFIleDirectory->Location = System::Drawing::Point(692, 82);
			this->tbxOfflineModeFlawFIleDirectory->Name = L"tbxOfflineModeFlawFIleDirectory";
			this->tbxOfflineModeFlawFIleDirectory->Size = System::Drawing::Size(438, 20);
			this->tbxOfflineModeFlawFIleDirectory->TabIndex = 60;
			// 
			// btnApplyChangedIngredients
			// 
			this->btnApplyChangedIngredients->Location = System::Drawing::Point(565, 179);
			this->btnApplyChangedIngredients->Name = L"btnApplyChangedIngredients";
			this->btnApplyChangedIngredients->Size = System::Drawing::Size(43, 21);
			this->btnApplyChangedIngredients->TabIndex = 62;
			this->btnApplyChangedIngredients->Text = L"Apply";
			this->btnApplyChangedIngredients->UseVisualStyleBackColor = true;
			this->btnApplyChangedIngredients->Visible = false;
			this->btnApplyChangedIngredients->Click += gcnew System::EventHandler(this, &TestInterface::btnApplyChangedIngredients_Click);
			// 
			// btnChineseEnglish
			// 
			this->btnChineseEnglish->Location = System::Drawing::Point(544, 4);
			this->btnChineseEnglish->Name = L"btnChineseEnglish";
			this->btnChineseEnglish->Size = System::Drawing::Size(62, 21);
			this->btnChineseEnglish->TabIndex = 65;
			this->btnChineseEnglish->Text = L"Chinese";
			this->btnChineseEnglish->UseVisualStyleBackColor = true;
			this->btnChineseEnglish->Click += gcnew System::EventHandler(this, &TestInterface::btnChineseEnglish_Click);
			// 
			// grpbxOfflineMode
			// 
			this->grpbxOfflineMode->Controls->Add(this->tbxOfflineModeProgramDirectory);
			this->grpbxOfflineMode->Controls->Add(this->lblOfflineModeProgramDirectory);
			this->grpbxOfflineMode->Controls->Add(this->tbxOfflineModeJobID);
			this->grpbxOfflineMode->Controls->Add(this->lblOfflineModeJobID);
			this->grpbxOfflineMode->Controls->Add(this->tbxOfflineModeWipEntity);
			this->grpbxOfflineMode->Controls->Add(this->lblOfflineModeWipEntity);
			this->grpbxOfflineMode->Controls->Add(this->tbxOfflineModeTestCount);
			this->grpbxOfflineMode->Controls->Add(this->lblOfflineModeFlawFileDirectory);
			this->grpbxOfflineMode->Controls->Add(this->lblOfflineModeTestCount);
			this->grpbxOfflineMode->Controls->Add(this->tbxOfflineModeFlawFIleDirectory);
			this->grpbxOfflineMode->Controls->Add(this->tbxOfflineModeAllowNGCount);
			this->grpbxOfflineMode->Controls->Add(this->lblOfflineModeNGCount);
			this->grpbxOfflineMode->Location = System::Drawing::Point(6, 250);
			this->grpbxOfflineMode->Name = L"grpbxOfflineMode";
			this->grpbxOfflineMode->Size = System::Drawing::Size(1145, 110);
			this->grpbxOfflineMode->TabIndex = 68;
			this->grpbxOfflineMode->TabStop = false;
			this->grpbxOfflineMode->Text = L"Offline Mode";
			// 
			// grpbxAGV
			// 
			this->grpbxAGV->Controls->Add(this->btnLoadA);
			this->grpbxAGV->Controls->Add(this->btnLoadB);
			this->grpbxAGV->Controls->Add(this->btnUnload);
			this->grpbxAGV->Controls->Add(this->btnReturn);
			this->grpbxAGV->Controls->Add(this->lblAGVAAging);
			this->grpbxAGV->Controls->Add(this->lblAGVBAging);
			this->grpbxAGV->Location = System::Drawing::Point(612, 7);
			this->grpbxAGV->Name = L"grpbxAGV";
			this->grpbxAGV->Size = System::Drawing::Size(227, 168);
			this->grpbxAGV->TabIndex = 69;
			this->grpbxAGV->TabStop = false;
			this->grpbxAGV->Text = L"AGV";
			// 
			// TestInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1167, 367);
			this->Controls->Add(this->grpbxAGV);
			this->Controls->Add(this->grpbxOfflineMode);
			this->Controls->Add(this->btnChineseEnglish);
			this->Controls->Add(this->btnApplyChangedIngredients);
			this->Controls->Add(this->btnMESHistorySave);
			this->Controls->Add(this->btnMESHistoryClear);
			this->Controls->Add(this->dtgrdvwIngredients);
			this->Controls->Add(this->btnChangeMachineStatus);
			this->Controls->Add(this->btnCalliMESSetup);
			this->Controls->Add(this->btnModeSwitching);
			this->Controls->Add(this->lblModeSwitching);
			this->Controls->Add(this->tbxTestCountAll);
			this->Controls->Add(this->lblTestCount2);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->btnTestFinish);
			this->Controls->Add(this->lblHeartbeatShow);
			this->Controls->Add(this->grpbxMESHistory);
			this->Controls->Add(this->btnlEmployeeLogoff);
			this->Controls->Add(this->lblIngredients);
			this->Controls->Add(this->tbxTestCountNow);
			this->Controls->Add(this->lblTestCount);
			this->Controls->Add(this->tbxJobID);
			this->Controls->Add(this->lblJobID);
			this->Controls->Add(this->tbxWipEntity);
			this->Controls->Add(this->lblWipEntity);
			this->Controls->Add(this->tbxBarCode);
			this->Controls->Add(this->lblBarCode);
			this->Controls->Add(this->tbxEmployeeID);
			this->Controls->Add(this->lblEmployeeID);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"TestInterface";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Flying Probe iMES";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &TestInterface::TestInterface_FormClosing);
			this->Load += gcnew System::EventHandler(this, &TestInterface::TestInterface_Load);
			this->grpbxMESHistory->ResumeLayout(false);
			this->grpbxMESHistory->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgrdvwIngredients))->EndInit();
			this->grpbxOfflineMode->ResumeLayout(false);
			this->grpbxOfflineMode->PerformLayout();
			this->grpbxAGV->ResumeLayout(false);
			this->grpbxAGV->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public: System::Void TestInterface_Load(System::Object^  sender, System::EventArgs^  e) {
	System::Drawing::Rectangle^ rect = Screen::GetWorkingArea(this);
	int HeightLocation = rect->Height;
	this->SetDesktopLocation(0, HeightLocation - global_FormWindowHeightOnline - 2);
	this->Height = global_FormWindowHeightOnline;
	
	AllGlobalFileDirectoryInitial();
	Global_MachineStatus::global_MachineStatusForm->Visible = FALSE;
	
	ReadINIFile();
	lblHeartbeatShow->Text = gcnew System::String(global_HeartbeatContent.c_str());
	AllParameterInitial();
	AllButtonInitial();
	if (global_Flag_EnabelHeartbeat == 1)
	{
		HeartbeatInitialize();
	}
	else {
		TimerHeartbeat->Stop();
	}

	WebService::SCCWebService = gcnew SccServiceHelper(gcnew System::String(global_iMESURL.c_str()), global_CommunicationTimeout);
	ReadMachineStatusFile();
	MachineStatusChange(16, 0);
	SendMachineStatusToServer();
	if (CheckTheHighestStatus() <= 2) {
		Global_MachineStatus::global_MachineStatusForm->Visible = FALSE;
	}

	//Parameter Server
	PSSocket::SocketConnect("localhost", 4710);
	TimerParameterServer->Start();

	global_Flag_IfLogin = 0;
	this->Enabled = FALSE;
	Global_MachineStatus::global_MachineStatusForm->Enabled = FALSE;
}

public: System::Void TimerHeartbeat_Tick(System::Object^  sender, System::EventArgs^  e) {
	HeartbeatSendInformation();
}
		 
public: System::Void btnModeSwitching_Click(System::Object^  sender, System::EventArgs^  e) {
	if (global_Flag_iMESMode == 0) {
		global_Flag_iMESMode = 1;

		grpbxAGV->Visible = TRUE;

		if (global_Flag_ChineseEnglishVersion == 1) {
			btnModeSwitching->Text = "在线";
		}
		else {
			btnModeSwitching->Text = "Online";
		}

		this->Height = global_FormWindowHeightOnline;
		System::Drawing::Rectangle^ rect = Screen::GetWorkingArea(this);
		int HeightLocation = rect->Height;
		this->SetDesktopLocation(0, HeightLocation - global_FormWindowHeightOnline - 2);
	}
	else if (global_Flag_iMESMode == 1) {
		global_Flag_iMESMode = 0;

		grpbxAGV->Visible = FALSE;

		if (global_Flag_ChineseEnglishVersion == 1) {
			btnModeSwitching->Text = "离线";
			MessageBox::Show("请在下方离线模式框中填写需要修改的值！");
		}
		else {
			btnModeSwitching->Text = "Offline";
			MessageBox::Show("Still need MES System working! But can change the parameters!");
		}

		this->Height = global_FormWindowHeightOffline;
		System::Drawing::Rectangle^ rect = Screen::GetWorkingArea(this);
		int HeightLocation = rect->Height;
		this->SetDesktopLocation(0, HeightLocation - global_FormWindowHeightOffline - 2);
	}
}
public: System::Void btnApplyChangedIngredients_Click(System::Object^  sender, System::EventArgs^  e) {
	System::String^ tempValue;
	System::String^ tempLabel;
	for (int i = 0;i < dtgrdvwIngredients->Rows->Count; i++) {
		tempLabel = "" + dtgrdvwIngredients->Rows[i]->Cells[2]->Value;
		tempValue = "" + dtgrdvwIngredients->Rows[i]->Cells[1]->Value;
		if (tempLabel == "1000") {
			global_WipEntity = msclr::interop::marshal_as<std::string>(tempValue);
			tbxWipEntity->Text = tempValue;
		}
		else if (tempLabel == "1001") {
			tbxJobID->Text = tempValue;
			global_JobID = msclr::interop::marshal_as<std::string>(tempValue);
		}
		else if (tempLabel == "1002") {
			global_SerialNumber = msclr::interop::marshal_as<std::string>(tempValue);
		}
		else if (tempLabel == "1003") {
			global_StripCount = msclr::interop::marshal_as<std::string>(tempValue);
		}
		else if (tempLabel == "1010") {
			global_Continuity = msclr::interop::marshal_as<std::string>(tempValue);
		}
		else if (tempLabel == "1011") {
			global_Insulation = msclr::interop::marshal_as<std::string>(tempValue);
		}
		else if (tempLabel == "1012") {
			global_TestProgramWholeDirectory = msclr::interop::marshal_as<std::string>(tempValue);
		}
		else if (tempLabel == "1013") {
			tbxTestCountAll->Text = tempValue;
			tbxTestCountNow->Text = tempValue;

			convertFromString(global_DoubleAllTestCount, msclr::interop::marshal_as<std::string>(tempValue));
			global_DoubleRestTestCount = global_DoubleAllTestCount;
		}
		else if (tempLabel == "1014") {
			convertFromString(global_DoubleAllowNGCount, msclr::interop::marshal_as<std::string>(tempValue));
		}
	}

	try {
		FileStream^ fileIngre = gcnew FileStream(gcnew String(global_TestPlayerIngredientsPath.c_str()), FileMode::Create);
		StreamWriter^ swIngredients = gcnew StreamWriter(fileIngre);
		swIngredients->WriteLine("[CurrentIngredientsCredentials]");
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
		swIngredients->Close();

		PSSocket::socketSendMessage("WebService.Cmd=1 SendIngredients\n");
		ShowMessageToMESHistory("Ingredients Update Succeed!" + "\r\n", true);
	}
	catch (Exception^ e) {
		ShowMessageToMESHistory("Ingredients Update Failed!" + "\r\n", true);
	}
	
	delete tempValue;
	delete tempLabel;
}
public: System::Void btnlEmployeeLogoff_Click(System::Object^  sender, System::EventArgs^  e) {
	global_Flag_IfLogin = 0;
	this->Enabled = FALSE;
	Global_MachineStatus::global_MachineStatusForm->Enabled = FALSE;
}
public: System::Void btnCalliMESSetup_Click(System::Object^  sender, System::EventArgs^  e) {
	if (global_Flag_Testing == 0) {
		iMESSetup^ iMESSetupForm = gcnew iMESSetup();
		if (global_Flag_ChineseEnglishVersion == 1) {
			iMESSetupForm->lblMachineID->Text = "设备编号：";
			iMESSetupForm->lbliMESURL->Text = "iMES URL：";
			iMESSetupForm->lblTestProgramDirectory->Text = "资料主路径：";
			iMESSetupForm->lblCartAID->Text = "A载位标号：";
			iMESSetupForm->lblCartBID->Text = "B载位编号：";
			iMESSetupForm->lblAGVAging->Text = "AGV按钮时效：";
			iMESSetupForm->lblCommunicationTimeout->Text = "通讯超时：";
			iMESSetupForm->lblSaveFlawFileZip->Text = "保存废点压缩文件";
			iMESSetupForm->chckbxSaveOriginFlawFile->Text = "保存原始废点文件";
			iMESSetupForm->chckbxSaveChangedFlawFile->Text = "保存更新后废点文件";

			iMESSetupForm->grpbxHeartbeat->Text = "心跳";
			iMESSetupForm->chckbxEnableHeartbeat->Text = "启用心跳";
			iMESSetupForm->lblHeartbeatContent->Text = "心跳内容：";
			iMESSetupForm->lblHeartbeatURL->Text = "心跳服务：";
			iMESSetupForm->lblHeartbeatPort->Text = "心跳端口：";
			iMESSetupForm->lblHeartbeatFrequency->Text = "心跳频率(s)：";
			iMESSetupForm->btniMESSetupSave->Text = "保存";
			iMESSetupForm->btniMESSetupCancel->Text = "取消";

			iMESSetupForm->lblIngredientsDescription->Text = "配方标签说明";
			iMESSetupForm->dtgrdvwIngredientsDescription->Columns[0]->HeaderText = "序号";
			iMESSetupForm->dtgrdvwIngredientsDescription->Columns[1]->HeaderText = "标签";
			iMESSetupForm->dtgrdvwIngredientsDescription->Columns[2]->HeaderText = "说明";
		}

		if (iMESSetupForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			

			lblHeartbeatShow->Text = gcnew System::String(global_HeartbeatContent.c_str());
			if (global_Flag_EnabelHeartbeat == 1)
			{
				HeartbeatInitialize();
			}
			else {
				lblHeartbeatShow->BackColor = Color::DarkGray;
				TimerHeartbeat->Stop();
			}

			delete iMESSetupForm;
		}
	}
	else {
		MessageBox::Show("Cannot change iMES setup until the test is finished!");
	}
}

public: System::Void btnLoadA_Click(System::Object^  sender, System::EventArgs^  e) {
	btnLoadA->Enabled = FALSE;

	if (global_Flag_EnabelHeartbeat == 1 && global_Flag_HeartbeatWorking == 0) {
		btnLoadA->Enabled = TRUE;
		HeartbeatMessageBoxControl();
		return;
	}
	WebService::SCCReturn = 
		WebService::SCCWebService->CallAgv(gcnew System::String(global_MachineID.c_str()), "In_" + gcnew System::String(global_TransportCartAID.c_str()), "");
	ShowMessageToMESHistory("CallAgv " + gcnew System::String(global_TransportCartAID.c_str()) + "\r\n");

	if (WebService::SCCReturn->errorCodek__BackingField == "0") {
		global_Flag_CallAgv++;
		
		TimerA->Start();
		int tempAllSecond = global_AGVButtonAging;
		global_ShowLoadAHour = tempAllSecond / 3600;
		tempAllSecond = tempAllSecond - global_ShowLoadAHour * 3600;
		global_ShowLoadAMinite = tempAllSecond / 60;
		tempAllSecond = tempAllSecond - global_ShowLoadAMinite * 60;
		global_ShowLoadASecond = tempAllSecond;

		ShowAGVLoadATiming();
	}
	else if (WebService::SCCReturn->errorCodek__BackingField == "-1") {
		btnLoadA->Enabled = TRUE;
	}
	else if(WebService::SCCReturn->errorCodek__BackingField == "999" || WebService::SCCReturn->errorCodek__BackingField == "998") {
		btnLoadA->Enabled = TRUE;
	}
	else {
		btnLoadA->Enabled = TRUE;
	}
}
public: System::Void TimerA_Tick(System::Object^  sender, System::EventArgs^  e) {
	int tempAllSecond = global_ShowLoadAHour * 3600 + global_ShowLoadAMinite * 60 + global_ShowLoadASecond;
	if (tempAllSecond == 0) {
		TimerA->Stop();
		btnLoadA->Enabled = TRUE;
	}
	else if (tempAllSecond == 1) {
		TimerA->Stop();
		global_ShowLoadASecond--;
		btnLoadA->Enabled = TRUE;
	}
	else {
		tempAllSecond--;
		global_ShowLoadAHour = tempAllSecond / 3600;
		tempAllSecond = tempAllSecond - global_ShowLoadAHour * 3600;
		global_ShowLoadAMinite = tempAllSecond / 60;
		tempAllSecond = tempAllSecond - global_ShowLoadAMinite * 60;
		global_ShowLoadASecond = tempAllSecond;
	}

	ShowAGVLoadATiming();
}
		 void ShowAGVLoadATiming() {
			 System::String^ tempStr;

			 if (global_ShowLoadAHour < 10) {
				 tempStr += "0";
			 }
			 tempStr += global_ShowLoadAHour + ":";
			 if (global_ShowLoadAMinite < 10) {
				 tempStr += "0";
			 }
			 tempStr += global_ShowLoadAMinite + ":";
			 if (global_ShowLoadASecond < 10) {
				 tempStr += "0";
			 }
			 tempStr += global_ShowLoadASecond;
			 lblAGVAAging->Text = tempStr;

			 delete tempStr;
		 }
public: System::Void btnLoadB_Click(System::Object^  sender, System::EventArgs^  e) {
	btnLoadB->Enabled = FALSE;
	
	if (global_Flag_EnabelHeartbeat == 1 && global_Flag_HeartbeatWorking == 0) {
		btnLoadB->Enabled = TRUE;
		HeartbeatMessageBoxControl();
		return;
	}
	WebService::SCCReturn =
		WebService::SCCWebService->CallAgv(gcnew System::String(global_MachineID.c_str()), "In_" + gcnew System::String(global_TransportCartBID.c_str()), "");
	ShowMessageToMESHistory("CallAgv " + gcnew System::String(global_TransportCartBID.c_str()) + "\r\n");

	if (WebService::SCCReturn->errorCodek__BackingField == "0") {
		global_Flag_CallAgv++;
		
		TimerB->Start();
		int tempAllSecond = global_AGVButtonAging;
		global_ShowLoadBHour = tempAllSecond / 3600;
		tempAllSecond = tempAllSecond - global_ShowLoadBHour * 3600;
		global_ShowLoadBMinite = tempAllSecond / 60;
		tempAllSecond = tempAllSecond - global_ShowLoadBMinite * 60;
		global_ShowLoadBSecond = tempAllSecond;

		ShowAGVLoadBTiming();
	}
	else if (WebService::SCCReturn->errorCodek__BackingField == "-1") {
		btnLoadB->Enabled = TRUE;
	}
	else if (WebService::SCCReturn->errorCodek__BackingField == "999" || WebService::SCCReturn->errorCodek__BackingField == "998") {
		btnLoadB->Enabled = TRUE;
	}
	else {
		btnLoadB->Enabled = TRUE;
	}
}
public: System::Void TimerB_Tick(System::Object^  sender, System::EventArgs^  e) {
	int tempAllSecond = global_ShowLoadBHour * 3600 + global_ShowLoadBMinite * 60 + global_ShowLoadBSecond;
	if (tempAllSecond == 0) {
		TimerB->Stop();
		btnLoadB->Enabled = TRUE;
	}
	else if (tempAllSecond == 1) {
		TimerB->Stop();
		global_ShowLoadBSecond--;
		btnLoadB->Enabled = TRUE;
	}
	else {
		tempAllSecond--;
		global_ShowLoadBHour = tempAllSecond / 3600;
		tempAllSecond = tempAllSecond - global_ShowLoadBHour * 3600;
		global_ShowLoadBMinite = tempAllSecond / 60;
		tempAllSecond = tempAllSecond - global_ShowLoadBMinite * 60;
		global_ShowLoadBSecond = tempAllSecond;
	}

	ShowAGVLoadBTiming();
}
		 void ShowAGVLoadBTiming() {
			 System::String^ tempStr;

			 if (global_ShowLoadBHour < 10) {
				 tempStr += "0";
			 }
			 tempStr += global_ShowLoadBHour + ":";
			 if (global_ShowLoadBMinite < 10) {
				 tempStr += "0";
			 }
			 tempStr += global_ShowLoadBMinite + ":";
			 if (global_ShowLoadBSecond < 10) {
				 tempStr += "0";
			 }
			 tempStr += global_ShowLoadBSecond;
			 lblAGVBAging->Text = tempStr;

			 delete tempStr;
		 }
public: System::Void btnUnload_Click(System::Object^  sender, System::EventArgs^  e) {
	btnUnload->Enabled = FALSE;

	if (global_Flag_EnabelHeartbeat == 1 && global_Flag_HeartbeatWorking == 0) {
		btnUnload->Enabled = TRUE;
		HeartbeatMessageBoxControl();
		return;
	}
	WebService::SCCReturn =
		WebService::SCCWebService->CallAgv(gcnew System::String(global_MachineID.c_str()), "Out", gcnew System::String(global_WipEntity.c_str()));
	ShowMessageToMESHistory("CallAgv Out " + gcnew System::String(global_WipEntity.c_str()) + "\r\n");

	if (WebService::SCCReturn->errorCodek__BackingField == "0") {
		if (global_Flag_CallAgv > 0) {
			global_Flag_CallAgv--;
		}
		else {
			global_Flag_CallAgv = 0;
		}
	}
	else if (WebService::SCCReturn->errorCodek__BackingField == "-1") {
		btnUnload->Enabled = TRUE;
	}
	else if (WebService::SCCReturn->errorCodek__BackingField == "999" || WebService::SCCReturn->errorCodek__BackingField == "998") {
		btnUnload->Enabled = TRUE;
	}
	else {
		btnUnload->Enabled = TRUE;
	}
}
public: System::Void btnReturn_Click(System::Object^  sender, System::EventArgs^  e) {
	btnReturn->Enabled = FALSE;

	if (global_Flag_EnabelHeartbeat == 1 && global_Flag_HeartbeatWorking == 0) {
		btnReturn->Enabled = TRUE;
		HeartbeatMessageBoxControl();
		return;
	}
	WebService::SCCReturn =
		WebService::SCCWebService->CallAgv(gcnew System::String(global_MachineID.c_str()), "Ret", gcnew System::String(global_WipEntity.c_str()));
	ShowMessageToMESHistory("CallAgv Return " + gcnew System::String(global_WipEntity.c_str()) + "\r\n");

	if (WebService::SCCReturn->errorCodek__BackingField == "0") {
		if (global_Flag_CallAgv > 0) {
			global_Flag_CallAgv--;
		}
		else {
			global_Flag_CallAgv = 0;
		}
	}
	else if (WebService::SCCReturn->errorCodek__BackingField == "-1") {
		btnReturn->Enabled = TRUE;
	}
	else if (WebService::SCCReturn->errorCodek__BackingField == "999" || WebService::SCCReturn->errorCodek__BackingField == "998") {
		btnReturn->Enabled = TRUE;
	}
	else {
		btnReturn->Enabled = TRUE;
	}
}
public: System::Void btnTestFinish_Click(System::Object^  sender, System::EventArgs^  e) {
	try {
		btnTestFinish->Enabled = FALSE;
		int tempFlagForLotDataUpload = 1;
		System::String^ tempString = "";

		if (global_Flag_Reset == 1) {
			tempFlagForLotDataUpload = 0;

			System::Collections::Generic::List<SccService::item^>^ tempListItem = gcnew System::Collections::Generic::List<SccService::item^>();
			for (int i = 0; i < global_TestedBoards.size(); i++) {
				SccService::item^ TempItem = gcnew item();

				TempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1001";
				TempItem->tagValue = gcnew System::String(global_TestedBoards[i].BoardBarCode.c_str());
				TempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");

				tempListItem->Add(TempItem);
				tempString += TempItem->tagValue + " ";
			}

			if (global_Flag_EnabelHeartbeat == 1 && global_Flag_HeartbeatWorking == 0) {
				btnTestFinish->Enabled = TRUE;
				HeartbeatMessageBoxControl();
				return;
			}
			WebService::SCCReturn =
				WebService::SCCWebService->PSUpload(gcnew System::String(global_MachineID.c_str()), gcnew System::String(global_WipEntity.c_str()), tempListItem);
			ShowMessageToMESHistory("PSUpload " + tempString + "\r\n");

			if (WebService::SCCReturn->errorCodek__BackingField == "0") {
				tempFlagForLotDataUpload = 1;
			}
			else if (WebService::SCCReturn->errorCodek__BackingField == "-1") {

			}
			else if (WebService::SCCReturn->errorCodek__BackingField == "999" || WebService::SCCReturn->errorCodek__BackingField == "998") {
				btnTestFinish->Enabled = TRUE;
			}
			else {
				btnTestFinish->Enabled = TRUE;
			}
		}

		if (tempFlagForLotDataUpload == 1) {
			System::Collections::Generic::List<SccService::StripNum^>^ tempListStripNum = gcnew System::Collections::Generic::List<SccService::StripNum^>();
			tempString = "";

			for (int i = 0; i < global_TestedBoards.size(); i++) {
				SccService::StripNum^ tempStripNum = gcnew SccService::StripNum();
				tempStripNum->WipEntityStrip = gcnew System::String(global_TestedBoards[i].BoardBarCode.c_str());
				tempStripNum->ItemList = gcnew System::Collections::Generic::List<SccService::item^>();

				SccService::item^ tempItem = gcnew SccService::item();
				//Testing count
				tempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1002";
				tempItem->tagValue = gcnew System::String("" + (global_TestedBoards[i].GoodUnitCount + global_TestedBoards[i].BadUnitCount));
				tempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
				tempStripNum->ItemList->Add(tempItem);
				//NC count
				tempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1003";
				tempItem->tagValue = gcnew System::String("" + global_TestedBoards[i].BadUnitCount);
				tempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
				tempStripNum->ItemList->Add(tempItem);
				//Soft landing
				tempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1004";
				tempItem->tagValue = gcnew System::String(global_TestedBoards[i].SoftLanding.c_str());
				tempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
				tempStripNum->ItemList->Add(tempItem);
				//Pressure
				tempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1005";
				tempItem->tagValue = gcnew System::String(global_TestedBoards[i].PressureSmall.c_str());
				tempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
				tempStripNum->ItemList->Add(tempItem);
				//Speed
				tempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1006";
				tempItem->tagValue = gcnew System::String(global_TestedBoards[i].TestingSpeed.c_str());
				tempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
				tempStripNum->ItemList->Add(tempItem);
				//Height
				tempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1007";
				tempItem->tagValue = gcnew System::String(global_TestedBoards[i].ArmHeight.c_str());
				tempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
				tempStripNum->ItemList->Add(tempItem);
				//Check In
				tempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1016";
				tempItem->tagValue = gcnew System::String(global_GetIngredientsTime.c_str());
				tempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
				tempStripNum->ItemList->Add(tempItem);
				//Check Out
				tempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1017";
				tempItem->tagValue = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
				tempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
				tempStripNum->ItemList->Add(tempItem);
				//Employee ID
				tempItem->tagCode = gcnew System::String(global_MachineID.c_str()) + "_1018";
				tempItem->tagValue = gcnew System::String(global_EmployeeID.c_str());
				tempItem->timeStamp = (DateTime::Now).ToString("yyyy-MM-dd HH:mm:ss");
				tempStripNum->ItemList->Add(tempItem);

				tempListStripNum->Add(tempStripNum);
				tempString += "\r\n" + gcnew System::String(global_TestedBoards[i].BoardBarCode.c_str()) 
					+ " Good:" + global_TestedBoards[i].GoodUnitCount + " Bad:" + global_TestedBoards[i].BadUnitCount
					+ " Pressure:" + gcnew System::String(global_TestedBoards[i].PressureSmall.c_str()) + " Speed:" + gcnew System::String(global_TestedBoards[i].TestingSpeed.c_str())
					+ " Height:" + gcnew System::String(global_TestedBoards[i].ArmHeight.c_str()) + " SoftLanding:" + gcnew System::String(global_TestedBoards[i].SoftLanding.c_str())
					+ " CheckIn:" + gcnew System::String(global_GetIngredientsTime.c_str());
			}

			if (global_Flag_EnabelHeartbeat == 1 && global_Flag_HeartbeatWorking == 0) {
				btnTestFinish->Enabled = TRUE;
				HeartbeatMessageBoxControl();
				return;
			}
			WebService::SCCReturn =
				WebService::SCCWebService->LotDataUpload(gcnew System::String(global_MachineID.c_str()), gcnew System::String(global_WipEntity.c_str()), tempListStripNum);
			ShowMessageToMESHistory("LotDataUpload" + tempString + "\r\n");

			if (WebService::SCCReturn->errorCodek__BackingField == "0") {
				btnUnload->Enabled = TRUE;
				global_Flag_Testing = 0;

				int tempIntReturn = -1;
				
				try {
					if (File::Exists(gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\" + gcnew String(global_WipEntity.c_str()) + ".zip")) {
						File::Delete(gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\" + gcnew String(global_WipEntity.c_str()) + ".zip");
					}
					System::IO::Compression::ZipFile::CreateFromDirectory(gcnew String(global_FlawFileTestPlayerPath.c_str()), gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\" + gcnew String(global_WipEntity.c_str()) + ".zip");
					tempIntReturn = 0;
				}
				catch (Exception^ e) {
					tempIntReturn = -1;
					iMES::ShowMessageToMESHistory("Zipping Error!" + "\r\n", true);
				}

				if (tempIntReturn == 0) {
					if (UploadFileToServer(gcnew String(global_FlawFileServerPath.c_str()), gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\" + gcnew String(global_WipEntity.c_str()) + ".zip") == 0) {
						if (SendFlawFileFinish() == 0) {
							tempFlagForLotDataUpload = 1;
						}
						else {
							tempFlagForLotDataUpload = -1;
						}
					}
					else {
						tempFlagForLotDataUpload = -1;
					}
				}
				else {
					tempFlagForLotDataUpload = -1;
				}

				if (global_Flag_CommandNextTest == 1)
				{
					PSSocket::socketSendMessage("WebService.Cmd=2\n");
					global_Flag_CommandNextTest = -1;
				}
			}
			else if (WebService::SCCReturn->errorCodek__BackingField == "1" || WebService::SCCReturn->errorCodek__BackingField == "2") {
				LotDataUpload^ InputBox = gcnew LotDataUpload();
				if (global_Flag_ChineseEnglishVersion == 1) {
					InputBox->lblInputCount->Text = "请输入重测Unit数量：";
				}
				global_Flag_Testing++;
				if (InputBox->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					tbxTestCountNow->Text = "" + global_DoubleRestTestCount;
					tbxTestCountAll->Text = "" + global_DoubleAllTestCount;
				}

				if (global_Flag_CommandNextTest == 1)
				{
					PSSocket::socketSendMessage("WebService.Cmd=0\n");
					global_Flag_CommandNextTest = -1;
				}
			}
			else if (WebService::SCCReturn->errorCodek__BackingField == "-1") {
				tempFlagForLotDataUpload = -1;
			}
			else if (WebService::SCCReturn->errorCodek__BackingField == "999" || WebService::SCCReturn->errorCodek__BackingField == "998") {
				tempFlagForLotDataUpload = -1;
			}
			else {
				tempFlagForLotDataUpload = -1;
			}
		}

		if (tempFlagForLotDataUpload == -1) {
			btnTestFinish->Enabled = TRUE;
		}
		else {
			FinishTestFlagControl();

			if (global_Flag_SaveOriginFlawFile == 0) {
				if (File::Exists(gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\" + gcnew String(global_WipEntity.c_str()) + "_ORI.zip")) {
					File::Delete(gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\" + gcnew String(global_WipEntity.c_str()) + "_ORI.zip");
				}
			}
			if (global_Flag_SaveChangedFlawFile == 0) {
				if (File::Exists(gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\" + gcnew String(global_WipEntity.c_str()) + ".zip")) {
					File::Delete(gcnew String(global_EXEBasicDirectory.c_str()) + "DownloadFiles\\" + gcnew String(global_WipEntity.c_str()) + ".zip");
				}
			}
		}

		delete tempString;
	}
	catch (Exception^ e) {
		iMES::ShowMessageToMESHistory(e->Source + "\r\n" + e->Message + "\r\n", true);
	}
}

void StartTestFlagControl() {
	global_Flag_Testing = 1;
	global_Flag_Reset = 0;
}
void FinishTestFlagControl() {
	global_Flag_Testing = 0;
	global_Flag_Reset = 0;
}

public: System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e) {
	global_Flag_Reset = 1;
	btnTestFinish->Enabled = TRUE;
}
		 
public: System::Void btnChangeMachineStatus_Click(System::Object^  sender, System::EventArgs^  e) {
	Global_MachineStatus::global_MachineStatusForm->Visible = TRUE;
	this->Enabled = FALSE;
}

public: System::Void TimerParameterServer_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (PSSocket::global_PSSocket->Connected) {
		PSSocket::socketSendMessage(PSSocket::SendMessage);
		PSSocket::KeepReceiveSocketMessage();

		PSSocket::ParameterServerReceive(PSSocket::ReceiveMessage);
	}
	else {
		PSSocket::SocketConnect("localhost", 4710);
	}
}
public: System::Void TestInterface_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	PSSocket::global_PSSocket->Close();

	MachineStatusChange(16, 1);
}
public: System::Void btnMESHistorySave_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!Directory::Exists(Path::GetDirectoryName("MESHistory\\MESHistory_" + (DateTime::Now).ToString("yyyyMMddHHmmss") + ".txt")))
		Directory::CreateDirectory(Path::GetDirectoryName("MESHistory\\MESHistory_" + (DateTime::Now).ToString("yyyyMMddHHmmss") + ".txt"));

	FileStream^ file = gcnew FileStream("MESHistory\\MESHistory_" + (DateTime::Now).ToString("yyyyMMddHHmmss") + ".txt", FileMode::Create);
	StreamWriter^ swMESHistory = gcnew StreamWriter(file);

	swMESHistory->WriteLine(tbxMESHistory->Text);
	swMESHistory->Close();

	delete swMESHistory;
	delete file;
}
public: System::Void btnMESHistoryClear_Click(System::Object^  sender, System::EventArgs^  e) {
	tbxMESHistory->Text = "";
}
public: System::Void btnChineseEnglish_Click(System::Object^  sender, System::EventArgs^  e) {
	if (global_Flag_ChineseEnglishVersion == 0) {
		btnChineseEnglish->Text = "English";
		global_Flag_ChineseEnglishVersion = 1;

		//iMES main interface
		lblModeSwitching->Text = "模式切换：";
		if (global_Flag_iMESMode == 0) {
			btnModeSwitching->Text = "离线";
		}
		else if (global_Flag_iMESMode == 1) {
			btnModeSwitching->Text = "在线";
		}
		lblEmployeeID->Text = "员工ID：";
		btnlEmployeeLogoff->Text = "注销";
		lblBarCode->Text = "条码：";
		lblWipEntity->Text = "工单ID：";
		lblJobID->Text = "物资编码：";
		lblTestCount->Text = "检测数量：";
		lblTestCount2->Text = "共有：";

		lblIngredients->Text = "加工参数：";
		dtgrdvwIngredients->Columns[0]->HeaderText = "配方名";
		dtgrdvwIngredients->Columns[1]->HeaderText = "配方值";
		btnApplyChangedIngredients->Text = "修改";
		btnCalliMESSetup->Text = "iMES设置";
		btnChangeMachineStatus->Text = "改变设备状态";

		btnLoadA->Text = "A叫料";
		btnLoadB->Text = "B叫料";
		btnUnload->Text = "出料";
		btnReturn->Text = "退料";
		btnReset->Text = "复位";
		btnTestFinish->Text = "检测完成";

		grpbxMESHistory->Text = "MES信息";
		btnMESHistoryClear->Text = "清除";
		btnMESHistorySave->Text = "保存";

		//Machine Status
		Global_MachineStatus::global_MachineStatusForm->Text = "设备状态";
		Global_MachineStatus::global_MachineStatusForm->btnMachineDown->Text = "停机";
		Global_MachineStatus::global_MachineStatusForm->btnMaintenance->Text = "保养";
		Global_MachineStatus::global_MachineStatusForm->btnUnderRepair->Text = "故障";
		Global_MachineStatus::global_MachineStatusForm->btnCannotTest->Text = "异常停止";

		grpbxOfflineMode->Text = "离线模式框";
		lblOfflineModeJobID->Text = "物资编码：";
		lblOfflineModeWipEntity->Text = "工单ID：";
		lblOfflineModeProgramDirectory->Text = "测试程序路径：";
		lblOfflineModeTestCount->Text = "检测数量：";
		lblOfflineModeNGCount->Text = "允许NG数量：";
		lblOfflineModeFlawFileDirectory->Text = "废点文件路径：";
	}
	else {
		btnChineseEnglish->Text = "Chinese";
		global_Flag_ChineseEnglishVersion = 0;

		//iMES main interface
		lblModeSwitching->Text = "Mode Switching: ";
		if (global_Flag_iMESMode == 0) {
			btnModeSwitching->Text = "Offline";
		}
		else if (global_Flag_iMESMode == 1) {
			btnModeSwitching->Text = "Online";
		}
		lblEmployeeID->Text = "Employee ID: ";
		btnlEmployeeLogoff->Text = "Logoff";
		lblBarCode->Text = "Bar Code: ";
		lblWipEntity->Text = "Wip Entity: ";
		lblJobID->Text = "Job ID: ";
		lblTestCount->Text = "Test Count: ";
		lblTestCount2->Text = "out of";

		lblIngredients->Text = "Ingredients: ";
		dtgrdvwIngredients->Columns[0]->HeaderText = "Ingredients Name";
		dtgrdvwIngredients->Columns[1]->HeaderText = "Ingredients Value";
		btnApplyChangedIngredients->Text = "Apply";
		btnCalliMESSetup->Text = "iMES Setup";
		btnChangeMachineStatus->Text = "Change Machine Status";

		btnLoadA->Text = "Load A";
		btnLoadB->Text = "Load B";
		btnUnload->Text = "Unload";
		btnReturn->Text = "Return";
		btnReset->Text = "Reset";
		btnTestFinish->Text = "Test Finish";

		grpbxMESHistory->Text = "MES History";
		btnMESHistoryClear->Text = "Clear";
		btnMESHistorySave->Text = "Save";

		//Machine Status
		Global_MachineStatus::global_MachineStatusForm->Text = "MachineStatus";
		Global_MachineStatus::global_MachineStatusForm->btnMachineDown->Text = "Machine Down";
		Global_MachineStatus::global_MachineStatusForm->btnMaintenance->Text = "Maintenance";
		Global_MachineStatus::global_MachineStatusForm->btnUnderRepair->Text = "Under Repair";
		Global_MachineStatus::global_MachineStatusForm->btnCannotTest->Text = "Cannot Test";

		grpbxOfflineMode->Text = "Offline Mode";
		lblOfflineModeJobID->Text = "Job ID: ";
		lblOfflineModeWipEntity->Text = "Wip Entity: ";
		lblOfflineModeProgramDirectory->Text = "Program Directory: ";
		lblOfflineModeTestCount->Text = "Test Count: ";
		lblOfflineModeNGCount->Text = "NG Count: ";
		lblOfflineModeFlawFileDirectory->Text = "Flaw File Directory: ";
	}
}
};
}
