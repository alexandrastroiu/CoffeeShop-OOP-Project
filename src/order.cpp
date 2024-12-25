#include <iostream>
#include "../headers/order.hpp"

using namespace std;

// Constructor
Order::Order(string clientName, vector<Product> products) {
    this->clientName = clientName;
    this->products =  products;
    totalPrice = 0.0;
}

void Order::setClientName(string name) {
    clientName = name;
}

void Order::setProducts(vector<Product> products) {
    this->products = products;
}

void Order::setTotalPrice(float price) {
    totalPrice = price;
}

vector<Product> Order::getProducts() {
    return products;

}

string Order::getClientName() {
   return clientName;
}

void Order::showOrderInfo() {
    cout << "Order Info: " << endl;
    cout << "Client: " << clientName << endl;
    cout << "Products: ";

    for (auto product : products) {
        cout << product.getProductName() << " "; 
    }
}

float Order::calculateTotalPrice() {
    float sum = 0.0;
    for (auto product : products) {
        float currentPrice = product.getPrice();
        sum += currentPrice;
    }
   
    return sum;
}

//TODO: sistem de reduceri

