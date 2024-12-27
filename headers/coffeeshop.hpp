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
    std::vector<Employee*> allEmployees; 
    std::vector<Product> allProducts;
    std::vector<Order> allOrders;
    std::vector<Event*> allEvents;
    float dailyRevenue, dailyCost, dailyIncome, productsCost, employeesCost;
    

    public:
    Coffeeshop(std::string city, int number);  // Constructor
    
    //TODO: ADD REPORT AND FILES , CHECK METHODS  AND ATTRIBUTES AGAIN
    void setCity(std::string name);  // Setter
    void setEmployeesNumber(int number);
    std::string getCity();  // Getter
    int getEmployeesNumber();
    void showCoffeeshopInfo();
    void getAllEmployees(std::string fileName, std::vector<Employee*>& allEmployees);
    void addEmployee(std::string fileName, std::string name, std::string role, int start, int end, float payment);
    void deleteEmployee(std::string fileName, std::string name, std::string role, int start, int end, float payment);
    void updateEmployeeHours(std::string fileName, std::string name, std::string role, int start, int end, float payment, int newStart, int newEnd);
    float calculateEmployeesCost(); ///TODO
    void getAllProducts(std::string fileName, std::vector<Product>& allProducts);
    void addProduct(std::string fileName, std::string productName, std::string productType, int quantity, float price, float cost);
    void deleteProduct(std::string fileName,std::string productName, std::string productType, int quantity, float price, float cost);
    float calculateProductsCost();
    void getAllOrders(std::string fileName, std::vector<Order>& allOrders);
    void placeOrder(std::string fileName, Order order); ///todo
    void getAllEvents(std::string fileName, std::vector<Event*>& allEvents);
    void organizeEvent(std::string fileName, Event* event); ///TODO
    float calculateDailyRevenue(); //TODO
    float calculateDailyCost();   //TODO  
    float calculateDailyIncome();  //TODO
    void createReport(std::string fileName, float revenue, float cost, float income, float productsCost, float employeesCost);

   ~Coffeeshop(); // Destructor
};

#endif