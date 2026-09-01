#ifndef STALL_H
#define STALL_H

#include "Leaf.h"

/**
 * @class Stall
 * @brief A concrete leaf representing a stall at the event.
 * 
 * A Stall is a leaf in the Composite pattern that has no children.
 * It represents individual operational units like food stalls,
 * medical stalls, and cattle stalls.
 */
class Stall : public Leaf
{
	public:
		/**
         * @brief Constructs a Stall with a given capacity.
         * @param cap The maximum capacity of the stall.
         */
		Stall(int cap);
};

#endif
