#pragma once

enum sortType { bubble, counting, quick };

struct Characteristics {
  int time;
  int comparisonCount;
  int permutationCount;
};

// It's a BASE
class IMethod {
protected:
  Characteristics analysis;
  IMethod() {
    analysis.time = 0;
    analysis.comparisonCount = 0;
    analysis.permutationCount = 0;
  }
public:
  virtual void sort(int* mass, int size) = 0;
};

// Derived class
class BubbleSort : IMethod {
public:
  BubbleSort() {};
  void sort(int* mass, int size);
};

// Derived class
class CountingSort : IMethod {
public:
  CountingSort() {};
  void sort(int* mass, int size);
};

// Derived class
class QuickSort : IMethod {
public:
  QuickSort() {};
  void sort(int* mass, int size) {
    qsort(mass, 0, size - 1);
  };

  void qsort(int *mass, int left, int right);
};
