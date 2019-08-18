#pragma once
#include <msclr\marshal_cppstd.h>

#include "iMESMainForm.h"
#include "Basic.h"
#include "IngredientsLabel.h"

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
extern int global_DoubleAllTestCount;
extern int global_DoubleAllowNGCount;
extern int global_Flag_SaveOriginFlawFile;
extern int global_Flag_SaveChangedFlawFile;

//HeartBeat
extern int global_Flag_EnabelHeartbeat;
extern std::string global_HeartbeatContent;
extern std::string global_HeartbeatServerURL;
extern std::string global_HeartbeatPort;
extern int global_HeartbeatFrequency;

//ingredients
extern std::vector<IngredientsLabel> global_IngredientsLabel;

namespace iMES {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for iMESSetup
	/// </summary>
	public ref class iMESSetup : public System::Windows::Forms::Form
	{
	public:
		int flag_IFSave = 0;
		iMESSetup(void)
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
		~iMESSetup()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  lblIngredientsDescription;
	public: System::Windows::Forms::DataGridView^  dtgrdvwIngredientsDescription;
	protected:

	protected:

	public: System::Windows::Forms::DataGridViewTextBoxColumn^  SerialNumber;
	public: System::Windows::Forms::DataGridViewTextBoxColumn^  Label;
	public: System::Windows::Forms::DataGridViewTextBoxColumn^  Description;
	public: System::Windows::Forms::Button^  btniMESSetupCancel;

	public: System::Windows::Forms::Button^  btniMESSetupSave;

	public: System::Windows::Forms::GroupBox^  grpbxHeartbeat;
	public: System::Windows::Forms::CheckBox^  chckbxEnableHeartbeat;
	public: System::Windows::Forms::Label^  lblHeartbeatContent;
	public: System::Windows::Forms::TextBox^  tbxHeartbeatContent;
	public: System::Windows::Forms::Label^  lblHeartbeatURL;
	public: System::Windows::Forms::TextBox^  tbxHeartbeatFrequency;







	public: System::Windows::Forms::TextBox^  tbxHeartbeatURL;
	public: System::Windows::Forms::Label^  lblHeartbeatFrequency;


	public: System::Windows::Forms::Label^  lblHeartbeatPort;
	public: System::Windows::Forms::TextBox^  tbxHeartbeatPort;
	public: System::Windows::Forms::Label^  lblAGVAgingS;
	public: System::Windows::Forms::Label^  lblCommunicationTimeoutS;




	public: System::Windows::Forms::TextBox^  tbxAGVAging;

	public: System::Windows::Forms::Label^  lblAGVAging;

	public: System::Windows::Forms::TextBox^  tbxCartBID;

	public: System::Windows::Forms::Label^  lblCartBID;

	public: System::Windows::Forms::TextBox^  tbxCartAID;

	public: System::Windows::Forms::Label^  lblCartAID;
	public: System::Windows::Forms::TextBox^  tbxCommunicationTimeout;


	public: System::Windows::Forms::Label^  lblCommunicationTimeout;

	public: System::Windows::Forms::TextBox^  tbxTestProgramDirectory;

	public: System::Windows::Forms::Label^  lblTestProgramDirectory;




	public: System::Windows::Forms::TextBox^  tbxiMESURL;


	public: System::Windows::Forms::Label^  lbliMESURL;

	public: System::Windows::Forms::TextBox^  tbxMachineID;

	public: System::Windows::Forms::Label^  lblMachineID;
	public: System::Windows::Forms::Label^  lblSaveFlawFileZip;
	public: System::Windows::Forms::CheckBox^  chckbxSaveOriginFlawFile;
	public: System::Windows::Forms::CheckBox^  chckbxSaveChangedFlawFile;






















	public:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblIngredientsDescription = (gcnew System::Windows::Forms::Label());
			this->dtgrdvwIngredientsDescription = (gcnew System::Windows::Forms::DataGridView());
			this->SerialNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Label = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btniMESSetupCancel = (gcnew System::Windows::Forms::Button());
			this->btniMESSetupSave = (gcnew System::Windows::Forms::Button());
			this->grpbxHeartbeat = (gcnew System::Windows::Forms::GroupBox());
			this->chckbxEnableHeartbeat = (gcnew System::Windows::Forms::CheckBox());
			this->lblHeartbeatContent = (gcnew System::Windows::Forms::Label());
			this->tbxHeartbeatContent = (gcnew System::Windows::Forms::TextBox());
			this->lblHeartbeatURL = (gcnew System::Windows::Forms::Label());
			this->tbxHeartbeatFrequency = (gcnew System::Windows::Forms::TextBox());
			this->tbxHeartbeatURL = (gcnew System::Windows::Forms::TextBox());
			this->lblHeartbeatFrequency = (gcnew System::Windows::Forms::Label());
			this->lblHeartbeatPort = (gcnew System::Windows::Forms::Label());
			this->tbxHeartbeatPort = (gcnew System::Windows::Forms::TextBox());
			this->lblAGVAgingS = (gcnew System::Windows::Forms::Label());
			this->lblCommunicationTimeoutS = (gcnew System::Windows::Forms::Label());
			this->tbxAGVAging = (gcnew System::Windows::Forms::TextBox());
			this->lblAGVAging = (gcnew System::Windows::Forms::Label());
			this->tbxCartBID = (gcnew System::Windows::Forms::TextBox());
			this->lblCartBID = (gcnew System::Windows::Forms::Label());
			this->tbxCartAID = (gcnew System::Windows::Forms::TextBox());
			this->lblCartAID = (gcnew System::Windows::Forms::Label());
			this->tbxCommunicationTimeout = (gcnew System::Windows::Forms::TextBox());
			this->lblCommunicationTimeout = (gcnew System::Windows::Forms::Label());
			this->tbxTestProgramDirectory = (gcnew System::Windows::Forms::TextBox());
			this->lblTestProgramDirectory = (gcnew System::Windows::Forms::Label());
			this->tbxiMESURL = (gcnew System::Windows::Forms::TextBox());
			this->lbliMESURL = (gcnew System::Windows::Forms::Label());
			this->tbxMachineID = (gcnew System::Windows::Forms::TextBox());
			this->lblMachineID = (gcnew System::Windows::Forms::Label());
			this->lblSaveFlawFileZip = (gcnew System::Windows::Forms::Label());
			this->chckbxSaveOriginFlawFile = (gcnew System::Windows::Forms::CheckBox());
			this->chckbxSaveChangedFlawFile = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgrdvwIngredientsDescription))->BeginInit();
			this->grpbxHeartbeat->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblIngredientsDescription
			// 
			this->lblIngredientsDescription->AutoSize = true;
			this->lblIngredientsDescription->Location = System::Drawing::Point(341, 8);
			this->lblIngredientsDescription->Name = L"lblIngredientsDescription";
			this->lblIngredientsDescription->Size = System::Drawing::Size(115, 13);
			this->lblIngredientsDescription->TabIndex = 54;
			this->lblIngredientsDescription->Text = L"Ingredients Description";
			// 
			// dtgrdvwIngredientsDescription
			// 
			this->dtgrdvwIngredientsDescription->AllowUserToOrderColumns = true;
			this->dtgrdvwIngredientsDescription->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtgrdvwIngredientsDescription->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->SerialNumber,
					this->Label, this->Description
			});
			this->dtgrdvwIngredientsDescription->Location = System::Drawing::Point(344, 28);
			this->dtgrdvwIngredientsDescription->Name = L"dtgrdvwIngredientsDescription";
			this->dtgrdvwIngredientsDescription->Size = System::Drawing::Size(443, 452);
			this->dtgrdvwIngredientsDescription->TabIndex = 53;
			// 
			// SerialNumber
			// 
			this->SerialNumber->HeaderText = L"Serial Number";
			this->SerialNumber->Name = L"SerialNumber";
			// 
			// Label
			// 
			this->Label->HeaderText = L"Label";
			this->Label->Name = L"Label";
			// 
			// Description
			// 
			this->Description->HeaderText = L"Description";
			this->Description->Name = L"Description";
			this->Description->Width = 200;
			// 
			// btniMESSetupCancel
			// 
			this->btniMESSetupCancel->Location = System::Drawing::Point(231, 497);
			this->btniMESSetupCancel->Name = L"btniMESSetupCancel";
			this->btniMESSetupCancel->Size = System::Drawing::Size(63, 25);
			this->btniMESSetupCancel->TabIndex = 52;
			this->btniMESSetupCancel->Text = L"Cancel";
			this->btniMESSetupCancel->UseVisualStyleBackColor = true;
			this->btniMESSetupCancel->Click += gcnew System::EventHandler(this, &iMESSetup::btniMESSetupCancel_Click);
			// 
			// btniMESSetupSave
			// 
			this->btniMESSetupSave->Location = System::Drawing::Point(91, 497);
			this->btniMESSetupSave->Name = L"btniMESSetupSave";
			this->btniMESSetupSave->Size = System::Drawing::Size(63, 25);
			this->btniMESSetupSave->TabIndex = 51;
			this->btniMESSetupSave->Text = L"Save";
			this->btniMESSetupSave->UseVisualStyleBackColor = true;
			this->btniMESSetupSave->Click += gcnew System::EventHandler(this, &iMESSetup::btniMESSetupSave_Click);
			// 
			// grpbxHeartbeat
			// 
			this->grpbxHeartbeat->Controls->Add(this->chckbxEnableHeartbeat);
			this->grpbxHeartbeat->Controls->Add(this->lblHeartbeatContent);
			this->grpbxHeartbeat->Controls->Add(this->tbxHeartbeatContent);
			this->grpbxHeartbeat->Controls->Add(this->lblHeartbeatURL);
			this->grpbxHeartbeat->Controls->Add(this->tbxHeartbeatFrequency);
			this->grpbxHeartbeat->Controls->Add(this->tbxHeartbeatURL);
			this->grpbxHeartbeat->Controls->Add(this->lblHeartbeatFrequency);
			this->grpbxHeartbeat->Controls->Add(this->lblHeartbeatPort);
			this->grpbxHeartbeat->Controls->Add(this->tbxHeartbeatPort);
			this->grpbxHeartbeat->Location = System::Drawing::Point(4, 301);
			this->grpbxHeartbeat->Name = L"grpbxHeartbeat";
			this->grpbxHeartbeat->Size = System::Drawing::Size(315, 179);
			this->grpbxHeartbeat->TabIndex = 50;
			this->grpbxHeartbeat->TabStop = false;
			this->grpbxHeartbeat->Text = L"Heartbeat";
			// 
			// chckbxEnableHeartbeat
			// 
			this->chckbxEnableHeartbeat->AutoSize = true;
			this->chckbxEnableHeartbeat->Location = System::Drawing::Point(10, 20);
			this->chckbxEnableHeartbeat->Name = L"chckbxEnableHeartbeat";
			this->chckbxEnableHeartbeat->Size = System::Drawing::Size(109, 17);
			this->chckbxEnableHeartbeat->TabIndex = 26;
			this->chckbxEnableHeartbeat->Text = L"Enable Heartbeat";
			this->chckbxEnableHeartbeat->UseVisualStyleBackColor = true;
			// 
			// lblHeartbeatContent
			// 
			this->lblHeartbeatContent->AutoSize = true;
			this->lblHeartbeatContent->Location = System::Drawing::Point(7, 50);
			this->lblHeartbeatContent->Name = L"lblHeartbeatContent";
			this->lblHeartbeatContent->Size = System::Drawing::Size(97, 13);
			this->lblHeartbeatContent->TabIndex = 16;
			this->lblHeartbeatContent->Text = L"Heartbeat Content:";
			// 
			// tbxHeartbeatContent
			// 
			this->tbxHeartbeatContent->Location = System::Drawing::Point(133, 47);
			this->tbxHeartbeatContent->Name = L"tbxHeartbeatContent";
			this->tbxHeartbeatContent->Size = System::Drawing::Size(170, 20);
			this->tbxHeartbeatContent->TabIndex = 17;
			// 
			// lblHeartbeatURL
			// 
			this->lblHeartbeatURL->AutoSize = true;
			this->lblHeartbeatURL->Location = System::Drawing::Point(7, 85);
			this->lblHeartbeatURL->Name = L"lblHeartbeatURL";
			this->lblHeartbeatURL->Size = System::Drawing::Size(116, 13);
			this->lblHeartbeatURL->TabIndex = 18;
			this->lblHeartbeatURL->Text = L"Heartbeat Server URL:";
			// 
			// tbxHeartbeatFrequency
			// 
			this->tbxHeartbeatFrequency->Location = System::Drawing::Point(133, 150);
			this->tbxHeartbeatFrequency->Name = L"tbxHeartbeatFrequency";
			this->tbxHeartbeatFrequency->Size = System::Drawing::Size(170, 20);
			this->tbxHeartbeatFrequency->TabIndex = 23;
			// 
			// tbxHeartbeatURL
			// 
			this->tbxHeartbeatURL->Location = System::Drawing::Point(133, 81);
			this->tbxHeartbeatURL->Name = L"tbxHeartbeatURL";
			this->tbxHeartbeatURL->Size = System::Drawing::Size(170, 20);
			this->tbxHeartbeatURL->TabIndex = 19;
			// 
			// lblHeartbeatFrequency
			// 
			this->lblHeartbeatFrequency->AutoSize = true;
			this->lblHeartbeatFrequency->Location = System::Drawing::Point(7, 152);
			this->lblHeartbeatFrequency->Name = L"lblHeartbeatFrequency";
			this->lblHeartbeatFrequency->Size = System::Drawing::Size(124, 13);
			this->lblHeartbeatFrequency->TabIndex = 22;
			this->lblHeartbeatFrequency->Text = L"Heartbeat Frequency (s):";
			// 
			// lblHeartbeatPort
			// 
			this->lblHeartbeatPort->AutoSize = true;
			this->lblHeartbeatPort->Location = System::Drawing::Point(7, 118);
			this->lblHeartbeatPort->Name = L"lblHeartbeatPort";
			this->lblHeartbeatPort->Size = System::Drawing::Size(79, 13);
			this->lblHeartbeatPort->TabIndex = 20;
			this->lblHeartbeatPort->Text = L"Heartbeat Port:";
			// 
			// tbxHeartbeatPort
			// 
			this->tbxHeartbeatPort->Location = System::Drawing::Point(134, 115);
			this->tbxHeartbeatPort->Name = L"tbxHeartbeatPort";
			this->tbxHeartbeatPort->Size = System::Drawing::Size(169, 20);
			this->tbxHeartbeatPort->TabIndex = 21;
			// 
			// lblAGVAgingS
			// 
			this->lblAGVAgingS->AutoSize = true;
			this->lblAGVAgingS->Location = System::Drawing::Point(218, 184);
			this->lblAGVAgingS->Name = L"lblAGVAgingS";
			this->lblAGVAgingS->Size = System::Drawing::Size(18, 13);
			this->lblAGVAgingS->TabIndex = 49;
			this->lblAGVAgingS->Text = L"(s)";
			// 
			// lblCommunicationTimeoutS
			// 
			this->lblCommunicationTimeoutS->AutoSize = true;
			this->lblCommunicationTimeoutS->Location = System::Drawing::Point(218, 219);
			this->lblCommunicationTimeoutS->Name = L"lblCommunicationTimeoutS";
			this->lblCommunicationTimeoutS->Size = System::Drawing::Size(18, 13);
			this->lblCommunicationTimeoutS->TabIndex = 48;
			this->lblCommunicationTimeoutS->Text = L"(s)";
			// 
			// tbxAGVAging
			// 
			this->tbxAGVAging->Location = System::Drawing::Point(137, 181);
			this->tbxAGVAging->Name = L"tbxAGVAging";
			this->tbxAGVAging->Size = System::Drawing::Size(74, 20);
			this->tbxAGVAging->TabIndex = 47;
			// 
			// lblAGVAging
			// 
			this->lblAGVAging->AutoSize = true;
			this->lblAGVAging->Location = System::Drawing::Point(11, 184);
			this->lblAGVAging->Name = L"lblAGVAging";
			this->lblAGVAging->Size = System::Drawing::Size(96, 13);
			this->lblAGVAging->TabIndex = 46;
			this->lblAGVAging->Text = L"AGV Button Aging:";
			// 
			// tbxCartBID
			// 
			this->tbxCartBID->Location = System::Drawing::Point(137, 146);
			this->tbxCartBID->Name = L"tbxCartBID";
			this->tbxCartBID->Size = System::Drawing::Size(170, 20);
			this->tbxCartBID->TabIndex = 45;
			// 
			// lblCartBID
			// 
			this->lblCartBID->AutoSize = true;
			this->lblCartBID->Location = System::Drawing::Point(11, 149);
			this->lblCartBID->Name = L"lblCartBID";
			this->lblCartBID->Size = System::Drawing::Size(101, 13);
			this->lblCartBID->TabIndex = 44;
			this->lblCartBID->Text = L"Transport Cart B ID:";
			// 
			// tbxCartAID
			// 
			this->tbxCartAID->Location = System::Drawing::Point(137, 113);
			this->tbxCartAID->Name = L"tbxCartAID";
			this->tbxCartAID->Size = System::Drawing::Size(170, 20);
			this->tbxCartAID->TabIndex = 43;
			// 
			// lblCartAID
			// 
			this->lblCartAID->AutoSize = true;
			this->lblCartAID->Location = System::Drawing::Point(11, 116);
			this->lblCartAID->Name = L"lblCartAID";
			this->lblCartAID->Size = System::Drawing::Size(104, 13);
			this->lblCartAID->TabIndex = 42;
			this->lblCartAID->Text = L"Transport Cart A ID: ";
			// 
			// tbxCommunicationTimeout
			// 
			this->tbxCommunicationTimeout->Location = System::Drawing::Point(137, 216);
			this->tbxCommunicationTimeout->Name = L"tbxCommunicationTimeout";
			this->tbxCommunicationTimeout->Size = System::Drawing::Size(74, 20);
			this->tbxCommunicationTimeout->TabIndex = 41;
			// 
			// lblCommunicationTimeout
			// 
			this->lblCommunicationTimeout->Location = System::Drawing::Point(11, 219);
			this->lblCommunicationTimeout->Name = L"lblCommunicationTimeout";
			this->lblCommunicationTimeout->Size = System::Drawing::Size(118, 13);
			this->lblCommunicationTimeout->TabIndex = 40;
			this->lblCommunicationTimeout->Text = L"Communicate Timeout: ";
			// 
			// tbxTestProgramDirectory
			// 
			this->tbxTestProgramDirectory->Location = System::Drawing::Point(137, 78);
			this->tbxTestProgramDirectory->Name = L"tbxTestProgramDirectory";
			this->tbxTestProgramDirectory->Size = System::Drawing::Size(170, 20);
			this->tbxTestProgramDirectory->TabIndex = 39;
			// 
			// lblTestProgramDirectory
			// 
			this->lblTestProgramDirectory->Location = System::Drawing::Point(11, 71);
			this->lblTestProgramDirectory->Name = L"lblTestProgramDirectory";
			this->lblTestProgramDirectory->Size = System::Drawing::Size(100, 31);
			this->lblTestProgramDirectory->TabIndex = 38;
			this->lblTestProgramDirectory->Text = L"Test Program Main Directory:";
			// 
			// tbxiMESURL
			// 
			this->tbxiMESURL->Location = System::Drawing::Point(137, 41);
			this->tbxiMESURL->Name = L"tbxiMESURL";
			this->tbxiMESURL->Size = System::Drawing::Size(169, 20);
			this->tbxiMESURL->TabIndex = 35;
			// 
			// lbliMESURL
			// 
			this->lbliMESURL->AutoSize = true;
			this->lbliMESURL->Location = System::Drawing::Point(11, 44);
			this->lbliMESURL->Name = L"lbliMESURL";
			this->lbliMESURL->Size = System::Drawing::Size(63, 13);
			this->lbliMESURL->TabIndex = 34;
			this->lbliMESURL->Text = L"iMES URL: ";
			// 
			// tbxMachineID
			// 
			this->tbxMachineID->Location = System::Drawing::Point(137, 7);
			this->tbxMachineID->Name = L"tbxMachineID";
			this->tbxMachineID->Size = System::Drawing::Size(122, 20);
			this->tbxMachineID->TabIndex = 33;
			// 
			// lblMachineID
			// 
			this->lblMachineID->AutoSize = true;
			this->lblMachineID->Location = System::Drawing::Point(11, 10);
			this->lblMachineID->Name = L"lblMachineID";
			this->lblMachineID->Size = System::Drawing::Size(68, 13);
			this->lblMachineID->TabIndex = 32;
			this->lblMachineID->Text = L"Machine ID: ";
			// 
			// lblSaveFlawFileZip
			// 
			this->lblSaveFlawFileZip->AutoSize = true;
			this->lblSaveFlawFileZip->Location = System::Drawing::Point(11, 251);
			this->lblSaveFlawFileZip->Name = L"lblSaveFlawFileZip";
			this->lblSaveFlawFileZip->Size = System::Drawing::Size(100, 13);
			this->lblSaveFlawFileZip->TabIndex = 55;
			this->lblSaveFlawFileZip->Text = L"Save Flaw File Zip: ";
			// 
			// chckbxSaveOriginFlawFile
			// 
			this->chckbxSaveOriginFlawFile->AutoSize = true;
			this->chckbxSaveOriginFlawFile->Location = System::Drawing::Point(137, 250);
			this->chckbxSaveOriginFlawFile->Name = L"chckbxSaveOriginFlawFile";
			this->chckbxSaveOriginFlawFile->Size = System::Drawing::Size(125, 17);
			this->chckbxSaveOriginFlawFile->TabIndex = 27;
			this->chckbxSaveOriginFlawFile->Text = L"Save Origin Flaw File";
			this->chckbxSaveOriginFlawFile->UseVisualStyleBackColor = true;
			// 
			// chckbxSaveChangedFlawFile
			// 
			this->chckbxSaveChangedFlawFile->AutoSize = true;
			this->chckbxSaveChangedFlawFile->Location = System::Drawing::Point(137, 278);
			this->chckbxSaveChangedFlawFile->Name = L"chckbxSaveChangedFlawFile";
			this->chckbxSaveChangedFlawFile->Size = System::Drawing::Size(142, 17);
			this->chckbxSaveChangedFlawFile->TabIndex = 56;
			this->chckbxSaveChangedFlawFile->Text = L"Save Changed Flaw FIle";
			this->chckbxSaveChangedFlawFile->UseVisualStyleBackColor = true;
			// 
			// iMESSetup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(805, 532);
			this->Controls->Add(this->chckbxSaveChangedFlawFile);
			this->Controls->Add(this->chckbxSaveOriginFlawFile);
			this->Controls->Add(this->lblSaveFlawFileZip);
			this->Controls->Add(this->lblIngredientsDescription);
			this->Controls->Add(this->dtgrdvwIngredientsDescription);
			this->Controls->Add(this->btniMESSetupCancel);
			this->Controls->Add(this->btniMESSetupSave);
			this->Controls->Add(this->grpbxHeartbeat);
			this->Controls->Add(this->lblAGVAgingS);
			this->Controls->Add(this->lblCommunicationTimeoutS);
			this->Controls->Add(this->tbxAGVAging);
			this->Controls->Add(this->lblAGVAging);
			this->Controls->Add(this->tbxCartBID);
			this->Controls->Add(this->lblCartBID);
			this->Controls->Add(this->tbxCartAID);
			this->Controls->Add(this->lblCartAID);
			this->Controls->Add(this->tbxCommunicationTimeout);
			this->Controls->Add(this->lblCommunicationTimeout);
			this->Controls->Add(this->tbxTestProgramDirectory);
			this->Controls->Add(this->lblTestProgramDirectory);
			this->Controls->Add(this->tbxiMESURL);
			this->Controls->Add(this->lbliMESURL);
			this->Controls->Add(this->tbxMachineID);
			this->Controls->Add(this->lblMachineID);
			this->Name = L"iMESSetup";
			this->Text = L"iMES Setup";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &iMESSetup::iMESSetup_FormClosing);
			this->Load += gcnew System::EventHandler(this, &iMESSetup::iMESSetup_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgrdvwIngredientsDescription))->EndInit();
			this->grpbxHeartbeat->ResumeLayout(false);
			this->grpbxHeartbeat->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
