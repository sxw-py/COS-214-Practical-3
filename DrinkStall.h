#ifndef DRINK_STALL_H
#define DRINK_STALL_H

#include "GeneralStall.h"

class DrinkStall : public GeneralStall
{
	private:
		bool drinksSecured;
	public:
		DrinkStall(int cap);
		virtual int unitCost() const override;
		virtual void weatherAlert(int severity, const std::string& type) override;
		virtual void medicalEmergency(int severity, const std::string& injuryType) override;
        virtual void capacityAlert(int currentCount, int maxCapacity) override;
        virtual void setup() override;
        virtual void shutdown() override;
};

#endif
