#ifndef CARDIAC_STALL_H
#define CARDIAC_STALL_H

#include "MedicalStall.h"
#include "Patient.h"
#include "Complaint.h"
#include "Subject.h"

class CardiacStall : public MedicalStall
{
	public:
		CardiacStall(int cap);
		void treatPatient(const Patient<MI>& patient) const;
};

#endif
