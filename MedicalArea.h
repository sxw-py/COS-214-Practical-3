#ifndef MEDICAL_AREA_H
#define MEDICAL_AREA_H

#include "Area.h"
#include "Composite.h"
#include "MedicalStall.h"

class MedicalArea : public Composite
{
    public:
        virtual void open() override;
        virtual void close() override;
        virtual bool reportStatus() const override;
        virtual int getCapacity() const override;
        virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void weatherAlert(const std::string& location, int numBulls) override
};

#endif
