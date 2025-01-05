#include "../headers/product.hpp"

#include <iostream>

using namespace std;

// Constructor
Product::Product(string productName, string productType, int quantity, float price, float cost)
{
    this->productName = productName;
    this->productType = productType;
    this->quantity = quantity;
    this->price = price;
    this->cost = cost;
}

Product::Product(std::string productName)
{
    this->productName = productName;
    productType = "";
    quantity = 0;
    price = 0.0;
    cost = 0.0;
}

// Setters
void Product::setProductName(string name)
{
    productName = name;
}

void Product::setProductType(string type)
{
    productType = type;
}

void Product::setQuantity(int quantity)
{
    this->quantity = quantity;
}

void Product::setPrice(float price)
{
    this->price = price;
}

void Product::setCost(float cost)
{
    this->cost = cost;
}

// Getters
string Product::getProductName()
{
    return productName;
}

string Product::getProductType()
{
    return productType;
}

int Product::getQuantity()
{
    return quantity;
}

float Product::getPrice()
{
    return price;
}

float Product::getCost()
{
    return cost;
}

// Method
void Product::showProductInfo()
{
    cout << "Product Info: " << endl;
    cout << "Product Name: " << productName << " Product Type: " << productType << endl;
    cout << " Price: " << price << " Quantity: " << quantity << " Cost: " << cost << endl;
}

bool Product::operator==(const Product &product)
{
    return (this->productName == product.productName && this->productType == product.productType && this->cost == product.cost && this->price == product.price && this->quantity == product.quantity);
}