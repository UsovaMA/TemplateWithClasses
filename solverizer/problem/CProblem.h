#pragma once
#include <iostream>
#include <string>
#include "CMethod.h"

class CProblem {
public:
  int* massive;
  int size;
public:
  CProblem() {};
  CProblem(int* _massive, int _size) {
    size = _size;
    massive = new int[size];
    for (int i = 0; i < size; i++) {
      massive[i] = _massive[i];
    }
  };
  CProblem(const CProblem &problem) {};
  ~CProblem() { delete[]massive; };

  void setMassive(int* _massive);
  void setSize(int _size);
  void readFromFile();

  void sort(sortType type);

  void print();
};
