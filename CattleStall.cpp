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

void CattleStall::weatherAlert(int severity, const std::string& type){
	std::cout << "Cattle Stall: Weather alert - " << type << "[Severity" << severity<< "/" << Subject::MaxSeverity << "]" << std::endl;

	if (severity >= Subject::MoveThreshold){
		this->isSheltered = true;
		this->close();
		std::cout << "Moving " << numCattle << " cattle to shelter!" << std::endl;
	} else {
		std::cout << "Monitoring " << numCattle << " cattle (below threshold)" << std::endl;
	}
}

void CattleStall::escapedBull(const std::string& location, int numBulls){
	std::cout << "Bull Escape at " << location << "!" << numBulls << "bulls loose!" << std::endl;
	std::cout << numCattle << " cattle panicking !" << std::endl;

	//Moo loudly to alert others (typical cow behaviour)
	for (int i=0; i<numCattle; i++){
		std::cout << "MOO!";
	}
	std::cout << std::endl;

	//close for safety
	this->close();
	tsd::cout << "Cattle stall closed for safety !" << std::endl;
}
