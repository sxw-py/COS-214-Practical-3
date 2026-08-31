#include "MedicalStall.h"
#include <iostream>

MedicalStall::MedicalStall(int cap) : Stall(cap)
{
}

void MedicalStall::setup()
{
	std::cout << "Medical stall setup" << std::endl;
	this->open();
}

void MedicalStall::shutdown()
{
	std::cout << "Medical stall shutdown" << std::endl;
	this->close();
}

void MedicalStall::medicalEmergency(int severity, const std::string& injuryType)
{
    std::cout << "Medical stall ready for emergency - " << injuryType << " (severity " << severity << ")" << std::endl;
}

void MedicalStall::capacityAlert(int currentCount, int maxCapacity)
{
    std::cout << "Medical stall received capacity alert - " << currentCount << "/" << maxCapacity << std::endl;
}

void MedicalStall::weatherAlert(int severity, const std::string& type)
{
    std::cout << "Medical stall remaining open during weather - " << type << " (severity " << severity << ")" << std::endl;
}


void MedicalStall::escapedBull(const std::string& location, int numBulls)
{
    std::cout << "Medical stall preparing for bull escape injuries at " << location << std::endl;
}
