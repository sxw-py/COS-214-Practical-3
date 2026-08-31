#ifndef GENERAL_AREA_H
#define GENERAL_AREA_H

#include "Area.h"
#include "Composite.h"
#include "GeneralStall.h"

class GeneralArea : public Composite
{
    public:
        virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
};

#endif
