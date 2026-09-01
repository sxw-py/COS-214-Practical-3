#ifndef EVENT_COMPONENT_H
#define EVENT_COMPONENT_H


/**
 * @class EventComponent
 * @brief Abstract base class for all event components.
 * 
 * Defines the common interface for both Leaf and Composite objects
 * in the Composite pattern.
 */
class EventComponent
{
	public:
		/**
         * @brief Opens the event component.
         */
		virtual void open() = 0;

		/**
         * @brief Closes the event component.
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
		virtual ~EventComponent() = default;
};

#endif
