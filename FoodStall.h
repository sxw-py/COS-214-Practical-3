#ifndef FOOD_STALL_H
#define FOOD_STALL_H

#include "GeneralStall.h"

class FoodStall : public GeneralStall
{
	private:
		bool foodSecured;
		bool queueManaged;
	public:
		FoodStall(int cap);
		bool isQueueManaged() const;
		virtual int unitCost() const override;
		virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
		virtual void medicalEmergency(int severity, const std::string& injuryType) override;
        virtual void capacityAlert(int currentCount, int maxCapacity) override;
        virtual void setup() override;
        virtual void shutdown() override;
};

#endif
