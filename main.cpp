//
// Created by Arseny on 11/03/2026.
//
#include "vector.h"
#include "mySatur.h"

int main() {


    vector x(2), y(2);
    x[0] = 8255.4357; x[1] = 2.0;
    y[0] = 1642.0; y[1] = 67.0;

    vector res = x + y; // сложение массивов
    res.print();

    vector res2 = res; // операция копирования
    res2.print();
    // res2[2] = 123.2351; // index out of range
    x = y;
    // x.print();

    y = x;
    y.print();
    mySatur test = res2.lm(); //возвращает ссылкой последний элемент без проверок
    test.print();

    return 0;
}