public: System::Void iMESSetup_Load(System::Object^  sender, System::EventArgs^  e) {
	this->Cursor = System::Windows::Forms::Cursors::WaitCursor;

	if (File::Exists(gcnew String(global_INIFileDirectory.c_str()))) {
		ReadINIFile();
		String^ tempStr;

		//basic
		this->tbxMachineID->Text = gcnew String(global_MachineID.c_str());
		this->tbxiMESURL->Text = gcnew String(global_iMESURL.c_str());
		this->tbxTestProgramDirectory->Text = gcnew String(global_TestProgramMainDirectroy.c_str());
		this->tbxCartAID->Text = gcnew String(global_TransportCartAID.c_str());
		this->tbxCartBID->Text = gcnew String(global_TransportCartBID.c_str());
		tempStr = "" + global_AGVButtonAging;
		this->tbxAGVAging->Text = tempStr;
		tempStr = "" + global_CommunicationTimeout;
		this->tbxCommunicationTimeout->Text = tempStr;
		if (global_Flag_SaveOriginFlawFile == 1) {
			chckbxSaveOriginFlawFile->Checked = TRUE;
		}
		else {
			chckbxSaveOriginFlawFile->Checked = FALSE;
		}
		if (global_Flag_SaveChangedFlawFile == 1) {
			chckbxSaveChangedFlawFile->Checked = TRUE;
		}
		else {
			chckbxSaveChangedFlawFile->Checked = FALSE;
		}

		//heartbeat
		if (global_Flag_EnabelHeartbeat == 1) {
			this->chckbxEnableHeartbeat->Checked = TRUE;
		}
		else {
			this->chckbxEnableHeartbeat->Checked = FALSE;
		}
		this->tbxHeartbeatContent->Text = gcnew String(global_HeartbeatContent.c_str());
		this->tbxHeartbeatURL->Text = gcnew String(global_HeartbeatServerURL.c_str());
		this->tbxHeartbeatPort->Text = gcnew String(global_HeartbeatPort.c_str());
		tempStr = "" + global_HeartbeatFrequency;
		this->tbxHeartbeatFrequency->Text = tempStr;

		//ingredients
		for (int i = 0; i < global_IngredientsLabel.size(); i++) {
			DataGridViewRow^ tempRow = gcnew DataGridViewRow();
			int RowIndex = dtgrdvwIngredientsDescription->Rows->Add(tempRow);
			tempStr = "" + global_IngredientsLabel[i].SerialNumber;
			dtgrdvwIngredientsDescription->Rows[RowIndex]->Cells[0]->Value = tempStr;
			dtgrdvwIngredientsDescription->Rows[RowIndex]->Cells[1]->Value = gcnew String(global_IngredientsLabel[i].LabelID.c_str());
			dtgrdvwIngredientsDescription->Rows[RowIndex]->Cells[2]->Value = gcnew String(global_IngredientsLabel[i].Description.c_str());
			delete tempRow;
		}

		delete tempStr;
		this->Text = "iMES Setup" + "_" + gcnew String(global_INIFileVersion.c_str());
	}
	else {
		INIFileErrorMessageBoxControl("In directory: '" + gcnew String(global_INIFileDirectory.c_str()) + "' cannot find INI file! Please check again!");
	}

	this->Cursor = System::Windows::Forms::Cursors::Default;
}

