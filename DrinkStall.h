#ifndef DRINK_STALL_H
#define DRINK_STALL_H

#include "GeneralStall.h"

class DrinkStall : public GeneralStall
{
	public:
		virtual int unitCost() const override;
};

#endif
