#pragma once

#include <string>
#include <map>
#include <vector>
#include "Observer.h"

namespace States {
	enum State {
		PRODUCING, IDLE, STARVED
	};
}

class Subject
{
	std::map<States::State, std::string> stateToStringMap
	{
		{States::State::PRODUCING, "PRODUCING"},
		{States::State::IDLE, "IDLE"},
		{States::State::STARVED, "STARVED"}
	};

public:
	Subject();
	virtual ~Subject() {}

	std::string setState(std::string s);
	std::string getState();
	std::string stateToString(States::State state);
	void attach(Observer& o);
	void notifyAllObservers();

private:
	std::vector<Observer*>		m_observers; // A Vector of all the observers to pass around data.
	States::State				m_state;
};