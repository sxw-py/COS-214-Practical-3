#include "Tent.h"
#include <iostream>

void Tent::weatherAlert(Subject& s){
    std::cout << "Tent: activating weather protection, severity" << s.getSeverity() << std::endl;
    this->setSeverity(s.getSeverity());   //
    this->Subject::weatherAlert();         //relay to attached Area observers
}