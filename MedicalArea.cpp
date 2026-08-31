#include "MedicalArea.h"

void MedicalArea::open(){
    Composite<MedicalStall>::open();
}

void MedicalArea::close(){
    Composite<MedicalStall>::close();
}

void MedicalArea::reportStatus(){
    Composite<MedicalStall>::reportStatus();
}

void MedicalArea::getCapacity(){
    Composite<MedicalStall>::getCapacity();
}

void MedicalArea::weatherAlert(int severity, const std::string& type){
    std::cout << "Medical Area: Remaiing Open - " << type << "! [Severity " << severity << << "/" << Subject::MaxSeverity << std::endl;
    this->setWeatherData(severity, type);
    this->Subject::weatherAlert();
}

void MedicalArea::weatherAlert(const std::string& location, int numBulls){
    std::cout << "Medical Area: Preparing for injuries from bull escaped at " << location << "!" << std::endl;
    std::cout << "Trauma team on standby. Expecting injuries from " << numBulls << " loose bulls" << std::endl;

    this->setBullEscape(location, numBulls);
    this->Subject::escapedBull();
}
