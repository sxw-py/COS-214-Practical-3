#include "GeneralArea.h"
#include <iostream>

void GeneralArea::weatherAlert(int severity, const std::string& type){
    std::cout << "General Area: Closing - " << type << "(Severity" << "/" << Subject::MaxSeverity << ")" << std::endl;

    this->close();
    this->setWeatherData(severity, type);
    this->Subject::weatherAlert();
}

void GeneralArea::escapedBull(const std::string& location, int numBulls){
    std::cout << "General Area: Closing all food stalls - Bull escape at " << location << "!" << std::endl;
    std::cout << "- Protecting staff and customers" << std::endl;
    std::cout << "- Securing all food" << std::endl;

    this->close();
    this->setBullEscape(location, numBulls);
    this->Subject::escapedBull();
}


void GeneralArea::medicalEmergency(int severity, const std::string& injuryType){
    std::cout << "General Area: Pausing operations - Medical emergency! (" << injuryType << ")" << std::endl;
    std::cout << " Clearing paths for medical team" << std::endl;
    this->close();
    this->setMedicalEmergency(severity, injuryType);
    this->Subject::medicalEmergency();
}

void GeneralArea::capacityAlert(int currentCount, int maxCapacity){
    std::cout << "General area: monitoring capacity - " << currentCount << "/" << maxCapacity << std::endl;
    this->setCapacityAlert(currentCount, maxCapacity);
    this->Subject::capacityAlert();
}

void GeneralArea::setup(){
    std::cout << "General Area: Opening" << std::endl;
    this->open();
    this->Subject::setup();
}

void GeneralArea::shutdown(){
    std::cout << "General Area: CLOSING" << std::endl;
    this->close();
    this->Subject::shutdown();
}

void GeneralArea::quarantine(int days){
    std::cout << "General area: quarantine for " << days << " days" << std::endl;
    this->close();
}

void GeneralArea::feedingTime(std::string foodType){
    std::cout << "General area: feeding time - " << foodType << std::endl;
}
