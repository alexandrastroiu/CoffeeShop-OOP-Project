#include "../headers/coffeeshop.hpp"
#include "../headers/file.hpp"
#include "../headers/event.hpp"
#include "../headers/employee.hpp"
#include "../headers/order.hpp"
#include "../headers/product.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    Coffeeshop coffeeshop("Bucharest", 3);
    Product orangeJuice("Orange Juice", "Drinks", 1, 10, 5); // Create a new product
    Product lemonade("Lemonade", "Drinks", 1, 15, 7);        // Create a new product

    coffeeshop.getAllEmployees("../../data/employees_bucharest.csv");
    coffeeshop.showAllEmployees();
    coffeeshop.addEmployee("../../data/employees_bucharest.csv", "Radu Ion", "Waiter", 9, 17, 120);     // Add a new employee
    coffeeshop.addEmployee("../../data/employees_bucharest.csv", "Ana Dan", "Waiter", 9, 17, 120);      // Add a new employee
    coffeeshop.addEmployee("../../data/employees_bucharest.csv", "Elena Ion", "Barista", 9, 17, 200);   // Add a new employee
    coffeeshop.addEmployee("../../data/employees_bucharest.csv", "Diana Mihai", "Manager", 9, 16, 220); // Add a new employee
    coffeeshop.deleteEmployee("../../data/employees_bucharest.csv", "Radu Ion", "Waiter", 9, 17, 120);  // Delete an employee
    coffeeshop.showAllEmployees();
    coffeeshop.updateEmployeeHours("../../data/employees_bucharest.csv", "Ana Dan", "Waiter", 9, 17, 120, 9, 15); // Update employee hours
    coffeeshop.getAllProducts("../../data/products_bucharest.csv");
    coffeeshop.addProduct("../../data/products_bucharest.csv", "Orange Juice", "Drinks", 1, 10, 5); // Add a new product
    orangeJuice.showProductInfo();                                                                  // Show product information
    coffeeshop.addProduct("../../data/products_bucharest.csv", "Lemonade", "Drinks", 1, 15, 7);     // Add a new product
    lemonade.showProductInfo();                                                                     // Show product information
    coffeeshop.showAllProducts();
    coffeeshop.deleteProduct("../../data/products_bucharest.csv", "Orange Juice", "Drinks", 1, 10, 5); // Delete a product
    coffeeshop.showAllProducts();

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

    Order order("Ana Mihai", orderProducts); // Create a new order
    order.showOrderInfo();                   // Show order information
    cout << endl
         << "Order Price: " << order.calculateTotalPrice("../../data/orders_bucharest.csv") << endl; // Calculate the total price of the current order
    coffeeshop.getAllOrders("../../data/orders_bucharest.csv");
    coffeeshop.showAllOrders();
    coffeeshop.placeOrder("../../data/orders_bucharest.csv", order); // Place a new order
    coffeeshop.showAllOrders();                                      // Show all orders

    LiveMusicEventFactory liveMusicFactory;
    Product product3("Latte"), product4("Tea"), product5("Espresso");
    vector<Product> eventProducts = {product3, product4, product5};
    allProducts = coffeeshop.getAllProductsVector(); // Get all the products in the menu
    for (auto &eventProduct : eventProducts)
    {
        for (auto product : allProducts)
        {
            if (product.getProductName() == eventProduct.getProductName())
            {
                eventProduct.setCost(product.getCost()); // Set the event products cost
            }
        }
    }

    try // Exceptions
    {
        Event *musicEvent = liveMusicFactory.createLiveMusicEvent("Live Music", eventProducts, 0, 500, 500); // Create a new event
        cout << endl
             << "New event cost: " << musicEvent->calculateEventCost() << endl;
        musicEvent->showEventInfo(); // Show current event information
        coffeeshop.getAllEvents("../../data/events_bucharest.csv");
        coffeeshop.showAllEvents();                                              // Show all events
        coffeeshop.organizeEvent("../../data/events_bucharest.csv", musicEvent); // Organize a new event
        coffeeshop.showAllEvents();                                              // Show all events
        if (musicEvent == nullptr)
        {
            throw "Failed to create event.";
        }
    }
    catch (const char *message)
    {
        cout << message << endl;
    }

    cout << endl
         << "Daily Revenue: " << coffeeshop.calculateDailyRevenue() << endl;
    cout << "Daily Products cost: " << coffeeshop.calculateProductsCost() << endl;
    cout << "Daily Employees cost: " << coffeeshop.calculateEmployeesCost() << endl;
    cout << "Daily Events cost: " << coffeeshop.calculateEventsCost() << endl;
    cout << "Daily Cost: " << coffeeshop.calculateDailyCost() << endl;
    cout << "Daily Income: " << coffeeshop.calculateDailyIncome() << endl;
    coffeeshop.createReport("../../data/report_bucharest.csv"); // Create the daily report in English
    coffeeshop.createReport("../../data/raport_bucuresti.csv"); // Create the daily report in Romanian

    return 0;
}