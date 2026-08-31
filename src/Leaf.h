#ifndef LEAF_H
#define LEAF_H

#include "EventComponent.h"
#include "Observer.h"

class Leaf : public EventComponent, public Observer
{
	private:
		int capacity;
		bool isOpen;
	public:
		Leaf(int cap);
		virtual void open() override;
		virtual void close() override;
		virtual bool reportStatus() const override;
		virtual int getCapacity() const override;
		virtual ~Leaf() = default;
};

#endif
