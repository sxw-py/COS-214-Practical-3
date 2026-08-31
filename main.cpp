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

	CattleStall cattle(3, 20);
	cattle.moo();

	MedicalArea medArea;
	medArea.addChild(new PulmonaryStall(8));
	medArea.addChild(new CardiacStall(4));
	medArea.open();
	std::cout << "Medical area open: " << medArea.reportStatus() << std::endl;
	std::cout << "Medical area capacity: " << medArea.getCapacity() << std::endl;

	Auction auction;
	Tent* tent = new Tent();
	auction.addChild(tent);
	MedicalArea* medicalArea = new MedicalArea();
	tent->addChild(medicalArea);
	CardiacStall* cs = new CardiacStall(3);
	medicalArea->addChild(cs);
	std::cout << "Auction capacity: " << auction.getCapacity() << std::endl;

	return 0;
}
