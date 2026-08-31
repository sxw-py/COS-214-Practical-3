#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <vector>
#include "EventComponent.h"
#include "Subject.h"
#include "Observer.h"


/**
 * @class Composite
 * @brief The Composite participant in the Composite design pattern.
 *
 * Defines behavior for components having children. It stores child components
 * and implements child-related operations in the Component interface.
 */
class Composite : public EventComponent, public Subject, public Observer
{
	private:
		std::vector<EventComponent*> children;
	public:
		using Subject::setup;
		using Subject::shutdown;
		using Subject::medicalEmergency;
		using Subject::escapedBull;
		using Subject::weatherAlert;
		using Subject::capacityAlert;
		using Subject::vipArrival;
		using Subject::quarantine;
		using Subject::feedingTime;

		virtual void open() override
		{
			for (auto child : children)
				child->open();
		}
		virtual void close() override
		{
			for (auto child : children)
				child->close();
		}
		virtual bool reportStatus() const override
		{
			bool isOpen = false;
			for (auto child : children)
				isOpen |= child->reportStatus();
			return isOpen; // isOpen as long as at least one child is open
				       // closed if no children
		}
		virtual int getCapacity() const override
		{
			int sum = 0;
			for (auto child : children)
				sum += child->getCapacity();
			return sum;
		}
		/**
		 * @brief Adds a child component to this composite.
		 * 
		 * @note **Design Decision (Task 6.3):** By passing a raw pointer, the Composite
		 * takes ownership of the child's lifetime.
		 * 
		 * @param child Pointer to the child EventComponent to add.
		 */
		virtual void addChild(EventComponent* child)
		{
			removeChild(child);
			children.push_back(child);
		}

		/**
		 * @brief Removes a child component without deleting it.
		 * 
		 * @note **Design Decision (Task 6.3):** This method explicitly relinquishes ownership 
		 * without calling `delete`. This allows for runtime reorganization where a child
		 * can be transferred to another composite safely.
		 * 
		 * @param child Pointer to the child EventComponent to remove.
		 */
		virtual EventComponent* removeChild(EventComponent* child)
		{
			for (auto it = children.begin(); it != children.end(); )
			{
				if (*it == child)
					it = children.erase(it);
				else
					it++;
			}
			return child;
		}

		/**
		 * @brief Cleans up dynamically allocated children.
		 * 
		 * @note **Design Decision (Task 6.3):** The Composite assumes ownership of any child
		 * added to it. When the Composite is destroyed, it deletes all remaining children
		 * to prevent memory leaks.
		 */
		virtual ~Composite()
		{
			for (auto child : children)
				delete child;
		}

		virtual void setup(Subject& subject) override
		{
			for (auto o : observers)
				o->setup(subject);
		}
		virtual void shutdown(Subject& subject) override
		{
			for (auto o : observers)
				o->shutdown(subject);
		}
		virtual void medicalEmergency(Subject& subject) override
		{
			for (auto o : observers)
				o->medicalEmergency(subject);
		}
		virtual void escapedBull(Subject& subject) override
		{
			for (auto o : observers)
				o->escapedBull(subject);
		}
		virtual void weatherAlert(Subject& subject) override
		{
			for (auto o : observers)
				o->weatherAlert(subject);
		}
		virtual void capacityAlert(Subject& subject) override
		{
			for (auto o : observers)
				o->capacityAlert(subject);
		}
		
		virtual void vipArrival(int vipLevel) override
		{
			for (auto o : observers)
				o->vipArrival(vipLevel);
		}
		
		virtual void quarantine(int days) override
		{
			for (auto o : observers)
				o->quarantine(days);
		}
		
		virtual void feedingTime(std::string foodType) override
		{
			for (auto o : observers)
				o->feedingTime(foodType);
		}
};

#endif
