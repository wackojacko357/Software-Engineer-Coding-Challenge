#pragma once
#include <string>
#include "Subject.h"

class Machine : public Subject
{
public:
	Machine(const std::string& name);
	std::string				m_machineName;		// Name of the Machine in string format
};