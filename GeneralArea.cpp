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
