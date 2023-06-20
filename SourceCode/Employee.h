#pragma once
#include <string>
#include "Employee.h"
#include "Observer.h"
#include "Machine.h"

class Employee : public Observer
{
public:
	Employee(const std::string& role, const std::string& name);

	std::string update(std::string state, std::string newState) override;
	std::string getRole();

	std::string			m_role;
};