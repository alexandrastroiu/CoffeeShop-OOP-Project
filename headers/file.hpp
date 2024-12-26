#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include <fstream>
#include "../headers/product.hpp"
#include "../headers/order.hpp"
#include "../headers/employee.hpp"
#include "../headers/event.hpp"

class FileHandling {
private: // Encapsulation
    std::string fileName;

public:
    FileHandling(std::string fileName); // Constructor


    void setFileName(std::string fileName); // Setter
    std::string getFileName();              // Getter
    void addEmployeeToFile(std::string name, Employee* employee);
    void deleteEmployeeFromFile(std::string name, Employee* employee);
    void updateEmployeeFile(std::string name, Employee* employee, int start, int end);
    void readEmployeeData(std::string name, std::vector<Employee*>& employees);
    void addProductToFile(std::string name, Product product);
    void deleteProductFromFile(std::string name, Product product);
    void updateProductFile(std::string name, Product product);
    void readProductData(std::string name, std::vector<Product>& products);
    void addOrderToFile(std::string name, Order order);
    int isLoyalCustomer(std::string name, std::string client);
    void readOrderData();
    void addEventToFile(std::string name, Event* event);
    void readEventData();
    void addReportToFile(std::string name);
    void readReportData();


    ~FileHandling() = default; // Default Destructor
};

#endif