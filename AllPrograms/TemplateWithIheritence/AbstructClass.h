#pragma once
#include <iostream>

// абстрактный класс
class Device {
public:
  int serial_number;
protected:
  int pincode;
public:
  Device() {
    serial_number = 12834724;
    pincode = 887766;
  }
  void turn_on() {
    std::cout << "Device is ON" << std::endl;
  }
  void turn_off() {
    std::cout << "Device is OFF" << std::endl;
  }
  virtual void hello_massage() = 0;
};

class Computer : public Device {
public:
  void hello_massage() {
    std::cout << "Welcome!" << std::endl;
  }
};