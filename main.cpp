//
// Created by Arseny on 11/03/2026.
//
#include <stdio.h>
#include "vector.h"
#include "mySatur.h"

int main(void) {

    printf("Hello world!\n");
    vector x(3), y(3);
    x[0] = 9000.0; x[1] = 2.0;
    y[0] = 1002.0; y[1] = 9.0;
    int j = 0;
    vector res = x + y; // сложение массивов
    res.print();

    vector res2 = res; // операция копирования
    res2.print();
    res2[2] = 123.2351;
    x = y;
    x.print();


    mySatur test = res2.lm(); //возвращает ссылкой последний элемент без проверок
    test.print();

    return 0;
}