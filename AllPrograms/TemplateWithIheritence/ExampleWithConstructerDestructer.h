#pragma once
#include <iostream>

class Device {
public:
  Device() {
    std::cout << "Device Constructor CALLED" << std::endl;
  }
  ~Device() {
    std::cout << "Device Destructor CALLED" << std::endl;
  }
};

class Computer : public Device {
public:
  Computer() {
    std::cout << "Computer Constructor CALLED" << std::endl;
  }
  ~Computer() {
    std::cout << "Computer Destructor CALLED" << std::endl;
  }
};

class Laptop : public Computer {
public:
  Laptop() {
    std::cout << "Laptop Constructor CALLED" << std::endl;
  }
  ~Laptop() {
    std::cout << "Laptop Destructor CALLED" << std::endl;
  }
};