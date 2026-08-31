#ifndef PATIENT_H
#define PATIENT_H

#include <string>

// NOTE: Patient is a class template, so it must stay header-only.
template <typename T>
class Patient
{
	private:
		std::string name;
		T complaint;
	public:
		Patient(std::string name) : name(name) {}
		virtual std::string getName() const { return this->name; }
		virtual std::string getComplaint() const { return this->complaint.getComplaint(); }
};

#endif
