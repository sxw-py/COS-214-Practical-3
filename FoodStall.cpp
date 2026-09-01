#include "FoodStall.h"
#include "Subject.h"
#include <iostream>

FoodStall::FoodStall(int cap) : GeneralStall(cap), foodSecured(false), queueManaged(false) {}

bool FoodStall::isQueueManaged() const { 
	return this->queueManaged; 
}

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

void FoodStall::medicalEmergency(int severity, const std::string& injuryType){
    std::cout << "Food stall : Pausing - Medical emergency! (" << injuryType << ")" << std::endl;
    std::cout << "  Clearing paths for medical team" << std::endl;
    this->close();
}

void FoodStall::capacityAlert(int currentCount, int maxCapacity){
    queueManaged = true;
    std::cout << "Food Stall: managing queue" << std::endl;
    // stays open
}

void FoodStall::setup(){
    std::cout << "Food stall : Opening" << std::endl;
    this->foodSecured = false;
    this->open();
}

void FoodStall::shutdown(){
    std::cout << "Food stall : Closing" << std::endl;
    this->foodSecured = true;
    this->close();
}


