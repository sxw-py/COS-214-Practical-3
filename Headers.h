#ifndef HEADERS_H
#define HEADERS_H

#include <vector>
using namespace std;

class EventComponent
{
	private:
		bool isOpen;
	public:
		virtual void open() = 0;
		virtual void close() = 0;
		virtual void reportStatus() const = 0;
		virtual int getCapacity() const = 0;
};

class Subject;

class Observer
{
	public:
		virtual void setup(Subject&);
		virtual void shutdown(Subject&);
		virtual void medicalEmergency(Subject&);
		virtual void escapedBull(Subject&);
		virtual void weatherAlert(Subject&);
		virtual void capacityAlert(Subject&);
};

class Subject
{
	private:
		vector<Observer*> observers;
	public:
		virtual void attach(Observer*);
		virtual void detach(Observer*);
		virtual void setup();
		virtual void shutdown();
		virtual void medicalEmergency();
		virtual void escapedBull();
		virtual void weatherAlert();
		virtual void capacityAlert();
};

class Tent;

class Auction : public Subject, public EventComponent
{
	private:
		vector<Tent*> tents;
	public:
		virtual void addChild(Tent*);
		virtual Tent* removeChild(Tent*);
};

class Area : public EventComponent, public Observer {};

class Tent : public EventComponent, public Observer
{
	private:
		vector<Area*> areas;
	public:
		virtual void addChild(Area*);
		virtual Area* removeChild(Area*);
};

class Stall : public EventComponent, public Observer {};

class MedicalStall : public Stall {};
class PulmonaryStall : public MedicalStall {};
class CardiacStall : public MedicalStall {};

class MedicalArea : public Area
{
	private:
		vector<MedicalStall*> stalls;
	public:
		virtual void addChild(MedicalStall*);
		virtual MedicalStall* removeChild(MedicalStall*);
};

class GeneralStall : public Stall {};
class FoodStall : public GeneralStall {};
class DrinkStall : public GeneralStall {};

class GeneralArea : public Area
{
	private:
		vector<GeneralStall*> stalls;
	public:
		virtual void addChild(GeneralStall*);
		virtual GeneralStall* removeChild(GeneralStall*);
};

class CattleStall : public Stall {};

class CattleArea : public Area
{
	private:
		vector<CattleStall*> stalls;
	public:
		virtual void addChild(CattleStall*);
		virtual CattleStall* removeChild(CattleStall*);
};

#endif
