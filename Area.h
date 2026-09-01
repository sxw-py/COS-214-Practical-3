#ifndef AREA_H
#define AREA_H

/**
 * @class Area
 * @brief Abstract base class for all areas in the event.
 * 
 * An Area represents a location within the event that can be opened,
 * closed, and report its status and capacity.
 */

class Area
{
	public:
		/**
         * @brief Opens the area.
         */
		virtual void open() = 0;
		
		/**
         * @brief Closes the area.
         */
		virtual void close() = 0;
		
		/**
         * @brief Reports whether the component is open.
         * @return true if open, false if closed.
         */
		virtual bool reportStatus() const = 0;
		
		/**
         * @brief Gets the capacity of the component.
         * @return The maximum capacity.
         */
		virtual int getCapacity() const = 0;
		virtual ~Area() = default;
};

#endif
