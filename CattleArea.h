#ifndef CATTLE_AREA_H
#define CATTLE_AREA_H

#include "Area.h"
#include "Composite.h"
#include "CattleStall.h"

class CattleArea : public Composite
{
    public:
        virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
        virtual void medicalEmergency(int severity, const std::string& injuryType) override;
        virtual void capacityAlert(int currentCount, int maxCapacity) override;
        virtual void setup() override;
        virtual void shutdown() override;
};

#endif
