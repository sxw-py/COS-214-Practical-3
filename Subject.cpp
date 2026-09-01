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
		o->setup();
}

void Subject::shutdown()
{
	for (auto o : observers)
		o->shutdown();
}

void Subject::setMedicalEmergency(int severity, const std::string& injuryType){
	currentSeverity = severity;
	this->injuryType = injuryType;
	medicalEmergency();
}

void Subject::medicalEmergency()
{
	for (auto o : observers)
		o->medicalEmergency(currentSeverity, injuryType);
}

void Subject::setWeatherData(int severity, const std::string& type){
	currentSeverity = severity;
	currentWeatherType = type;
	weatherAlert();  //notify all observers
}

void Subject::weatherAlert()
{
	for (auto o : observers)
		o->weatherAlert(currentSeverity, currentWeatherType);
}


void Subject::setBullEscape(const std::string& location, int numBulls){
	bullLocation = location;
	this->numBulls = numBulls;
	escapedBull(); // notify
}

void Subject::escapedBull()
{
	for (auto o : observers)
		o->escapedBull(bullLocation, numBulls);
}

void Subject::setCapacityAlert(int currentCount, int maxCapacity){
	this->currentCount = currentCount;
	this->maxCapacity = maxCapacity;
	capacityAlert();
}

void Subject::capacityAlert()
{
	for (auto o : observers)
		o->capacityAlert(currentCount,maxCapacity);
}

void Subject::vipArrival(int vipLevel)
{
	for (auto o : observers)
		o->vipArrival(vipLevel);
}

void Subject::quarantine(int days)
{
	for (auto o : observers)
		o->quarantine(days);
}

void Subject::feedingTime(std::string foodType)
{
	for (auto o : observers)
		o->feedingTime(foodType);
}

