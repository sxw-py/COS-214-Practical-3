#include "Tent.h"
#include <iostream>

void Tent::weatherAlert(int severity, const std::string& type){
    std::cout << "Tent: Activating weather protection - " << type << "! [Severity" << "/" << Subject::MaxSeverity << "]" << std::endl;
    this->setWeatherData(severity, type);
    this->Subject::weatherAlert(); 
}

void Tent::escapedBull(const std::string& location, int numBulls) {
    std::cout << "Tent: Securing tent - Bull escape at " << location << "!" << std::endl;

    this->setBullEscape(location, numBulls);
    this->Subject::escapedBull();
}

