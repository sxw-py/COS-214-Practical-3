#include "Auction.h"
#include "Tent.h"
#include <iostream>

Auction::Auction() : paused(false) , pendingBids(0) {}

bool Auction::isPaused() const { 
    return paused; 
}

void Auction::weatherAlert(int severity, const std::string& type){
    paused = true;
    std::cout << "Auction: Paused " << type << "[Severity " << severity << "/" << Subject::MaxSeverity << "]" << std::endl;
    this->setWeatherData(severity, type);
    this->Subject::weatherAlert();
}

void Auction::escapedBull(const std::string& location, int numBull){
    paused = true;
    std::cout << "Auction: Paused - Bulls escape at " << location << " ! (" << numBulls << " bulls loose!)" << std::endl;
    this->setBullEscape(location, numBulls);
    this->Subject::escapedBull();
}

void Auction::medicalEmergency(int severity, const std::string& injuryType){
    paused = true;
    std::cout << "Auction: paused for medical access" << std::endl;
    this->setMedicalEmergency(severity, injuryType);
    this->Subject::medicalEmergency();
}

void Auction::capacityAlert(int currentCount, int maxCapacity){
    paused = true;
    std::cout << "Auction: pausing new entries" << std::endl;
    this->setCapacityAlert(currentCount, maxCapacity);
    this->Subject::capacityAlert();
}

void Auction::setup(){
   std::cout << "Auction: Opening for business " << std::endl;
   this->paused = false;
   this->open();
   this->Subject::setup(); 
}

void Auction::shutdown(){
    std::cout << "Auction: Shutting down - Completing " << pendingBids << " pending bids" << std::endl;
    this->pendingBids = 0;
    this->paused = true;
    this->close();
    this->Subject::shutdown(); 
}
