#include <iostream>
#include "PointsClasses.h"

int main() {
  SPoint sp;
  sp.x = 1;
  sp.y = 4;

  Point p;
  p.setY(1);
  std::cout << p.getX() << std::endl;

  Point p1, p2;
  p = p1 + p2;    // попарное сложение координат
  p = p1 - p2;
  p = p1;
  p = p1 = p2;

  p = p;

  if (p == p1) {
    std::cout << "Point 1: ";
    p1.print();
    std::cout << std::endl;
  }

  std::cout << "Point 2: " << p2 << std::endl;
  int x, y;
  std::cin >> x;
  std::cin >> y;
  //p.setX(x);
  p.setY(y);

  std::cin >> p;
  std::cout << p;

  DirectionPoint dp, dp1;
  dp1.setY(5);
  dp = dp1;
  std::cout << dp << std:: endl << dp1;

}