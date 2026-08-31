#ifndef CATTLE_STALL_H
#define CATTLE_STALL_H

#include "Stall.h"

class CattleStall : public Stall
{
	private:
		int numCattle;
	public:
		CattleStall(int numCattle, int cap);
		virtual int getNumCattle();
		virtual void moo();
		virtual void setup(Subject&) override;
		virtual void shutdown(Subject&) override;
		virtual void escapedBull(Subject&) override;
		virtual void capacityAlert(Subject&) override;
};

#endif
