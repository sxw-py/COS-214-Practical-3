#ifndef AUCTION_H
#define AUCTION_H

#include "Composite.h"

class Tent;

/**
 * @class Auction
 * @brief A composite representing the auction area of the event.
 * 
 * The Auction manages bidding activities and contains Tents as children.
 * It reacts to various event notifications by pausing operations for safety.
 */
class Auction : public Composite
{
    private:
        bool paused;
        int pendingBids;
    
    public:
        /**
         * @brief Constructs an Auction object.
         */
        Auction();

        /**
         * @brief Checks if the auction is paused.
         * @return true if paused, false if active.
         */
        bool isPaused() const;

        /**
         * @brief Reacts to a weather alert by pausing the auction.
         * @param severity The severity level of the weather (1-10).
         * @param type The type of weather (e.g., "storm", "rain").
         */
        virtual void weatherAlert(int severity, const std::string& type) override;

        /**
         * @brief Reacts to a bull escape by pausing the auction.
         * @param location The location where the bull escaped.
         * @param numBulls The number of bulls that escaped.
         */
        virtual void escapedBull(const std::string& location, int numBulls) override;

        /**
         * @brief Reacts to a medical emergency by pausing for access.
         * @param severity The severity level.
         * @param injuryType The type of injury.
         */
        virtual void medicalEmergency(int severity, const std::string& injuryType) override;

        /**
         * @brief Reacts to a capacity alert by pausing new entries.
         * @param currentCount The current number of people.
         * @param maxCapacity The maximum capacity allowed.
         */
        virtual void capacityAlert(int currentCount, int maxCapacity) override;

        /**
         * @brief Opens the auction for business.
         */
        virtual void setup() override;

        /**
         * @brief Shuts down the auction and completes pending bids.
         */
        virtual void shutdown() override;
};

#endif
