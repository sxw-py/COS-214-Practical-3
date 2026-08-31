#include "Subject.h"

void Subject::attach(Observer* o)
{
	detach(o);
	observers.push_back(o);
}

void Subject::detach(Observer* observer)
{
	for (auto it = observers.begin(); it != observers.end(); )
	{
		if (*it == observer)
			it = observers.erase(it);
		else
			it++;
	}
}

void Subject::setup()
{
	for (auto o : observers)
		o->setup(*this);
}

void Subject::shutdown()
{
	for (auto o : observers)
		o->shutdown(*this);
}

void Subject::medicalEmergency()
{
	for (auto o : observers)
		o->medicalEmergency(*this);
}

void Subject::setWeatherData(int severity, const std::string& type){
	currentSeverity = severity;
	currentWeatherType = type;
	weatherAlert();  //notify all observers
}


void Subject::weatherAlert()
{
	for (auto o : observers)
		o->weatherAlert(*this);
}


void Subject::setBullEscape(const std::string& location, int numBulls){
	bullLocation = location;
	this->numBulls = numBulls;
	escapedBull(); // notify
}

void Subject::escapedBull()
{
	for (auto o : observers)
		o->escapedBull(*this);
}

void Subject::capacityAlert()
{
	for (auto o : observers)
		o->capacityAlert(*this);
}



