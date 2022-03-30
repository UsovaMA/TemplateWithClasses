#ifndef MEDIUMCLASS_H
#define MEDIUMCLASS_H

#include <iostream>
#include <string>
#include "Types.h"

// ШАБЛОН КЛАССА С РАЗНЫМИ ТИПАМИ ПОЛЕЙ

class ClassTemplate {
  // поля класса - по умолчанию скрыты, может быть сколько и каких угодно
  // (разные типы данных, массивы, другие структуры и классы)
  int field1;
  double field2;
  std::string field3;
  // ...
  int* fieldN;
  int fieldN_size;

public:
  // конструктор по умолчанию
  ClassTemplate();
  // конструктор инициализации
  ClassTemplate(int _field1, double _field2, std::string _field3, /*...*/ int* _fieldN, int _fieldN_size);
  // конструктор копирования
  ClassTemplate(const ClassTemplate& current);

  // деструктор
  ~ClassTemplate();

  // методы
  void print();
};

#endif // MEDIUMCLASS_H
