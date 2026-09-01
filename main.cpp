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
	Auction auction;
	Tent* tent = new Tent();
	MedicalArea* medicalArea = new MedicalArea();
	CardiacStall* cs = new CardiacStall(3);
	medicalArea->attach(cs);
	tent->attach(medicalArea);
	auction.attach(tent);

	auction.medicalEmergency(3, "Heart palpitations");
}
