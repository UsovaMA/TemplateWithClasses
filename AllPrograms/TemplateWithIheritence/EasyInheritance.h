#pragma once

#include <iostream>

class Device {
public:
  int serial_number = 12834724;
protected:
  int pincode = 887766; // 3. protected-type
public:
  void turn_on() {
    std::cout << "Device is ON" << std::endl;
  }
  void turn_off() {
    std::cout << "Device is OFF" << std::endl;
  }

  // 1. friend class Computer;
  // 2. setter and getters
};

class Computer : private Device {
public:
  /*Computer() {
    pincode = 667788;
  }*/
  void hello_window() {
    turn_on();
    std::cout << "Welcome!" << std::endl;
  }
};
