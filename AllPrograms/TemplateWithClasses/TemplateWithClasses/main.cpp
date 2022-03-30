#include <iostream>
#include <string>

#include "SimpleClass.h"
#include "MediumClass.h"
#include "HardClass.h"

#include "Types.h"

int main() {
  int val_int = 15;
  double val_double = 7.98;
  std::string val_str = "Template of string";
  /*...*/
  int size = 10;
  int* mass = new int[size];
  for (int i = 0; i < size; i++) mass[i] = i + 1;

  ClassTemplate object1;
  ClassTemplate object2(val_int, val_double, val_str, mass, size);
  ClassTemplate object3(object1);

  object1.print();
  object2.print();
  object3.print();

  Type mass1[] = { 1, 2, 3, 4 }, mass2[] = { -2, -1, 0, 1, -3 };

  GrandParent GP(3);
  Parent P(5, mass1, 4);
  Child C(2, mass2, 5, -3);

  std::cout << "GRANDPARENT OBJECT" << std::endl;
  GP.print();
  std::cout << "PARENT OBJECT" << std::endl;
  P.print();
  std::cout << "CHILD OBJECT" << std::endl;
  C.print();

  system("pause");
  return 0;
}
