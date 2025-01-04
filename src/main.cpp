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

    ///tested getAllEmployees,addEmployee,deleteEmployee,updateEmployeeHours
    ///tested getAllProducts,addProduct,deleteProduct
    //tested calculateEmployeesCost
    //tested calculateProductsCost
    //tested getAllOrders placeOrder
    //TODO: test getAllEvents organizeEvent calculateEventsCost
    //TODO: test calculateDailyRevenue calculateDailyCost calculateDailyIncome createReport

int main() {
    Coffeeshop coffeeshop("Bucharest",3); 

    // coffeeshop.getAllEmployees("../../data/employees_bucharest.csv");
    // coffeeshop.showAllEmployees();
    // coffeeshop.addEmployee("../../data/employees_bucharest.csv","Radu Ion", "Waiter", 9, 17, 120);
    // coffeeshop.addEmployee("../../data/employees_bucharest.csv","Ana Dan", "Waiter", 9, 17, 120);
    // coffeeshop.deleteEmployee("../../data/employees_bucharest.csv","Radu Ion", "Waiter", 9, 17, 120);
    // coffeeshop.showAllEmployees();
    // coffeeshop.updateEmployeeHours("../../data/employees_bucharest.csv","Ana Dan", "Waiter", 9, 17, 120, 9, 15);
    // cout << coffeeshop.calculateEmployeesCost() << endl;
    // coffeeshop.getAllProducts("../../data/products_bucharest.csv");
    // coffeeshop.addProduct("../../data/products_bucharest.csv", "Orange Juice", "Drinks", 1, 10, 5);
    // coffeeshop.showAllProducts();
    // coffeeshop.deleteProduct("../../data/products_bucharest.csv", "Orange Juice", "Drinks", 1, 10, 5);
    // coffeeshop.showAllProducts();

    // Product product1("Tea"), product2("Latte"); 
    // coffeeshop.getAllProducts("../../data/products_bucharest.csv");
    // cout << coffeeshop.calculateProductsCost() << endl;
    // coffeeshop.showAllProducts();
    // vector<Product> orderProducts = {product1, product2}, allProducts = coffeeshop.getAllProductsVector();
    // for (auto &orderProduct : orderProducts)
    // {
    //     for (auto product : allProducts)
    //     {
    //         if (product.getProductName() == orderProduct.getProductName())
    //         {
    //             orderProduct.setPrice(product.getPrice());
    //         }
    //     }
    // } 

    // Order order("Ana Mihai", orderProducts); 
    // cout << order.calculateTotalPrice("../../data/orders_bucharest.csv") << endl; 
    // coffeeshop.getAllOrders("../../data/orders_bucharest.csv");
    // coffeeshop.showAllOrders();
    // coffeeshop.placeOrder("../../data/orders_bucharest.csv", order);
    // coffeeshop.showAllOrders();

    LiveMusicEventFactory liveMusicFactory; //TODO: test events related methods
    Product product1("Latte");
    vector<Product> eventProducts = {product1};
    vector<Product> allProducts = coffeeshop.getAllProductsVector();
    for (auto &eventProduct : eventProducts)
    {
        for (auto product : allProducts)
        {
            if (product.getProductName() == eventProduct.getProductName())
            {
                eventProduct.setPrice(product.getPrice());
            }
        }
    } 
    Event* musicEvent = liveMusicFactory.createLiveMusicEvent("Live Music", eventProducts, 0, 500, 500);
    cout << musicEvent->calculateEventCost() << endl;
    musicEvent->showEventInfo();
    coffeeshop.getAllEvents("../../events_bucharest.csv");
    coffeeshop.showAllEvents();
    coffeeshop.organizeEvent("../../events_bucharest.csv", musicEvent);
    coffeeshop.getAllEvents("../../events_bucharest.csv");
    coffeeshop.showAllEvents();
    cout << coffeeshop.calculateEventsCost() << endl;
    

    return 0;
}