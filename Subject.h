#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

/**
 * @class Subject
 * @brief The Subject participant in the Observer design pattern.
 *
 * The Subject knows its observers. Any number of Observer objects may observe a subject.
 * It provides an interface for attaching and detaching Observer objects.
 */
class Subject
{
	protected:
		/**
		 * @brief Non-owning pointers to registered observers.
		 * 
		 * @note **Design Decision (Task 6.3):** Observer pointers are non-owning to prevent
		 * circular dependencies and memory management conflicts. The Subject merely notifies them;
		 * the actual lifetime of the observers is managed elsewhere (e.g., by the Composite tree).
		 * Observers MUST be detached before they are destroyed.
		 */
		std::vector<Observer*> observers;
	public:
		/**
		 * @brief Registers an observer for future event notifications.
		 * @param o Observer to register. Must not be nullptr.
		 */
		virtual void attach(Observer* o);

		/**
		 * @brief Unregisters an observer so it no longer receives notifications.
		 * @param observer Observer to remove.
		 */
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
