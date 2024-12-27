#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
    private:      // Encapsulation 
    std::string productName, productType;
    int quantity;
    float price;
    float cost;

    public:
    Product(std::string productName, std::string productType, int quantity, float price, float cost);
    Product(std::string productName);

    void setProductName(std::string name);  // Setters
    void setProductType(std::string type);
    void setQuantity(int quantity);
    void setPrice(float price);
    void setCost(float cost);
    void showProductInfo();          // Method
    std::string getProductName();   // Getters
    std::string getProductType();
    int getQuantity();
    float getPrice();
    float getCost();

   ~Product() = default; // Default Destructors
};

#endif