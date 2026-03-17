//
// Created by Arseny on 11/03/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void error(const char *msg) {
    printf("%s\n", msg); exit(1);
}

vector::vector(int s) {
    if (s<1) error("wrong size");
    sz = s;
    v = new mySatur[s];
    if (v==0) {error("out of memory");}
}

vector::vector() {
    sz = 99;
    v = new mySatur[sz];
}

vector::vector(const vector& other) {
    sz = other.sz;
    v = new mySatur[sz];
    if (v == 0) error("out of memory");
    for (int i = 0; i < sz; i++) {
        v[i] = other.v[i];
    }
}


mySatur& vector::operator[](int i) {
    if (i < 0 || i >= sz) error("index out of range");
    return v[i];
}


vector::~vector() {
    delete [] v;
}


vector vector::operator+(vector& a) {
    int s = size();
    if (s != a.size())
        error("Vector size mismatch");

    vector sum(s);

    for (int i = 0; i < s; i++)
        sum.elem(i) = elem(i) + a.elem(i);

    return sum;
}


vector vector::operator-(vector& a) {
    int s = size();
    if (s != a.size())
        error("Vector size mismatch");
    vector sum(s);
    for (int i = 0; i < s; i++)
        sum.elem(i) = elem(i) - a.elem(i);
    return sum;
}


vector &vector::operator=(vector& a) {

    if (this == &a) {
        return *this;
    }

    if (sz == a.sz) { // если размеры одинаковые

        for (int i = 0; i < sz; i++) {
            elem(i) = a.elem(i);
        }
        return *this;
    } // защита от самоприсваивания

    delete [] v; // уничтожим прошлый массив и сделаем из него копию другого
    sz = a.sz;
    v = new mySatur[sz];

    if (v == 0) error("out of memory");
    for (int i = 0; i < sz; i++) {
        v[i] = a.v[i];
    }

    return *this;
}



void vector::print() {
    int s = size();
    printf("[");
    for (int i = 0; i<s; i++) {
        elem(i).print();
        if (i < s - 1) printf(", ");
    }
    printf("]\n");
}

