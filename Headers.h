#ifndef HEADERS_H
#define HEADERS_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Subject;

// move these into different files
// no information gets pulled from subject
class Observer // implement diff notifications in leaves
{
	public:
		virtual void setup(Subject&) {};
		virtual void shutdown(Subject&) {};
		virtual void medicalEmergency(Subject&) {};
		virtual void escapedBull(Subject&) {}; 
		virtual void weatherAlert(Subject&) {};
		virtual void capacityAlert(Subject&) {};
		virtual ~Observer() = default;
};

class EventComponent
{
	public:
		virtual void open() = 0;
		virtual void close() = 0;
		virtual bool reportStatus() const = 0;
		virtual int getCapacity() const = 0;
		virtual ~EventComponent() = default;
};


class Leaf : public EventComponent, public Observer
{
	private:
		int capacity;
		bool isOpen;
	public:
		Leaf(int cap) : capacity(cap), isOpen(false) {}
		virtual void open() override
		{
			this->isOpen = true;
		}
		virtual void close() override
		{
			this->isOpen = false;
		}
		virtual bool reportStatus() const override
		{
			return this->isOpen;
		}
		virtual int getCapacity() const override
		{
			return this->capacity;
		}
		virtual ~Leaf() = default;
};

class Subject
{
	protected:
		vector<Observer*> observers;
	public:
		virtual void attach(Observer* o)
		{
			detach(o);
			observers.push_back(o);
		}
		virtual void detach(Observer* observer)
		{
			for (auto it = observers.begin(); it != observers.end(); )
			{
				if (*it == observer)
					it = observers.erase(it);
				else
					it++;
			}
		}
		virtual void setup()
		{
			for (auto o : observers)
				o->setup(*this);
		}
		virtual void shutdown()
		{
			for (auto o : observers)
				o->shutdown(*this);
		}
		virtual void medicalEmergency()
		{
			for (auto o : observers)
				o->medicalEmergency(*this);
		}
		virtual void escapedBull()
		{
			for (auto o : observers)
				o->escapedBull(*this);
		}
		virtual void weatherAlert()
		{
			for (auto o : observers)
				o->weatherAlert(*this);
		}
		virtual void capacityAlert()
		{
			for (auto o : observers)
				o->capacityAlert(*this);
		}
		virtual ~Subject() = default;
};

template <typename T>
class Composite : public EventComponent, public Subject, public Observer
{
	private:
		vector<T*> children;
	public:
		using Subject::setup;
		virtual void open() override
		{
			for (auto child : children)
				child->open();
		}
		virtual void close() override
		{
			for (auto child : children)
				child->close();
		}
		virtual bool reportStatus() const override
		{
			bool isOpen = false;
			for (auto child : children)
				isOpen |= child->reportStatus();
			return isOpen; // isOpen as long as at least one child is open
				       // closed if no children
		}
		virtual int getCapacity() const override
		{
			int sum = 0;
			for (auto child : children)
				sum += child->getCapacity();
			return sum;
		}
		virtual void addChild(T* child)
		{
			removeChild(child);
			children.push_back(child);
		}

		virtual T* removeChild(T* child)
		{
			for (auto it = children.begin(); it != children.end(); )
			{
				if (*it == child)
					it = children.erase(it);
				else
					it++;
			}
			return child;
		}

		virtual ~Composite()
		{
			for (auto child : children)
				delete child;
		}
		virtual void setup(Subject& subject) override
		{
			for (auto o : observers)
				o->setup(subject);
		}
		virtual void shutdown(Subject& subject) override
		{
			for (auto o : observers)
				o->shutdown(subject);
		}
		virtual void medicalEmergency(Subject& subject) override
		{
			for (auto o : observers)
				o->medicalEmergency(subject);
		}
		virtual void escapedBull(Subject& subject) override
		{
			for (auto o : observers)
				o->escapedBull(subject);
		}
		virtual void weatherAlert(Subject& subject) override
		{
			for (auto o : observers)
				o->weatherAlert(subject);
		}
		virtual void capacityAlert(Subject& subject) override
		{
			for (auto o : observers)
				o->capacityAlert(subject);
		}
};

class Tent;

class Auction : public Composite<Tent>
{
};

class Area
{
	public:
		virtual void open() = 0;
		virtual void close() = 0;
		virtual bool reportStatus() const = 0;
		virtual int getCapacity() const = 0;
		virtual ~Area() = default;
};

class Tent : public Composite<Area>
{
};

class Stall : public Leaf
{
	public:
		Stall(int cap) : Leaf(cap) {}
};

class Complaint { public: virtual string getComplaint() const = 0; };
class Cough : public Complaint { public: virtual string getComplaint() const override { return "cough"; } };
class MI : public Complaint { public: virtual string getComplaint() const override { return "Heart attack"; } };

template <typename T>
class Patient
{
	private:
		string name;
		T complaint;
	public:
		Patient(string name) : name(name) {}
		virtual string getName() const { return this->name; }
		virtual string getComplaint() const { return this->complaint.getComplaint(); }
};

class MedicalStall : public Stall
{
	public:
		MedicalStall(int cap) : Stall(cap) {}
};
class PulmonaryStall : public MedicalStall
{
	public:
		PulmonaryStall(int cap) : MedicalStall(cap) {}
		void treatPatient(const Patient<Cough>& patient) const
		{
			cout << patient.getName() << " complains of " << patient.getComplaint() << endl;
			cout << "Patient is receiving pulmonary support" << endl;
		}
		virtual void setup(Subject&) override
		{
			cout << "Pulmonary stall ready" << endl;
		}
		virtual void shutdown(Subject&) override
		{
			cout << "Pulmonary stall closing" << endl;
		}
};
class CardiacStall : public MedicalStall
{
	public:
		CardiacStall(int cap) : MedicalStall(cap) {}
		void treatPatient(const Patient<MI>& patient) const
		{
			cout << patient.getName() << " complains of " << patient.getComplaint() << endl;
			cout << "Patient is receiving cardiac support" << endl;
		}
		virtual void setup(Subject&) override
		{
			cout << "Cardiac stall ready" << endl;
		}
		virtual void shutdown(Subject&) override
		{
			cout << "Cardiac stall closing" << endl;
		}
};

class MedicalArea : public Area, public Composite<MedicalStall>
{
	public:
		virtual void open() override {
			Composite<MedicalStall>::open();
		}
		virtual void close() override {
			Composite<MedicalStall>::close();
		}
		virtual bool reportStatus() const override {
			return Composite<MedicalStall>::reportStatus();
		}
		virtual int getCapacity() const override {
			return Composite<MedicalStall>::getCapacity();
		}
};

class GeneralStall : public Stall 
{
	private:
		int revenue = 0;
	public:
		virtual int unitCost() const = 0;
		void buyItem() { revenue += unitCost(); }
		int getRevenue() { return this->revenue; }

};
class FoodStall : public GeneralStall 
{
	public:
		virtual int unitCost() const override { return 30; }
};
class DrinkStall : public GeneralStall {
	public:
		virtual int unitCost() const override { return 10; }
};

class GeneralArea : public Area, public Composite<GeneralStall>
{
};

class CattleStall : public Stall 
{
	private:
		int numCattle;
	public:
		CattleStall(int numCattle, int cap) : Stall(cap), numCattle(numCattle) {}
		virtual int getNumCattle() { return this->numCattle; }
		virtual void moo()
		{
			for (int i = 0; i < numCattle; i++)
				cout << "moo ";
			cout << endl;
		}
};

class CattleArea : public Area, public Composite<CattleStall>
{
};

#endif
