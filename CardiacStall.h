#ifndef CARDIAC_STALL_H
#define CARDIAC_STALL_H

#include "MedicalStall.h"
#include "Patient.h"
#include "Complaint.h"
#include "Subject.h"

class CardiacStall : public MedicalStall
{
	private:
		bool cardiacProtocolActive; 
	public:
		CardiacStall(int cap);
		bool isCardiacProtocolActive() const;
		void treatPatient(const Patient<MI>& patient) const;
		virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
		virtual void medicalEmergency(int severity, const std::string& injuryType) override;
		virtual void capacityAlert(int currentCount, int maxCapacity) override;
		virtual void setup() override;
		virtual void shutdown() override;
};	


#endif
