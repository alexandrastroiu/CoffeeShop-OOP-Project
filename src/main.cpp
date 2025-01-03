#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../headers/coffeeshop.hpp"
#include "../headers/file.hpp"
#include "../headers/event.hpp"
#include "../headers/employee.hpp"
#include "../headers/order.hpp"
#include "../headers/product.hpp"

using namespace std;

int main() {
    Coffeeshop coffeeshop("Bucharest",3); ///first test

    coffeeshop.getAllEmployees("../../data/employees_bucharest.csv");
    coffeeshop.addEmployee("../../data/employees_bucharest.csv","Radu Ion", "Waiter", 9, 17, 120);
    coffeeshop.addEmployee("../../data/employees_bucharest.csv","Ana Dan", "Waiter", 9, 17, 120);
    // coffeeshop.deleteEmployee("../data/employees_bucharest.csv","Radu Ion", "Waiter", 9, 17, 120);
    coffeeshop.updateEmployeeHours("../../data/employees_bucharest.csv","Ana Dan", "Waiter", 9, 17, 120, 9, 15);
    coffeeshop.getAllProducts("../../data/products_bucharest.csv");
    coffeeshop.addProduct("../../data/products_bucharest.csv", "Orange Juice", "Drinks", 5, 10, 5);

    return 0;
}