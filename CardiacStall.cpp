#include "CardiacStall.h"
#include <iostream>

CardiacStall::CardiacStall(int cap) : MedicalStall(cap) {}


bool CardiacStall::isCardiacProtocolActive() const { 
	return this->cardiacProtocolActive; 
} 


void CardiacStall::treatPatient(const Patient<MI>& patient) const
{
	std::cout << patient.getName() << " complains of " << patient.getComplaint() << std::endl;
	std::cout << "Patient is receiving cardiac support" << std::endl;
}


void CardiacStall::weatherAlert(int severity, const std::string& type) {
	std::cout << "Cardiac Stall: remaining open - " << type << " (severity " << severity << "/" << Subject::MaxSeverity << ")" << std::endl;
	std::cout << "- Preparing for weather related cardiac issues" << std::endl;
}

void CardiacStall::escapedBull(const std::string& location, int numBulls){
	std::cout << "Cardiac Stall : Remaining operational - Bull escape at " << location << "!" << std::endl;
	std::cout << "- Defibrillator ready" << std::endl;
	std::cout << "- Expecting panic-induced heart issues" << std::endl;	
}

void CardiacStall::medicalEmergency(int severity, const std::string& injuryType){
    cardiacProtocolActive = true;
    std::cout << "Cardiac Stall: treating cardiac cases" << std::endl;
}


void CardiacStall::capacityAlert(int currentCount, int maxCapacity){
    std::cout << "Cardiac Stall: Preparing for influx - " << currentCount << "/" << maxCapacity << std::endl;
    std::cout << "  - Extra cardiac monitors ready" << std::endl;
}

void CardiacStall::setup(){
    std::cout << " Cardiac Stall: Opening" << std::endl;
    this->open();
}

void CardiacStall::shutdown(){
    std::cout << "Cardiac Stall: Closing" << std::endl;
    this->close();
}
