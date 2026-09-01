#ifndef GENERAL_AREA_H
#define GENERAL_AREA_H

#include "Composite.h"
#include "GeneralStall.h"

class GeneralArea : public Composite
{
    public:
        virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
        virtual void medicalEmergency(int severity, const std::string& injuryType) override;
        virtual void capacityAlert(int currentCount, int maxCapacity) override;
        virtual void setup() override;
        virtual void shutdown() override;
		virtual void quarantine(int days) override;
		virtual void feedingTime(std::string foodType) override;

};

#endif
