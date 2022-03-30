#ifndef HARDCLASS_H
#define HARDCLASS_H

#include <iostream>
#include <string>
#include "Types.h"

// ØÀÁËÎÍ ÍÀÑËÅÄÎÂÀÍÈß ÊËÀÑÑÎÂ

class GrandParent {
protected:
  Type field1;

public:
  GrandParent();
  GrandParent(Type val1);
  GrandParent(const GrandParent& curr);

  void print();

private:
  SomeOutputType secretMethod(/* ïàğàìåòğû */);
};

class Parent : public GrandParent {
protected:
  Type* field2;
  int size;
public:
  Parent();
  Parent(Type val1, Type* vals, int _size);
  Parent(const Parent& curr);

  void print();
};

class Child : public Parent {
  Type field3;

public:
  Child();
  Child(Type val1, Type* vals, int _size, Type val3);
  Child(const Child& curr);

  void print();
};

#endif // HARDCLASS_H
