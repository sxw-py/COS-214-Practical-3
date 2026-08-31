#ifndef AUCTION_H
#define AUCTION_H

#include "Composite.h"

class Tent;

// Composite<Tent> only needs a complete Tent type where its members
// actually get instantiated (e.g. the destructor). Any translation unit
// that uses Auction's methods must also #include "Tent.h".
class Auction : public Composite
{
};

#endif
