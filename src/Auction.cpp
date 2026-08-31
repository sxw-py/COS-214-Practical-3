#include "Auction.h"
#include "Tent.h"
#include <iostream>

Auction::Auction() : paused(false) {}

void Auction::weatherAlert(Subject& s){
    paused = true;
    std::cout << "Auction: pausing, severity " << s.getSeverity() << std::endl;
    this->setSeverity(s.getSeverity());
    this->Subject::weatherAlert();       //relay to attached Tent observers
}