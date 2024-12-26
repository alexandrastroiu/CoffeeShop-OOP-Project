#include <iostream>
#include "../headers/event.hpp"

using namespace std;

// Event Constructor
Event::Event(std::string eventName, std::vector<Product> products, float cost) {
   this->eventName = eventName;
   this->products = products;
   totalEventCost = 0.0;
}

std::string Event::getEventName() {
    return eventName;
}

std::vector<Product> Event::getEventProducts() {
    return products;
}

float Event::getTotalEventCost() {
    return totalEventCost;
}

// CofeeTastingEvent Constructor
CoffeeTastingEvent::CoffeeTastingEvent(std::string eventName, std::vector<Product> products, float cost, float marketingCost): Event(eventName, products, cost) {
    this->marketingCost = marketingCost;
}

// LiveMusicEvent Constructor
LiveMusicEvent::LiveMusicEvent(std::string eventName, std::vector<Product> products, float cost, float bandCost, float marketingCost): Event(eventName, products, cost) {
    this->marketingCost = marketingCost;
    this->bandCost = bandCost;
}

void CoffeeTastingEvent::showEventInfo() {
    cout << "Cofee Tasting Event Info: " << endl;
    cout << "Total Cost: " << totalEventCost << endl;
    cout << "Marketing Cost: " << marketingCost << endl;
    cout << "Products: " << endl;

    for (auto product : products) {
        cout << product.getProductName() << " "; 
    }
}

void LiveMusicEvent::showEventInfo() {
    cout << "Live Music Event Info: " << endl;
    cout << "Total Cost: " << totalEventCost << endl;
    cout << "Marketing Cost: " << marketingCost << endl;
    cout << "Band Cost: " << bandCost << endl;
    cout << "Products: " << endl;

    for (auto product : products) {
        cout << product.getProductName() << " "; 
    }
}

float CoffeeTastingEvent::calculateEventCost() {
    float currentCost = 0.0;

    for (auto product : products) {
        currentCost += product.getCost();
    }

    currentCost += marketingCost;
    totalEventCost = currentCost;
    return currentCost;
}

float LiveMusicEvent::calculateEventCost() {
    float currentCost = 0.0;

    for (auto product : products) {
        currentCost += product.getCost();
    }

    currentCost += marketingCost + bandCost;
    totalEventCost = currentCost;
    return currentCost;
}

Event* CoffeeTastingEventFactory::createCoffeeTastingEvent(std::string eventName, std::vector<Product> products, float cost, float marketingCost) {
   return new CoffeeTastingEvent(eventName, products, cost, marketingCost);
}

Event* CoffeeTastingEventFactory::createLiveMusicEvent(std::string eventName, std::vector<Product> products, float cost, float bandCost, float marketingCost) {
    return nullptr;
}

Event* LiveMusicEventFactory::createLiveMusicEvent(std::string eventName, std::vector<Product> products, float cost, float bandCost, float marketingCost) {
   return new LiveMusicEvent(eventName, products, cost, bandCost, marketingCost);
}

Event* LiveMusicEventFactory::createCoffeeTastingEvent(std::string eventName, std::vector<Product> products, float cost, float marketingCost) {
    return nullptr;
}

