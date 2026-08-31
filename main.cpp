/**
 * @file main.cpp
 * @brief Main execution file for the Cattle Auction system.
 *
 * This file demonstrates the runtime behavior of the system, including
 * setting up the Composite trees, simulating runtime reorganizations,
 * and broadcasting Observer notifications for various emergencies and features.
 *
 * @mainpage Cattle Auction Documentation
 * 
 * Welcome to the Doxygen documentation for the Cattle Auction system!
 * 
 * ### Overview
 * This project models an agricultural show using various design patterns:
 * - **Composite Pattern:** Used to structure areas (like MedicalArea and CattleArea) and stalls in a tree hierarchy.
 * - **Observer Pattern:** Used to broadcast emergency events (like weather alerts or escaped bulls) to all connected stalls.
 * 
 * Navigate via the **Classes** or **Files** tabs at the top to explore the codebase.
 */
#include "headers.h"
#include "PulmonaryStall.h"
#include "CardiacStall.h"
#include "CattleStall.h"
#include "MedicalArea.h"
#include "Tent.h"
#include "Auction.h"
#include "GeneralArea.h"
#include "CattleArea.h"
#include "FoodStall.h"
#include "DrinkStall.h"
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
	
	Auction mainAuction;
	MedicalArea* medArea = new MedicalArea();
	CattleArea* cattleArea = new CattleArea();
	mainAuction.addChild(medArea);
	mainAuction.addChild(cattleArea);

	// We create a dynamically allocated stall because Composite takes ownership
	MedicalStall* rapidResponseTeam = new MedicalStall(5);
	
	// Add to Medical Area (Composite Tree) and register for notices (Observer)
	std::cout << "Adding Rapid Response Team to Medical Area..." << std::endl;
	medArea->addChild(rapidResponseTeam);
	medArea->attach(rapidResponseTeam);
	
	std::cout << "\n--- Emergency: Escaped Bull in Cattle Area! ---" << std::endl;
	mainAuction.escapedBull(); // Broadcasts to its observers (cascades)
	
	std::cout << "\n--- Runtime Reorganisation: Transferring Medical Team ---" << std::endl;
	std::cout << "1. Removing from Medical Area..." << std::endl;
	medArea->removeChild(rapidResponseTeam);
	medArea->detach(rapidResponseTeam);
	
	std::cout << "2. Reassigning to Cattle Area..." << std::endl;
	cattleArea->addChild(rapidResponseTeam);
	cattleArea->attach(rapidResponseTeam);
	
	std::cout << "\n--- Situation Update ---" << std::endl;
	cattleArea->capacityAlert(); // Now the rapid response team should receive this!

	std::cout << "\n--- Task 4.4: Original Features Demonstration ---" << std::endl;
	
	// Create a new Cattle Stall directly under cattleArea
	CattleStall* feedingStall = new CattleStall(20, 30);
	cattleArea->addChild(feedingStall);
	cattleArea->attach(feedingStall);
	
	std::cout << "\n[Broadcasting Feeding Time...]" << std::endl;
	cattleArea->feedingTime("premium alfalfa");
	
	std::cout << "\n[Broadcasting Quarantine...]" << std::endl;
	cattleArea->quarantine(14);
	
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


	std::cout << "\n\n=== TESTING RULES: GeneralArea + CattleArea additions ===" << std::endl;
	GeneralArea* genArea = new GeneralArea();
	CattleArea* cattleAreaFinal = new CattleArea();
	tent->addChild(genArea);
	tent->addChild(cattleAreaFinal);
	tent->attach(genArea);
	tent->attach(cattleAreaFinal);

	FoodStall* food = new FoodStall(15);
	DrinkStall* drink = new DrinkStall(15);
	genArea->addChild(food);
	genArea->addChild(drink);
	genArea->attach(food);
	genArea->attach(drink);

	CattleStall* cattle = new CattleStall(15, 20);
	cattleAreaFinal->addChild(cattle);
	cattleAreaFinal->attach(cattle);

	std::cout << "\n=== RULE 1: WEATHER ALERT (severity 8) ===" << std::endl;
	auction.setWeatherData(8, "storm");
	std::cout << "Auction paused: " << auction.isPaused() << std::endl;
	std::cout << "Tent weather-protected: " << tent->isWeatherProtected() << std::endl;
	std::cout << "Food stall open (expect 0): " << food->reportStatus() << std::endl;
	std::cout << "Medical area open (expect 1): " << medicalArea->reportStatus() << std::endl;

	std::cout << "\n=== RULE 2: ESCAPED BULL ===" << std::endl;
	cattleAreaFinal->setBullEscape("North Pen", 2);
	std::cout << "Auction paused: " << auction.isPaused() << std::endl;
	std::cout << "Food stall open (expect 0): " << food->reportStatus() << std::endl;
	std::cout << "Medical area prepared: " << medicalArea->isPreparedForInjuries() << std::endl;

	std::cout << "\n=== RULE 3: MEDICAL EMERGENCY ===" << std::endl;
	auction.setMedicalEmergency(6, "cardiac arrest");
	std::cout << "Cardiac protocol active: " << cs->isCardiacProtocolActive() << std::endl;
	std::cout << "Cattle stall open (expect unchanged/1): " << cattle->reportStatus() << std::endl;

	std::cout << "\n=== RULE 4: CAPACITY ALERT ===" << std::endl;
	auction.setCapacityAlert(95, 100);
	std::cout << "Food queue managed: " << food->isQueueManaged() << std::endl;
	std::cout << "Cattle access limited: " << cattle->isAccessLimited() << std::endl;

	std::cout << "\n=== RUNTIME REORGANISATION: cattle -> genArea ===" << std::endl;
	cattleAreaFinal->removeChild(cattle);
	cattleAreaFinal->detach(cattle);
	genArea->addChild(cattle);
	genArea->attach(cattle);
	std::cout << "GeneralArea capacity now: " << genArea->getCapacity() << std::endl;

	std::cout << "\n=== SHUTDOWN ===" << std::endl;
	auction.shutdown();
	std::cout << "Auction closed: " << !auction.reportStatus() << std::endl;

	return 0;
}
