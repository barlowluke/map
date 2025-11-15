cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0") 

project(dsac)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(dsac src/main.cpp src/api_monitor.cpp src/box_optimizer.cpp src/cart_analysis.cpp src/customer_loyalty.cpp)

add_executable(my_test tests/test.cpp src/api_monitor.cpp src/box_optimizer.cpp src/cart_analysis.cpp src/customer_loyalty.cpp)

enable_testing()
add_test(NAME my_test COMMAND my_test)
