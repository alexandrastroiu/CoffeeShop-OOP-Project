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
    void updateEmployeeFile(std::string name, Employee* employee);
    void readEmployeeData(std::string name);
    void addProductToFile();
    void deleteProductFromFile();
    void updateProductFile();
    void readProductData();
    void addOrderToFile();
    int isLoyalCustomer();
    void readOrderData();
    void addEventToFile();
    void readEventData();
    void addReportToFile();
    void readReportData();


    ~FileHandling() = default; // Default Destructor
};

#endif