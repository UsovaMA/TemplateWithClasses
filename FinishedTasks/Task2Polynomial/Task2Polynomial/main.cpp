#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <fstream>
#include <Windows.h>
#include <cmath>

using namespace std;

class Polynom {
private:
    unsigned int deg;
    double* koef;
    void CorrectDeg();
public:
    Polynom();
    Polynom(unsigned int, double*);
    Polynom(const Polynom&);
    ~Polynom();
    void valuePolynom(double x);
    void nextPolynom();
    void InputPolynom();
    string OutputPolynom();
    unsigned int SetKoef(double, unsigned int);
    Polynom operator+(const Polynom&);
    Polynom operator=(const Polynom&);
    friend ofstream& operator<<(ofstream& out, const Polynom& polynom);
    friend ifstream& operator>>(ifstream& input, Polynom& polynom);
};

Polynom::Polynom() {
    deg = 0;
    koef = new double[deg + 1];
    koef[0] = 0.0;
}

Polynom::Polynom(unsigned int newDeg, double* newKoef) {
    deg = 0;
    for (int i = 0;i <= newDeg;i++)
        if (newKoef[i] != 0) deg = i;
    koef = new double[deg + 1];
    for (int i = 0;i <= deg;i++)
        koef[i] = newKoef[i];
}

Polynom::Polynom(const Polynom& f) {
    deg = f.deg;
    koef = new double[deg + 1];
    for (int i = 0;i <= deg;i++)
        koef[i] = f.koef[i];
}

Polynom::~Polynom() {
    delete[] koef;
}

Polynom Polynom::operator+ (const Polynom& t) {
    Polynom* result;

    if (deg >= t.deg) { //  степень 1 > 2
        result = new Polynom(deg, koef);
        for (int i = 0; i <= t.deg; i++)
            result->koef[i] = result->koef[i] + t.koef[i];
    }
    else {                   //  степень 2 > 1
        result = new Polynom(t.deg, t.koef);
        for (int i = 0; i <= deg; i++)
            result->koef[i] = result->koef[i] + koef[i];
    }
    result->CorrectDeg();
    return *result;
}

Polynom Polynom::operator= (const Polynom& t) {
    deg = t.deg;
    delete[] koef;
    koef = new double[deg + 1];
    for (int i = 0;i <= deg;i++)
        koef[i] = t.koef[i];
    return *this;
}

void Polynom::CorrectDeg() {
    if (koef[deg] == 0) {
        do {
            deg--;
        } while (deg && koef[deg] == 0); // макс степень != 0
    }
}

unsigned int Polynom::SetKoef(double new_koef, unsigned int i) {
    if (i <= deg) koef[i] = new_koef;
    else return deg;
    CorrectDeg();
    return deg;
}

void Polynom::valuePolynom(double x) {
    double result = 0;

    for (int i = 0; i <= deg; i++)
        result += pow(x, i) * koef[i];

    cout << "Значение полинома в точке " << x << " = " << result;
}

void Polynom::nextPolynom() {
    int j = 0;
    Polynom* result = new Polynom(deg - 1, koef);

    for (int i = 1; i <= deg; i++)
    {
        result->koef[j] = i * koef[i];
        j += 1;
    }
    cout << "\n" << "Производная от исходного полинома = ";
    cout << result->OutputPolynom();
}

void Polynom::InputPolynom() {
    cout << "Введите степень полинома: ";
    cin >> deg;
    delete[] koef;
    koef = new double[deg + 1];
    for (int i = 0;i < deg;i++) {
        cout << "Коэффициент" << i << " = ";
        cin >> koef[i];
    }
    do {
        cout << "Коэффициент" << deg << " = ";
        cin >> koef[deg];
        if (koef[deg] == 0)
            cout << "Коэффициент" << deg << " не должен быть 0!!!\n";
    } while (!koef[deg]);
}

string Polynom::OutputPolynom() {
    string strok;
    if (koef[deg] == 1) {
        unsigned int predeg = deg;
        strok += "X^";
        strok += to_string(predeg);
    }
    else if (koef[deg] == -1) {
        unsigned int predeg = deg;
        strok += "-X^";
        strok += to_string(predeg);
    }
    else {
        double prom = koef[deg];
        unsigned int predeg = deg;
        strok += to_string(prom);
        strok += "X^";
        strok += to_string(predeg);
    }
    for (int i = deg - 1;i > 0;i--) {
        if (koef[i] > 0) {
            if (koef[i] == 1) {
                int j = i;
                strok += " + ";
                strok += "X^";
                strok += to_string(j);
            }
            else {
                double prom = koef[i];
                int j = i;
                strok += " + ";
                strok += to_string(prom);
                strok += "X^";
                strok += to_string(j);
            }
        }
        else if (koef[i] < 0)
            if (koef[i] == -1) {
                int j = i;
                strok += " - ";
                strok += "X^";
                strok += to_string(j);
            }
            else {
                double prom = (-1) * koef[i];
                strok += " - ";
                strok += to_string(prom);
                strok += "X^";

            }
    }
    if (koef[0] > 0) {
        double prom = koef[0];
        strok += " + ";
        strok += to_string(prom);
        strok += "\n";
    }
    else if (koef[0] < 0) {
        double prom = (-1) * koef[0];
        strok += " - ";
        strok += to_string(prom);
        strok += "\n";
    }
    return strok;
}

/*
void Polynom::OutputPolynom(){
    if(koef[deg]==1)
        cout << "X^" << deg;
    else if(koef[deg]==-1)
        cout << "-X^" << deg;
    else
        cout << koef[deg] << "X^" << deg;
 
    for(int i=deg-1;i>0;i--){
        if(koef[i]>0){
            if(koef[i]==1)
                cout << " + " << "X^" << i;
            else
                cout << " + " << koef[i] << "X^" << i;
        }else if(koef[i]<0)
            if(koef[i]==-1)
                cout << " - " << "X^" << i;
            else
                cout << " - " << (-1)*koef[i] << "X^" << i;
    }
 
    if(koef[0]>0)
        cout << " + " << koef[0] << "\n";
    else if(koef[0]<0)
        cout << " - " << (-1)*koef[0] << "\n";
}

*/

/*
ofstream& operator<<(ofstream& out, const Polynom& polynom) {
   
    return out;
}


ifstream& operator>>(ifstream& input, Polynom& polynom) {
    
    return input;
}
*/


int main() {
    setlocale(LC_ALL, "Russian");

    int step = 4;
    double* mass = new double[step];
    Polynom a1(step, mass);
    Polynom a2(step, mass);
    Polynom a3(step, mass);
    a1.SetKoef(10, 0);
    a1.SetKoef(-1, 1);
    a1.SetKoef(0, 2);
    a1.SetKoef(7, 3);
    a1.SetKoef(1, 4);
    cout << a1.OutputPolynom();
    a2 = a1;
    cout << a2.OutputPolynom();
    a3 = a1 + a2;
    cout << a3.OutputPolynom();

    a3.valuePolynom(2.5);

    a3.nextPolynom();
    
    ifstream fileIn;
    fileIn.open("file.TXT");
    ofstream fileOut;
    fileOut.open("file.TXT");

    string f = a3.OutputPolynom();

    fileOut << f;


    fileIn.close();
    fileOut.close();

    return 0;
}