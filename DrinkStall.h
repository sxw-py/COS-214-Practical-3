#ifndef DRINK_STALL_H
#define DRINK_STALL_H

#include "GeneralStall.h"

class DrinkStall : public GeneralStall
{
	private:
		bool drinksSecured;
	public:
		virtual int unitCost() const override;
		virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
};

#endif
