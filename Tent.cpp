#include "Tent.h"
#include <iostream>

Tent::Tent() : weatherProtectionActive(false) {}
bool Tent::isWeatherProtected() const { 
    return weatherProtectionActive; 
}

void Tent::weatherAlert(int severity, const std::string& type){
    weatherProtectionActive = true;
    std::cout << "Tent: activating weather protection" << std::endl;
    this->setWeatherData(severity, type);
    this->Subject::weatherAlert();
}


void Tent::setup(){
    std::cout << "Tent: Opening" << std::endl;
    this->open();
    this->Subject::setup();
}

void Tent::shutdown(){
    std::cout << "Tent: Closing" << std::endl;
    this->close();
    this->Subject::shutdown();
}



