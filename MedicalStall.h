#ifndef MEDICAL_STALL_H
#define MEDICAL_STALL_H

#include "Stall.h"

class MedicalStall : public Stall
{
	public:
		MedicalStall(int cap);
		virtual void capacityAlert(Subject& subject) override;
		virtual void setup(Subject&) override;
		virtual void shutdown(Subject&) override;
		virtual void medicalEmergency(Subject&) override;
};

#endif
