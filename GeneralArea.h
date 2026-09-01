#ifndef GENERAL_AREA_H
#define GENERAL_AREA_H

#include "Area.h"
#include "Composite.h"
#include "GeneralStall.h"


/**
 * @class GeneralArea
 * @brief A composite representing a general area with food and drink stalls.
 * 
 * The GeneralArea contains GeneralStalls and closes during emergencies
 * to protect staff and customers.
 */
class GeneralArea : public Composite
{
    public:
        /**
         * @brief Reacts to a weather alert by closing.
         * @param severity The severity level (1-10).
         * @param type The type of weather.
         */
        virtual void weatherAlert(int severity, const std::string& type) override;

        /**
         * @brief Reacts to a bull escape by closing all food stalls.
         * @param location The location where the bull escaped.
         * @param numBulls The number of bulls escaped.
         */
        virtual void escapedBull(const std::string& location, int numBulls) override;

        /**
         * @brief Reacts to a medical emergency by pausing operations.
         * @param severity The severity level.
         * @param injuryType The type of injury.
         */
        virtual void medicalEmergency(int severity, const std::string& injuryType) override;
        
        /**
         * @brief Reacts to a capacity alert by monitoring.
         * @param currentCount The current number of people.
         * @param maxCapacity The maximum capacity.
         */
        virtual void capacityAlert(int currentCount, int maxCapacity) override;
        
        /**
         * @brief Opens the general area.
         */
        virtual void setup() override;
        
        /**
         * @brief Closes the general area.
         */
        virtual void shutdown() override;
		
         /**
         * @brief Reacts to a quarantine order.
         * @param days The number of days for quarantine.
         */
        virtual void quarantine(int days) override;
		
        /**
         * @brief Reacts to feeding time.
         * @param foodType The type of food being served.
         */
        virtual void feedingTime(std::string foodType) override;

};

#endif
