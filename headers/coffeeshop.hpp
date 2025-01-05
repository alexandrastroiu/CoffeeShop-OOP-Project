#ifndef COFFEESHOP_H
#define COFFEESHOP_H

#include "../headers/product.hpp"
#include "../headers/order.hpp"
#include "../headers/employee.hpp"
#include "../headers/event.hpp"
#include "../headers/file.hpp"

#include <string>
#include <vector>

class Coffeeshop
{
private: // Encapsulation
    std::string city;
    int employeesNumber;
    std::vector<Employee *> allEmployees;
    std::vector<Product> allProducts;
    std::vector<Order> allOrders;
    std::vector<Event *> allEvents;
    float dailyRevenue, dailyCost, dailyIncome, productsCost, employeesCost, eventsCost;

public:
    Coffeeshop(std::string city, int number); // Constructor

    void setCity(std::string name);      // Setter
    void setEmployeesNumber(int number); // Setter
    std::string getCity();               // Getter
    void showAllEmployees();
    void showAllProducts();
    void showAllOrders();
    void showAllEvents();
    int getEmployeesNumber();
    std::vector<Product> getAllProductsVector(); // Getter
    void showCoffeeshopInfo();
    void getAllEmployees(std::string fileName);
    void addEmployee(std::string fileName, std::string name, std::string role, int start, int end, float payment);
    void deleteEmployee(std::string fileName, std::string name, std::string role, int start, int end, float payment);
    void updateEmployeeHours(std::string fileName, std::string name, std::string role, int start, int end, float payment, int newStart, int newEnd);
    float calculateEmployeesCost();
    void getAllProducts(std::string fileName);
    void addProduct(std::string fileName, std::string productName, std::string productType, int quantity, float price, float cost);
    void deleteProduct(std::string fileName, std::string productName, std::string productType, int quantity, float price, float cost);
    float calculateProductsCost();
    void getAllOrders(std::string fileName);
    void placeOrder(std::string fileName, Order order);
    void getAllEvents(std::string fileName);
    void organizeEvent(std::string fileName, Event *event);
    float calculateEventsCost();
    float calculateDailyRevenue();
    float calculateDailyCost();
    float calculateDailyIncome();
    void createReport(std::string fileName);

    ~Coffeeshop(); // Destructor
};

#endif