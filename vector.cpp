#include <iostream>
#include <stdexcept>
#include "vector.h"

// operator<< для вывода вектора через cout<<

std::ostream& operator<<(std::ostream& os, mySatur& x) {
x.print();
return os;
}

// конструкторы

vector::vector(int s) {
try {
if (s < 1) throw std::runtime_error("wrong size");
sz = s;
v  = new mySatur[s];
if (v == 0) throw std::runtime_error("out of memory");
} catch (std::runtime_error& e) {
std::cerr << e.what() << std::endl;
}
}

vector::vector() : sz(99), v(new mySatur[99]) {}

vector::vector(const vector& other) : sz(other.sz), v(nullptr) {
try {
v = new mySatur[sz];
if (v == 0) throw std::runtime_error("out of memory");
} catch (std::runtime_error& e) {
std::cerr << e.what() << std::endl;
return;
}
for (int i = 0; i < sz; i++)
v[i] = other.v[i];
}

vector::vector(vector&& other){
other.v  = nullptr;
other.sz = 0;
}

vector::~vector() {
delete[] v;
}

// ── Доступ к элементам ───────────────────────────────────────────────────────

mySatur& vector::operator[](int i) {
try {
if (i < 0 || i >= sz) throw std::runtime_error("index out of range");
} catch (std::runtime_error& e) {
std::cerr << e.what() << std::endl;
}
return v[i];
}

const mySatur& vector::operator[](int i) const {
try {
if (i < 0 || i >= sz) throw std::runtime_error("index out of range");
} catch (std::runtime_error& e) {
std::cerr << e.what() << std::endl;
}
return v[i];
}

// ── Арифметика ───────────────────────────────────────────────────────────────

vector vector::operator+(vector& a) {
int s = size();
try {
if (s != a.size()) throw std::runtime_error("vector size mismatch");
} catch (std::runtime_error& e) {
std::cerr << e.what() << std::endl;
}
vector sum(s);
for (int i = 0; i < s; i++)
sum.elem(i) = elem(i) + a.elem(i);
return sum;
}

vector vector::operator-(vector& a) {
int s = size();
try {
if (s != a.size()) throw std::runtime_error("vector size mismatch");
} catch (std::runtime_error& e) {
std::cerr << e.what() << std::endl;
}
vector sum(s);
for (int i = 0; i < s; i++)
sum.elem(i) = elem(i) - a.elem(i);
return sum;
}

// ── Присваивание ─────────────────────────────────────────────────────────────

vector& vector::operator=(const vector& a) {
if (this == &a) return *this;


if (sz == a.sz) {
    for (int i = 0; i < sz; i++)
        v[i] = a.v[i];
    return *this;
}

delete[] v;
sz = a.sz;
try {
    v = new mySatur[sz];
    if (v == 0) throw std::runtime_error("out of memory");
} catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
}
for (int i = 0; i < sz; i++)
    v[i] = a.v[i];
return *this;


}

vector& vector::operator=(vector&& a) {
if (this == &a) return *this;
delete[] v;
v    = a.v;
sz   = a.sz;
a.v  = nullptr;
a.sz = 0;
return *this;
}

// ── Вывод ────────────────────────────────────────────────────────────────────

void vector::print() {
std::cout << "[";
for (int i = 0; i < sz; i++) {
std::cout << elem(i);
if (i < sz - 1) std::cout << ", ";
}
std::cout << "]" << std::endl;
}