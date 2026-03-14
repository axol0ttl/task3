#pragma once
#include "myFloat.h"



class mySatur : public myFloat { // объявляем mySatur предком myFloat
private:
    bool isSaturated;
    void saturate();

public:
    void print();
    void printSuffix();

    mySatur(double x =0.0);
    mySatur(int a, int b);
    mySatur(const myFloat& f); // конструктор преобразования из myFloat в mySatur, т.к. операторы возвращают myFloat, а не mySatur
};


