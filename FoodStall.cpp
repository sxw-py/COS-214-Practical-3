#include "FoodStall.h"

int FoodStall::unitCost() const
{
	return 30;
}

void FoodStall::weatherAlert(int severity, const std::string& type){
	std::cout << "Food stall : Closing - " << type << "(severity" << severity << "/" << Subject::MaxSeverity << ")" << std::endl;

	this ->foodSecured = true;
	this->close();
}


void FoodStall::escapedBull(const std::string& location, int numBulls){
	std::cout << "Food stall : Closing - Bull escape at " << location << "!" << std::endl;
	std::cout << "- Staff moved to safety"<< std::endl;
	std::cout << "- Food secured" << std::endl;

	this ->foodSecured = true;
	this->close();
}
