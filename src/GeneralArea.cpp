#include "GeneralArea.h"

void GeneralArea::escapedBull(Subject& s){
    this->setSeverity(s.getSeverity());
    this->Subject::escapedBull();  //each child stall decided how to react
}