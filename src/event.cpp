#include <iostream>
#include "../headers/event.hpp"

using namespace std;

// Event Constructor
Event::Event(std::vector<Product> products, float cost) {
   this->products = products;
   totalEventCost = 0.0;
}

// CofeeTastingEvent Constructor
CoffeeTastingEvent::CoffeeTastingEvent(std::vector<Product> products, float cost, float marketingCost): Event(products, cost) {
    this->marketingCost = marketingCost;
}

// LiveMusicEvent Constructor
LiveMusicEvent::LiveMusicEvent(std::vector<Product> products, float cost, float bandCost, float marketingCost): Event(products, cost) {
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

Event* CoffeeTastingEventFactory::createCoffeeTastingEvent(std::vector<Product> products, float cost, float marketingCost) {
   return new CoffeeTastingEvent(products, cost, marketingCost);
}

Event* CoffeeTastingEventFactory::createLiveMusicEvent(std::vector<Product> products, float cost, float bandCost, float marketingCost) {
    return nullptr;
}

Event* LiveMusicEventFactory::createLiveMusicEvent(std::vector<Product> products, float cost, float bandCost, float marketingCost) {
   return new LiveMusicEvent(products, cost, bandCost, marketingCost);
}

Event* LiveMusicEventFactory::createCoffeeTastingEvent(std::vector<Product> products, float cost, float marketingCost) {
    return nullptr;
}

