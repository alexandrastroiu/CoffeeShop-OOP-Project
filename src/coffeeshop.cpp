#include "../headers/coffeeshop.hpp"

#include <iostream>

using namespace std;

Coffeeshop::Coffeeshop(std::string city, int number)
{
    this->city = city;
    employeesNumber = number;
    dailyRevenue = 0.0;
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

void Coffeeshop::setCity(std::string name)
{
    city = name;
}

void Coffeeshop::setEmployeesNumber(int number)
{
    employeesNumber = number;
}

std::string Coffeeshop::getCity()
{
    return city;
}

int Coffeeshop::getEmployeesNumber()
{
    return employeesNumber;
}

std::vector<Product> Coffeeshop::getAllProductsVector()
{
    return allProducts;
}

void Coffeeshop::showAllEmployees()
{
    try // Exceptions
    {
        cout << endl
             << "All employees: " << endl;
        for (auto employee : allEmployees)
        {
            cout << employee->getEmployeeName() << endl;
        }

        if (allEmployees.empty())
        {
            throw "No employees to show.";
        }
    }
    catch (const char *message)
    {
        cout << endl
             << message << endl;
        return;
    }
}

void Coffeeshop::showAllEvents()
{
    try // Exceptions
    {
        if (allEvents.empty())
        {
            throw "No events to show.";
        }

        cout << endl
             << "All events: " << endl;
        for (auto event : allEvents)
        {
            cout << event->getEventName() << endl;
        }
    }
    catch (const char *message)
    {
        cout << endl
             << message << endl;
        return;
    }
}

void Coffeeshop::showAllOrders()
{
    try // Exceptions
    {
        cout << endl
             << "All orders: " << endl;
        for (auto order : allOrders)
        {
            cout << order.getClientName() << endl;
        }

        if (allOrders.empty())
        {
            throw "No orders to show.";
        }
    }
    catch (const char *message)
    {
        cout << endl
             << message << endl;
        return;
    }
}

void Coffeeshop::showAllProducts()
{
    try // Exceptions
    {
        cout << endl
             << "All products: " << endl;
        for (auto product : allProducts)
        {
            cout << product.getProductName() << endl;
        }

        if (allProducts.empty())
        {
            throw "No products to show.";
        }
    }
    catch (const char *message)
    {
        cout << endl
             << message << endl;
        return;
    }
}

void Coffeeshop::showCoffeeshopInfo()
{
    cout << endl
         << "Coffeeshop Info: " << endl;
    cout << "City: " << city << endl;
    cout << "Employee number: " << employeesNumber << endl;
}

void Coffeeshop::getAllEmployees(std::string fileName)
{
    FileHandling file(fileName);

    file.readEmployeeData(fileName, allEmployees);
}

void Coffeeshop::addEmployee(std::string fileName, std::string name, std::string role, int start, int end, float payment)
{
    Employee *employee = nullptr;
    FileHandling file(fileName);

    if (role == "Manager")
    {
        employee = new Manager(name, role, start, end, payment);
    }
    else if (role == "Barista")
    {
        employee = new Barista(name, role, start, end, payment);
    }
    else if (role == "Waiter" || role == "Ospatar")
    {
        employee = new Waiter(name, role, start, end, payment);
    }

    if (employee != nullptr)
    {

        file.addEmployeeToFile(fileName, employee);
        allEmployees.push_back(employee);
    }
}

void Coffeeshop::deleteEmployee(std::string fileName, std::string name, std::string role, int start, int end, float payment)
{
    Employee *employee = nullptr;
    FileHandling file(fileName);

    if (role == "Manager")
    {
        employee = new Manager(name, role, start, end, payment);
    }
    else if (role == "Barista")
    {
        employee = new Barista(name, role, start, end, payment);
    }
    else if (role == "Waiter" || role == "Ospatar")
    {
        employee = new Waiter(name, role, start, end, payment);
    }

    if (employee != nullptr)
    {
        file.deleteEmployeeFromFile(fileName, employee);

        auto it = find_if(allEmployees.begin(), allEmployees.end(), [employee](Employee *currentEmployee)
                          { return (currentEmployee->getEmployeeName() == employee->getEmployeeName() && currentEmployee->getEmployeeRole() == employee->getEmployeeRole()); });
        if (it != allEmployees.end())
        {
            allEmployees.erase(it);
        }

        delete employee;
    }
}

void Coffeeshop::updateEmployeeHours(std::string fileName, std::string name, std::string role, int start, int end, float payment, int newStart, int newEnd)
{
    Employee *employee = nullptr;
    FileHandling file(fileName);

    if (role == "Manager")
    {
        employee = new Manager(name, role, start, end, payment);
    }
    else if (role == "Barista")
    {
        employee = new Barista(name, role, start, end, payment);
    }
    else if (role == "Waiter" || role == "Ospatar") // Import and export csv files in Romanian and English
    {
        employee = new Waiter(name, role, start, end, payment);
    }

    if (employee != nullptr)
    {
        file.updateEmployeeFile(fileName, employee, newStart, newEnd);
        delete employee;
    }
}

float Coffeeshop::calculateEmployeesCost()
{
    float cost = 0.0;

    for (auto employee : allEmployees)
    {
        cost += employee->getPayment();
    }

    employeesCost = cost;
    return cost;
}

void Coffeeshop::getAllProducts(std::string fileName)
{
    FileHandling file(fileName);

    file.readProductData(fileName, allProducts);
}

void Coffeeshop::addProduct(std::string fileName, std::string productName, std::string productType, int quantity, float price, float cost)
{
    FileHandling file(fileName);
    Product newProduct(productName, productType, quantity, price, cost);

    for (auto &product : allProducts)
    {
        if (product.getProductName() == productName && product.getProductType() == productType)
        {
            file.updateProductFile(fileName, product, product.getQuantity() + 1);
            product.setQuantity(product.getQuantity() + 1);
            return;
        }
    }

    file.addProductToFile(fileName, newProduct);
    allProducts.push_back(newProduct);
}

void Coffeeshop::deleteProduct(std::string fileName, std::string productName, std::string productType, int quantity, float price, float cost)
{
    FileHandling file(fileName);
    Product deletedProduct(productName, productType, quantity, price, cost);

    for (auto &product : allProducts)
    {
        if (product.getProductName() == productName && product.getProductType() == productType)
        {
            if (product.getQuantity() == 1)
            {
                file.deleteProductFromFile(fileName, deletedProduct);
                auto it = find(allProducts.begin(), allProducts.end(), deletedProduct);
                if (it != allProducts.end())
                {
                    allProducts.erase(it);
                }
            }
            else
            {
                file.updateProductFile(fileName, deletedProduct, product.getQuantity() - 1);
                product.setQuantity(product.getQuantity() - 1);
            }
            return;
        }
    }
}

float Coffeeshop::calculateProductsCost()
{
    float cost = 0.0;

    for (auto product : allProducts)
    {
        cost += product.getCost() * product.getQuantity();
    }

    productsCost = cost;
    return cost;
}

void Coffeeshop::getAllOrders(std::string fileName)
{
    FileHandling file(fileName);

    file.readOrderData(fileName, allOrders);
}

void Coffeeshop::placeOrder(std::string fileName, Order order)
{
    FileHandling file(fileName);

    file.addOrderToFile(fileName, order);
    allOrders.push_back(order);
}

void Coffeeshop::getAllEvents(std::string fileName)
{
    FileHandling file(fileName);

    file.readEventData(fileName, allEvents);
}

void Coffeeshop::organizeEvent(std::string fileName, Event *event)
{
    FileHandling file(fileName);

    file.addEventToFile(fileName, event);
    allEvents.push_back(event);
}

float Coffeeshop::calculateEventsCost()
{
    float cost = 0.0;

    for (auto event : allEvents)
    {
        cost += event->getTotalEventCost();
    }

    eventsCost = cost;
    return cost;
}

float Coffeeshop::calculateDailyRevenue()
{
    float sum = 0.0;

    for (auto order : allOrders)
    {
        sum += order.getTotalPrice();
    }

    dailyRevenue = sum;
    return sum;
}

float Coffeeshop::calculateDailyCost()
{
    dailyCost = productsCost + employeesCost + eventsCost;
    return dailyCost;
}

float Coffeeshop::calculateDailyIncome()
{
    dailyIncome = dailyRevenue - dailyCost;
    return dailyIncome;
}

void Coffeeshop::createReport(std::string fileName)
{
    FileHandling file(fileName);

    file.addReportToFile(fileName, dailyRevenue, dailyCost, dailyIncome, productsCost, employeesCost, eventsCost);
}