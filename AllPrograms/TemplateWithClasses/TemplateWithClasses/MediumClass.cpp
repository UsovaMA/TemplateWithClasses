#include "MediumClass.h"
 
/*
  int* a = new int;
  delete a;

  int* mass = new int[10];
  delete[] mass;
*/

// конструктор по умолчанию
ClassTemplate::ClassTemplate() {
  field1 = 0;
  field2 = 0.0;
  field3 = "";
  // ...
  fieldN_size = 10;

  // для массивов данных в конструкторах происходит ВЫДЕЛЕНИЕ ПАМЯТИ
  // fieldN = (int*)malloc(fieldN_size * sizeof(int))       // выделение памяти в языке C
  fieldN = new int[fieldN_size];                            // выделение памяти в языке C++
  for (int i = 0; i < fieldN_size; i++) {
    fieldN[i] = 0;
  }
}

// конструктор инициализации
ClassTemplate::ClassTemplate(int _field1, double _field2, std::string _field3, /*...*/ int* _fieldN, int _fieldN_size) {
  field1 = _field1;
  field2 = _field2;
  field3 = _field3;
  // ...
  fieldN_size = _fieldN_size;
  fieldN = new int[fieldN_size];
  for (int i = 0; i < fieldN_size; i++) {
    fieldN[i] = _fieldN[i];
  }
}

// конструктор копирования
ClassTemplate::ClassTemplate(const ClassTemplate& current) {
  field1 = current.field1;
  field2 = current.field2;
  field3 = current.field3;
  // ...
  fieldN_size = current.fieldN_size;
  fieldN = new int[fieldN_size];
  for (int i = 0; i < fieldN_size; i++) {
    fieldN[i] = current.fieldN[i];
  }
}

// деструктор (необходим, так как было выделение памяти)
ClassTemplate::~ClassTemplate() {
  // free(fieldN);     // C
  delete[] fieldN;     // C++
}

// печать
void ClassTemplate::print() {
  std::cout << "Field 1: " << field1 << std::endl
    << "Field 2: " << field2 << std::endl
    << "Field 3: " << field3 << std::endl
    << "// ..." << std::endl
    << "Field N: [ ";
  for (int i = 0; i < fieldN_size; i++) {
    std::cout << fieldN[i] << " ";
  }
  std::cout << "]" << std::endl << std::endl;
}
