#include <iostream>
#include "../headers/coffeeshop.hpp"

using namespace std;

Coffeeshop::Coffeeshop(std::string city, int number) {
    this->city = city;
    employeesNumber = number;
    dailyRevenue  = 0.0;
    dailyCost = 0.0;
    dailyIncome = 0.0;
    productsCost = 0.0;
    employeesCost = 0.0;
}

// Destructor
Coffeeshop::~Coffeeshop()
{
    for (auto employee : allEmployees)
    {
        delete employee;
    }
    for (auto event : allEvents)
    {
        delete event;
    }
}

void Coffeeshop::setCity(std::string name) {
    city = name;
}

void Coffeeshop::setEmployeesNumber(int number) {
    employeesNumber = number;
}

std::string Coffeeshop::getCity() {
    return city;
}

int Coffeeshop::getEmployeesNumber() {
    return employeesNumber;
}

void Coffeeshop::showCoffeeshopInfo() {
    cout << "City: " << city << endl;
    cout << "Employee number: " << employeesNumber << endl;
}

void Coffeeshop::getAllEmployees(std::string fileName, std::vector<Employee*>& allEmployees) {
    FileHandling file(fileName);

    file.readEmployeeData(fileName, allEmployees);
}

void Coffeeshop::addEmployee(std::string fileName, std::string name, std::string role, int start, int end, float payment) {
    Employee* employee;
    FileHandling file(fileName);

    if (role == "Manager") {
       employee = new Manager(name, role, start, end, payment);
    }
    else if (role == "Barista") {
        employee = new Barista(name, role, start, end, payment);

    }
    else if (role == "Waiter") {
        employee = new Waiter(name, role, start, end, payment);
    }

    file.addEmployeeToFile(fileName, employee);
}

void Coffeeshop::deleteEmployee(std::string fileName, std::string name, std::string role, int start, int end, float payment) {
    Employee* employee;
    FileHandling file(fileName);

    if (role == "Manager") {
       employee = new Manager(name, role, start, end, payment);
    }
    else if (role == "Barista") {
        employee = new Barista(name, role, start, end, payment);

    }
    else if (role == "Waiter") {
        employee = new Waiter(name, role, start, end, payment);
    }

    file.deleteEmployeeFromFile(fileName, employee);
}

void Coffeeshop::updateEmployeeHours(std::string fileName, std::string name, std::string role, int start, int end, float payment, int newStart, int newEnd) {
    Employee* employee;
    FileHandling file(fileName);

    if (role == "Manager") {
       employee = new Manager(name, role, start, end, payment);
    }
    else if (role == "Barista") {
        employee = new Barista(name, role, start, end, payment);

    }
    else if (role == "Waiter") {
        employee = new Waiter(name, role, start, end, payment);
    }

    file.updateEmployeeFile(fileName,employee, newStart, newEnd);
}

float Coffeeshop::calculateEmployeesCost() {

}

void Coffeeshop::getAllProducts(std::string fileName, std::vector<Product>& allProducts) {
    FileHandling file(fileName);

    file.readProductData(fileName, allProducts);
}

void Coffeeshop::addProduct(std::string fileName, std::string productName, std::string productType, int quantity, float price, float cost) {
    FileHandling file(fileName);
    Product newProduct(productName, productType, quantity, price, cost);

    for (auto& product : allProducts) {
        if (product.getProductName() == productName && product.getProductType() == productType) {
            file.updateProductFile(fileName, product, product.getQuantity() + 1);
            product.setQuantity(product.getQuantity() + 1);
            return;
        }
    }

    file.addProductToFile(fileName, newProduct);
    allProducts.push_back(newProduct);
}

void Coffeeshop::deleteProduct(std::string fileName,std::string productName, std::string productType, int quantity, float price, float cost) {
    FileHandling file(fileName);
    Product deletedProduct(productName, productType, quantity, price, cost);

    for (auto& product : allProducts) {
        if (product.getProductName() == productName && product.getProductType() == productType) {
            if (product.getQuantity() == 1) {
                file.deleteProductFromFile(fileName, deletedProduct);
                allProducts.erase(std::remove(allProducts.begin(), allProducts.end(), product), allProducts.end());
            }
            else {
                file.updateProductFile(fileName, deletedProduct, product.getQuantity() - 1);
                product.setQuantity(product.getQuantity() - 1);
            }
            return;
        }
    }
}

float Coffeeshop::calculateProductsCost() {

}

void Coffeeshop::getAllOrders(std::string fileName, std::vector<Order>& allOrders) {
    FileHandling file(fileName);

    file.readOrderData(fileName, allOrders);
}

void Coffeeshop::placeOrder(std::string fileName, Order order) {

}

void Coffeeshop::getAllEvents(std::string fileName, std::vector<Event*>& allEvents) {
    FileHandling file(fileName);

    file.readEventData(fileName, allEvents);
}

void Coffeeshop::organizeEvent(std::string fileName, Event* event) {

}

float Coffeeshop::calculateDailyRevenue() {

}

float Coffeeshop::calculateDailyCost() {

}

float Coffeeshop::calculateDailyIncome() {

}

void Coffeeshop::createReport() {

}
