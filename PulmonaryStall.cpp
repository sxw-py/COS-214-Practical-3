#include "PulmonaryStall.h"
#include <iostream>

PulmonaryStall::PulmonaryStall(int cap) : MedicalStall(cap) {}

void PulmonaryStall::treatPatient(const Patient<Cough>& patient) const
{
	std::cout << patient.getName() << " complains of " << patient.getComplaint() << std::endl;
	std::cout << "Patient is receiving pulmonary support" << std::endl;
}
