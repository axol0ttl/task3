#pragma once
#include "mySatur.h"

class vector {
    mySatur* v;
    int sz;
public:
    vector(int);
    vector();
    vector(vector&& other);
    ~vector();

    inline int size() const{
        return sz;
    }
    mySatur& operator[](int);
    const mySatur& operator[](int) const;

    inline mySatur& elem(int i) {
        return v[i];
    }

    inline mySatur& lm() {
        return v[sz-1];
    }

    vector operator+(vector&a);
    vector operator-(vector&a);
    vector& operator=(vector&&a);

    void print();

};
void error(const char* msg);

inline vector&& lvalue_to_rvalue(vector& x) {
    return (vector&&)x;
}