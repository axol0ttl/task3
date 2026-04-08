#pragma once
#include <iostream>
#include "mySatur.h"

class vector {
    mySatur* v;
    int sz;

public:
    vector(int s);
    vector();
    vector(const vector& other);
    vector(vector&& other);
    ~vector();


    inline int size() const { return sz; }

    mySatur& operator[](int i);
    const mySatur& operator[](int i) const;

    inline mySatur& elem(int i) { return v[i]; }
    inline mySatur& lm()        { return v[sz - 1]; }

    vector operator+(vector& a);
    vector operator-(vector& a);

    vector& operator=(const vector& a);
    vector& operator=(vector&& a);

    void print();


    };

std::ostream& operator<<(std::ostream& os, mySatur& x);
std::ostream& operator<<(std::ostream& os, vector& x);