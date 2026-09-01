#ifndef MEDICAL_AREA_H
#define MEDICAL_AREA_H

#include "Composite.h"
#include "MedicalStall.h"

class MedicalArea : public Composite
{
    private:
        bool emergencyProtocolActive;
        bool preparedForInjuries;
        bool bedsPrepared;
    public:
        MedicalArea();
        bool isPreparedForInjuries() const;
        bool isBedsPrepared() const;
        virtual void open() override;
        virtual void close() override;
        virtual bool reportStatus() const override;
        virtual int getCapacity() const override;
        virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
        virtual void capacityAlert(int currentCount, int maxCapacity) override;
        virtual void setup() override;
        virtual void shutdown() override;
};

#endif
