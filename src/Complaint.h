#ifndef COMPLAINT_H
#define COMPLAINT_H

#include <string>

class Complaint
{
	public:
		virtual std::string getComplaint() const = 0;
		virtual ~Complaint() = default;
};

class Cough : public Complaint
{
	public:
		virtual std::string getComplaint() const override;
};

class MI : public Complaint
{
	public:
		virtual std::string getComplaint() const override;
};

#endif