public: System::Void btniMESSetupSave_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Cursor = System::Windows::Forms::Cursors::WaitCursor;

	StreamWriter^ swIniFile;
	swIniFile = File::CreateText(gcnew String(global_INIFileDirectory.c_str()));

	swIniFile->WriteLine("{VERSION 2}");
	swIniFile->WriteLine("#Hash will allow you to put notes in. First line is always the version");
	swIniFile->WriteLine("#Please spell all the parameters the same as the example ini file");
	swIniFile->WriteLine("#all the columns are separated by exactly one space ");
	swIniFile->WriteLine("#End with {EOF}");

	swIniFile->WriteLine("#basic parameters");
	swIniFile->WriteLine("<parameter MachineID=\"" + tbxMachineID->Text + "\" />");
	swIniFile->WriteLine("<parameter iMESURL=\"" + tbxiMESURL->Text + "\" />");
	swIniFile->WriteLine("<parameter TestProgramMainDirectory=\"" + tbxTestProgramDirectory->Text + "\" />");
	swIniFile->WriteLine("<parameter TransportAID=\"" + tbxCartAID->Text + "\" />");
	swIniFile->WriteLine("<parameter TransportBID=\"" + tbxCartBID->Text + "\" />");
	swIniFile->WriteLine("<parameter AGVButtonAging=\"" + tbxAGVAging->Text + "\" />");
	swIniFile->WriteLine("<parameter CommunicationTimeout=\"" + tbxCommunicationTimeout->Text + "\" />");
	if (chckbxSaveOriginFlawFile->Checked == TRUE) {
		swIniFile->WriteLine("<parameter SaveOriginFlawFile=\"YES\" />");
	}
	else{
		swIniFile->WriteLine("<parameter SaveOriginFlawFile=\"NO\" />");
	}
	if (chckbxSaveChangedFlawFile->Checked == TRUE) {
		swIniFile->WriteLine("<parameter SaveChangedFlawFile=\"YES\" />");
	}
	else {
		swIniFile->WriteLine("<parameter SaveChangedFlawFile=\"NO\" />");
	}

	swIniFile->WriteLine("#heartbeat");
	swIniFile->WriteLine("#If enable heartbeat, put YES; if not, put NO ");
	if (chckbxEnableHeartbeat->Checked == TRUE) {
		swIniFile->WriteLine("<heartbeat EnableHeartbeat=\"YES\" />");
	}
	else {
		swIniFile->WriteLine("<heartbeat EnableHeartbeat=\"NO\" />");
	}
	swIniFile->WriteLine("<heartbeat HeartbeatContent=\"" + tbxHeartbeatContent->Text + "\" />");
	swIniFile->WriteLine("<heartbeat HeartbeatServerURL=\"" + tbxHeartbeatURL->Text + "\" />");
	swIniFile->WriteLine("<heartbeat HeartbeatPort=\"" + tbxHeartbeatPort->Text + "\" />");
	swIniFile->WriteLine("<heartbeat HeartbeatFrequency=\"" + tbxHeartbeatFrequency->Text + "\" />");
	
	swIniFile->WriteLine("#ingredients");
	String^ tempStr;
	for (int i = 0; i < dtgrdvwIngredientsDescription->Rows->Count; i++) {
		tempStr = "" + dtgrdvwIngredientsDescription->Rows[i]->Cells[1]->Value;
		if (tempStr != "") {
			swIniFile->WriteLine("<ingredient SerialNumber=\"" + dtgrdvwIngredientsDescription->Rows[i]->Cells[0]->Value + "\" "
				+ "Label=\"" + dtgrdvwIngredientsDescription->Rows[i]->Cells[1]->Value + "\" "
				+ "Description=\"" + dtgrdvwIngredientsDescription->Rows[i]->Cells[2]->Value + "\" />");
		}
	}

	swIniFile->WriteLine("{EOF}");
	swIniFile->Close();
	delete swIniFile;

	MessageBox::Show("Save successfully! Using the new ini file now!");

	ReadINIFile();

	this->Cursor = System::Windows::Forms::Cursors::Default;
	flag_IFSave = 1;
	DialogResult = System::Windows::Forms::DialogResult::OK;
}
public: System::Void btniMESSetupCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	DialogResult = System::Windows::Forms::DialogResult::OK;
}
public: System::Void iMESSetup_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	if (flag_IFSave == 0) {
		if (MessageBox::Show("If continue closing the form, the setup now will not be saved!", "", MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
			DialogResult = System::Windows::Forms::DialogResult::OK;
		}
		else {
			e->Cancel = true;
		}
	}
}
};
}
