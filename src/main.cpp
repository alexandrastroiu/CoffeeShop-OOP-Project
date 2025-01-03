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
    ///tested getAllEmployees,addEmployee,deleteEmployee,updateEmployeeHours
    ///tested getAllProducts,addProduct,deleteProduct
    //TODO: test calculateEmployeesCost
    //TODO: test calculateProductsCost
    //TODO: test getAllOrders placeOrder
    //TODO: test getAllEvents organizeEvent calculateEventsCost
    //TODO: test calculateDailyRevenue calculateDailyCost calculateDailyIncome createReport

    // coffeeshop.getAllEmployees("../../data/employees_bucharest.csv");
    // coffeeshop.showAllEmployees();
    // coffeeshop.addEmployee("../../data/employees_bucharest.csv","Radu Ion", "Waiter", 9, 17, 120);
    // coffeeshop.addEmployee("../../data/employees_bucharest.csv","Ana Dan", "Waiter", 9, 17, 120);
    // coffeeshop.deleteEmployee("../../data/employees_bucharest.csv","Radu Ion", "Waiter", 9, 17, 120);
    // coffeeshop.showAllEmployees();
    // coffeeshop.updateEmployeeHours("../../data/employees_bucharest.csv","Ana Dan", "Waiter", 9, 17, 120, 9, 15);
    // coffeeshop.getAllProducts("../../data/products_bucharest.csv");
    // coffeeshop.addProduct("../../data/products_bucharest.csv", "Orange Juice", "Drinks", 1, 10, 5);
    // coffeeshop.showAllProducts();
    // coffeeshop.deleteProduct("../../data/products_bucharest.csv", "Orange Juice", "Drinks", 1, 10, 5);
    // coffeeshop.showAllProducts();
    // coffeeshop.getAllOrders("../../data/orders_bucharest.csv");


    Product product1("Tea"), product2("Latte");
    vector<Product> orderProducts = {product1, product2}, allProducts = coffeeshop.getAllProductsVector();
    for (auto &orderProduct : orderProducts)
    {
        for (auto product : allProducts)
        {
            if (product.getProductName() == orderProduct.getProductName())
            {
                orderProduct.setPrice(product.getPrice());
            }
        }
    }
    
    Order order("Ana Mihai", orderProducts);
    cout << order.calculateTotalPrice("../../data/orders_bucharest.csv") << endl;
    coffeeshop.getAllOrders("../../data/orders_bucharest.csv");
    coffeeshop.showAllOrders();
    coffeeshop.placeOrder("../../data/orders_bucharest.csv", order);
    coffeeshop.showAllOrders();

    return 0;
}