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
    Coffeeshop coffeeshop("Bucharest", 3), coffeeshopCluj("Cluj", 1);
    coffeeshop.showCoffeeshopInfo();
    coffeeshopCluj.showCoffeeshopInfo();
    Product orangeJuice("Orange Juice", "Drinks", 1, 10, 5); // Create a new product
    Product lemonade("Lemonade", "Drinks", 1, 15, 7);        // Create a new product

    coffeeshop.getAllEmployees("../../data/employees_bucharest.csv");
    coffeeshopCluj.getAllEmployees("../../data/angajati_cluj.csv");                                 // Import the csv file  for employees in Romanian
    coffeeshop.showAllEmployees();                                                                  // Show all employees in the first coffeeshop
    coffeeshopCluj.showAllEmployees();                                                              // Show all employees in the second coffeeshop
    coffeeshop.addEmployee("../../data/employees_bucharest.csv", "Radu Ion", "Waiter", 9, 17, 120); // Add a new employee
    coffeeshopCluj.addEmployee("../../data/angajati_cluj.csv", "Oana Ion", "Ospatar", 9, 15, 100);  // Add a new employee in the csv file in Romanian
    coffeeshopCluj.showAllEmployees();
    coffeeshop.addEmployee("../../data/employees_bucharest.csv", "Ana Dan", "Waiter", 9, 17, 120);      // Add a new employee
    coffeeshop.addEmployee("../../data/employees_bucharest.csv", "Elena Ion", "Barista", 9, 17, 200);   // Add a new employee
    coffeeshop.addEmployee("../../data/employees_bucharest.csv", "Diana Mihai", "Manager", 9, 16, 220); // Add a new employee
    coffeeshop.deleteEmployee("../../data/employees_bucharest.csv", "Radu Ion", "Waiter", 9, 17, 120);  // Delete an employee
    coffeeshop.showAllEmployees();
    coffeeshop.updateEmployeeHours("../../data/employees_bucharest.csv", "Ana Dan", "Waiter", 9, 17, 120, 9, 15); // Update employee hours
    coffeeshop.getAllProducts("../../data/products_bucharest.csv");
    coffeeshopCluj.getAllProducts("../../data/produse_cluj.csv");                                       // Import the csv file for products in Romanian
    coffeeshop.addProduct("../../data/products_bucharest.csv", "Orange Juice", "Drinks", 1, 10, 5);     // Add a new product
    coffeeshopCluj.addProduct("../../data/produse_cluj.csv", "Suc de portocale", "Bauturi", 1, 10, 15); // Add a new product in the csv file in Romanian
    orangeJuice.showProductInfo();                                                                      // Show product information
    coffeeshop.addProduct("../../data/products_bucharest.csv", "Lemonade", "Drinks", 1, 15, 7);         // Add a new product
    lemonade.showProductInfo();                                                                         // Show product information
    coffeeshop.showAllProducts();                                                                       // Show all products in the first coffeeshop
    coffeeshopCluj.showAllProducts();                                                                   // Show all product in the second coffeeshop
    coffeeshop.deleteProduct("../../data/products_bucharest.csv", "Orange Juice", "Drinks", 1, 10, 5);  // Delete a product
    coffeeshop.showAllProducts();

    Product product1("Tea"), product2("Latte");
    Product product6("Apa"), product7("Ceai");
    vector<Product> orderProducts = {product1, product2}, allProducts = coffeeshop.getAllProductsVector();
    vector<Product> orderProductsCluj = {product6, product7}, allProductsCluj = coffeeshopCluj.getAllProductsVector();

    for (auto &orderProduct : orderProducts)
    {
        for (auto product : allProducts)
        {
            if (product.getProductName() == orderProduct.getProductName())
            {
                orderProduct.setPrice(product.getPrice()); // Set the price for the products in the current order
            }
        }
    }

    for (auto &orderProduct : orderProductsCluj)
    {
        for (auto product : allProductsCluj)
        {
            if (product.getProductName() == orderProduct.getProductName())
            {
                orderProduct.setPrice(product.getPrice());
            }
        }
    }

    Order order("Ana Mihai", orderProducts), orderCluj("Mihaela Ion", orderProductsCluj); // Create a new order
    order.showOrderInfo();                                                                // Show order information for the first order
    orderCluj.showOrderInfo();                                                            // Show order information for the second order
    cout << endl
         << "Order Price: " << order.calculateTotalPrice("../../data/orders_bucharest.csv") << endl; // Calculate the total price of the current order
    cout << endl
         << "Order Price: " << orderCluj.calculateTotalPrice("../../data/comenzi_cluj.csv") << endl;
    coffeeshop.getAllOrders("../../data/orders_bucharest.csv");
    coffeeshopCluj.getAllOrders("../../data/comenzi_cluj.csv"); // Import the csv file for orders in Romanian
    coffeeshop.showAllOrders();
    coffeeshopCluj.showAllOrders();
    coffeeshop.placeOrder("../../data/orders_bucharest.csv", order);     // Place a new order for the first coffeeshop
    coffeeshopCluj.placeOrder("../../data/comenzi_cluj.csv", orderCluj); // Place a new order for the second coffeeshop
    coffeeshop.showAllOrders();                                          // Show all orders  for the first coffeeshop
    coffeeshopCluj.showAllOrders();                                      // Show all orders  for the second coffeeshop

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
                eventProduct.setCost(product.getCost()); // Set the event products cost according to the products in the menu
            }
        }
    }

    try // Exceptions
    {
        Event *musicEvent = liveMusicFactory.createLiveMusicEvent("Live Music", eventProducts, 0, 500, 500); // Create a new event
        cout << endl
             << "New event cost: " << musicEvent->calculateEventCost() << endl; // Calculate the cost for the current event
        musicEvent->showEventInfo();                                            // Show current event information
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

    cout << "First Coffeeshop: ";
    cout << endl
         << "Daily Revenue: " << coffeeshop.calculateDailyRevenue() << endl;
    cout << "Daily Products cost: " << coffeeshop.calculateProductsCost() << endl;
    cout << "Daily Employees cost: " << coffeeshop.calculateEmployeesCost() << endl;
    cout << "Daily Events cost: " << coffeeshop.calculateEventsCost() << endl;
    cout << "Daily Cost: " << coffeeshop.calculateDailyCost() << endl;
    cout << "Daily Income: " << coffeeshop.calculateDailyIncome() << endl;

    cout << "Second Coffeeshop: ";
    cout << endl
         << "Daily Revenue: " << coffeeshopCluj.calculateDailyRevenue() << endl;
    cout << "Daily Products cost: " << coffeeshopCluj.calculateProductsCost() << endl;
    cout << "Daily Employees cost: " << coffeeshopCluj.calculateEmployeesCost() << endl;
    cout << "Daily Events cost: " << coffeeshopCluj.calculateEventsCost() << endl;
    cout << "Daily Cost: " << coffeeshopCluj.calculateDailyCost() << endl;
    cout << "Daily Income: " << coffeeshopCluj.calculateDailyIncome() << endl;

    coffeeshop.createReport("../../data/report_bucharest.csv"); // Create the daily report in English for the first coffeeshop
    coffeeshop.createReport("../../data/raport_bucuresti.csv"); // Create the daily report in Romanian for the first coffeeshop
    coffeeshopCluj.createReport("../../data/raport_cluj.csv");  // Create the daily report in Romanian for the second coffeeshop

    return 0;
}