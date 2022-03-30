#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H

#include <iostream>
#include <string>
#include "Types.h"

// ОБЩАЯ СХЕМА НАПИСАНИЯ ПРОСТОГО КЛАССА

class NameClass {
  // поля
  Type example;
public:
  // конструкторы (по умолчанию, инициализации, копирования)
  NameClass() {};
  NameClass(Type _example /*<список параметров, соответствующий набору полей класса>*/) {};
  NameClass(const NameClass&) {};

  // деструктор (необходим, если в конструкторах происходило динамическое выделение памяти)
  ~NameClass() {};

  // вывод на экран
  void show() { std::cout << example; };

  // необходимые по задаче методы (часть методов можно делать private,
  // чтобы скрыть их от пользователя вашего класса, это могут быть, например, служебные методы)
};

#endif // SIMPLECLASS_H
