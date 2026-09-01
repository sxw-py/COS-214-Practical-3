#ifndef COMPLAINT_H
#define COMPLAINT_H

#include <string>


/**
 * @class Complaint
 * @brief Abstract base class for medical complaints.
 * 
 * Represents different types of medical complaints that patients
 * can have when visiting medical stalls.
 */
class Complaint
{
	public:
		/**
         * @brief Gets the complaint description.
         * @return A string describing the complaint.
         */
		virtual std::string getComplaint() const = 0;
		virtual ~Complaint() = default;
};

/**
 * @class Cough
 * @brief Represents a cough complaint.
 * 
 * A respiratory complaint treated by the PulmonaryStall.
 */
class Cough : public Complaint
{
	public:
		/**
         * @brief Gets the complaint description.
         * @return "cough".
         */
		virtual std::string getComplaint() const override;
};

/**
 * @class MI
 * @brief Represents a myocardial infarction (heart attack) complaint.
 * 
 * A cardiac complaint treated by the CardiacStall.
 */
class MI : public Complaint
{
	public:
		/**
         * @brief Gets the complaint description.
         * @return "Heart attack".
         */
		virtual std::string getComplaint() const override;
};

#endif
