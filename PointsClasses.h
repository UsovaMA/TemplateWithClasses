#pragma once
#include <iostream>

class Point {
protected:
  int x;
  int y;

public:
  // конструтор по умолчанию
  Point() { x = 0; y = 0; }

  // сеттеры и геттеры
  int getX() { return x; };
  void setY(int _y) { y = _y; };

public:
  Point operator+(const Point& right) {
    Point res;
    res.x = this->x + right.x;
    res.y = y + right.y;
    return res;
  };

  friend Point operator-(const Point& left, const Point& right);

  Point& operator=(const Point& right) {
    if (this == &right) {
      return *this;
    }
    x = right.x;
    y = right.y;
    return *this;
  };

  bool operator==(const Point& right) {
    return (x == right.x && y == right.y);
  };

  void print() {
    std::cout << "(" << x << ", " << y << ")";
  };

  friend std::ostream& operator<<(std::ostream& out, const Point& right);
  friend std::istream& operator>>(std::istream& in, Point& right);
};

std::ostream& operator<<(std::ostream& out, const Point& right) {
  out << "(" << right.x << ", " << right.y << ")";
  return out;
};

std::istream& operator>>(std::istream& in, Point& right) {
  std::cout << "Input coordinate by Ox: ";
  in >> right.x;
  std::cout << "Input coordinate by Oy: ";
  in >> right.y;

  return in;
};

Point operator-(const Point& left, const Point& right) {
  Point res;
  res.x = left.x - right.x;
  res.y = left.y - right.y;
  return res;
};

enum Directions { begin, end };

class DirectionPoint : public Point {
  //bool isEnd;
  Directions direction;

public:
  DirectionPoint() : Point() { direction = begin; };

  DirectionPoint& operator=(const DirectionPoint& right) {
    if (this == &right) {
      return *this;
    }
    x = right.x;
    y = right.y;
    direction = right.direction;
    return *this;
  };

private:
  void swapDirection() {
    if (direction == begin) direction = end;
    else direction = begin;
  };
};

struct SPoint {
  int x;
  int y;
};
