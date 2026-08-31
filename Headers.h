#ifndef HEADERS_H
#define HEADERS_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Subject;

// make composite observations relay to children
class Observer // implement diff notifications in leaves
{
	public:
		virtual void setup(Subject&) {};
		virtual void shutdown(Subject&) {};
		virtual void medicalEmergency(Subject&) {};
		virtual void escapedBull(Subject&) {}; 
		virtual void weatherAlert(Subject&) {};
		virtual void capacityAlert(Subject&) {};
};

class EventComponent
{
	public:
		virtual void open() = 0;
		virtual void close() = 0;
		virtual bool reportStatus() const = 0;
		virtual int getCapacity() const = 0;
};


class Leaf : public EventComponent, public Observer
{
	private:
		int capacity;
		bool isOpen;
	public:
		Leaf(int cap) : capacity(cap) {}
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
};

class Subject
{
	private:
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
};

template <typename T>
class Composite : public EventComponent, public Subject, public Observer
{
	private:
		vector<T*> children;
	public:
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
		}
		virtual int getCapacity() const override
		{
			int sum = 0;
			for (auto child : children)
				sum += child.getCapacity();
			return sum;
		}
		virtual void addChild(T* child)
		{
			children.push_back(child);
		}

		virtual T* removeChild(T* child)
		{
			// implement
		}

		virtual ~Composite()
		{
			// implement
		}
};

class Tent;

class Auction : public Composite<Tent>
{
};

class Area
{
};

class Tent : public Composite<Area>
{
};

class Stall : public Leaf
{
	public:
		Stall(int cap) : Leaf(cap) {}
};

class Complaint { public: virtual string getComplaint() = 0; };
class Cough : public Complaint { public: virtual string getComplaint() override { return "cough"; } };
class MI : public Complaint { public: virtual string getComplaint() override { return "Heart attack"; } };

template <typename T>
class Patient
{
	private:
		string name;
		T complaint;
	public:
		Patient(string name) : name(name) {}
		virtual string getName() const { return this->name; }
		virtual string getComplaint() const { return this->complaint->getComplaint(); }
};

class MedicalStall : public Stall
{
};
class PulmonaryStall : public MedicalStall
{
	public:
		void treatPatient(const Patient<Cough>& patient) const
		{
			cout << patient.getName() << " complains of " << patient.getComplaint() << endl;
			cout << "Patient is receiving pulmonary support" << endl;
		}
};
class CardiacStall : public MedicalStall
{
	public:
		void treatPatient(const Patient<MI>& patient) const
		{
			cout << patient.getName() << " complains of " << patient.getComplaint() << endl;
			cout << "Patient is receiving cardiac support" << endl;
		}
};

class MedicalArea : public Area, public Composite<MedicalStall>
{
};

class GeneralStall : public Stall 
{
	private:
		int revenue;
	public:
		virtual int unitCost() const = 0;
		virtual void buyFood() { revenue += unitCost(); }
		virtual int getRevenue() { return this->revenue; }

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
			// print numCattle * moo
		}
};

class CattleArea : public Area, public Composite<CattleStall>
{
};

#endif
