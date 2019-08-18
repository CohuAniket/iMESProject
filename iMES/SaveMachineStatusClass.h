#pragma once

#include <msclr\marshal_cppstd.h>

//down 16; maintenace 8; repair 4; standby 2; testing 1
public ref class SaveMachineStatusClass
{
public:
	static int global_Flag_MachineStatus_Down;
	static System::String ^ global_MachineStatus_Down_Time = "";
	static int global_Flag_MachineStatus_Maintenance;
	static System::String ^ global_MachineStatus_Maintenance_Time = "";
	static int global_Flag_MachineStatus_Repair;
	static System::String ^ global_MachineStatus_Repair_Time = "";
	static int global_Flag_MachineStatus_Standby;
	static System::String ^ global_MachineStatus_Standby_Time = "";
	static int global_Flag_MachineStatus_Testing;
	static System::String ^ global_MachineStatus_Testing_Time = "";
};