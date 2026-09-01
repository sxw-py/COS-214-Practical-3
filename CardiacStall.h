#ifndef CARDIAC_STALL_H
#define CARDIAC_STALL_H

#include "MedicalStall.h"
#include "Patient.h"
#include "Complaint.h"
#include "Subject.h"


/**
 * @class CardiacStall
 * @brief A medical stall that provides cardiac care.
 * 
 * The CardiacStall treats heart-related conditions and activates
 * cardiac protocols during medical emergencies. It remains operational
 * during weather alerts and bull escapes.
 */
class CardiacStall : public MedicalStall
{
	private:
		bool cardiacProtocolActive; 
	public:
	/**
         * @brief Constructs a CardiacStall with a given capacity.
         * @param cap The maximum capacity of the stall.
         */
		CardiacStall(int cap);

		 /**
         * @brief Checks if cardiac protocols are active.
         * @return true if active, false otherwise.
         */
		bool isCardiacProtocolActive() const;

		/**
         * @brief Treats a patient with a myocardial infarction (heart attack).
         * @param patient The patient to treat.
         */
		void treatPatient(const Patient<MI>& patient) const;

		/**
         * @brief Reacts to a weather alert by remaining open.
         * @param severity The severity level (1-10).
         * @param type The type of weather.
         */
		virtual void weatherAlert(int severity, const std::string& type) override;

		/**
         * @brief Reacts to a bull escape by preparing for cardiac emergencies.
         * @param location The location where the bull escaped.
         * @param numBulls The number of bulls escaped.
         */
        virtual void escapedBull(const std::string& location, int numBulls) override;

		/**
         * @brief Reacts to a medical emergency by activating cardiac protocols.
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
         * @brief Opens the cardiac stall.
         */
		virtual void setup() override;

		/**
         * @brief Closes the cardiac stall.
         */
		virtual void shutdown() override;
};	


#endif
