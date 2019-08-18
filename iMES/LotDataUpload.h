#pragma once

extern int global_DoubleAllTestCount;
extern int global_DoubleRestTestCount;

namespace iMES {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LotDataUpload
	/// </summary>
	public ref class LotDataUpload : public System::Windows::Forms::Form
	{
	public:
		int IfGetCount = -1;

		LotDataUpload(void)
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
		~LotDataUpload()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  lblInputCount;
	public: System::Windows::Forms::TextBox^  tbxCountNumber;
	public: System::Windows::Forms::Button^  btnOK;
	protected:



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
			this->lblInputCount = (gcnew System::Windows::Forms::Label());
			this->tbxCountNumber = (gcnew System::Windows::Forms::TextBox());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblInputCount
			// 
			this->lblInputCount->AutoSize = true;
			this->lblInputCount->Location = System::Drawing::Point(24, 29);
			this->lblInputCount->Name = L"lblInputCount";
			this->lblInputCount->Size = System::Drawing::Size(116, 13);
			this->lblInputCount->TabIndex = 0;
			this->lblInputCount->Text = L"Please input the count:";
			// 
			// tbxCountNumber
			// 
			this->tbxCountNumber->Location = System::Drawing::Point(73, 64);
			this->tbxCountNumber->Name = L"tbxCountNumber";
			this->tbxCountNumber->Size = System::Drawing::Size(179, 20);
			this->tbxCountNumber->TabIndex = 1;
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(117, 102);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(65, 23);
			this->btnOK->TabIndex = 4;
			this->btnOK->Text = L"OK";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &LotDataUpload::btnOK_Click);
			// 
			// LotDataUpload
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(301, 147);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->tbxCountNumber);
			this->Controls->Add(this->lblInputCount);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LotDataUpload";
			this->ShowInTaskbar = false;
			this->Text = L"Input";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LotDataUpload::LotDataUpload_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public: System::Void btnOK_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ tempStr = tbxCountNumber->Text;
	int tempInt = 0;
	convertFromString(tempInt, msclr::interop::marshal_as<std::string>(tempStr));

	if (tempInt >= 0) {
		IfGetCount = 1;
		global_DoubleAllTestCount = tempInt;
		global_DoubleRestTestCount = tempInt;

		DialogResult = System::Windows::Forms::DialogResult::OK;
	}
}
private: System::Void LotDataUpload_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	DialogResult = System::Windows::Forms::DialogResult::OK;
	if (IfGetCount == -1) {
		global_DoubleAllTestCount = 0;
		global_DoubleRestTestCount = 0;
	}
}
};
}
