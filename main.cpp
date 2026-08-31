/**
 * @file main.cpp
 * @brief Main execution file for the Agricultural Event Coordination system.
 *
 * This file demonstrates the runtime behavior of the system, including
 * setting up the Composite trees, simulating runtime reorganizations,
 * and broadcasting Observer notifications for various emergencies and features.
 */
#include "headers.h"
#include "PulmonaryStall.h"
#include "CardiacStall.h"
#include "CattleStall.h"
#include "MedicalArea.h"
#include "Tent.h"
#include "Auction.h"
#include <iostream>

/**
 * @brief Entry point for the application.
 * 
 * Simulates various practical requirements including the medical stall usage,
 * composite tree setups, runtime reorganizations, and observer pattern broadcasts.
 * 
 * @return Exit status (0 for success).
 */
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

	std::cout << "\n--- Task 4.4: Original Features Demonstration ---" << std::endl;
	
	// Create a new Cattle Stall directly under cattleArea
	CattleStall* feedingStall = new CattleStall(20, 30);
	cattleArea.addChild(feedingStall);
	cattleArea.attach(feedingStall);
	
	std::cout << "\n[Broadcasting Feeding Time...]" << std::endl;
	cattleArea.feedingTime("premium alfalfa");
	
	std::cout << "\n[Broadcasting Quarantine...]" << std::endl;
	cattleArea.quarantine(14);
	
	// Note: We would instantiate FoodStall to test vipArrival, but it currently lacks constructors.
	// However, the function vipArrival is fully implemented in GeneralStall!

	std::cout << "\n\n=== TASK 8:SCENARIO ===" << std::endl;
	Auction auction;
	Tent* tent = new Tent();
	auction.addChild(tent);
	MedicalArea* medicalArea = new MedicalArea();
	tent->addChild(medicalArea);
	PulmonaryStall* ps = new PulmonaryStall(3);
	CardiacStall* cs = new CardiacStall(3);
	medicalArea->addChild(ps);
	medicalArea->addChild(cs);
	std::cout << auction.reportStatus() << std::endl;
	auction.open();
	std::cout << auction.reportStatus() << std::endl;
	std::cout << auction.getCapacity() << std::endl;
	Patient<Cough> p("greg");
	Patient<MI> g("gonge");
	ps->treatPatient(p);
	cs->treatPatient(g);
	auction.attach(tent);
	tent->attach(medicalArea);
	medicalArea->attach(ps);
	medicalArea->attach(cs);
	auction.setup();
	std::cout << "Auction capacity: " << auction.getCapacity() << std::endl;

	return 0;
}
