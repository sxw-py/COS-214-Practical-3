#ifndef EVENT_COMPONENT_H
#define EVENT_COMPONENT_H

class EventComponent
{
	public:
		virtual void open() = 0;
		virtual void close() = 0;
		virtual bool reportStatus() const = 0;
		virtual int getCapacity() const = 0;
		virtual ~EventComponent() = default;
};

#endif
