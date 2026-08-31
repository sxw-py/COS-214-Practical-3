#ifndef FOOD_STALL_H
#define FOOD_STALL_H

#include "GeneralStall.h"

class FoodStall : public GeneralStall
{
	private:
		bool foodSecured;
	public:
		virtual int unitCost() const override;
		virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
};

#endif
