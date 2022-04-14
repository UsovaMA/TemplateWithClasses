#pragma once
#include <iostream>

class Device {
public:
  void turn_on() {
    std::cout << "Device is ON" << std::endl;
  }
};

class Monitor : public Device {
public:
  void show_hello_massage() {
    std::cout << "Welcome to Windows 11!" << std::endl;
  }
};

class Computer : public Device {
public:
  void start() {
    std::cout << "Not save data restructed." << std::endl;
  }
};

// множественное наследование
class Laptop : public Computer, public Monitor {};
