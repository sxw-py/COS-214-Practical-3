#include "Headers.h"

int main()
{
	Auction auction;
	Tent* tent = new Tent();
	auction.addChild(tent);
	MedicalArea* medicalArea = new MedicalArea();
	tent->addChild(medicalArea);
	PulmonaryStall* ps = new PulmonaryStall(3);
	CardiacStall* cs = new CardiacStall(3);
	medicalArea->addChild(ps);
	medicalArea->addChild(cs);
	cout << auction.reportStatus() << endl;
	auction.open();
	cout << auction.reportStatus() << endl;
	cout << auction.getCapacity() << endl;
	Patient<Cough> p("greg");
	Patient<MI> g("gonge");
	ps->treatPatient(p);
	cs->treatPatient(g);
	auction.attach(tent);
	tent->attach(medicalArea);
	medicalArea->attach(ps);
	medicalArea->attach(cs);
	auction.setup();

}
