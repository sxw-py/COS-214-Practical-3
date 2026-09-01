#ifndef DRINK_STALL_H
#define DRINK_STALL_H

#include "GeneralStall.h"


/**
 * @class DrinkStall
 * @brief A stall that sells drinks at the event.
 * 
 * The DrinkStall closes during weather alerts and bull escapes
 * for safety, pauses during medical emergencies to clear paths,
 * and monitors capacity during capacity alerts.
 */
class DrinkStall : public GeneralStall
{
	private:
		bool drinksSecured;
	public:
		/**
         * @brief Constructs a DrinkStall with a given capacity.
         * @param cap The maximum capacity of the stall.
         */
		DrinkStall(int cap);

		/**
         * @brief Gets the cost of one drink item.
         * @return The unit cost.
         */
		virtual int unitCost() const override;
		
		/**
         * @brief Reacts to a weather alert by closing.
         * @param severity The severity level (1-10).
         * @param type The type of weather.
         */
		virtual void weatherAlert(int severity, const std::string& type) override;
		
		/**
         * @brief Reacts to a medical emergency by pausing.
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
         * @brief Opens the drink stall.
         */
		virtual void setup() override;
        
		 /**
         * @brief Closes the drink stall.
         */
		virtual void shutdown() override;
};

#endif
