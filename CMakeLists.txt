cmake_minimum_required(VERSION 3.10)

project(CoffeeshopProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(headers)

set(SOURCES
    src/main.cpp
    src/employee.cpp
    src/product.cpp
    src/order.cpp
    src/event.cpp
    src/file.cpp
    src/coffeeshop.cpp
)

add_executable(CoffeeshopProject ${SOURCES})

