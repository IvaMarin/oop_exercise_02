#ifndef FAZZYNUMBER_H_
#define FAZZYNUMBER_H_

#include <iostream>
using namespace std;

class FazzyNumber //класс нечетких чисел
{
private:
    double el;
    double x;      
    double er;  

public:
    FazzyNumber();  //конструктор
    FazzyNumber(double el, double x, double er);    //конструктор по умолчанию
    FazzyNumber(const FazzyNumber &other);  //конструктор копирования
    const FazzyNumber &operator=(const FazzyNumber &other); //оператор присваивания

    double getEl() const {
        return el;
    }
    double getX() const {
        return x;
    }
    double getEr() const {
        return er;
    }
    
    
    void Inverse();
    void Display();
};

FazzyNumber operator+(const FazzyNumber &fn1, const FazzyNumber &fn2);
FazzyNumber operator-(const FazzyNumber &fn1, const FazzyNumber &fn2);
FazzyNumber operator*(const FazzyNumber &fn1, const FazzyNumber &fn2);
FazzyNumber operator/(const FazzyNumber &fn1, const FazzyNumber &fn2);

bool operator==(const FazzyNumber &fn1, const FazzyNumber &fn2);
bool operator!=(const FazzyNumber &fn1, const FazzyNumber &fn2);
bool operator<(const FazzyNumber &fn1, const FazzyNumber &fn2);
bool operator<=(const FazzyNumber &fn1, const FazzyNumber &fn2);
bool operator>(const FazzyNumber &fn1, const FazzyNumber &fn2);
bool operator>=(const FazzyNumber &fn1, const FazzyNumber &fn2);

FazzyNumber operator"" _fn(long double num);

#endif /* FAZZYNUMBER_H_ */