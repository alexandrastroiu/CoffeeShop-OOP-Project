#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
protected:
    std::string name, role;
    int shiftStart, shiftEnd;
    float payment;

public:
    Employee(std::string name, std::string role, int start, int end, float payment);

    virtual void showEmployeeInfo() = 0;     /// Abstraction
    virtual void updateEmployeeHours(int start, int end) = 0;
    std::string getEmployeeName();   // Getters
    std::string getEmployeeRole();
    int getShiftStart();
    int getShiftEnd();
    float getPayment();

    virtual ~Employee(); /// Destructor
};

/// Inheritance
class Manager : public Employee {
public:
    Manager(std::string name, std::string role, int start, int end, float payment);

    void showEmployeeInfo() override;
    void updateEmployeeHours(int start, int end) override;
};

class Barista : public Employee {
public:
    Barista(std::string name, std::string role, int start, int end, float payment);

    void showEmployeeInfo() override;
    void updateEmployeeHours(int start, int end)  override;
};

class Waiter : public Employee {
public:
    Waiter(std::string name, std::string role, int start, int end, float payment);

    void showEmployeeInfo() override;  /// Polymorphism
    void updateEmployeeHours(int start, int end) override;
};

/// Abstract Factory Pattern
class EmployeeFactory {
    public:
    virtual Employee* createManager(std::string name, std::string role, int start, int end, float payment) = 0;
    virtual Employee* createBarista(std::string name, std::string role, int start, int end, float payment) = 0;
    virtual Employee* createWaiter(std::string name, std::string role, int start, int end, float payment) = 0;

    virtual ~EmployeeFactory() = default; /// Destructor
};

class ManagerFactory: public EmployeeFactory {
public:
    Employee *createManager(std::string name, std::string role, int start, int end, float payment) override;
    Employee *createBarista(std::string name, std::string role, int start, int end, float payment) override;
    Employee *createWaiter(std::string name, std::string role, int start, int end, float payment) override;
};

class BaristaFactory: public EmployeeFactory {
public:
    Employee *createManager(std::string name, std::string role, int start, int end, float payment) override;
    Employee *createBarista(std::string name, std::string role, int start, int end, float payment) override;
    Employee *createWaiter(std::string name, std::string role, int start, int end, float payment) override;
};

class WaiterFactory: public EmployeeFactory {
public:
    Employee *createManager(std::string name, std::string role, int start, int end, float payment) override;
    Employee *createBarista(std::string name, std::string role, int start, int end, float payment) override;
    Employee *createWaiter(std::string name, std::string role, int start, int end, float payment) override;
};

#endif