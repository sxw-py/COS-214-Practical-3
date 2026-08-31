#include "PulmonaryStall.h"
#include <iostream>

PulmonaryStall::PulmonaryStall(int cap) : MedicalStall(cap) {}

void PulmonaryStall::treatPatient(const Patient<Cough>& patient) const
{
	std::cout << patient.getName() << " complains of " << patient.getComplaint() << std::endl;
	std::cout << "Patient is receiving pulmonary support" << std::endl;
}

void PulmonaryStall::setup()
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

void PulmonaryStall::medicalEmergency(int severity, const std::string& injuryType){
	std::cout << "Pulmonary stall: treating respiratory cases - " << injuryType << " (severity " << severity << ")" << std::endl;
    std::cout << "  Ventilators activated" << std::endl;
    std::cout << "  Respiratory team deployed" << std::endl;
    this->emergencyProtocolActive = true;
}

void PulmonaryStall::capacityAlert(int currentCount, int maxCapacity){
    std::cout << "Pulmonary stall: preparing for influx - " << currentCount << "/" << maxCapacity << std::endl;
    std::cout << "  Extra oxygen tanks prepared" << std::endl;
}


void PulmonaryStall::shutdown(){
    std::cout << "Pulmonary stall: closing" << std::endl;
    this->emergencyProtocolActive = false;
    this->close();
}

