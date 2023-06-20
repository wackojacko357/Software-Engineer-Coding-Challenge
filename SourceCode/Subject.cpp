#include <string.h>
#include "Subject.h"

using namespace States;

Subject::Subject()
{
	m_state = IDLE;
	{
		m_observers.clear();
	}
}

std::string Subject::setState(std::string string)
{
	std::cout << "----------------------------------------\n";
	std::cout << "Setting Machine State...\n";

	if ((string == "IDLE") || (string == "idle"))
	{
		string = "IDLE";
		m_state = IDLE;
		std::cout << "Machine State Set: " << string << " - " << "Machine is waiting for work. \n";
	}
	else if ((string == "PRODUCING") || (string == "producing"))
	{
		string = "PRODUCING";
		m_state = PRODUCING;
		std::cout << "Machine State Set: " << string << " - " << "The machine is currently working. \n";
	}
	else if ((string == "STARVED") || (string == "starved"))
	{
		string = "STARVED";
		m_state = STARVED;
		std::cout << "Machine State Set: " << string << " - " << "There is no material available for the machine to complete it's work. \n";
	}
	else
	{
		string = "IDLE";
		m_state = IDLE;
		std::cout << "INVALID STATE: " << string << " - " << "Setting machine to idle. \n";
	}

	return string;
}

void Subject::attach(Observer& observer)
{
	std::cout << "Attaching observer: " << observer.m_name << "\n";
	m_observers.push_back(&observer);
}

void Subject::notifyAllObservers()
{
	std::cout << "----------------------------------------\n";
	std::cout << "Notifing Observers...\n";
	if (false == m_observers.empty())
	{
		for (auto observers : m_observers)
		{
			observers->update("IDLE", "STARVED");
		}
	}
	else
		std::cout << "No observers found!";
}

std::string Subject::getState()
{
	return stateToString(m_state);
}

std::string Subject::stateToString(State state)
{
	std::string s;

	switch (state)
	{
	case IDLE:
		s = "IDLE";
		std::cout << "State: IDLE \n" << endl;
		break;
	case PRODUCING:
		s = "PRODUCING";
		std::cout << "State: PRODUCING \n" << endl;
		break;
	case STARVED:
		s = "STARVED";
		std::cout << "State: STARVED \n" << endl;
		break;
	}

	return s;
}