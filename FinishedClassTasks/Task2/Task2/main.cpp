#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

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
    float p, S, P;
    bool exit_flag = false, back_flag;

    Type _inputType;

    while (!exit_flag) {
        back_flag = false;
        cout << "Ways to define a triangle:" << endl
            << "1) by three sides," << endl
            << "2) by base and height," << endl
            << "3) by three points" << endl
            << "Input: ";
        cin >> user_choosen;

        switch (user_choosen) {
        case 1:
            _inputType = bySides;
            while (1) {
                cout << "Input 3 side of triangle (between space): ";
                cin >> AB >> BC >> AC;
                if (!(AB + BC > AC && AB + AC > BC && AC + BC > AB)) {
                    cout << "Input error: triangle dont exist" << endl;
                    cout << "Try again" << endl;
                    continue;
                }
                break;
            }
            break;
        case 2:
            _inputType = byBaseAndHeight;
            cout << "Input base of triangle: ";
            cin >> AB;
            cout << "Input height of triangle: ";
            cin >> h;
            break;
        case 3:
            _inputType = byPointsCoords;
            cout << "Input 1st point's coordinates (between space): ";
            cin >> A[0] >> A[1];
            cout << "Input 2nd point's coordinates (between space): ";
            cin >> B[0] >> B[1];
            cout << "Input 3rd point's coordinates (between space): ";
            cin >> C[0] >> C[1];
            break;
        default:
            cout << "Input error: error in input" << endl;
        }

        while (!back_flag) {
            cout << "Methods: 1) get square," << endl
                << "2) get perimeter, " << endl
                << "3) get type of triangle," << endl
                << "4) compare with another triangle by square," << endl
                << "5) back to first menu," << endl
                << "0) exit," << endl
                << "Input: ";
            cin >> user_choosen;

            switch (user_choosen) {
            case 0:
                exit_flag = true;
                break;
            case 1:
                if (_inputType == bySides) {
                    if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
                        p = (AB + BC + AC) * 0.5;
                        S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
                        cout << "Square of triangle: S = " << S << endl;
                    }
                    else {
                        cout << "Input error: triangle dont exist" << endl;
                    }
                }
                else if (_inputType == byBaseAndHeight) {
                    if (AB > 0 && h > 0) {
                        S = AB * h * 0.5;
                        cout << "Square of triangle: S = " << S << endl;
                    }
                    else {
                        cout << "Input error: triangle dont exist" << endl;
                    }
                }
                else if (_inputType == byPointsCoords) {
                    AB = sqrt(pow(B[0] - A[0], 2) + pow(B[1] - A[1], 2));
                    BC = sqrt(pow(C[0] - B[0], 2) + pow(C[1] - B[1], 2));
                    AC = sqrt(pow(C[0] - A[0], 2) + pow(C[1] - A[1], 2));
                    if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
                        p = (AB + BC + AC) * 0.5;
                        S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
                        cout << "Square of triangle: S = " << S << endl;
                    }
                    else {
                        cout << "Input error: triangle dont exist" << endl;
                    }
                }
                system("pause");
                system("cls");
                break;
            case 2:
                if (_inputType == bySides) {
                    if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
                        P = AB + BC + AC;
                        cout << "Square of triangle: P = " << P << endl;
                    }
                    else {
                        cout << "Input error: triangle dont exist" << endl;
                    }
                }
                else if (_inputType == byBaseAndHeight) {
                    cout << "Input error: we couldn't find perimeter by your parameters" << endl;
                }
                else if (_inputType == byPointsCoords) {
                    AB = sqrt(pow(B[0] - A[0], 2) + pow(B[1] - A[1], 2));
                    BC = sqrt(pow(C[0] - B[0], 2) + pow(C[1] - B[1], 2));
                    AC = sqrt(pow(C[0] - A[0], 2) + pow(C[1] - A[1], 2));
                    if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
                        P = AB + BC + AC;
                        cout << "Square of triangle: P = " << P << endl;
                    }
                    else {
                        cout << "Input error: triangle dont exist" << endl;
                    }
                }
                break;
            case 3:
                if (_inputType == bySides) {
                    if (AB == AC && AC == BC)
                        cout << "Type of triangle: equilateral" << endl;
                    else if ((AB == AC && AC != BC) || (AB == BC && BC != AC) || (AC == BC && BC != AB))
                        cout << "Type of triangle: isosceles" << endl;
                    else if ((AB == sqrt(pow(AC, 2) + pow(BC, 2))) || (BC == sqrt(pow(AC, 2) + pow(AB, 2))) || (AC == sqrt(pow(AB, 2) + pow(BC, 2))))
                        cout << "Type of triangle: right triangle" << endl;
                    else cout << "Type of triangle: scalene" << endl;
                }
                else if (_inputType == byBaseAndHeight) {
                    cout << "Input error: we couldn't find type of triangles by your parameters" << endl;
                }
                else if (_inputType == byPointsCoords) {
                    AB = sqrt(pow(B[0] - A[0], 2) + pow(B[1] - A[1], 2));
                    BC = sqrt(pow(C[0] - B[0], 2) + pow(C[1] - B[1], 2));
                    AC = sqrt(pow(C[0] - A[0], 2) + pow(C[1] - A[1], 2));
                    if (AB == AC && AC == BC)
                        cout << "Type of triangle: equilateral" << endl;
                    else if ((AB == AC && AC != BC) || (AB == BC && BC != AC) || (AC == BC && BC != AB))
                        cout << "Type of triangle: isosceles" << endl;
                    else if ((AB == sqrt(pow(AC, 2) + pow(BC, 2))) || (BC == sqrt(pow(AC, 2) + pow(AB, 2))) || (AC == sqrt(pow(AB, 2) + pow(BC, 2))))
                        cout << "Type of triangle: right triangle" << endl;
                    else cout << "Type of triangle: scalene" << endl;
                }
                break;
            case 4:
                float S2;
                cout << "Enter the square of another triangle: ";
                cin >> S2;
                if (_inputType == bySides) {
                    if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
                        p = (AB + BC + AC) * 0.5;
                        S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
                        if (S > S2)
                            cout << "Your square " << S << " > " << S2 << endl;
                        else if (S < S2)
                            cout << "Your square " << S << " < " << S2 << endl;
                        else cout << "Your square " << S << " = " << S2 << endl;
                    }
                    else {
                        cout << "Input error: Your triangle dont exist" << endl;
                    }
                }
                else if (_inputType == byBaseAndHeight) {
                    if (AB > 0 && h > 0) {
                        S = AB * h * 0.5;
                        if (S > S2)
                            cout << "Your square " << S << " > " << S2 << endl;
                        else if (S < S2)
                            cout << "Your square " << S << " < " << S2 << endl;
                        else cout << "Your square " << S << " = " << S2 << endl;
                    }
                    else {
                        cout << "Input error: Your triangle dont exist" << endl;
                    }
                }
                else if (_inputType == byPointsCoords) {
                    AB = sqrt(pow(B[0] - A[0], 2) + pow(B[1] - A[1], 2));
                    BC = sqrt(pow(C[0] - B[0], 2) + pow(C[1] - B[1], 2));
                    AC = sqrt(pow(C[0] - A[0], 2) + pow(C[1] - A[1], 2));
                    if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
                        p = (AB + BC + AC) * 0.5;
                        S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
                        if (S > S2)
                            cout << "Your square " << S << " > " << S2 << endl;
                        else if (S < S2)
                            cout << "Your square " << S << " < " << S2 << endl;
                        else cout << "Your square " << S << " = " << S2 << endl;
                    }
                    else {
                        cout << "Input error: Your triangle dont exist" << endl;
                    }
                }
                break;
            case 5:
                back_flag = true;
                break;
            default:
                cout << "Input error: error in input" << endl;
            }

            if (back_flag || exit_flag) {
                system("cls");
                cout << "Last parameters: ";
                if (_inputType == bySides) {
                    cout << AB << "x" << BC << "x" << AC << endl;
                }
                else if (_inputType == byBaseAndHeight) {
                    cout << "a = " << AB << ", h = " << h << endl;
                }
                else if (_inputType == byPointsCoords) {
                    cout << "(" << A[0] << ", " << A[1] << ")" << ", ";
                    cout << "(" << B[0] << ", " << B[1] << ")" << ", ";
                    cout << "(" << C[0] << ", " << C[1] << ")" << endl;
                }
            }
            break;
        }
    }
    system("cls");
    cout << "Goodbay!" << endl;
}