#include <string.h>
#include "Employee.h"

Employee::Employee(const std::string& role, const std::string& name)
{
	m_role = role;
	m_name = name;
}

std::string Employee::update(std::string state, std::string newState)
{
	std::cout << "----------------------------------------\n";
	std::cout << "Updating Machine State...\n";
	std::cout << "Employees' Name: " << m_name << " | Role: " << m_role << "\n";
	std::cout << "Changing State: " << state << " to State: " << newState << "\n\n";
	state = newState;

	return newState;
}

std::string Employee::getRole()
{
	return m_role;
}