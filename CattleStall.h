#ifndef CATTLE_STALL_H
#define CATTLE_STALL_H

#include "Stall.h"

class CattleStall : public Stall
{
	private:
		int numCattle;
		bool isSheltered;

	public:
		CattleStall(int numCattle, int cap);
		virtual int getNumCattle();
		virtual void moo();
		virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;

};

#endif
