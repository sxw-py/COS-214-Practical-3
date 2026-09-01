#ifndef MEDICAL_AREA_H
#define MEDICAL_AREA_H

#include "Area.h"
#include "Composite.h"
#include "MedicalStall.h"


/**
 * @class MedicalArea
 * @brief A composite representing the medical area of the event.
 * 
 * The MedicalArea contains MedicalStalls and remains operational
 * during emergencies. It prepares for injuries and patient influx.
 */
class MedicalArea : public Composite
{
    private:
        bool emergencyProtocolActive;
        bool preparedForInjuries;
        bool bedsPrepared;
    public:
        /**
         * @brief Constructs a MedicalArea object.
         */
        MedicalArea();

        /**
         * @brief Checks if the area is prepared for injuries.
         * @return true if prepared, false otherwise.
         */
        bool isPreparedForInjuries() const;

        /**
         * @brief Checks if extra beds have been prepared.
         * @return true if prepared, false otherwise.
         */
        bool isBedsPrepared() const;

        /**
         * @brief Opens the medical area.
         */
        virtual void open() override;

        /**
         * @brief Closes the medical area.
         */
        virtual void close() override;

        /**
         * @brief Reports if the medical area is open.
         * @return true if open, false if closed.
         */
        virtual bool reportStatus() const override;

        /**
         * @brief Gets the total capacity of the medical area.
         * @return The sum of all child capacities.
         */
        virtual int getCapacity() const override;

        /**
         * @brief Reacts to a weather alert by remaining open.
         * @param severity The severity level (1-10).
         * @param type The type of weather.
         */
        virtual void weatherAlert(int severity, const std::string& type) override;

        /**
         * @brief Reacts to a bull escape by preparing for injuries.
         * @param location The location where the bull escaped.
         * @param numBulls The number of bulls escaped.
         */
        virtual void escapedBull(const std::string& location, int numBulls) override;

        /**
         * @brief Reacts to a capacity alert by preparing more beds.
         * @param currentCount The current number of people.
         * @param maxCapacity The maximum capacity.
         */
        virtual void capacityAlert(int currentCount, int maxCapacity) override;

        /**
         * @brief Activates emergency protocols and opens the area.
         */
        virtual void setup() override;

        /**
         * @brief Deactivates emergency protocols and closes the area.
         */
        virtual void shutdown() override;
};

#endif
