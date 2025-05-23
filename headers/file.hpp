#ifndef FILE_H
#define FILE_H

#include "../headers/product.hpp"
#include "../headers/employee.hpp"
#include "../headers/event.hpp"

#include <string>
#include <vector>
#include <fstream>

class Order;

class FileHandling
{
private: // Encapsulation
    std::string fileName;

public:
    FileHandling(std::string fileName); // Constructor

    void setFileName(std::string fileName); // Setter
    std::string getFileName();              // Getter
    void addEmployeeToFile(std::string name, Employee *employee);
    void deleteEmployeeFromFile(std::string name, Employee *employee);
    void updateEmployeeFile(std::string name, Employee *employee, int start, int end);
    void readEmployeeData(std::string name, std::vector<Employee *> &employees);
    void addProductToFile(std::string name, Product product);
    void deleteProductFromFile(std::string name, Product product);
    void updateProductFile(std::string name, Product product, int newQuantity);
    void readProductData(std::string name, std::vector<Product> &products);
    void addOrderToFile(std::string name, Order order);
    int isLoyalCustomer(std::string name, std::string client);
    void readOrderData(std::string name, std::vector<Order> &orders);
    void addEventToFile(std::string name, Event *event);
    void readEventData(std::string name, std::vector<Event *> &events);
    void addReportToFile(std::string name, float revenue, float cost, float income, float productsCost, float employeesCost, float eventsCost);

    ~FileHandling() = default; // Default Destructor
};

#endif