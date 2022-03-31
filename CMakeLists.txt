cmake_minimum_required(VERSION 3.21)
project(projeto1)

set(CMAKE_CXX_STANDARD 23)

add_executable(projeto1 main.cpp src/DeliveryMan.cpp include/DeliveryMan.h src/Package.cpp include/Package.h)
