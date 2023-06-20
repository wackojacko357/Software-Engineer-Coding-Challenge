#include "Observer.h"

Observer::Observer()
{
}

std::string Observer::update(std::string currentState, std::string newState)
{ 
	currentState = newState;

	return newState;
}