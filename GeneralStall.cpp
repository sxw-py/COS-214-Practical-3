#include "GeneralStall.h"

void GeneralStall::buyItem()
{
	revenue += unitCost();
}

int GeneralStall::getRevenue()
{
	return this->revenue;
}

void FoodStall::weatherAlert(int severity, const std::string& type){
	std::cout << "General stall : Closing - " << type << "(severity" << severity << "/" << Subject::MaxSeverity << ")" << std::endl;

	this->close();
}


void FoodStall::escapedBull(const std::string& location, int numBulls){
	std::cout << "Food stall : Closing - Bull escape at " << location << "!" << std::endl;
	this->close();
