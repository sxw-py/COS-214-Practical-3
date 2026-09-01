#ifndef MEDICAL_STALL_H
#define MEDICAL_STALL_H

#include "Stall.h"

/**
 * @class MedicalStall
 * @brief A base class for medical stalls at the event.
 * 
 * MedicalStalls provide medical services and remain operational
 * during emergencies. They prepare for patient influx during
 * capacity alerts and bull escapes.
 */
class MedicalStall : public Stall
{
	public:
		/**
         * @brief Constructs a MedicalStall with a given capacity.
         * @param cap The maximum capacity of the stall.
         */
		MedicalStall(int cap);

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
         * @brief Reacts to a medical emergency by preparing for treatment.
         * @param severity The severity level.
         * @param injuryType The type of injury.
         */
		virtual void medicalEmergency(int severity, const std::string& injuryType) override;
		
		/**
         * @brief Reacts to a capacity alert by preparing for influx.
         * @param currentCount The current number of people.
         * @param maxCapacity The maximum capacity.
         */
		virtual void capacityAlert(int currentCount, int maxCapacity) override;
		
		/**
         * @brief Opens the medical stall.
         */
		virtual void setup() override;
		
		/**
         * @brief Closes the medical stall.
         */
		virtual void shutdown() override;
};

#endif

