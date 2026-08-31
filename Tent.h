#ifndef TENT_H
#define TENT_H

#include "Composite.h"
#include "Area.h"

class Tent : public Composite
{
    public:
        virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
};

#endif
