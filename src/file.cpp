#include <iostream>
#include <sstream>
#include "../headers/file.hpp"
#include "../headers/order.hpp"

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

void FileHandling::readEmployeeData(std::string name, std::vector<Employee*>& employees) {
    this->setFileName(name);

    try {             // Exceptions
        fstream in;

        in.open(fileName, ios::in);

        if (!in.is_open()) {
            throw "Error: Unable to open file.";
        }

        string line, word;
        vector<string> row;

        getline(in, line);
        
        while (getline(in, line))
        {
            row.clear();
            stringstream s(line);
            Employee* employee = nullptr;

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (row[1] == "Manager") {
                employee = new Manager(row[0], row[1], stoi(row[2]), stoi(row[3]), stof(row[4]));
            }
            else if (row[1] == "Barista") {
                employee = new Barista(row[0], row[1], stoi(row[2]), stoi(row[3]), stof(row[4]));
            }
            else if (row[1] == "Waiter") {
                employee = new Waiter(row[0], row[1], stoi(row[2]), stoi(row[3]), stof(row[4]));
            }

            if (employee != nullptr) {
                employees.push_back(employee);
            }

        }

        in.close();

    }
    catch(const char* message) {
        cout << message << endl;
        return;
    }
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

void FileHandling::updateProductFile(std::string name, Product product, int newQuantity) {

    this->setFileName(name);

    try {
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
            else
            {
                out << row[0] << "," << row[1] << "," << newQuantity << "," << row[3] << "," << row[4] << endl;
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

void FileHandling::readProductData(std::string name, std::vector<Product>& products) {

    this->setFileName(name);

    try {
        fstream in;

        in.open(fileName, ios::in);

        if (!in.is_open()) {
            throw "Error: Unable to open file.";
        }

        string line, word;
        vector<string> row;

        getline(in, line);

        while (getline(in, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }
 
           Product product(row[0], row[1], stoi(row[2]), stof(row[3]), stof(row[4]));
           products.push_back(product);
        }

        in.close();

    }
    catch(const char* message) {
        cout << message << endl;
        return;
    }
}

void FileHandling::addOrderToFile(std::string name, Order order) {

    this->setFileName(name);

    try {      // Exceptions
        fstream out;

        out.open(fileName, ios::app); /// append

        if (!out.is_open())
        {
            throw "Error: Unable to open file.";
        }
        out << order.getClientName() << ",";

        for(auto product : order.getProducts()) {
            out << product.getProductName() << ",";
        }

        out << order.calculateTotalPrice(name) << endl;

        out.close();
    }
    catch(const char* message) {
        cout << message << endl;
        return;
    }
}

int FileHandling::isLoyalCustomer(std::string name, std::string client) {
    int previousOrders = 0;
    this->setFileName(name);

    try {
        fstream in(fileName, ios::in);

        if (!in.is_open())
        {
            throw "Error: Unable to open file.";
        }

        string line, word;
        vector<string> row;

        getline(in, line);
        
        while (getline(in, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (!row.empty() && row[0] == client)
            {
                previousOrders++;
            }
        }

        in.close();

        if(previousOrders >= 2) {
            return 1;
        }
        return 0;
    }
    catch(const char* message) {
        cout << message << endl;
        return 0;
    }
}

void FileHandling::readOrderData(std::string name, std::vector<Order>& orders) {

    this->setFileName(name);

    try {
        fstream in;

        in.open(fileName, ios::in);

        if (!in.is_open()) {
            throw "Error: Unable to open file.";
        }

        string line, word;
        vector<string> row;

        getline(in, line);

        while (getline(in, line))
        {
            row.clear();
            stringstream s(line);
            std::vector<Product> orderProducts;

            while (getline(s, word, ','))
            {
                row.push_back(word);   //TODO CREATE FILES (CSV)
            }

            int size = row.size();

            for (int i = 1; i < size - 1; i++) {
                Product product(row[i]);
                orderProducts.push_back(product);
            }
          
            Order order(row[0], orderProducts);
            order.setTotalPrice(stof(row[size - 1]));
            orders.push_back(order);
        }

        in.close();
    }
    catch(const char* message) {
        cout << message << endl;
        return;
    }
}

void FileHandling::addEventToFile(std::string name, Event* event) {

    this->setFileName(name);

    try {     // Exceptions
        fstream out;

        out.open(fileName, ios::app); /// append

        if (!out.is_open())
        {
            throw "Error: Unable to open file.";
        }

        out << event->getEventName() << ",";

        for(auto product : event->getEventProducts()) {
            out << product.getProductName() << ",";
        }

        out << event->getTotalEventCost() << endl;

        out.close();
    }
    catch(const char* message) {
        cout << message << endl;
        return;
    }
}

void FileHandling::readEventData(std::string name, std::vector<Event*>& events) {

    this->setFileName(name);

    try {           // Exceptions
        fstream in;

        in.open(fileName, ios::in);

        if (!in.is_open()) {
            throw "Error: Unable to open file.";
        }

        string line, word;
        vector<string> row;
        std::vector<Product> eventProducts;

        getline(in, line);
        
        while (getline(in, line))
        {
            row.clear();
            stringstream s(line);
            Event* event;

            while (getline(s, word, ','))
            {
                row.push_back(word);  
            }

            int size = row.size();

            for (int i = 1; i < size - 1; i++) {
                Product product(row[i]);
                eventProducts.push_back(product);
            }
          
            if (row[1] == "Coffee Tasting") {
                event = new CoffeeTastingEvent(row[1], eventProducts, stof(row[size -1]));
            }
            else if (row[1] == "Live Music") {
                event = new LiveMusicEvent(row[1], eventProducts, stof(row[size - 1]));
            }

            events.push_back(event);
           
        }

        in.close();

    }
    catch(const char* message) {
        cout << message << endl;
        return;
    }
}

void FileHandling::addReportToFile(std::string name, float revenue, float cost, float income, float productsCost, float employeesCost, float eventsCost) {

    this->setFileName(name);

    try {              // Exceptions
        fstream out;

        out.open(fileName, ios::app); /// append

        if (!out.is_open())
        {
            throw "Error: Unable to open file.";
        }

        out << revenue << "," << cost << "," << income << "," << productsCost << "," << employeesCost << "," << eventsCost << endl;
        out.close();

    }
    catch(const char* message) {
        cout << message << endl;
        return;
    }
}