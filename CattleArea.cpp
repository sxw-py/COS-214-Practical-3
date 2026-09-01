#include "CattleArea.h"
#include <iostream>

void CattleArea::weatherAlert(int severity, const std::string& type){
    std::cout << "Cattle area: Closing - " << type << " (severity " << severity << "/" << Subject::MaxSeverity << ")" << std::endl;
    this->close();
    this->setWeatherData(severity, type);
    this->Subject::weatherAlert();
}

void CattleArea::escapedBull(const std::string& location, int numBulls){
    std::cout << "Cattle area: Closing - Bull escape at " << location << "!" << std::endl;
    this->close();
    this->setBullEscape(location, numBulls);
    this->Subject::escapedBull();
}

void CattleArea::medicalEmergency(int severity, const std::string& injuryType){
    std::cout << "Cattle area: Monitoring - Medical emergency!" << std::endl;
    this->setMedicalEmergency(severity, injuryType);
    this->Subject::medicalEmergency();
}

void CattleArea::capacityAlert(int currentCount, int maxCapacity){
    std::cout << "Cattle area: Limiting access - " << currentCount << "/" << maxCapacity << std::endl;
    this->setCapacityAlert(currentCount, maxCapacity);
    this->Subject::capacityAlert();
}

void CattleArea::setup(){
    std::cout << "Cattle area: Opening" << std::endl;
    this->open();
    this->Subject::setup();
}

void CattleArea::shutdown(){
    std::cout << "Cattle area: Closing" << std::endl;
    this->close();
    this->Subject::shutdown();
}
