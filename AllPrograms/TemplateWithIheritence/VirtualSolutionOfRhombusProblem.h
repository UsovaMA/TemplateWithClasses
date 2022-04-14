#pragma once
#include <iostream>

class Device {
public:
  Device() {
    std::cout << "Device Constructor CALLED" << std::endl;
  }
  void turn_on() {
    std::cout << "Device is ON" << std::endl;
  }
};

class Monitor : virtual public Device {
public:
  Monitor() {
    std::cout << "Monitor Constructor CALLED" << std::endl;
  }
};

class Computer : virtual public Device {
public:
  Computer() {
    std::cout << "Computer Constructor CALLED" << std::endl;
  }
};

// множественное наследование
class Laptop : public Computer, public Monitor/*, virtual public Device */ {
public:
  Laptop() {
    std::cout << "Laptop Constructor CALLED" << std::endl;
  }
};