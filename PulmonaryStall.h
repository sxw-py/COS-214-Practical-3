#ifndef PULMONARY_STALL_H
#define PULMONARY_STALL_H

#include "MedicalStall.h"
#include "Patient.h"
#include "Complaint.h"
#include "Subject.h"

class PulmonaryStall : public MedicalStall
{
	private:
		bool emergencyProtocolActive;
	public:
		PulmonaryStall(int cap);
		void treatPatient(const Patient<Cough>& patient) const;
		virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
		virtual void medicalEmergency(int severity, const std::string& injuryType) override;
		virtual void capacityAlert(int currentCount, int maxCapacity) override;
		virtual void setup() override;
		virtual void shutdown() override;
};

#endif
