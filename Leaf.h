#ifndef LEAF_H
#define LEAF_H

#include "EventComponent.h"
#include "Observer.h"

/**
 * @class Leaf
 * @brief The Leaf participant in the Composite design pattern.
 *
 * Represents leaf objects in the composition. A leaf has no children.
 * It defines behavior for primitive objects in the composition and inherits
 * the Observer interface to respond to Subject broadcasts.
 */
class Leaf : public EventComponent, public Observer
{
	protected:
		int capacity;
		bool isOpen;
	public:
		/**
		 * @brief Constructs a leaf node with a specific capacity.
		 * @param cap Maximum capacity of this leaf node.
		 */
		Leaf(int cap);

		/**
		 * @brief Opens the leaf node, making it operational.
		 */
		virtual void open() override;
		virtual void close() override;
		virtual bool reportStatus() const override;
		virtual int getCapacity() const override;
		virtual ~Leaf() = default;
};

#endif
