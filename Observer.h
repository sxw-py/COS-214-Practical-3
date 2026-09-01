#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Subject;

/**
 * @class Observer
 * @brief The Observer participant in the Observer design pattern.
 *
 * Defines an updating interface for objects that should be notified of changes in a Subject.
 * Concrete observers override only the notifications they care about; all hooks default to no-ops.
 */
class Observer
{
	public:
		virtual void setup() {};
		virtual void shutdown() {};
		virtual void medicalEmergency(int severity, const std::string& injuryType) {};
		virtual void escapedBull(const std::string& location, int numBulls) {};
		virtual void weatherAlert(int severity, const std::string& type) {};
		virtual void capacityAlert(int currentCount, int maxCapacity) {};
		
		/**
		 * @brief Broadcasts when a VIP arrives.
		 * @param vipLevel The importance level of the VIP (higher is more important).
		 */
		virtual void vipArrival(int) {};

		/**
		 * @brief Broadcasts a quarantine order.
		 * @param days The number of days the quarantine should last.
		 */
		virtual void quarantine(int) {};

		/**
		 * @brief Broadcasts the start of feeding time.
		 * @param foodType The type of food being distributed.
		 */
		virtual void feedingTime(std::string) {};
		
		virtual ~Observer() = default;
};

#endif
