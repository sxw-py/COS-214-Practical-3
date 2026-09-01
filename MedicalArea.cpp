#include "MedicalArea.h"
#include "Subject.h"
#include <iostream>

MedicalArea::MedicalArea() : preparedForInjuries(false) , bedsPrepared(false) {}


bool MedicalArea::isPreparedForInjuries() const { 
    return preparedForInjuries; 
}  

bool MedicalArea::isBedsPrepared() const { 
    return bedsPrepared; 
} 


void MedicalArea::open(){
    Composite::open();
}

void MedicalArea::close(){
    Composite::close();
}

bool MedicalArea::reportStatus() const{
    return Composite::reportStatus();
}

int MedicalArea::getCapacity() const{
    return Composite::getCapacity();
}

void MedicalArea::weatherAlert(int severity, const std::string& type){
    std::cout << "Medical Area: Remaining Open - " << type << "! [Severity " << severity << "/" << Subject::MaxSeverity << std::endl;
    this->setWeatherData(severity, type);
    this->Subject::weatherAlert();
}

void MedicalArea::escapedBull(const std::string& location, int numBulls){
    preparedForInjuries = true;
    std::cout << "MedicalArea: preparing for injuries" << std::endl;
    this->setBullEscape(location, numBulls);
    this->Subject::escapedBull();
}


void MedicalArea::capacityAlert(int currentCount, int maxCapacity){
    bedsPrepared = true;
    std::cout << "MedicalArea: preparing extra beds" << std::endl;
    this->setCapacityAlert(currentCount, maxCapacity);
    this->Subject::capacityAlert();
}

void MedicalArea::setup(){
    std::cout << "MedicalArea: Activating emergency protocols" << std::endl;
    this->emergencyProtocolActive = true;
    this->open();
    this->Subject::setup();
}

void MedicalArea::shutdown(){
    std::cout << "MedicalArea: Closing" << std::endl;
    this->emergencyProtocolActive = false;
    this->close();
    this->Subject::shutdown();
}