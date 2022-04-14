#pragma once
#include <iostream>

// класс-интерфейс (абстрактный базовый класс)
class IDevice {
public:
  virtual void turn_on() = 0;
  virtual void turn_off() = 0;
  virtual void hello_massage() = 0;
};

class Computer : public IDevice {
public:
  void turn_on() {
    std::cout << "Device is ON" << std::endl;
  }
  void turn_off() {
    std::cout << "Device is OFF" << std::endl;
  }
  void hello_massage() {
    std::cout << "Welcome!" << std::endl;
  }
};