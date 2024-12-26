#ifndef COFFEESHOP_H
#define COFFEESHOP_H

#include "../headers/product.hpp"
#include "../headers/order.hpp"
#include "../headers/employee.hpp"
#include "../headers/event.hpp"
#include "../headers/file.hpp"
#include <string>
#include <vector>

class Coffeeshop {
    private:       // Encapsulation
    std::string city;
    int employeesNumber;
    std::vector<Employee> allEmployees;
    std::vector<Product> allProducts;
    std::vector<Order> allOrders;
    std::vector<Event> allEvents;
    float dailyRevenue, dailyCost, dailyIncome, productsCost, employeesCost;
    

    public:
    Coffeeshop(std::string city, int number);  // Constructor
    
    //TODO: ADD REPORT AND FILES , CHECK METHODS  AND ATTRIBUTES AGAIN
    void setCity(std::string name);  // Setter
    void setEmployeesNumber(int number);
    std::string getCity();  // Getter
    int getEmployeesNumber();
    void showCoffeeshopInfo();
    void addEmployee();
    void deleteEmployee();
    void updateEmployeeHours();
    float calculateEmployeesCost();
    void addProduct();
    void deleteProduct();
    float calculateProductsCost();
    void placeOrder();
    void organizeEvent();
    float calculateDailyRevenue();
    float calculateDailyCost();
    float calculateDailyIncome();


    ~Coffeeshop() = default;  // Default Destructor
};

#endif