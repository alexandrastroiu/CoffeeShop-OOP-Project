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
    eventsCost = 0.0;
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

void Coffeeshop::showAllEmployees() {
    cout << "All employees: " << endl;
    for (auto employee : allEmployees) {
        cout << employee->getEmployeeName() << endl;
    }
}

void Coffeeshop::showAllEvents() {
    cout << "All events: " << endl;
    for (auto event : allEvents) {
        cout << event->getEventName() << endl;
    }
}

void Coffeeshop::showAllOrders() {
    cout << "All orders: " << endl;
    for (auto order : allOrders) {
        cout << order.getClientName() << endl;
    }
}

void Coffeeshop::showAllProducts() {
    cout << "All products: " << endl;
    for (auto product : allProducts) {
        cout << product.getProductName() << endl;
    }
}

void Coffeeshop::showCoffeeshopInfo() {
    cout << "City: " << city << endl;
    cout << "Employee number: " << employeesNumber << endl;
}

void Coffeeshop::getAllEmployees(std::string fileName) {
    FileHandling file(fileName);

    file.readEmployeeData(fileName, allEmployees);
}

void Coffeeshop::addEmployee(std::string fileName, std::string name, std::string role, int start, int end, float payment) {
    Employee* employee = nullptr;
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

    if (employee != nullptr) {

        file.addEmployeeToFile(fileName, employee);
        allEmployees.push_back(employee);
    }
}

void Coffeeshop::deleteEmployee(std::string fileName, std::string name, std::string role, int start, int end, float payment) {
    Employee* employee = nullptr;
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

    if (employee != nullptr) {
        file.deleteEmployeeFromFile(fileName, employee); 
        
        auto it = find( allEmployees.begin(), allEmployees.end(), employee);
        if (it != allEmployees.end()) {
            allEmployees.erase(it);
        }
    
        delete employee;
    }
}

void Coffeeshop::updateEmployeeHours(std::string fileName, std::string name, std::string role, int start, int end, float payment, int newStart, int newEnd) {
    Employee* employee = nullptr;
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

    if (employee != nullptr) {
        file.updateEmployeeFile(fileName, employee, newStart, newEnd);
        delete employee;
    }
}

float Coffeeshop::calculateEmployeesCost() {
    float cost = 0.0;

    for (auto employee : allEmployees) {
        cost += employee->getPayment();
    }

    employeesCost = cost;
    return cost;
}

void Coffeeshop::getAllProducts(std::string fileName) {
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
                allProducts.erase(find( allProducts.begin(), allProducts.end(), deletedProduct));
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
    float cost = 0.0;

    for (auto product : allProducts) {
        cost +=  product.getCost();
    }

    productsCost = cost;
    return cost;
}

void Coffeeshop::getAllOrders(std::string fileName) {
    FileHandling file(fileName);

    file.readOrderData(fileName, allOrders);
}

void Coffeeshop::placeOrder(std::string fileName, Order order) {
    FileHandling file(fileName);

    file.addOrderToFile(fileName, order);
    allOrders.push_back(order);
}

void Coffeeshop::getAllEvents(std::string fileName) {
    FileHandling file(fileName);

    file.readEventData(fileName, allEvents);
}

void Coffeeshop::organizeEvent(std::string fileName, Event* event) {
    FileHandling file(fileName);

    file.addEventToFile(fileName, event);
    allEvents.push_back(event);
}

float Coffeeshop::calculateEventsCost() {
    float cost = 0.0;

    for (auto event : allEvents) {
        cost += event->getTotalEventCost();
    }

    eventsCost = cost;
    return cost;
}

float Coffeeshop::calculateDailyRevenue() {
    float sum = 0.0;

    for (auto order : allOrders) {
        sum += order.getTotalPrice();
    }
 
    dailyRevenue = sum;
    return sum;
}

float Coffeeshop::calculateDailyCost() {
    dailyCost = productsCost + employeesCost + eventsCost;
    return dailyCost;
}

float Coffeeshop::calculateDailyIncome() {
    dailyIncome = dailyRevenue - dailyCost;
    return dailyIncome;
}

void Coffeeshop::createReport(std::string fileName) {
    FileHandling file(fileName);

    file.addReportToFile(fileName, dailyRevenue, dailyCost, dailyIncome, productsCost, employeesCost, eventsCost);
}