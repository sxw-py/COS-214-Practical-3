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
		virtual void setup(Subject&) override;
		virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
};

#endif
