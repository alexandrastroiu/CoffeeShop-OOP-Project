#include <iostream>
#include "../headers/product.hpp"

using namespace std;

// Constructor
Product::Product(string productName, string productType, int quantity, float price, float cost) {
    this->productName = productName;
    this->productType = productType;
    this->quantity = quantity;
    this->price = price;
    this->cost = cost;
}

// Setters
void Product::setProductName(string name) {
    productName = name;
}

void Product::setProductType(string type) {
    productType = type;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Product::setPrice(float price) {
    this->price = price;
}

void Product::setCost(float cost) {
    this->cost = cost;
}

// Getters
string Product::getProductName() {
    return this->productName;
}

string Product::getProductType() {
    return this->productType;
}

int Product::getQuantity() {
    return this->quantity;
}

float Product::getPrice() {
    return this->price;
}

float Product::getCost() {
    return this->cost;
}

// Method
void Product::showProductInfo() {
    cout << "Product Info: " << endl;
    cout << "Product Name: " << this->productName << " Product Type: " << this->productType << endl;
    cout << " Price: " << this->price << " Quantity: " << this->quantity << " Cost: " << this->cost << endl;
}