#include <iostream>
#include "InterfaceExample.h"

int main() {
  Computer c1;

  c1.turn_on();
  c1.hello_massage();
  c1.turn_off();

  /*
  ДЗ 1: словить вызов конструктора и деструктора при 
  использовании метода
  ДЗ 2: в множественном наследовании посмотреть деструкторы
  ДЗ 3: попробовать решить проблему через дружественные классы
  */

  return 0;
}