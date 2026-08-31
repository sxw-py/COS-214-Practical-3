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
		virtual void moo();
		virtual void setup(Subject&) override;
		virtual void shutdown(Subject&) override;
		virtual void escapedBull(Subject&) override;
		virtual void capacityAlert(Subject&) override;
		virtual void quarantine(int days) override;
		virtual void feedingTime(std::string foodType) override;
};

#endif
