#ifndef PATIENT_H
#define PATIENT_H

#include <string>

/**
 * @class Patient
 * @brief Template class representing a patient with a medical complaint.
 * 
 * @tparam T The type of complaint (e.g., Cough, MI).
 */
template <typename T>
class Patient
{
	private:
		std::string name;
		T complaint;
	public:
		 /**
         * @brief Constructs a Patient with a given name.
         * @param name The patient's name.
         */
		Patient(std::string name) : name(name) {}
		
		/**
         * @brief Gets the patient's name.
         * @return The patient's name.
         */
		virtual std::string getName() const { return this->name; }
		
		/**
         * @brief Gets the patient's complaint description.
         * @return The complaint description.
         */
		virtual std::string getComplaint() const { return this->complaint.getComplaint(); }
};

#endif
