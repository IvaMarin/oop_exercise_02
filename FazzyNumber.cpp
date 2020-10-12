#include "FazzyNumber.h"


FazzyNumber operator+(const FazzyNumber &fn1, const FazzyNumber &fn2) {   //оператор сложения нечетких чисел
    return FazzyNumber(fn1.getEl() + fn2.getEl(), fn1.getX() + fn2.getX(), fn1.getEr() + fn2.getEr());
}

FazzyNumber operator-(const FazzyNumber &fn1, const FazzyNumber &fn2) {   //оператор вычитания нечетких чисел
    return FazzyNumber(fn1.getEl() + fn2.getEl(), fn1.getX() - fn2.getX(), fn1.getEr() + fn2.getEr());
}

FazzyNumber operator*(const FazzyNumber &fn1, const FazzyNumber &fn2) {   //оператор умножения нечетких чисел
    return FazzyNumber((fn2.getX() * fn1.getEl() + fn1.getX() * fn2.getEl() - fn1.getEl() * fn2.getEl()), fn1.getX() * fn2.getX(), (fn2.getX() * fn1.getEl() + fn1.getX() * fn2.getEl() + fn1.getEl() * fn2.getEl()));
}

FazzyNumber operator/(const FazzyNumber &fn1, const FazzyNumber &fn2) {   //оператор деления нечетких чисел
    return FazzyNumber(((fn1.getX() - fn1.getEl()) / (fn2.getX() + fn2.getEr())) - (fn1.getX() / fn2.getX()), fn1.getX() / fn2.getX(),((fn1.getX() + fn1.getEr()) / (fn2.getX() - fn2.getEl())) - (fn1.getX() / fn2.getX()));
    }

bool operator==(const FazzyNumber &fn1, const FazzyNumber &fn2) {   //оператор сравнения == нечетких чисел
    return (fn1.getX() == fn2.getX());
}

bool operator!=(const FazzyNumber &fn1, const FazzyNumber &fn2) {   //оператор сравнения != нечетких чисел
    return !(fn1 == fn2);
}

bool operator<(const FazzyNumber &fn1, const FazzyNumber &fn2) {   //оператор сравнения < нечетких чисел
    return (fn1.getX() < fn2.getX());
}

bool operator<=(const FazzyNumber &fn1, const FazzyNumber &fn2) {   //оператор сравнения <= нечетких чисел
    return (fn1 < fn2) || (fn1 == fn2);
}

bool operator>(const FazzyNumber &fn1, const FazzyNumber &fn2) {   //оператор сравнения > нечетких чисел
    return fn2 < fn1;
}

bool operator>=(const FazzyNumber &fn1, const FazzyNumber &fn2) {   //оператор сравнения >= нечетких чисел
    return fn2 <= fn1;
}

void FazzyNumber::Inverse() {   //метод вывода обратного нечеткого числа
    if (x <= 0) {
        cout << "There is no inverse number." << endl;
    }
    else {
        double LeftInverse = 1 / (x + er);
        double MiddleInverse = 1 / x;
        double RightInverse = 1 / (x - el);
        cout << "(" << LeftInverse << ", " << MiddleInverse << ", " << RightInverse << ")" << endl;
    }
}

void FazzyNumber::Display() {   //метод вывода нечетких чисел
    double Left = x - el;
    double Middle = x;
    double Right = x + er;
    cout << "(" << Left << ", " << Middle << ", " << Right << ")" << endl;
}

FazzyNumber::FazzyNumber(): el(0), x(0), er(0) {}    //Конструктор по умолчанию

FazzyNumber::FazzyNumber(double el, double x, double er): el(el), x(x), er(er) {}   //Конструктор

FazzyNumber::FazzyNumber(const FazzyNumber &other) {
    el = other.el;
    x = other.x;
    er = other.er;
}   //конструктор копирования

const FazzyNumber &FazzyNumber::operator=(const FazzyNumber &other) {
    el = other.el;
    x = other.x;
    er = other.er;

    return *this;
}   //оператор присваивания

FazzyNumber operator"" _fn(long double num) {
    double x = num;
    double e = num;
    FazzyNumber fn(e, x, e);
    return fn;
} //пользовательсктй литерал для нечетких чисел