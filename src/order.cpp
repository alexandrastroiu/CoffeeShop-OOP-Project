#include "../headers/order.hpp"

#include <iostream>

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

float Order::getTotalPrice() { 
    return totalPrice;
}

void Order::showOrderInfo() {
    cout << "Order Info: " << endl;
    cout << "Client: " << clientName << endl;
    cout << "Products: ";

    for (auto product : products) {
        cout << product.getProductName() << " "; 
    }
}

float Order::calculateTotalPrice(std::string name)
{
    float sum = 0.0;
    FileHandling file(name);

    for (auto product : products)
    {
        sum += product.getPrice();
    }

    if (file.isLoyalCustomer(name, clientName)) // apply discount
    { 
        totalPrice = sum / 2;
    }
    else
    {
        totalPrice = sum;
    }

    return totalPrice;
}