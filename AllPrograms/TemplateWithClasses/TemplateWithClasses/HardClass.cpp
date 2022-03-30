#include "HardClass.h"

GrandParent::GrandParent() {
  field1 = 0.0;
}

GrandParent::GrandParent(Type val1) {
  field1 = val1;
}

GrandParent::GrandParent(const GrandParent& curr) {
  field1 = curr.field1;
}

void GrandParent::print() {
  std::cout << "Output field 1: " << field1 << std::endl;
}

SomeOutputType GrandParent::secretMethod(/* параметры */) {
  SomeOutputType res = 0;
  /* реализация */
  return res;
}

Parent::Parent() : GrandParent() {
  size = 10;
  field2 = new Type[size];
  for (int i = 0; i < size; i++) {
    field2[i] = 0.0;
  }
}

Parent::Parent(Type val1, Type* vals, int _size) : GrandParent(val1) {
  size = _size;
  field2 = new Type[size];
  for (int i = 0; i < size; i++) {
    field2[i] = vals[i];
  }
}

Parent::Parent(const Parent& curr) : GrandParent(curr.field1) {
  size = curr.size;
  field2 = new Type[size];
  for (int i = 0; i < size; i++) {
    field2[i] = curr.field2[i];
  }
}

// деструктор!!!

void Parent::print() {
  GrandParent::print();
  std::cout << "Output field 2: [ ";
  for (int i = 0; i < size; i++) {
    std::cout << field2[i] << " ";
  }
  std::cout << "]" << std::endl;
}

Child::Child() : Parent() {
  size = 10;
  field2 = new Type[size];
  for (int i = 0; i < size; i++) {
    field2[i] = 0.0;
  }
}

Child::Child(Type val1, Type* vals, int _size, Type val3) : Parent(val1, vals, _size) {
  field3 = val3;
}

Child::Child(const Child& curr) : Parent(curr.field1, curr.field2, curr.size) {
  field3 = curr.field3;
}

void Child::print() {
  Parent::print();
  std::cout << "Output field 3: " << field3 << std::endl;
}
