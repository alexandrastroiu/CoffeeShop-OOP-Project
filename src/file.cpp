#include <iostream>
#include <sstream>
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

void FileHandling::addEmployeeToFile(std::string name, Employee* employee) {

    this->setFileName(name);
    
    try{        // Exceptions
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

void FileHandling::deleteEmployeeFromFile(std::string name, Employee* employee) {

       this->setFileName(name);

       try {         // Exceptions
        fstream in, out;

        in.open(fileName, ios::in);
        out.open("output.csv", ios::out);

        if (!out.is_open() || !in.is_open())
        {
            throw "Error: Unable to open file.";
        }

        string line, word;
        vector<string> row;

        getline(in, line);
        out << line << endl;

        while (getline(in, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (!(row[0] == employee->getEmployeeName() && row[1] == employee->getEmployeeRole() && stoi(row[2]) == employee->getShiftStart() && stoi(row[3]) ==  employee->getShiftEnd() && stof(row[4]) == employee->getPayment()))
            {
                out << line << endl;
            }
        }

        in.close();
        out.close();

        remove(fileName.c_str());
        rename("output.csv", fileName.c_str());
       }
       catch(const char* message) {
        cout << message << endl;
        return;
       }
}

void FileHandling::updateEmployeeFile(std::string name, Employee* employee, int start, int end) {

     this->setFileName(name);

     try {                // Exceptions
        fstream in, out;

        in.open(fileName, ios::in);
        out.open("output.csv", ios::out);

        if (!out.is_open() || !in.is_open())
        {
            throw "Error: Unable to open file.";
        }

        string line, word;
        vector<string> row;

        getline(in, line);
        out << line << endl;

        while (getline(in, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (!(row[0] == employee->getEmployeeName() && row[1] == employee->getEmployeeRole() && stoi(row[2]) == employee->getShiftStart() && stoi(row[3]) ==  employee->getShiftEnd() && stof(row[4]) == employee->getPayment()))
            {
                out << line << endl;
            }
            else {
                row[2] = std::to_string(start);
                row[3] = std::to_string(end);
                out << row[0] << "," << row[1] << "," << row[2] << "," << row[3] << "," << row[4] << endl;
            }
        }

        in.close();
        out.close();

        remove(fileName.c_str());
        rename("output.csv", fileName.c_str());
     }
     catch(const char* message) {
        cout << message << endl;
        return;
     }
}

void FileHandling::readEmployeeData(std::string name, std::vector<Employee> employees) {

}

void FileHandling::addProductToFile(std::string name, Product product) {

    this->setFileName(name);

    try {        // Exceptions

        fstream out;

        out.open(fileName, ios::app); /// append

        if (!out.is_open())
        {
            throw "Error: Unable to open file.";
        }

        out << product.getProductName() << "," << product.getProductType() << "," << product.getQuantity() << "," << product.getPrice() << "," << product.getCost() << endl;

        out.close();
    }
    catch(const char* message) {
        cout << message << endl;
        return;
    }
}

void FileHandling::deleteProductFromFile(std::string name, Product product) {

    this->setFileName(name);

    try {      // Exceptions
        fstream in, out;

        in.open(fileName, ios::in);
        out.open("output.csv", ios::out);

        if (!out.is_open() || !in.is_open())
        {
            throw "Error: Unable to open file.";
        }

        string line, word;
        vector<string> row;

        getline(in, line);
        out << line << endl;

        while (getline(in, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (!(row[0] == product.getProductName() && row[1] == product.getProductType() && stoi(row[2]) == product.getQuantity() && stof(row[3]) ==  product.getPrice() && stof(row[4]) == product.getCost()))
            {
                out << line << endl;
            }
        }

        in.close();
        out.close();

        remove(fileName.c_str());
        rename("output.csv", fileName.c_str());
    }
    catch(const char* message) {
        cout << message << endl;
        return;
    }
}

