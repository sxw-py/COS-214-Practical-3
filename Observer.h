#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Subject;

// Base Observer interface. Concrete observers override only the
// notifications they care about; all hooks default to no-ops.
class Observer
{
	public:
		virtual void setup(Subject&) {};
		virtual void shutdown(Subject&) {};
		virtual void medicalEmergency(Subject&) {};
		virtual void escapedBull(Subject&) {};
		virtual void weatherAlert(Subject&) {};
		virtual void capacityAlert(Subject&) {};
		
		// Task 4.4 Original Features (Push Model)
		virtual void vipArrival(int vipLevel) {};
		virtual void quarantine(int days) {};
		virtual void feedingTime(std::string foodType) {};
		
		virtual ~Observer() = default;
};

#endif
