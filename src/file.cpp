#include <iostream>
#include "../headers/file.hpp"

using namespace std;

FileHandling::FileHandling(std::string fileName) {
    this->fileName = fileName;
}

void FileHandling::setFileName(std::string fileName) {
    this->fileName = fileName;
}

std::string FileHandling::getFileName() {
    return fileName;
}

void FileHandling::addEmployeeToFile(std::string name, Employee* employee){

    this->setFileName(name);

    try{
        fstream out;

        out.open(fileName, ios::app); /// append

        if (!out.is_open())
        {
            throw "Error: Unable to open file.";
        }
 
        out << employee->getEmployeeName() << "," << employee->getEmployeeRole() << "," << employee->getShiftStart() << "," << employee->getShiftEnd() << "," << employee->getPayment() << endl;

        out.close();
    }
    catch(const char* message) {
        cout << message << endl;
        return;
    }
}