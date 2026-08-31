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
	std::cout << std::endl;
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
