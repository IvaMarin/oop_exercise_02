/* Мариничев Иван М8О-208Б-19
 *
 * github: IvaMarin
 *
 * Вариант 4:
 *Реализовать класс FazzyNumber для работы с нечеткими числами, которые представляются тройками чисел (x – el, x, x + er). Для чисел A = (A – al, A, A + ar) и B = (B – bl, B, B + br) арифметические операции выполняются по следующим формулам:
 *  -сложение A + B = (A + B – al – bl, A + B, A + B + ar + br);
 *  -вычитание A – B = (A – B – al – bl, A – B, A – B + ar + br);
 *  -умножение A · B = (A ´ B – B ´ al – A ´ bl + al ´ bl, A ´ B, A ´ B + B ´ al + A ´ bl + al ´ bl);
 *  -обратное число A = (1 / (A + ar), 1 / A, 1 / (A – al)), A > 0;
 *  -деление A / B = ((A – al) / (B + br), A / B, (A + ar) / (B – bl)), B > 0; Считать el = er, то есть число представлено парой <x, e>.
 *Реализовать операции сравнения по х.
 *Операции сложения, вычитания, умножения, деления, сравнения (на равенство, больше и меньше) должны быть выполнены в виде перегрузки операторов. 
 *Необходимо реализовать пользовательский литерал для работы с константами типа FazzyNumber.
 */


#include <iostream>
#include <fstream>
#include "FazzyNumber.h"

using namespace std;


int main () {
    cout << "Creating 2 FazzyNumber class objects..." << endl;
    string test_name;
    cout << "Type test file name (e.g. test_01.txt) ";
    cout << "or type 'console' to enter them by yourself: ";
    cin >> test_name;
    double x_a, e_a, x_b, e_b;
    if (test_name != "console") {
        ifstream input;
        input.open(test_name);
        if (!input.is_open()) {
            cout << "File is not exists\n"; // если не открылся
            return -1;
        }
        input >> x_a >> e_a >> x_b >> e_b;
    }else {
        cout << "Enter x and e parts of FazzyNumber 1: ";
        cin >> x_a >> e_a;
        cout << "Enter x and e parts of FazzyNumber 2: ";
        cin >> x_b >> e_b;
    }
    cout << endl;

    FazzyNumber fn1(e_a, x_a, e_a);
    FazzyNumber fn2(e_b, x_b, e_b);
    cout << "FazzyNumber 1: ";
    fn1.Display();
    cout << "FazzyNumber 2: ";
    fn2.Display();
    cout << endl;

    FazzyNumber sum = fn1 + fn2;
    FazzyNumber dif = fn1 - fn2;
    FazzyNumber mul = fn1 * fn2;
    FazzyNumber div = fn1 / fn2 ;
    cout << "Sum of Fazzy Numbers: ";
    sum.Display();
    cout << "Difference of Fazzy Numbers: ";
    dif.Display();
    cout << "Product of Fazzy Numbers: ";
    mul.Display();
    if (fn2.getX() > 0) {
        cout << "Quotient of Fazzy Numbers: ";
        div.Display();
    } else {
        cout << "Can't divide those Fazzy Numbers." << endl;
    }
    cout << endl;

    cout << "Let's find inversed Fazzy Numbers." << endl;
    cout << "Inversed FazzyNumber1: ";
    fn1.Inverse();
    cout << "Inversed FazzyNumber2: ";
    fn2.Inverse();
    cout << endl;

    cout << "Comparing 2 Fazzy Numbers by x..." << endl;
    if (fn1 != fn2) {
        cout << "FazzyNumber1 is not equal to FazzyNumber2" << endl;
        if (fn1 > fn2) {
            cout << "FazzyNumber1 is greater than FazzyNumber2" << endl;
        }
        else {
            cout << "FazzyNumber1 is lower than FazzyNumber2" << endl;
        }
    }
    else {
        cout << "FazzyNumber1 is equal to FazzyNumber2" << endl;
    }
    cout << endl;
    cout << "And also we can use Fazzy Number literals. So let's create FazzyNumber3 using '3.14_fn' literal." <<endl;
    FazzyNumber fn3 = 3.14_fn;
    cout << "FazzyNumber 3: ";
    fn3.Display();
}