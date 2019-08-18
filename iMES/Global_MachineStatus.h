#pragma once
#include "MachineStatus.h"

public ref class Global_MachineStatus {
public:
	static iMES::MachineStatus^ global_MachineStatusForm = gcnew iMES::MachineStatus();
};
