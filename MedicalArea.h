#ifndef MEDICAL_AREA_H
#define MEDICAL_AREA_H

#include "Area.h"
#include "Composite.h"
#include "MedicalStall.h"

class MedicalArea : public Area, public Composite<MedicalStall>
{
	public:
		virtual void open() override;
		virtual void close() override;
		virtual bool reportStatus() const override;
		virtual int getCapacity() const override;
};

#endif
