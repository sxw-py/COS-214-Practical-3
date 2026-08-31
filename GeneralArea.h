#ifndef GENERAL_AREA_H
#define GENERAL_AREA_H

#include "Area.h"
#include "Composite.h"
#include "GeneralStall.h"

class GeneralArea : public Area, public Composite<GeneralStall>
{
};

#endif
