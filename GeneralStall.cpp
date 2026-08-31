#include <iostream>
#include "GeneralStall.h"

void GeneralStall::buyItem()
{
	if (this->reportStatus())
		revenue += unitCost();
}

int GeneralStall::getRevenue()
{
	return this->revenue;
}

void GeneralStall::setup(Subject&)
{
	std::cout << "General stall setup" << std::endl;
	this->open();
}

void GeneralStall::shutdown(Subject&)
{
	std::cout << "General stall shutdown" << std::endl;
	this->close();
}

void GeneralStall::weatherAlert(Subject&)
{
	std::cout << "Everything is packed away due to weather" << std::endl;
}

void GeneralStall::vipArrival(int vipLevel)
{
	if (vipLevel >= 5) {
		std::cout << "[GeneralStall] Level " << vipLevel << " VIP arrived! Rolling out the red carpet and premium items!" << std::endl;
	} else {
		std::cout << "[GeneralStall] VIP arrived. Greeting them." << std::endl;
	}
}
