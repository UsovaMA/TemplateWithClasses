#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

enum Type { bySides, byBaseAndHeight, byPointsCoords };

void typeOftriangle (int AB, int BC, int AC) {
    if (AB == AC && AC == BC)
        cout << "Type of triangle: equilateral" << endl;
    else if ((AB == AC && AC != BC) || (AB == BC && BC != AC) || (AC == BC && BC != AB))
        cout << "Type of triangle: isosceles" << endl;
    else if ((AB == sqrt(pow(AC, 2) + pow(BC, 2))) || (BC == sqrt(pow(AC, 2) + pow(AB, 2))) || (AC == sqrt(pow(AB, 2) + pow(BC, 2))))
        cout << "Type of triangle: right triangle" << endl;
    else cout << "Type of triangle: scalene" << endl;
}
void squareComp (float S1) {
    float S2;
    cout << "Enter the square of another triangle: ";
    cin >> S2;
    if (S1 > S2)
        cout << "Your square " << S1 << " > " << S2 << endl;
    else if (S1 < S2)
        cout << "Your square " << S1 << " < " << S2 << endl;
    else cout << "Your square " << S1 << " = " << S2 << endl;
}
float squareSide (int AB, int BC, int AC) {
    int p = (AB + BC + AC) * 0.5;
    return sqrt(p * (p - AB) * (p - BC) * (p - AC));
}
float squareH (int AB, int H) {
    return AB * H * 0.5;
}
float squarePoints (int *A, int *B, int *C) {
    return 0.5 * abs((B[0] - A[0]) * (C[1] - A[1]) - (C[0] - A[0]) * (B[1] - A[1]));
}
void checkS_Sides (int AB, int BC, int AC, int userChoosen) {
    if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
        int S = squareSide(AB, BC, AC);
        if (userChoosen == 1) {
            cout << "Square of triangle: S = " << S << endl;
        }
        else if (userChoosen == 2) {
            int P = AB + BC + AC;
            cout << "Square of triangle: P = " << P << endl;
        }
        else if (userChoosen == 3) {
            typeOftriangle(AB, BC, AC);
        }
        else if (userChoosen == 4){
            squareComp(S);
        }
    }
    else {
        cout << "Input error: triangle dont exist" << endl;
    }
}
void checkS_H(int AB, int H, int userChoosen) {
    if (AB > 0 && H > 0) {
        int S = squareH(AB, H);
        if (userChoosen == 1) {
            cout << "Square of triangle: S = " << S << endl;
        }
        else if (userChoosen == 2 || userChoosen == 3) {
            cout << "Input error: we couldn't find type of triangles by your parameters" << endl;
        }
        else if (userChoosen == 4){
            squareComp(S);
        }
    }
    else {
        cout << "Input error: triangle dont exist" << endl;
    }
}
void checkS_Points(int* A, int* B, int* C, int userChoosen) {
    int AB = sqrt(pow(B[0] - A[0], 2) + pow(B[1] - A[1], 2));
    int BC = sqrt(pow(C[0] - B[0], 2) + pow(C[1] - B[1], 2));
    int AC = sqrt(pow(C[0] - A[0], 2) + pow(C[1] - A[1], 2));
    if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
        if (userChoosen == 1) {
            int S = squarePoints(A, B, C);
            cout << "Square of triangle: S = " << S << endl;
        }
        else if (userChoosen == 2) {
            int P = AB + BC + AC;
            cout << "Square of triangle: P = " << P << endl;
        }
        else if (userChoosen == 3) {
            typeOftriangle(AB, BC, AC);
        }
        else if (userChoosen == 4) {
            int S = squarePoints(A, B, C);
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