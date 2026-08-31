#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <vector>
#include "EventComponent.h"
#include "Subject.h"
#include "Observer.h"

// NOTE: Composite is a class template, so its definition must remain
// entirely in this header (templates are compiled per translation unit
// on use; there is no separate .cpp for it).
template <typename T>
class Composite : public EventComponent, public Subject, public Observer
{
	private:
		std::vector<T*> children;
	public:
		using Subject::setup;

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
		virtual void addChild(T* child)
		{
			removeChild(child);
			children.push_back(child);
		}

		virtual T* removeChild(T* child)
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
};

#endif
