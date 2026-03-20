#include "myFloat.h"
#include <iostream>

/*
----условия задания------
мы делаем класс который будет считать вместо double остаток
есть 4 варианта как это будет возможно сделать
должно поддерживать плюс и минус
----условия задания------
*/


int abs(int num){ // не хочу использовать cmath
    if (num < 0){
        return num*-1;
    }
    else {
        return num;
    }
}

//3 способ
myFloat::myFloat(double x){
    c=(int)x;
    d=(int)((x-c)*10000);

    //округляем значение десятичной части
    int z=(int)((x-c)*100000);
    int y=z%10;
    if(y>=5)d+=1;
    else if(y<=-5)d-=1;
}

myFloat::myFloat(int a,int b){
    
    c=a;
    d=b;
    while(d<0 && c>0) {//если десятичная часть меньше нуля, а целая - больше, то убавляем 1 от целой и добавляем 10000 к десятичной
        c-=1;
        d+=10000;
    }
    while(d>0 && c<0) {//если десятичная часть больше нуля, а целая - меньше, то добавляем 1 к целой и убавляем 10000 от десятичной
        c+=1;
        d-=10000;
    }
    while(d>=10000) {//если десятичная часть больше 10000, то убавляем 10000 от десятичной и добавляем 1 к целой 
        d-=10000;
        c+=1;
    }
    while(d<=-10000){//если десятичная часть меньше 10000, то прибавляем 10000 к десятичной и убавляем 1 от целой 
        d+=10000;
        c-=1;
    }
    //округление до 4-х знаков
    if(d/10000!=0){//если больше 4 знаков в десятичной части
        int z=d;//записываем значение десятичной части в z
        int n=0;
        //далее делим на 10 пока можем и считаем количество
        while(z!=0){
            z/=10;
            n++;
        }
        //оставляем 5 знаков
        n=n-5;
        while(n!=0){
            //если пятый больше или равен 5, то добавляем к 4-му +1 и убираем пятый
            if(d%10>=5){
                d/=10;
                d+=1;
            //если нет, то просто убираем 5-ый
            }
            else{
                d/=10;
            }
        }
    }
    //убираем незначащие нули
}

void myFloat::print(){
    // std::cout<< c << abs(d) << std::endl;
    printf("%d.%04d", c, abs(d));
    }

    

//оператор сложения
myFloat operator+(myFloat a, myFloat b){
    return myFloat(a.c+b.c,a.d+b.d);
}
//оператор вычитания
myFloat operator-(myFloat a, myFloat b){
    return myFloat(a.c-b.c,a.d-b.d);
}
//оператор умножения
myFloat operator*(myFloat a, myFloat b){

    long long res1 = ((long long)(a.c*10000)+a.d)*((long long)(b.c*10000)+b.d);//перемножаем числа, в 10000 раз большие исходных
    long long fin = res1 /10000;
    //разделяем получившееся число на целую и десятичную, учитывая разрядности
    return myFloat(fin/10000, fin%10000);
}

myFloat operator/(myFloat a, myFloat b){
    
    long long A = (long long)a.c * 10000 + a.d;
    long long B = (long long)b.c * 10000 + b.d;

    long long R = A*10000 / B;
    myFloat res(0);
    res.c = R / 10000;
    res.d = R % 10000;

    return res;
}

bool operator>(myFloat a, myFloat b){
    if (a.c > b.c) {return true;}
    else if (a.c == b.c && a.d > b.d) {return true;}
    else {return false;}
}

bool operator<(myFloat a, myFloat b){
    return !(a>b);
}

// Функция возвращает синус числа x в радианах (мой мозг + стаковерфлоу + чатгпт)
myFloat myFloat::Sin(myFloat x) {
    myFloat pi=3.1415;
    myFloat twoPi = pi * 2;
    myFloat halfPi = pi / myFloat(2);

    // нормализуем x к [0, 2*pi]
    while (x > twoPi) x = x - twoPi;
    while (x < myFloat(0)) x = x + twoPi;

    int sign = 1;

    // теперь x ∈ [0, 2*pi], приводим к [0, pi]
    if (x > pi) {
        x = twoPi - x;  // sin(2pi - x) = -sin(x)
        sign = -1;
    }

    // приводим к [0, pi/2] для сходимости ряда
    if (x > halfPi) {
        x = pi - x;     // sin(pi - x) = sin(x)
    }

    // ряд Тейлора
    myFloat term = x;
    myFloat sum = term;

    for (int i = 3; i <= 15; i += 2) {
        term = term * x * x;
        myFloat denom(i*(i-1));
        term = term / denom;
        term = myFloat(-1) * term;
        sum = sum + term;
    }

    if (sign == -1) sum = myFloat(0) - sum;

    return sum;
}
