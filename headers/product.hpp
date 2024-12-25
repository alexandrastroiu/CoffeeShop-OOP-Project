#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
    private:      // Encapsulation 
    std::string productName, productType;
    int quantity;
    float price;

    public:
    Product(std::string productName, std::string productType, int quantity, float price);

    void setProductName(std::string name);  // Setters
    void setProductType(std::string type);
    void setQuantity(int quantity);
    void setPrice(float price);
    void showProductInfo();          // Method
    std::string getProductName();   // Getters
    std::string getProductType();
    int getQuantity();
    float getPrice();

   ~Product() = default; // Default Destructors
};

#endif