#pragma once

#include <msclr\marshal_cppstd.h>

using namespace System::IO;

//down 16; maintenace 8; repair 4; standby 2; testing 1
public ref class WipEntityLogFileStreamWriter
{
public:
	static StreamWriter^ global_WipEntityLogFileSW;
	//WipEntity Log File Name
	static System::String^ global_WipEntityLogFileName;
	static int global_flagIfWipEntityFinish;
};