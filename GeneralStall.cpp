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
