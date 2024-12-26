#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include <fstream>

class FileHandling {
private: // Encapsulation
    std::string fileName;

public:
    FileHandling(std::string fileName); // Constructor


    void setFileName(std::string fileName); // Setter
    std::string getFileName();              // Getter
    void addEmployeeToFile();
    void deleteEmployeeFromFile();
    void updateEmployeeFile();
    void readEmployeeFile();
    void addProductToFile();
    void deleteProductFromFile();
    void updateProductFile();
    void readProductFile();
    void addOrderToFile();
    void readOrderFile();
    void addEventToFile();
    void readEventFile();
    void addReportToFile();
    void readReportFile();


    ~FileHandling() = default; // Default Destructor
};

#endif