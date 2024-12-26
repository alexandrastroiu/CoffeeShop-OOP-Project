#ifndef EVENT_H
#define EVENT_H

#include "../headers/product.hpp"
#include <string>
#include <vector>

class Event {
    protected:
    std::string eventName;
    std::vector<Product> products;
    float totalEventCost;

    public:
    Event(std::string eventName, std::vector<Product> products, float cost);  // Constructor

    virtual float calculateEventCost() = 0;    // Abstraction
    virtual void showEventInfo() = 0;
    std::string getEventName();                  // Getters
    std::vector<Product> getEventProducts();
    float getTotalEventCost();

    virtual ~Event() {}   // Destructor

};

// Inheritance
class CoffeeTastingEvent: public Event {
    private:
    float marketingCost;

    public:
    CoffeeTastingEvent(std::string eventName, std::vector<Product> products, float cost, float marketingCost);

    float calculateEventCost() override;
    void showEventInfo() override;
};

class LiveMusicEvent: public Event {
    private:
    float bandCost, marketingCost;

    public:
    LiveMusicEvent(std::string eventName, std::vector<Product> products, float cost, float bandCost, float marketingCost);

    float calculateEventCost() override;
    void showEventInfo() override;
};

// Abstract Factory design pattern
class EventFactory {
    public:
    virtual Event* createCoffeeTastingEvent(std::string eventName, std::vector<Product> products, float cost, float marketingCost) = 0;
    virtual Event* createLiveMusicEvent(std::string eventName, std::vector<Product> products, float cost, float bandCost, float marketingCost) = 0;

    virtual ~EventFactory() = default; // Destructor
};

class CoffeeTastingEventFactory: public EventFactory {
    public:
    Event* createCoffeeTastingEvent(std::string eventName, std::vector<Product> products, float cost, float marketingCost) override;
    Event* createLiveMusicEvent(std::string eventName, std::vector<Product> products, float cost, float bandCost, float marketingCost) override;
};

class LiveMusicEventFactory: public EventFactory {
    public:
    Event* createCoffeeTastingEvent(std::string eventName, std::vector<Product> products, float cost, float marketingCost) override;
    Event* createLiveMusicEvent(std::string eventName, std::vector<Product> products, float cost, float bandCost, float marketingCost) override;
};

#endif