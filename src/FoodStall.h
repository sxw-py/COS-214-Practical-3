#ifndef FOOD_STALL_H
#define FOOD_STALL_H

#include "GeneralStall.h"

class FoodStall : public GeneralStall
{
	public:
		virtual int unitCost() const override;
};

#endif
