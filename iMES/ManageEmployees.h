#pragma once

namespace iMES {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ManageEmployees
	/// </summary>
	public ref class ManageEmployees : public System::Windows::Forms::Form
	{
	public:
		ManageEmployees(void)
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
		~ManageEmployees()
		{
			if (components)
			{
				delete components;
			}
		}

	public: System::Windows::Forms::Button^  btnChangePassword;
	protected:

	protected:














	public: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::Button^  button2;

	public: System::Windows::Forms::Button^  button3;
	public: System::Windows::Forms::Button^  button4;
	public: System::Windows::Forms::DataGridView^  dtgrdvwEmployees;
	public: System::Windows::Forms::DataGridViewTextBoxColumn^  dtgrdvwtbxclmnSerialNumber;
	public: System::Windows::Forms::DataGridViewTextBoxColumn^  dtgrdvwtbxclmnUserID;
	public: System::Windows::Forms::DataGridViewTextBoxColumn^  dtgrdvwtbxclmnPassword;
	public: System::Windows::Forms::DataGridViewComboBoxColumn^  dtgrdvwtbxclmnAccessLevel;











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
			this->btnChangePassword = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dtgrdvwEmployees = (gcnew System::Windows::Forms::DataGridView());
			this->dtgrdvwtbxclmnSerialNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dtgrdvwtbxclmnUserID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dtgrdvwtbxclmnPassword = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dtgrdvwtbxclmnAccessLevel = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgrdvwEmployees))->BeginInit();
			this->SuspendLayout();
			// 
			// btnChangePassword
			// 
			this->btnChangePassword->Location = System::Drawing::Point(323, 285);
			this->btnChangePassword->Name = L"btnChangePassword";
			this->btnChangePassword->Size = System::Drawing::Size(65, 23);
			this->btnChangePassword->TabIndex = 13;
			this->btnChangePassword->Text = L"Change";
			this->btnChangePassword->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(124, 285);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(65, 23);
			this->button1->TabIndex = 20;
			this->button1->Text = L"Remove";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(24, 285);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(65, 23);
			this->button2->TabIndex = 21;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ManageEmployees::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(222, 285);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(65, 23);
			this->button3->TabIndex = 23;
			this->button3->Text = L"Find";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(433, 285);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(65, 23);
			this->button4->TabIndex = 24;
			this->button4->Text = L"Save";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// dtgrdvwEmployees
			// 
			this->dtgrdvwEmployees->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtgrdvwEmployees->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dtgrdvwtbxclmnSerialNumber,
					this->dtgrdvwtbxclmnUserID, this->dtgrdvwtbxclmnPassword, this->dtgrdvwtbxclmnAccessLevel
			});
			this->dtgrdvwEmployees->Location = System::Drawing::Point(20, 24);
			this->dtgrdvwEmployees->Name = L"dtgrdvwEmployees";
			this->dtgrdvwEmployees->Size = System::Drawing::Size(482, 228);
			this->dtgrdvwEmployees->TabIndex = 25;
			this->dtgrdvwEmployees->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &ManageEmployees::dtgrdvwEmployees_EditingControlShowing);
			// 
			// dtgrdvwtbxclmnSerialNumber
			// 
			this->dtgrdvwtbxclmnSerialNumber->HeaderText = L"Serial Number";
			this->dtgrdvwtbxclmnSerialNumber->Name = L"dtgrdvwtbxclmnSerialNumber";
			this->dtgrdvwtbxclmnSerialNumber->Width = 98;
			// 
			// dtgrdvwtbxclmnUserID
			// 
			this->dtgrdvwtbxclmnUserID->HeaderText = L"User ID";
			this->dtgrdvwtbxclmnUserID->Name = L"dtgrdvwtbxclmnUserID";
			this->dtgrdvwtbxclmnUserID->Width = 110;
			// 
			// dtgrdvwtbxclmnPassword
			// 
			this->dtgrdvwtbxclmnPassword->HeaderText = L"Password";
			this->dtgrdvwtbxclmnPassword->Name = L"dtgrdvwtbxclmnPassword";
			this->dtgrdvwtbxclmnPassword->Width = 120;
			// 
			// dtgrdvwtbxclmnAccessLevel
			// 
			this->dtgrdvwtbxclmnAccessLevel->HeaderText = L"Access Level";
			this->dtgrdvwtbxclmnAccessLevel->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Administrator", L"Engineer",
					L"Operator"
			});
			this->dtgrdvwtbxclmnAccessLevel->Name = L"dtgrdvwtbxclmnAccessLevel";
			this->dtgrdvwtbxclmnAccessLevel->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dtgrdvwtbxclmnAccessLevel->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->dtgrdvwtbxclmnAccessLevel->Width = 110;
			// 
			// ManageEmployees
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(533, 338);
			this->Controls->Add(this->dtgrdvwEmployees);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnChangePassword);
			this->Name = L"ManageEmployees";
			this->Text = L"User Management";
			this->Load += gcnew System::EventHandler(this, &ManageEmployees::ManageEmployees_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgrdvwEmployees))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: System::Void btnChangePassword_Click(System::Object^  sender, System::EventArgs^  e) {
	}

