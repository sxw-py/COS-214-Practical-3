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
