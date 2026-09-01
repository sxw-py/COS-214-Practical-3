#ifndef CATTLE_AREA_H
#define CATTLE_AREA_H

#include "Area.h"
#include "Composite.h"
#include "CattleStall.h"


/**
 * @class CattleArea
 * @brief A composite representing the cattle area of the event.
 * 
 * The CattleArea contains CattleStalls and manages cattle-related
 * operations and emergency responses.
 */
class CattleArea : public Composite
{
    public:
        /**
         * @brief Reacts to a weather alert by closing the area.
         * @param severity The severity level (1-10).
         * @param type The type of weather.
         */
        virtual void weatherAlert(int severity, const std::string& type) override;

        /**
         * @brief Reacts to a bull escape by closing the area.
         * @param location The location where the bull escaped.
         * @param numBulls The number of bulls escaped.
         */
        virtual void escapedBull(const std::string& location, int numBulls) override;

        /**
         * @brief Reacts to a medical emergency by monitoring.
         * @param severity The severity level.
         * @param injuryType The type of injury.
         */
        virtual void medicalEmergency(int severity, const std::string& injuryType) override;

        /**
         * @brief Reacts to a capacity alert by limiting access.
         * @param currentCount The current number of people.
         * @param maxCapacity The maximum capacity.
         */
        virtual void capacityAlert(int currentCount, int maxCapacity) override;

        /**
         * @brief Opens the cattle area.
         */
        virtual void setup() override;

        /**
         * @brief Closes the cattle area.
         */
        virtual void shutdown() override;
};

#endif
