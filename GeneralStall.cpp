#include <iostream>
#include "GeneralStall.h"
#include "Subject.h"

GeneralStall::GeneralStall(int cap) : Stall(cap), revenue(0) {}
void GeneralStall::buyItem()
{
	if (this->reportStatus())
		revenue += unitCost();
}

bool GeneralStall::isServiceSlowed() const { 
	return serviceSlowed; 
}

int GeneralStall::getRevenue()
{
	return this->revenue;
}


void GeneralStall::weatherAlert(int severity, const std::string& type){
	std::cout << "General stall : Closing - " << type << "(severity" << severity << "/" << Subject::MaxSeverity << ")" << std::endl;

	this->close();
}


void GeneralStall::escapedBull(const std::string& location, int numBulls){
	std::cout << "General stall : Closing - Bull escape at " << location << "!" << std::endl;
	this->close();
}

void GeneralStall::medicalEmergency(int severity, const std::string& injuryType){
    std::cout << "General Stall: Pausing - Medical emergency! (" << injuryType << ")" << std::endl;
    this->close();
}


void GeneralStall::capacityAlert(int currentCount, int maxCapacity){
    serviceSlowed = (currentCount >= maxCapacity);
    std::cout << "General Stall: slowing service" << std::endl;
}

void GeneralStall::setup()
{
	std::cout << "General stall setup" << std::endl;
	this->open();
}

void GeneralStall::shutdown()
{
	std::cout << "General stall shutdown" << std::endl;
	this->close();
}

void GeneralStall::vipArrival(int vipLevel)
{
	if (vipLevel >= 5) {
		std::cout << "[GeneralStall] Level " << vipLevel << " VIP arrived! Rolling out the red carpet and premium items!" << std::endl;
	} else {
		std::cout << "[GeneralStall] VIP arrived. Greeting them." << std::endl;
	}
}

