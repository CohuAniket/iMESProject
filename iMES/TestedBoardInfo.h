#pragma once

#include <msclr\marshal_cppstd.h>

class TestedBoardInfo
{
public:
	int TestUnitCount;
	int GoodUnitCount;
	int BadUnitCount;
	std::string BoardBarCode;
	std::string SoftLanding;
	std::string PressureSmall;
	std::string TestingSpeed;
	std::string ArmHeight;
};