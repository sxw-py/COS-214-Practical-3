#include "MedicalStall.h"
#include <iostream>

MedicalStall::MedicalStall(int cap) : Stall(cap)
{
}

void MedicalStall::capacityAlert(Subject& subject)
{
	std::cout << "[MedicalStall] Received capacity alert! Preparing for incoming triage." << std::endl;
}
