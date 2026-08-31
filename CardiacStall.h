#ifndef CARDIAC_STALL_H
#define CARDIAC_STALL_H

#include "MedicalStall.h"
#include "Patient.h"
#include "Complaint.h"
#include "Subject.h"

class CardiacStall : public MedicalStall
{

	public:
		CardiacStall(int cattle, int cap);
		void treatPatient(const Patient<MI>& patient) const;
		virtual void setup(Subject&) override;
		virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
};	


#endif
