#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

enum Type { bySides, byBaseAndHeight, byPointsCoords };

class Triangle {
private:
    int AB, BC, AC;
    int A[2], B[2], C[2];
    int h;
    float p, S, P;
    Type _inputType;
public:
    Triangle(int side1, int side2, int side3);
    Triangle(int base, int height);
    Triangle(int* point1, int* point2, int* point3);
    float squareSide();
    float squareH();
    float squarePoints();
    float perimeter();
    void squareComp(float square1);
    void typeOftriangle();
    void checkS_Sides(int side1, int side2, int side3, int userChoosen);
    void checkS_H(int base, int height, int userChoosen);
    void checkS_Points(int* point1, int* point2, int* point3, int userChoosen);
};

Triangle::Triangle(int side1, int side2, int side3) {
    AB = side1;
    BC = side2;
    AC = side3;
    _inputType = bySides;
}
Triangle::Triangle(int base, int height) {
    AB = base;
    h = height;
    _inputType = byBaseAndHeight;
}
Triangle::Triangle(int* point1, int* point2, int* point3) {
    A[0] = point1[0];
    A[1] = point1[1];
    B[0] = point2[0];
    B[1] = point2[1];
    C[0] = point3[0];
    C[1] = point3[1];
    _inputType = byPointsCoords;
}

void Triangle::typeOftriangle() {
    if (AB == AC && AC == BC)
        cout << "Type of triangle: equilateral" << endl;
    else if ((AB == AC && AC != BC) || (AB == BC && BC != AC) || (AC == BC && BC != AB))
        cout << "Type of triangle: isosceles" << endl;
    else if ((AB == sqrt(pow(AC, 2) + pow(BC, 2))) || (BC == sqrt(pow(AC, 2) + pow(AB, 2))) || (AC == sqrt(pow(AB, 2) + pow(BC, 2))))
        cout << "Type of triangle: right triangle" << endl;
    else cout << "Type of triangle: scalene" << endl;
}
void Triangle::squareComp(float square1) {
    float S2;
    cout << "Enter the square of another triangle: ";
    cin >> S2;
    if (square1 > S2)
        cout << "Your square " << square1 << " > " << S2 << endl;
    else if (square1 < S2)
        cout << "Your square " << square1 << " < " << S2 << endl;
    else cout << "Your square " << square1 << " = " << S2 << endl;
}
float Triangle::squareSide() {
    p = (AB + BC + AC) * 0.5;
    return S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
}
float Triangle::squareH() {
    return S = AB * h * 0.5;
}
float Triangle::squarePoints() {
    return S = 0.5 * abs((B[0] - A[0]) * (C[1] - A[1]) - (C[0] - A[0]) * (B[1] - A[1]));
}
float Triangle::perimeter() {
    return P = AB + BC + AC;
}
void Triangle::checkS_Sides(int side1, int side2, int side3, int userChoosen) {
    if (side1 + side2 > side3 && side1 + side3 > side2 && side3 + side2 > side1) {
        if (userChoosen == 1) {
            cout << "Square of triangle: S = " << squareSide() << endl;
        }
        else if (userChoosen == 2) {
            cout << "Square of triangle: P = " << perimeter() << endl;
        }
        else if (userChoosen == 3) {
            typeOftriangle();
        }
        else if (userChoosen == 4) {
            int S = squareSide();
            squareComp(S);
        }
    }
    else {
        cout << "Input error: triangle dont exist" << endl;
    }
}
void Triangle::checkS_H(int base, int height, int userChoosen) {
    if (base > 0 && height > 0) {
        if (userChoosen == 1) {
            int S = squareH(base, height);
            cout << "Square of triangle: S = " << S << endl;
        }
        else if (userChoosen == 2 || userChoosen == 3) {
            cout << "Input error: we couldn't find triangles by your parameters" << endl;
        }
        else if (userChoosen == 4) {
            int S = squareH(base, height);
            squareComp(S);
        }
    }
    else {
        cout << "Input error: triangle dont exist" << endl;
    }
}
void Triangle::checkS_Points(int* point1, int* point2, int* point3, int userChoosen) {
    int AB = sqrt(pow(point2[0] - point1[0], 2) + pow(point2[1] - point1[1], 2));
    int BC = sqrt(pow(point3[0] - point2[0], 2) + pow(point3[1] - point2[1], 2));
    int AC = sqrt(pow(point3[0] - point1[0], 2) + pow(point3[1] - point1[1], 2));
    if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
        if (userChoosen == 1) {
            int S = squarePoints(point1, point2, point3);
            cout << "Square of triangle: S = " << S << endl;
        }
        else if (userChoosen == 2) {
            int P = perimeter(AB, BC, AC);
            cout << "Square of triangle: P = " << P << endl;
        }
        else if (userChoosen == 3) {
            typeOftriangle(AB, BC, AC);
        }
        else if (userChoosen == 4) {
            int S = squarePoints(point1, point2, point3);
            squareComp(S);
        }
    }
    else {
        cout << "Input error: triangle dont exist" << endl;
    }
}

void toFirstMenu() {
    system("pause");
    system("cls");
}

int main() {
    Triangle triangle1;
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
            Triangle triangle1(AB, BC, AC);
            break;
        case 2:
            cout << "Input base of triangle: ";
            cin >> AB;
            cout << "Input height of triangle: ";
            cin >> h;
            Triangle triangle2(AB, h);
            break;
        case 3:
            cout << "Input 1st point's coordinates (between space): ";
            cin >> A[0] >> A[1];
            cout << "Input 2nd point's coordinates (between space): ";
            cin >> B[0] >> B[1];
            cout << "Input 3rd point's coordinates (between space): ";
            cin >> C[0] >> C[1];
            Triangle triangle3(A, B, C);
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
                    checkS_Sides(AB, BC, AC, user_choosen);
                }
                else if (_inputType == byBaseAndHeight) {
                    checkS_H(AB, h, user_choosen);
                }
                else if (_inputType == byPointsCoords) {
                    checkS_Points(A, B, C, user_choosen);
                }
                toFirstMenu();
                break;
            case 2:
                if (_inputType == bySides) {
                    checkS_Sides(AB, BC, AC, user_choosen);
                }
                else if (_inputType == byBaseAndHeight) {
                    checkS_H(AB, h, user_choosen);
                }
                else if (_inputType == byPointsCoords) {
                    checkS_Points(A, B, C, user_choosen);
                }
                toFirstMenu();
                break;
            case 3:
                if (_inputType == bySides) {
                    checkS_Sides(AB, BC, AC, user_choosen);
                }
                else if (_inputType == byBaseAndHeight) {
                    checkS_H(AB, h, user_choosen);
                }
                else if (_inputType == byPointsCoords) {
                    checkS_Points(A, B, C, user_choosen);
                }
                toFirstMenu();
                break;
            case 4:
                if (_inputType == bySides) {
                    checkS_Sides(AB, BC, AC, user_choosen);
                }
                else if (_inputType == byBaseAndHeight) {
                    checkS_H(AB, h, user_choosen);
                }
                else if (_inputType == byPointsCoords) {
                    checkS_Points(A, B, C, user_choosen);
                }
                toFirstMenu();
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