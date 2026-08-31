#ifndef AREA_H
#define AREA_H

class Area
{
	public:
		virtual void open() = 0;
		virtual void close() = 0;
		virtual bool reportStatus() const = 0;
		virtual int getCapacity() const = 0;
		virtual ~Area() = default;
};

#endif
