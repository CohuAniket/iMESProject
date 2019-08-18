#include "iMESMainForm.h"
#include "PSSocket.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;

[STAThread]
int  main(array<String^>^ args) {
	Application::EnableVisualStyles();

	try
	{
		iMESMainForm::global_iMESMainForm = gcnew iMES::TestInterface();
		Application::Run(iMESMainForm::global_iMESMainForm);
	}
	catch (Exception^ e)
	{
		int random = (gcnew Random())->Next(100, 999);
		String^ fileName = (DateTime::Now).ToString("yyyyMMddHHmmss") + "_" + random;

		FileStream^ file = gcnew FileStream("LogFile\\" + fileName + ".txt", FileMode::Create);
		StreamWriter^ sw = gcnew StreamWriter(file);

		sw->Write(e->Message + "\r\n" + e->StackTrace);
		sw->Flush();
		sw->Close();
		file->Close();
	}

	return 0;
}

