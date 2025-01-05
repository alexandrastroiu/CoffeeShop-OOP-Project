#include <iostream>
#include "../headers/employee.hpp"

using namespace std;

// Employee constructor
Employee::Employee(string name, string role, int start, int end, float payment)
{
    this->name = name;
    this->role = role;
    this->shiftStart = start;
    this->shiftEnd = end;
    this->payment = payment;
}

// Employee Destructor
Employee::~Employee() {}

void Employee::setName(std::string name)
{
    this->name = name;
}

void Employee::setRole(std::string role)
{
    this->role = role;
}

void Employee::setStart(int start)
{
    this->shiftStart = start;
}

void Employee::setEnd(int end)
{
    this->shiftEnd = end;
}

void Employee::setPayment(float payment)
{
    this->payment = payment;
}

std::string Employee::getEmployeeName()
{
    return name;
}

std::string Employee::getEmployeeRole()
{
    return role;
}

int Employee::getShiftStart()
{
    return shiftStart;
}

int Employee::getShiftEnd()
{
    return shiftEnd;
}

float Employee::getPayment()
{
    return payment;
}

bool Employee::operator==(const Employee &employee)
{
    return (this->name == employee.name && this->role == employee.role);
}

// Manager Constructor
Manager::Manager(string name, string role, int start, int end, float payment) : Employee(name, role, start, end, payment) {}

// Barista Constructor
Barista::Barista(string name, string role, int start, int end, float payment) : Employee(name, role, start, end, payment) {}

// Waiter Constructor
Waiter::Waiter(string name, string role, int start, int end, float payment) : Employee(name, role, start, end, payment) {}

// Methods
void Manager::showEmployeeInfo()
{
    cout << "Manager Info: " << endl;
    cout << "Name: " << this->name << " " << "Hours: " << this->shiftStart << " - " << this->shiftEnd << " Payment: " << this->payment << endl;
}

void Barista::showEmployeeInfo()
{
    cout << "Barista Info: " << endl;
    cout << "Name: " << this->name << " " << "Hours: " << this->shiftStart << " - " << this->shiftEnd << " Payment: " << this->payment << endl;
}

void Waiter::showEmployeeInfo()
{
    cout << "Waiter Info: " << endl;
    cout << "Name: " << this->name << " " << "Hours: " << this->shiftStart << " - " << this->shiftEnd << " Payment: " << this->payment << endl;
}

void Manager::updateEmployeeHours(int start, int end)
{
    cout << "Updated Manager hours." << endl;
    this->shiftStart = start;
    this->shiftEnd = end;
}

void Barista::updateEmployeeHours(int start, int end)
{
    cout << "Updated Barista hours." << endl;
    this->shiftStart = start;
    this->shiftEnd = end;
}

void Waiter::updateEmployeeHours(int start, int end)
{
    cout << "Updated Waiter hours." << endl;
    this->shiftStart = start;
    this->shiftEnd = end;
}

Employee *ManagerFactory::createManager(std::string name, std::string role, int start, int end, float payment)
{
    return new Manager(name, role, start, end, payment);
}

Employee *ManagerFactory::createBarista(std::string name, std::string role, int start, int end, float payment)
{
    return nullptr;
}

Employee *ManagerFactory::createWaiter(std::string name, std::string role, int start, int end, float payment)
{
    return nullptr;
}

Employee *BaristaFactory::createBarista(std::string name, std::string role, int start, int end, float payment)
{
    return new Barista(name, role, start, end, payment);
}

Employee *BaristaFactory::createManager(std::string name, std::string role, int start, int end, float payment)
{
    return nullptr;
}

Employee *BaristaFactory::createWaiter(std::string name, std::string role, int start, int end, float payment)
{
    return nullptr;
}

Employee *WaiterFactory::createWaiter(std::string name, std::string role, int start, int end, float payment)
{
    return new Waiter(name, role, start, end, payment);
}

Employee *WaiterFactory::createManager(std::string name, std::string role, int start, int end, float payment)
{
    return nullptr;
}

Employee *WaiterFactory::createBarista(std::string name, std::string role, int start, int end, float payment)
{
    return nullptr;
}
