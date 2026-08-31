#include "CardiacStall.h"
#include <iostream>

CardiacStall::CardiacStall(int cap) : MedicalStall(cap) {}

void CardiacStall::treatPatient(const Patient<MI>& patient) const
{
	std::cout << patient.getName() << " complains of " << patient.getComplaint() << std::endl;
	std::cout << "Patient is receiving cardiac support" << std::endl;
}

void CardiacStall::setup(Subject&)
{
	std::cout << "Cardiac stall ready" << std::endl;
}

void PulmonaryStall::weatherAlert(int severity, const std::string& type) {
	std::cout << "Cardiac Stall: remaining open - " << type << " (severity " << severity << "/" << Subject::MaxSeverity << ")" << std::endl;
	std::cout << "- Preparing for weather related cardiac issues" << std::endl;
}

void PulmonaryStall::escapedBull(const std::string& location, int numBulls){
	std::cout << "Cardiac Stall : Remaining operational - Bull escape at " << location << "!" << std::endl;
	std::cout << "- Defibrillator ready" << std::endl;
	std::cout << "- Expecting panic-induced heart issues" << std::endl;	
}


