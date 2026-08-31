#ifndef GENERAL_STALL_H
#define GENERAL_STALL_H

#include "Stall.h"

class GeneralStall : public Stall
{
	private:
		int revenue;
	public:
		virtual int unitCost() const = 0;
		void buyItem();
		int getRevenue();
		virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
};

#endif
