#pragma once
#include "SaveMachineStatusClass.h"
#include "Basic.h"
#include "WebService.h"

//heartbeat
extern int global_Flag_HeartbeatWorking;

namespace iMES {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace SccService;

	/// <summary>
	/// Summary for MachineStatus
	/// </summary>
	public ref class MachineStatus : public System::Windows::Forms::Form
	{
	public:
		MachineStatus(void)
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
		~MachineStatus()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^  btnUnderRepair;
	public: System::Windows::Forms::Button^  btnMachineDown;
	protected:

	protected:


	public: System::Windows::Forms::Button^  btnMaintenance;
	public: System::Windows::Forms::Button^  btnCannotTest;





	protected:

	protected:

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
			this->btnUnderRepair = (gcnew System::Windows::Forms::Button());
			this->btnMachineDown = (gcnew System::Windows::Forms::Button());
			this->btnMaintenance = (gcnew System::Windows::Forms::Button());
			this->btnCannotTest = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnUnderRepair
			// 
			this->btnUnderRepair->BackColor = System::Drawing::Color::LightGray;
			this->btnUnderRepair->Location = System::Drawing::Point(32, 107);
			this->btnUnderRepair->Name = L"btnUnderRepair";
			this->btnUnderRepair->Size = System::Drawing::Size(94, 31);
			this->btnUnderRepair->TabIndex = 0;
			this->btnUnderRepair->Text = L"Under Repair";
			this->btnUnderRepair->UseVisualStyleBackColor = false;
			this->btnUnderRepair->Click += gcnew System::EventHandler(this, &MachineStatus::btnUnderRepair_Click);
			// 
			// btnMachineDown
			// 
			this->btnMachineDown->BackColor = System::Drawing::Color::LightGray;
			this->btnMachineDown->Location = System::Drawing::Point(32, 32);
			this->btnMachineDown->Name = L"btnMachineDown";
			this->btnMachineDown->Size = System::Drawing::Size(94, 31);
			this->btnMachineDown->TabIndex = 1;
			this->btnMachineDown->Text = L"Machine Down";
			this->btnMachineDown->UseVisualStyleBackColor = false;
			this->btnMachineDown->Click += gcnew System::EventHandler(this, &MachineStatus::btnMachineDown_Click);
			// 
			// btnMaintenance
			// 
			this->btnMaintenance->BackColor = System::Drawing::Color::LightGray;
			this->btnMaintenance->Location = System::Drawing::Point(32, 182);
			this->btnMaintenance->Name = L"btnMaintenance";
			this->btnMaintenance->Size = System::Drawing::Size(94, 31);
			this->btnMaintenance->TabIndex = 2;
			this->btnMaintenance->Text = L"Maintenance";
			this->btnMaintenance->UseVisualStyleBackColor = false;
			this->btnMaintenance->Click += gcnew System::EventHandler(this, &MachineStatus::btnMaintenance_Click);
			// 
			// btnCannotTest
			// 
			this->btnCannotTest->BackColor = System::Drawing::Color::LightGray;
			this->btnCannotTest->Location = System::Drawing::Point(160, 79);
			this->btnCannotTest->Name = L"btnCannotTest";
			this->btnCannotTest->Size = System::Drawing::Size(101, 84);
			this->btnCannotTest->TabIndex = 3;
			this->btnCannotTest->Text = L"Cannot Test";
			this->btnCannotTest->UseVisualStyleBackColor = false;
			this->btnCannotTest->Click += gcnew System::EventHandler(this, &MachineStatus::btnCannotTest_Click);
			// 
			// MachineStatus
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->btnCannotTest);
			this->Controls->Add(this->btnMaintenance);
			this->Controls->Add(this->btnMachineDown);
			this->Controls->Add(this->btnUnderRepair);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MachineStatus";
			this->Text = L"MachineStatus";
			this->TopMost = true;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MachineStatus::MachineStatus_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MachineStatus::MachineStatus_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
public: System::Void MachineStatus_Load(System::Object^  sender, System::EventArgs^  e) {
	this->Cursor = System::Windows::Forms::Cursors::WaitCursor;

	btnCannotTest->Enabled = FALSE;
	ReadMachineStatusFile();
	if (SaveMachineStatusClass::global_Flag_MachineStatus_Down == 1) {
		btnMachineDown->BackColor = Color::Red;
	}
	else {
		btnMachineDown->BackColor = Color::LightGray;
	}

	if (SaveMachineStatusClass::global_Flag_MachineStatus_Maintenance == 1) {
		btnMaintenance->BackColor = Color::Red;
	}
	else {
		btnMaintenance->BackColor = Color::LightGray;
	}
	
	if (SaveMachineStatusClass::global_Flag_MachineStatus_Repair == 1) {
		btnUnderRepair->BackColor = Color::Red;
		btnCannotTest->Enabled = TRUE;
	}
	else {
		btnUnderRepair->BackColor = Color::LightGray;
	}

	this->Cursor = System::Windows::Forms::Cursors::Default;
}
public: System::Void MachineStatus_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	e->Cancel = TRUE;

	if (SaveMachineStatusClass::global_Flag_MachineStatus_Down == 1 || 
		SaveMachineStatusClass::global_Flag_MachineStatus_Maintenance == 1 || 
		SaveMachineStatusClass::global_Flag_MachineStatus_Repair == 1) {
		MessageBox::Show("Please unselect red machine status to close this window!");
		this->Visible = TRUE;
	}
	else { 
		this->Visible = FALSE; 
		EnableTheMainIMESInterface();
	}
}
		 
public: System::Void btnMachineDown_Click(System::Object^  sender, System::EventArgs^  e) {
	if (SaveMachineStatusClass::global_Flag_MachineStatus_Down == 1) {
		MachineStatusChange(16, 0);

		if (CheckTheHighestStatus() <= 2) {
			this->Visible = FALSE;
			EnableTheMainIMESInterface();
		}
	}
	else {
		MachineStatusChange(16, 1);
	}
}
public: System::Void btnUnderRepair_Click(System::Object^  sender, System::EventArgs^  e) {
	if (SaveMachineStatusClass::global_Flag_MachineStatus_Repair == 1) {
		MachineStatusChange(4, 0);
		btnCannotTest->Enabled = FALSE;

		if (CheckTheHighestStatus() <= 2) {
			this->Visible = FALSE;
			EnableTheMainIMESInterface();
		}
	}
	else {
		MachineStatusChange(4, 1);
		btnCannotTest->Enabled = TRUE;
	}
}
public: System::Void btnMaintenance_Click(System::Object^  sender, System::EventArgs^  e) {
	if (SaveMachineStatusClass::global_Flag_MachineStatus_Maintenance == 1) {
		MachineStatusChange(8, 0);

		if (CheckTheHighestStatus() <= 2) {
			this->Visible = FALSE;
			EnableTheMainIMESInterface();
		}
	}
	else {
		MachineStatusChange(8, 1);
	}
}
public: System::Void btnCannotTest_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show("If continue the machine will be initialized! This wip entity information will all be given up!\nPress OK to abort all test result on this job!", "", MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
		GiveUpWipEntityInitializeTheWholeIMES();
	}
}
		 void GiveUpWipEntityInitializeTheWholeIMES() {
			 AllInterfaceShowingForOldWipEntityInitial();
			 AllButtonInitial();
			 AllParameterInitial();
		 }
};
}
