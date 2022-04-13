cmake_minimum_required(VERSION 3.21)
project(projeto1)

set(CMAKE_CXX_STANDARD 23)

add_executable(projeto1 main.cpp src/DeliveryMan.cpp include/DeliveryMan.h src/Package.cpp include/Package.h src/FileReader.cpp include/FileReader.h src/Application.cpp include/Application.h src/Menu.cpp include/Menu.h src/Starter.cpp include/Starter.h src/Shipping.cpp include/Shipping.h)
