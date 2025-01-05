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

    coffeeshop.getAllEmployees("../../data/employees_bucharest.csv");
    coffeeshop.showAllEmployees();
    coffeeshop.addEmployee("../../data/employees_bucharest.csv", "Radu Ion", "Waiter", 9, 17, 120);
    coffeeshop.addEmployee("../../data/employees_bucharest.csv", "Ana Dan", "Waiter", 9, 17, 120);
    coffeeshop.deleteEmployee("../../data/employees_bucharest.csv", "Radu Ion", "Waiter", 9, 17, 120);
    coffeeshop.showAllEmployees();
    coffeeshop.updateEmployeeHours("../../data/employees_bucharest.csv", "Ana Dan", "Waiter", 9, 17, 120, 9, 15);
    coffeeshop.getAllProducts("../../data/products_bucharest.csv");
    coffeeshop.addProduct("../../data/products_bucharest.csv", "Orange Juice", "Drinks", 1, 10, 5);
    coffeeshop.showAllProducts();
    coffeeshop.deleteProduct("../../data/products_bucharest.csv", "Orange Juice", "Drinks", 1, 10, 5);
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

    Order order("Ana Mihai", orderProducts);
    cout << "Order Price: " << order.calculateTotalPrice("../../data/orders_bucharest.csv") << endl;
    coffeeshop.getAllOrders("../../data/orders_bucharest.csv");
    coffeeshop.showAllOrders();
    coffeeshop.placeOrder("../../data/orders_bucharest.csv", order);
    coffeeshop.showAllOrders();

    LiveMusicEventFactory liveMusicFactory;
    Product product3("Latte"), product4("Tea"), product5("Espresso");
    vector<Product> eventProducts = {product3, product4, product5};
    allProducts = coffeeshop.getAllProductsVector();
    for (auto &eventProduct : eventProducts)
    {
        for (auto product : allProducts)
        {
            if (product.getProductName() == eventProduct.getProductName())
            {
                eventProduct.setCost(product.getCost());
            }
        }
    }

    try // Exceptions
    {
        Event *musicEvent = liveMusicFactory.createLiveMusicEvent("Live Music", eventProducts, 0, 500, 500);
        cout << endl
             << "New event cost: " << musicEvent->calculateEventCost() << endl;
        musicEvent->showEventInfo();
        coffeeshop.getAllEvents("../../data/events_bucharest.csv");
        coffeeshop.showAllEvents();
        coffeeshop.organizeEvent("../../data/events_bucharest.csv", musicEvent);
        coffeeshop.showAllEvents();
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
    coffeeshop.createReport("../../data/report_bucharest.csv");

    return 0;
}