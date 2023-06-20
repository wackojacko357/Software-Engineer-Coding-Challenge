#pragma once
#include "Includes.h"

class Observer
{
public:
	Observer();
	virtual ~Observer() {}

	virtual std::string update(std::string currentState, std::string newState);

	std::string				m_name;	// String containing the names to ID which Observer is which.
};