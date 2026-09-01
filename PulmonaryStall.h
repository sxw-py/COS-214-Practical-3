#ifndef PULMONARY_STALL_H
#define PULMONARY_STALL_H

#include "MedicalStall.h"
#include "Patient.h"
#include "Complaint.h"
#include "Subject.h"


/**
 * @class PulmonaryStall
 * @brief A medical stall that provides respiratory care.
 * 
 * The PulmonaryStall treats respiratory conditions and activates
 * emergency protocols during medical emergencies. It remains operational
 * during weather alerts to treat weather-related respiratory issues
 * and during bull escapes to treat panic attacks.
 */
class PulmonaryStall : public MedicalStall
{
	private:
		bool emergencyProtocolActive;
	public:
	/**
         * @brief Constructs a PulmonaryStall with a given capacity.
         * @param cap The maximum capacity of the stall.
         */
		PulmonaryStall(int cap);

		/**
         * @brief Treats a patient with a cough or respiratory complaint.
         * @param patient The patient to treat.
         */
		void treatPatient(const Patient<Cough>& patient) const;
		
		/**
         * @brief Reacts to a weather alert by remaining open.
         * @param severity The severity level (1-10).
         * @param type The type of weather.
         */
		virtual void weatherAlert(int severity, const std::string& type) override;
        
		/**
         * @brief Reacts to a bull escape by remaining operational.
         * @param location The location where the bull escaped.
         * @param numBulls The number of bulls escaped.
         */
		virtual void escapedBull(const std::string& location, int numBulls) override;
		
		/**
         * @brief Reacts to a medical emergency by treating respiratory cases.
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
         * @brief Opens the pulmonary stall.
         */
		virtual void setup() override;
		
		/**
         * @brief Closes the pulmonary stall.
         */
		virtual void shutdown() override;
};

#endif
