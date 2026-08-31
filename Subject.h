#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Subject
{
	protected:
		std::vector<Observer*> observers;
		int currentSeverity;
		std::string currentWeatherType;
		std::string bullLocation;
		int numBulls;

	public:
		static const int MaxSeverity =10;
		static const int MoveThreshold = 7;
		virtual void attach(Observer* o);
		virtual void detach(Observer* observer);
		virtual void setWeatherData(int severity, const std::string& type);
		virtual void weatherAlert();

		virtual void setBullEscape(const std::string& location, int numBulls);
		virtual void escapedBull();
		
		virtual void setup();
		virtual void shutdown();
		virtual void medicalEmergency();
	
		virtual void capacityAlert();
		virtual ~Subject() = default;
};

#endif
