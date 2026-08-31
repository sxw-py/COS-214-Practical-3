#ifndef PULMONARY_STALL_H
#define PULMONARY_STALL_H

#include "MedicalStall.h"
#include "Patient.h"
#include "Complaint.h"
#include "Subject.h"

class PulmonaryStall : public MedicalStall
{
	public:
		PulmonaryStall(int cap);
		void treatPatient(const Patient<Cough>& patient) const;
		virtual void setup(Subject&) override;
};

#endif
