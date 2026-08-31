#include "DrinkStall.h"

int DrinkStall::unitCost() const
{
	return 10;
}

void FoodStall::weatherAlert(int severity, const std::string& type){
	std::cout << "Drinks stall : Closing - " << type << "(severity" << severity << "/" << Subject::MaxSeverity << ")" << std::endl;

	this ->drinksSecured = true;
	this->close();
}


void FoodStall::escapedBull(const std::string& location, int numBulls){
	std::cout << "Drink stall : Closing - Bull escape at " << location << "!" << std::endl;
	std::cout << "- Staff moved to safety"<< std::endl;
	std::cout << "- Food secured" << std::endl;

	this ->drinksSecured = true;
	this->close();
}