public: System::Void ManageEmployees_Load(System::Object^  sender, System::EventArgs^  e) {
	String^ tempStr="123456";

	DataGridViewRow^ tempRow1 = gcnew DataGridViewRow();
	int RowIndex = dtgrdvwEmployees->Rows->Add(tempRow1);
	dtgrdvwEmployees->Rows[RowIndex]->Cells[0]->Value = "1";
	dtgrdvwEmployees->Rows[RowIndex]->Cells[1]->Value = "Admin";
	dtgrdvwEmployees->Rows[RowIndex]->Cells[2]->Value = "******";
	dtgrdvwEmployees->Rows[RowIndex]->Cells[3]->Value = "Administrator";

	DataGridViewRow^ tempRow2 = gcnew DataGridViewRow();
	RowIndex = dtgrdvwEmployees->Rows->Add(tempRow2);
	dtgrdvwEmployees->Rows[RowIndex]->Cells[0]->Value = "2";
	dtgrdvwEmployees->Rows[RowIndex]->Cells[1]->Value = "SN41211";
	dtgrdvwEmployees->Rows[RowIndex]->Cells[2]->Value = "******";
	dtgrdvwEmployees->Rows[RowIndex]->Cells[3]->Value = "Administrator";
	dtgrdvwEmployees->Rows[RowIndex]->DefaultCellStyle->BackColor = Color::Pink;

	DataGridViewRow^ tempRow3 = gcnew DataGridViewRow();
	RowIndex = dtgrdvwEmployees->Rows->Add(tempRow3);
	dtgrdvwEmployees->Rows[RowIndex]->Cells[0]->Value = "3";
	dtgrdvwEmployees->Rows[RowIndex]->Cells[1]->Value = "SN65842";
	dtgrdvwEmployees->Rows[RowIndex]->Cells[2]->Value = "******";
	dtgrdvwEmployees->Rows[RowIndex]->Cells[3]->Value = "Engineer";

	DataGridViewRow^ tempRow4 = gcnew DataGridViewRow();
	RowIndex = dtgrdvwEmployees->Rows->Add(tempRow4);
	dtgrdvwEmployees->Rows[RowIndex]->Cells[0]->Value = "4";
	dtgrdvwEmployees->Rows[RowIndex]->Cells[1]->Value = "SN52462";
	dtgrdvwEmployees->Rows[RowIndex]->Cells[2]->Value = "";
	dtgrdvwEmployees->Rows[RowIndex]->Cells[3]->Value = "Operator";
	dtgrdvwEmployees->Rows[RowIndex]->DefaultCellStyle->BackColor = Color::Pink;
}
public: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
}
public: System::Void dtgrdvwEmployees_EditingControlShowing(System::Object^  sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^  e) {
	TextBox^ t = nullptr; 
	e->Control ;
}
};
}
