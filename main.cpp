#include "headers.h"
#include "PulmonaryStall.h"
#include "CardiacStall.h"
#include "CattleStall.h"
#include "MedicalArea.h"
#include "Tent.h"
#include "Auction.h"
#include <iostream>

int main()
{
	PulmonaryStall pulm(10);
	CardiacStall card(5);
	Patient<Cough> p1("Alice");
	Patient<MI> p2("Bob");
	pulm.treatPatient(p1);
	card.treatPatient(p2);

	std::cout << "--- Initial Setup ---" << std::endl;
	MedicalArea medArea;
	CattleArea cattleArea;

	// We create a dynamically allocated stall because Composite takes ownership
	MedicalStall* rapidResponseTeam = new MedicalStall(5);
	
	// Add to Medical Area (Composite Tree) and register for notices (Observer)
	std::cout << "Adding Rapid Response Team to Medical Area..." << std::endl;
	medArea.addChild(rapidResponseTeam);
	medArea.attach(rapidResponseTeam);
	
	std::cout << "\n--- Emergency: Escaped Bull in Cattle Area! ---" << std::endl;
	cattleArea.escapedBull(); // Broadcasts to its observers (currently none)
	
	std::cout << "\n--- Runtime Reorganisation: Transferring Medical Team ---" << std::endl;
	std::cout << "1. Removing from Medical Area..." << std::endl;
	medArea.removeChild(rapidResponseTeam);
	medArea.detach(rapidResponseTeam);
	
	std::cout << "2. Reassigning to Cattle Area..." << std::endl;
	cattleArea.addChild(rapidResponseTeam);
	cattleArea.attach(rapidResponseTeam);
	
	std::cout << "\n--- Situation Update ---" << std::endl;
	cattleArea.capacityAlert(); // Now the rapid response team should receive this!

	return 0;
}
