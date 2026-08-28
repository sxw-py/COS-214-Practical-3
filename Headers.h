#ifndef HEADERS_H
#define HEADERS_H

#include <vector>
#include <string>
using namespace std;

enum class NoticeType {
    OPEN,
    CLOSE,
    SCHEDULE_CHANGE,
    CAPACITY_ALERT,
    WEATHER_ALERT,
    ESCAPED_BULL,
    MEDICAL_EMERGENCY,
    RESUME
};

class AuctionNotice {
    public:
        NoticeType type;
        string message;
        int capacityThreshold;

        AuctionNotice(NoticeType t, const string& msg, int threshold = 0)
            : type(t), message(msg), capacityThreshold(threshold) {}
};

class Observer {
    public:
        virtual ~Observer() {}
        virtual void update(AuctionNotice* notice);

    protected:
        virtual void setupNotice(AuctionNotice* notice) {}
        virtual void closeNotice(AuctionNotice* notice) {}
        virtual void capacityNotice(AuctionNotice* notice) {}
        virtual void weatherNotice(AuctionNotice* notice) {}
        virtual void bullEscapeNotice(AuctionNotice* notice) {}
        virtual void medicalNotice(AuctionNotice* notice) {}
        virtual void resumeNotice(AuctionNotice* notice) {}
};

class Subject {
    private:
        vector<Observer*> observers;

    public:
        virtual ~Subject() {}
        virtual void attach(Observer* observer);
        virtual void detach(Observer* observer);
        virtual void notify(AuctionNotice* notice);
};

class EventComponent {
    public:
        virtual ~EventComponent() {}
        virtual void open() = 0;
        virtual void close() = 0;
        virtual void reportStatus() const = 0;
        virtual int getCapacity() const = 0;
};

class EventGroup : public EventComponent {
    protected:
        vector<EventComponent*> children;

    public:
        virtual ~EventGroup();
        virtual void add(EventComponent* child);
        virtual void remove(EventComponent* child);

        virtual void open();
        virtual void close();
        virtual void reportStatus() const;
        virtual int getCapacity() const;
};

class EventUnit : public EventComponent {
    protected:
        string name;
        int capacity;
        bool isOpen;

    public:
        EventUnit(const string& n, int cap) : name(n), capacity(cap), isOpen(false) {}
        virtual ~EventUnit() {}

        virtual void reportStatus() const;
        virtual int getCapacity() const;
};

class Auction : public EventGroup, public Subject {
    public:
        virtual void open();
        virtual void close();
};

class Tent : public EventGroup, public Observer, public Subject {
    protected:
        virtual void setupNotice(AuctionNotice* notice);
        virtual void closeNotice(AuctionNotice* notice);
        virtual void weatherNotice(AuctionNotice* notice);
        virtual void medicalNotice(AuctionNotice* notice);
        virtual void bullEscapeNotice(AuctionNotice* notice);
        virtual void resumeNotice(AuctionNotice* notice);
};

class Area : public EventGroup, public Observer, public Subject {
    protected:
        virtual void setupNotice(AuctionNotice* notice);
        virtual void closeNotice(AuctionNotice* notice);
        virtual void weatherNotice(AuctionNotice* notice);
        virtual void medicalNotice(AuctionNotice* notice);
        virtual void bullEscapeNotice(AuctionNotice* notice);
        virtual void resumeNotice(AuctionNotice* notice);
};

class MedicalArea : public Area {
    protected:
        virtual void medicalNotice(AuctionNotice* notice);
        virtual void weatherNotice(AuctionNotice* notice);
};

class GeneralArea : public Area {
    protected:
        virtual void weatherNotice(AuctionNotice* notice);
        virtual void bullEscapeNotice(AuctionNotice* notice);
};

class CattleArea : public Area {
    protected:
        virtual void bullEscapeNotice(AuctionNotice* notice);
        virtual void weatherNotice(AuctionNotice* notice);
};

class Stall : public EventUnit, public Observer {
    public:
        Stall(const string& n, int cap) : EventUnit(n, cap) {}
        virtual void open();
        virtual void close();
};

class MedicalStall : public Stall {
    public:
        MedicalStall(const string& n, int cap) : Stall(n, cap) {}
    protected:
        virtual void medicalNotice(AuctionNotice* notice);
};

class PulmonaryStall : public MedicalStall {
    public:
        PulmonaryStall(const string& n, int cap) : MedicalStall(n, cap) {}
};

class CardiacStall : public MedicalStall {
    public:
        CardiacStall(const string& n, int cap) : MedicalStall(n, cap) {}
};

class GeneralStall : public Stall {
    public:
        GeneralStall(const string& n, int cap) : Stall(n, cap) {}
    protected:
        virtual void weatherNotice(AuctionNotice* notice);
};

class FoodStall : public GeneralStall {
    public:
        FoodStall(const string& n, int cap) : GeneralStall(n, cap) {}
};

class DrinkStall : public GeneralStall {
    public:
        DrinkStall(const string& n, int cap) : GeneralStall(n, cap) {}
};

class CattleStall : public Stall {
    public:
        CattleStall(const string& n, int cap) : Stall(n, cap) {}
    protected:
        virtual void bullEscapeNotice(AuctionNotice* notice);
};

#endif
