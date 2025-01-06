# CoffeeShop OOP Project

## Project Overview

The project aims to develop a management system for a network of coffeeshops. The system can be used for:
* Organizing staff
* Managing supplies and products
* Tracking orders
* Planning special events
* Calculating the daily revenue, daily costs and daily income

## Video Demo: 
https://youtu.be/eylSyXJY-Pw

## Features

#### Details

The program is used to manage a network of coffeeshops. The coffeeshops are located in five different cities across Romania.

#### Files

The system will store and manage data through CSV files. The CSV files can be found in the **data** folder.
The following CSV files are used:
* **employees.csv** - Contains the name, role, start and end of the work shift, payment for each employee.
* **products.csv** - Lists the name, type, quantity, price and cost for each product.
* **orders.csv** - Records the client name, the list of products ordered and the total price for each order.
* **events.csv** - Details the event name, the list of products and the total cost of the event
* **report.csv** -  Records the revenue, costs and income.

The program can import and export CSV files in Romanian or English.

## Technologies Used

* Programming Language: C++
* Data Storage: CSV files

## Prerequisites

* C++ compiler
* CMake (optional)

## Installation

1. Clone the repository 
```
git clone https://github.com/alexandrastroiu/CoffeeShop-OOP-Project.git
```
2. Navigate to the project directory
```
cd CoffeeShop-OOP-Project
```
3. Compile the project (manually or using CMake)
4. Run the executable