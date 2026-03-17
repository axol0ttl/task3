#include <stdio.h>
#include "mySatur.h"


void mySatur::saturate() {
    int limit = 10000;
    isSaturated = false;

    if (c > limit) {
        c = limit;
        d = 0;
        isSaturated = true;
    }
    else if (c < -limit) {
        c = -limit;
        d = 0;
        isSaturated = true;
    }
}


mySatur::mySatur(double x) : myFloat(x) {
    saturate();
}

// Конструктор от двух int
mySatur::mySatur(int a, int b) : myFloat(a, b) {
    saturate();
}

// Конструктор преобразования из myFloat
mySatur::mySatur(const myFloat& f) : myFloat(f) {
    saturate();
}

void mySatur::printSuffix() {
    if (isSaturated) {
        printf("*");
    }
    else {
        printf("");
    }
}

void mySatur::print() {
    printSuffix(); // печатаем суффикс после числа
    myFloat::print(); // вызываем базовый метод для печати числа
}



// void mySatur::print() {
//     char suffix;
//     suffix = ' ';
//     if (isSaturated == true) {suffix = '*';}
//     printf("%d.%04d %c \n", c, abs(d), suffix);///??????? (переделать принт в майфлоат, а вывод суффикса оставить здесь отдельно)
//     }