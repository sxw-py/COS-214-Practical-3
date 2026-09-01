#include "DrinkStall.h"
#include "Subject.h"
#include <iostream>

DrinkStall::DrinkStall(int cap) : GeneralStall(cap) {} 

int DrinkStall::unitCost() const
{
	return 10;
}

void DrinkStall::weatherAlert(int severity, const std::string& type){
	std::cout << "Drinks stall : Closing - " << type << "(severity" << severity << "/" << Subject::MaxSeverity << ")" << std::endl;

	this ->drinksSecured = true;
	this->close();
}


void DrinkStall::medicalEmergency(int severity, const std::string& injuryType){
    std::cout << "Drinks Stall: Pausing - Medical emergency! ("  << injuryType << ")" << std::endl;
    this->close();
}

void DrinkStall::capacityAlert(int currentCount, int maxCapacity){
    std::cout << " Drinks Stall: Monitoring capacity - " << currentCount << "/" << maxCapacity << std::endl;
}

void DrinkStall::setup(){
    std::cout << "Drinks Stall: Opening" << std::endl;
    this->drinksSecured = false;
    this->open();
}

void DrinkStall::shutdown(){
    std::cout << " Drinks Stall: Closing" << std::endl;
    this->drinksSecured = true;
    this->close();
}
