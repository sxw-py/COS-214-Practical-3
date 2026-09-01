#ifndef TENT_H
#define TENT_H

#include "Composite.h"
#include "Area.h"


/**
 * @class Tent
 * @brief A composite representing a tent structure at the event.
 * 
 * A Tent can contain Areas and activates weather protection when
 * weather alerts are issued.
 */
class Tent : public Composite
{
    private:
        bool weatherProtectionActive;
    public:
        /**
         * @brief Constructs a Tent object.
         */
        Tent();

        /**
         * @brief Checks if weather protection is active.
         * @return true if active, false otherwise.
         */
        bool isWeatherProtected() const;

        /**
         * @brief Reacts to a weather alert by activating weather protection.
         * @param severity The severity level (1-10).
         * @param type The type of weather.
         */
        virtual void weatherAlert(int severity, const std::string& type) override;

        /**
         * @brief Opens the tent.
         */
        virtual void setup() override;

        /**
         * @brief Closes the tent.
         */
        virtual void shutdown() override;
};

#endif
