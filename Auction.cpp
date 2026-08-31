#include "Auction.h"
#include "Tent.h"
#include <iostream>

Auction::Auction() : paused(false) {}

void Auction::weatherAlert(int severity, const std::string& type){
    paused = true;
    std::cout << "Auction: PAUSED " << type << "[Severity " << severity << "/" << Subject::MaxSeverity << "]" << std::endl;
    this->setWeatherData(severity, type);
    this->Subject::weatherAlert();
}

void Auction::escapedBull(const std::string& location, int numBull){
    paused = true;
    std::cout << "Auction: Paused - Bulla escape at " << location << " ! (" << numBulls << " bulls loose!)" << std::endl;
    this->setBullEscape(location, numBulls);
    this->Subject::escapedBull();
}
