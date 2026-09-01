#ifndef CATTLE_AREA_H
#define CATTLE_AREA_H

#include "Composite.h"
#include "CattleStall.h"

class CattleArea : public Area, public Composite<CattleStall>
{
};

#endif
