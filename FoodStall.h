#ifndef FOOD_STALL_H
#define FOOD_STALL_H

#include "GeneralStall.h"

/**
 * @class FoodStall
 * @brief A stall that sells food at the event.
 * 
 * The FoodStall closes during weather alerts to protect food,
 * closes during bull escapes for safety, pauses during medical
 * emergencies to clear paths, and continues operating with queue
 * management during capacity alerts.
 */
class FoodStall : public GeneralStall
{
	private:
		bool foodSecured;
		bool queueManaged;
	public:
		/**
         * @brief Constructs a FoodStall with a given capacity.
         * @param cap The maximum capacity of the stall.
         */
		FoodStall(int cap);

		/**
         * @brief Checks if queue management is active.
         * @return true if active, false otherwise.
         */
		bool isQueueManaged() const;

		/**
         * @brief Gets the cost of one food item.
         * @return The unit cost.
         */
		virtual int unitCost() const override;
		
		/**
         * @brief Reacts to a weather alert by closing to protect food.
         * @param severity The severity level (1-10).
         * @param type The type of weather.
         */
		virtual void weatherAlert(int severity, const std::string& type) override;
        
		/**
         * @brief Reacts to a bull escape by closing for safety.
         * @param location The location where the bull escaped.
         * @param numBulls The number of bulls escaped.
         */
		virtual void escapedBull(const std::string& location, int numBulls) override;
		
		/**
         * @brief Reacts to a medical emergency by pausing to clear paths.
         * @param severity The severity level.
         * @param injuryType The type of injury.
         */
		virtual void medicalEmergency(int severity, const std::string& injuryType) override;
        
		/**
         * @brief Reacts to a capacity alert by continuing with queue management.
         * @param currentCount The current number of people.
         * @param maxCapacity The maximum capacity.
         */
		virtual void capacityAlert(int currentCount, int maxCapacity) override;
        
		/**
         * @brief Opens the food stall.
         */
		virtual void setup() override;
        
		/**
         * @brief Closes the food stall.
         */
		virtual void shutdown() override;
};

#endif
