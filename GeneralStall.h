#ifndef GENERAL_STALL_H
#define GENERAL_STALL_H

#include "Stall.h"

/**
 * @class GeneralStall
 * @brief An abstract stall representing a generic vendor or service point.
 *
 * Acts as a base class for specific stalls like FoodStall and DrinkStall.
 */
class GeneralStall : public Stall
{
	private:
		int revenue;
		bool serviceSlowed;
	public:
		/**
		 * @brief Returns the cost of a single unit sold by the stall.
		 * @return Cost per unit.
		 */
		virtual int unitCost() const = 0;

		/**
		 * @brief Processes a purchase if the stall is open, adding to revenue.
		 */
		void buyItem();

		/**
		 * @brief Gets the total accumulated revenue.
		 * @return Current revenue.
		 */
		int getRevenue();
		GeneralStall(int cap);
		bool isServiceSlowed() const;
		virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
		virtual void medicalEmergency(int severity, const std::string& injuryType) override;
		virtual void capacityAlert(int currentCount, int maxCapacity) override;
		virtual void setup() override;
		virtual void shutdown() override;
		virtual void vipArrival(int vipLevel) override;

};

#endif
