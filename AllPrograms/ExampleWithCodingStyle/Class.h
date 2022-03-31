// Copyright 2022 Marina Usova
#pragma once
#include <iostream>

class Point {
  int x;
  int y;
 public:
  Point() { x = 0; y = 0; }
  void print() { std::cout << "(" << x << ", " << y << ")"; }
};
