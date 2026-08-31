#include "CardiacStall.h"
#include <iostream>

CardiacStall::CardiacStall(int cap) : MedicalStall(cap) {}

void CardiacStall::treatPatient(const Patient<MI>& patient) const
{
	std::cout << patient.getName() << " complains of " << patient.getComplaint() << std::endl;
	std::cout << "Patient is receiving cardiac support" << std::endl;
}
