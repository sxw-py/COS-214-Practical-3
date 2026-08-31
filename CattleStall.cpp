#include "CattleStall.h"
#include <iostream>

CattleStall::CattleStall(int numCattle, int cap) : Stall(cap), numCattle(numCattle) {}

int CattleStall::getNumCattle()
{
	return this->numCattle;
}

void CattleStall::moo()
{
	for (int i = 0; i < numCattle; i++)
		std::cout << "moo ";
}

void CattleStall::setup(Subject&)
{
	this->numCattle = 0;
	std::cout << "Cattle stall setup" << std::endl;
}

void CattleStall::shutdown(Subject&)
{
	this->numCattle = 0;
	std::cout << "Cattle stall shutdown" << std::endl;
}

void CattleStall::escapedBull(Subject&)
{
	this->numCattle--;
	std::cout << "Looking for escaped bull" << std::endl;
}

void CattleStall::capacityAlert(Subject&)
{
	if (this->numCattle > this->capacity)
	{
		std::cout << "Too many cattle!" << std::endl;
		this->close();
	}
	else
		std::cout << "No capacity problem!" << std::endl;
}

void CattleStall::quarantine(int days)
{
	std::cout << "[CattleStall] Quarantine ordered for " << days << " days! Locking down stall." << std::endl;
	this->close();
}

void CattleStall::feedingTime(std::string foodType)
{
	std::cout << "[CattleStall] Troughs opened! " << this->numCattle << " cows are eating " << foodType << "." << std::endl;
}
