#pragma once

namespace iMES {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChangePassword
	/// </summary>
	public ref class ChangePassword : public System::Windows::Forms::Form
	{
	public:
		ChangePassword(void)
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
		~ChangePassword()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^  tbxPassword;
	protected:
	public: System::Windows::Forms::Label^  lblPassword;
	public: System::Windows::Forms::TextBox^  tbxUserName;
	public: System::Windows::Forms::Label^  lblUserName;
	public: System::Windows::Forms::TextBox^  textBox1;
	public: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::Button^  btnLogin;

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
			this->tbxPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->tbxUserName = (gcnew System::Windows::Forms::TextBox());
			this->lblUserName = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// tbxPassword
			// 
			this->tbxPassword->Location = System::Drawing::Point(113, 80);
			this->tbxPassword->Name = L"tbxPassword";
			this->tbxPassword->Size = System::Drawing::Size(132, 20);
			this->tbxPassword->TabIndex = 7;
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(18, 83);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(78, 13);
			this->lblPassword->TabIndex = 6;
			this->lblPassword->Text = L"Old Password: ";
			// 
			// tbxUserName
			// 
			this->tbxUserName->Location = System::Drawing::Point(113, 36);
			this->tbxUserName->Name = L"tbxUserName";
			this->tbxUserName->Size = System::Drawing::Size(132, 20);
			this->tbxUserName->TabIndex = 5;
			// 
			// lblUserName
			// 
			this->lblUserName->AutoSize = true;
			this->lblUserName->Location = System::Drawing::Point(23, 39);
			this->lblUserName->Name = L"lblUserName";
			this->lblUserName->Size = System::Drawing::Size(73, 13);
			this->lblUserName->TabIndex = 4;
			this->lblUserName->Text = L"Employee ID: ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(113, 125);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 20);
			this->textBox1->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 128);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"New Password: ";
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(180, 178);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(65, 23);
			this->btnLogin->TabIndex = 10;
			this->btnLogin->Text = L"Change";
			this->btnLogin->UseVisualStyleBackColor = true;
			// 
			// ChangePassword
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 232);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbxPassword);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->tbxUserName);
			this->Controls->Add(this->lblUserName);
			this->Name = L"ChangePassword";
			this->Text = L"Change Password";
			this->Load += gcnew System::EventHandler(this, &ChangePassword::ChangePassword_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void ChangePassword_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
