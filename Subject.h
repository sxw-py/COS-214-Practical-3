#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Subject
{
	protected:
		std::vector<Observer*> observers;
	public:
		virtual void attach(Observer* o);
		virtual void detach(Observer* observer);
		virtual void setup();
		virtual void shutdown();
		virtual void medicalEmergency();
		virtual void escapedBull();
		virtual void weatherAlert();
		virtual void capacityAlert();
		
		// Task 4.4 Original Features
		virtual void vipArrival(int vipLevel);
		virtual void quarantine(int days);
		virtual void feedingTime(std::string foodType);
		
		virtual ~Subject() = default;
};

#endif
