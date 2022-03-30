#include <iostream>
#include <cmath>

/* Задание: дописать пропущенные методы, выделить функции, классы,
заменить часть функций перегрузкой операторов.

ЦЕЛЬ: main() должен стать хорошо читаемой структрутой, чтобы было понятно, что происходит во всей программе (без комментариев),
но при этом помещался бы на одном экране.

! В main() вносить свои изменения структуры программы запрещено. Только заменять действия на аналоги, реализованные в
функциях или с использованием классов. СТРУКТУРА ДОЛЖНА ОСТАТЬСЯ ИСХОДНОЙ.

На гитхабе должно появиться 4 коммита:
0. дописал методы
1. выделил функции
2. выделил классы и применил принципы ООП
3. заменил часть функций операторами

То есть по окончании каждого этапа делайте коммит.

Подсказки:
0. Возможные классы, которые проглядыываются в программе:
- класс МЕНЮ (объединяет функции, относящиеся к меню взаимодействия с пользователем),
- класс ТОЧКА (для хранения координат)
- класс ТРЕУГОЛЬНИК (в конструкторах должны отображаться все способы задания треугольника).

1. Функции:
- различные функции меню (показать меню 1 уровня, показать меню 2 уровня и т.д.),
- функции ввода и проверки корректности данных,
- функции различных действий над треугольником: проверка на существование, подсчёт площади и т.д.

Указание. На этапе создания классов предполагается, что объект класса создаётся не в данной функции, а после неё.
Не лепите ввод данных и конструктор в один метод. Функции ввода данных - функции МЕНЮ, а создание объекта (точки, например) -
функции соответствующего класса.

Пример допустимой реализации:
Через 3 метода:
1) метод ввода значений (метод класса меню) - inputSides
2) метод ввода треугльника (метод класса треугольник) -inputTriangle

Далее используется перечисление - enum Type {bySides, byBaseAndHeight, byPointsCoords};

Triange tr1;
tr1.inputTriangle(bySides);

void inputTriangle(Type _type) {
  switch (_type) {
   case bySides:
     int side1, side2, side3;
     inputSides(&side1, &side2, &side3);   // тут сидит ввод значений
     Triange temp(side1, side2, side3);    // тут создаётся треугольник с указанными полями
     this = temp;
     break;
   // ...
  }
}

или

void inputTriangle(Type _type) {
  switch (_type) {
   case bySides:
     int side1, side2, side3;
     inputSides(&side1, &side2, &side3);   // тут сидит ввод значений
     this->side1 = side1;                  // тут изменяется уже существующий треугольник, заполнение указанными полями
     this->side2 = side2;
     this->side3 = side3;
     break;
   // ...
  }
}

*/

enum Type { bySides, byBaseAndHeight, byPointsCoords };

int main() {
  int user_choosen;
  int AB, BC, AC;
  int A[2], B[2], C[2];
  int h;
  float p, S;
  bool exit_flag = false, back_flag;

  Type _inputType;

  while (!exit_flag) {
    back_flag = false;
    std::cout << "Ways to define a triangle:" << std::endl
      << "1) by three sides," << std::endl
      << "2) by base and height," << std::endl
      << "3) by three points" << std::endl
      << "Input: ";
    std::cin >> user_choosen;

    switch (user_choosen) {
    case 1:
      _inputType = bySides;
      while (1) {
        std::cout << "Input 3 side of triangle (between space): ";
        std::cin >> AB >> BC >> AC;
        if (!(AB + BC > AC && AB + AC > BC && AC + BC > AB)) {
          std::cout << "Input error: triangle dont exist" << std::endl;
          std::cout << "Try again" << std::endl;
          continue;
        }
        break;
      }
      break;
    case 2:
      _inputType = byBaseAndHeight;
      std::cout << "Input base of triangle: ";
      std::cin >> AB;
      std::cout << "Input height of triangle: ";
      std::cin >> h;
      break;
    case 3:
      _inputType = byPointsCoords;
      std::cout << "Input 1st point's coordinates (between space): ";
      std::cin >> A[0] >> A[1];
      std::cout << "Input 2nd point's coordinates (between space): ";
      std::cin >> B[0] >> B[1];
      std::cout << "Input 3rd point's coordinates (between space): ";
      std::cin >> C[0] >> C[1];
      break;
    default:
      std::cout << "Input error: error in input" << std::endl;
    }

    while (!back_flag) {
      std::cout << "Methods: 1) get square," << std::endl
        << "2) get perimeter, " << std::endl
        << "3) get type of triangle," << std::endl
        << "4) compare with another triangle by square," << std::endl
        << "5) back to first menu," << std::endl
        << "0) exit," << std::endl
        << "Input: ";
      std::cin >> user_choosen;

      switch (user_choosen) {
      case 0:
        exit_flag = true;
        break;
      case 1:
        if (_inputType == bySides) {
          if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
            p = (AB + BC + AC) * 0.5;
            S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
            std::cout << "Square of triangle: S = " << S << std::endl;
          } else {
            std::cout << "Input error: triangle dont exist" << std::endl;
          }
        } else if (_inputType == byBaseAndHeight) {
          // your code
        } else if (_inputType == byPointsCoords) {
          // your code
        }
        system("pause");
        system("cls");
        break;
      case 2:
        if (_inputType == bySides) {
          // your code
        }
        else if (_inputType == byBaseAndHeight) {
          std::cout << "Input error: we couldn't find perimeter by your parameters" << std::endl;
        }
        else if (_inputType == byPointsCoords) {
          // your code
        }
        break;
      case 3:
        // your code
        // Types of triangles:
        // equilateral - равносторонний,
        // isosceles - равнобедренный,
        // right triangle - прямоугольный,
        // scalene - произвольный.
        break;
      case 4:
        // your code
        break;
      case 5:
        back_flag = true;
        break;
      default:
        std::cout << "Input error: error in input" << std::endl;
      }

      if (back_flag || exit_flag) {
        system("cls");
        std::cout << "Last parameters: ";
        if (_inputType == bySides) {
          std::cout << AB << "x" << BC << "x" << AC << std::endl;
        }
        else if (_inputType == byBaseAndHeight) {
          std::cout << "a = " << AB << ", h = " << h << std::endl;
        }
        else if (_inputType == byPointsCoords) {
          std::cout << "(" << A[0] << ", " << A[1] << ")" << ", ";
          std::cout << "(" << B[0] << ", " << B[1] << ")" << ", ";
          std::cout << "(" << C[0] << ", " << C[1] << ")" << std::endl;
        }
      }
      break;
    }
  }
  system("cls");
  std::cout << "Goodbay!" << std::endl;
}
