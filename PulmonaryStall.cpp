#include "PulmonaryStall.h"
#include <iostream>

PulmonaryStall::PulmonaryStall(int cap) : MedicalStall(cap) {}

void PulmonaryStall::treatPatient(const Patient<Cough>& patient) const
{
	std::cout << patient.getName() << " complains of " << patient.getComplaint() << std::endl;
	std::cout << "Patient is receiving pulmonary support" << std::endl;
}

void PulmonaryStall::setup(Subject&)
{
	std::cout << "Pulmonary stall ready" << std::endl;
}

void PulmonaryStall::weatherAlert(int severity, const std::string& type) {
	std::cout << "Pulmonary Stall: remaining open - " << type << " (severity " << severity << "/" << Subject::MaxSeverity << ")" << std::endl;
	std::cout << "- Preparing for weather related respitory issues" << std::endl;
}

void PulmonaryStall::escapedBull(const std::string& location, int numBulls){
	std::cout << "Pulmonary Stall : Remaining operational - Bull escape at " << location << "!" << std::endl;
	std::cout << "- Treating panic attacks and hyperventilation" << std::endl;
	std::cout << "- Oxygen masks ready for anxious patients" << std::endl;	
}
