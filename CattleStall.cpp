#include "CattleStall.h"
#include "Subject.h"
#include <iostream>

CattleStall::CattleStall(int numCattle, int cap) : Stall(cap), numCattle(numCattle) {}

bool CattleStall::isAccessLimited() const { 
	return this->accessLimited; 
}

int CattleStall::getNumCattle()
{
	return this->numCattle;
}

void CattleStall::moo()
{
	for (int i = 0; i < numCattle; i++)
		std::cout << "moo ";
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
	std::cout << "Cattle stall closed for safety !" << std::endl;
}


void CattleStall::medicalEmergency(int severity, const std::string& injuryType){
    std::cout << "Cattle Stall: Remaining Operational - Medical emergency! (" << injuryType << ")" << std::endl;
    std::cout << "  Animals unaffected, continuing operations" << std::endl;
    // Stay open
}

void CattleStall::capacityAlert(int currentCount, int maxCapacity){
    accessLimited = (currentCount >= maxCapacity);
    std::cout << "Cattle Stall: limiting access" << std::endl;
}

void CattleStall::setup(){
    std::cout << "Cattle Stall: Opening" << std::endl;
    this->open();
    this->isSheltered = false;
}

void CattleStall::shutdown(){
    std::cout << "Cattle Stall: Shutting Down - Moving " << numCattle << " cattle to transport" << std::endl;
    this->close();
    this->isSheltered = false;
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

