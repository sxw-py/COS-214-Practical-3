#ifndef AUCTION_H
#define AUCTION_H

#include "Composite.h"

class Tent;

// Composite<Tent> only needs a complete Tent type where its members
// actually get instantiated (e.g. the destructor). Any translation unit
// that uses Auction's methods must also #include "Tent.h".
class Auction : public Composite
{
    private:
        bool paused;
        int pendingBids;
    
    public:
        Auction();
        bool isPaused() const;
        virtual void weatherAlert(int severity, const std::string& type) override;
        virtual void escapedBull(const std::string& location, int numBulls) override;
        virtual void medicalEmergency(int severity, const std::string& injuryType) override;
        virtual void capacityAlert(int currentCount, int maxCapacity) override;
        virtual void setup() override;
        virtual void shutdown() override;
};

#endif
