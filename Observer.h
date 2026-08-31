#ifndef OBSERVER_H
#define OBSERVER_H

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
		virtual ~Observer() = default;
};

#endif
