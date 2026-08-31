#ifndef TENT_H
#define TENT_H

#include "Composite.h"
#include "Area.h"

class Tent : public Composite
{
    private:
        bool weatherProtectionActive;
    public:
        Tent();
        bool isWeatherProtected() const;
        virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void setup() override;
        virtual void shutdown() override;
};

#endif
