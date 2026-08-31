#ifndef MEDICAL_STALL_H
#define MEDICAL_STALL_H

#include "Stall.h"

class MedicalStall : public Stall
{
	public:
		MedicalStall(int cap);
		virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
		virtual void medicalEmergency(int severity, const std::string& injuryType) override;
		virtual void capacityAlert(int currentCount, int maxCapacity) override;
		virtual void setup() override;
		virtual void shutdown() override;
};

#endif

