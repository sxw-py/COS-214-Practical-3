#include "MedicalStall.h"
#include <iostream>

MedicalStall::MedicalStall(int cap) : Stall(cap)
{
}

void MedicalStall::capacityAlert(Subject& subject)
{
	std::cout << "[MedicalStall] Received capacity alert! Preparing for incoming triage." << std::endl;
}

void MedicalStall::setup(Subject&)
{
	std::cout << "Medical stall setup" << std::endl;
	this->open();
}

void MedicalStall::shutdown(Subject&)
{
	std::cout << "Medical stall shutdown" << std::endl;
	this->close();
}

void MedicalStall::medicalEmergency(Subject&)
{
	std::cout << "Medical stall ready for emergency" << std::endl;
}
