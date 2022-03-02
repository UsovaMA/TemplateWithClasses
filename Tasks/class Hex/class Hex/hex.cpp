#include "hex.h"
#include <iostream>

using namespace std;

Hex::Hex() {
    hexSymbols = 0;
}

Hex::~Hex() {
    hexSymbols = 0;
}

Hex& Hex::operator=(const Hex& elem) {
    for (int i = 0; i < num; i++) {
        this->hexSymbols[i] = elem.hexSymbols[i];
    }
    return *this;
};

Hex operator+(const Hex& elem) {
    Hex sum, hex1, hex2;
    sum = hex1 + hex2;
    cout << sum << endl;
    return sum;;
};

Hex operator-(const Hex& elem) {
    Hex dif, hex1, hex2;
    dif = hex1 - hex2;
    cout << dif << endl;
    return dif;;
};

bool Hex::operator>(const Hex& elem) {
    if (this->num > elem.num)
        return true;
    for (int i = 0; i < elem.num; i++) {
        if (this->hexSymbols[i] != elem.hexSymbols[i])
            return true;
    }
    return false;
};

bool Hex::operator<(const Hex& elem) {
    if (this->num < elem.num)
        return true;
    for (int i = 0; i < elem.num; i++) {
        if (this->hexSymbols[i] != elem.hexSymbols[i])
            return true;
    }
    return false;
};

bool Hex::operator>=(const Hex& elem) {
    if (this->num >= elem.num)
        return true;
    for (int i = 0; i < elem.num; i++) {
        if (this->hexSymbols[i] != elem.hexSymbols[i])
            return true;
    }
    return false;
};

bool Hex::operator<=(const Hex& elem) {
    if (this->num <= elem.num)
        return true;
    for (int i = 0; i < elem.num; i++) {
        if (this->hexSymbols[i] != elem.hexSymbols[i])
            return true;
    }
    return false;
};

bool Hex::operator==(const Hex& elem) {
    if (this->num == elem.num)
        return true;
    for (int i = 0; i < elem.num; i++) {
        if (this->hexSymbols[i] != elem.hexSymbols[i])
            return true;
    }
    return false;
};

bool Hex::operator!=(const Hex& elem) {
    if (this->num != elem.num)
        return true;
    for (int i = 0; i < elem.num; i++) {
        if (this->hexSymbols[i] != elem.hexSymbols[i])
            return true;
    }
    return false;
};

