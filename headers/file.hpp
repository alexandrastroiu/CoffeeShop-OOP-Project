#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>

class FileHandling {
private: // Encapsulation
    std::string fileName;

public:
    FileHandling(std::string fileName); // Constructor


    void setFileName(std::string fileName); // Setter
    std::string getFileName();              // Getter
    addEmployeeToFile();
    deleteEmployeeFromFile();
    updateEmployeeFile();
    readEmployeeFile();
    addProductToFile();
    deleteProductFromFile();
    updateProductFile();
    readProductFile();
    addOrderToFile();
    readOrderFile();
    addEventToFile();
    readEventFile();
    addReportToFile();
    readReportFile();


    ~FileHandling() = default; // Default Destructor
};

#endif