#ifndef CATTLE_STALL_H
#define CATTLE_STALL_H

#include "Stall.h"

/**
 * @class CattleStall
 * @brief Represents a stall holding cattle.
 *
 * A concrete leaf component in the Composite pattern, representing an individual cattle enclosure.
 */
class CattleStall : public Stall
{
	private:
		int numCattle;
		bool isSheltered;
		bool accessLimited;
	public:
		/**
		 * @brief Constructor for CattleStall.
		 * @param numCattle The initial number of cattle in the stall.
		 * @param cap The maximum capacity of the stall.
		 */
		CattleStall(int numCattle, int cap);

		/**
		 * @brief Returns the current number of cattle.
		 * @return The number of cattle.
		 */
		virtual int getNumCattle();
		bool isAccessLimited() const;
		virtual void moo();
		virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
		virtual void medicalEmergency(int severity, const std::string& injuryType) override;
        virtual void capacityAlert(int currentCount, int maxCapacity) override;
        virtual void setup() override;
        virtual void shutdown() override;
		virtual void quarantine(int days) override;
		virtual void feedingTime(std::string foodType) override;

};

#endif
