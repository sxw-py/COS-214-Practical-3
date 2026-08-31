#include "MedicalArea.h"

void MedicalArea::open()
{
	Composite<MedicalStall>::open();
}

void MedicalArea::close()
{
	Composite<MedicalStall>::close();
}

bool MedicalArea::reportStatus() const
{
	return Composite<MedicalStall>::reportStatus();
}

int MedicalArea::getCapacity() const
{
	return Composite<MedicalStall>::getCapacity();
}
