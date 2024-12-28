#ifndef ORDER_H
#define ORDER_H

#include "../headers/product.hpp"
#include <string>
#include <vector>

class Order {
    private:
    std::string clientName;
    std::vector<Product> products;
    float totalPrice;

    public:
    Order(std::string clientName, std::vector<Product> products);  // Constructor

    void showOrderInfo(); //Method
    void setClientName(std::string name); // Setter
    void setProducts(std::vector<Product> products); //Setter 
    void setTotalPrice(float price);
    std::string getClientName(); //Getter
    std::vector<Product> getProducts(); // Getter
    float getTotalPrice(); // Getter
    float calculateTotalPrice(); // Method

    ~Order() = default;  // Default Destructor
};

#endif