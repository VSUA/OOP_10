#include <mainwindow.h>
#ifndef RATIONAL_H
#define RATIONAL_H


class Rational
{
    int numerator;
    int denominator;
public:
    static int amountOfObjects;
    Rational();
    Rational(int,int);
    void set_numerator(int);
    void set_denominator(int);
    int get_numerator();
    int get_denominator();
    static void changeAmount();
    Rational * Reduse(Rational * A);
    Rational * Sum(Rational * A, Rational *B);
    Rational * Sub(Rational * A, Rational *B);
    Rational * Mul(Rational * A, Rational *B);
    Rational * Div(Rational * A, Rational *B);
    bool TheyEqual(Rational *A, Rational *B);
    Rational * Greate(Rational * A, Rational *B);
    Rational * Less(Rational * A, Rational *B);
    Rational operator+ (Rational B);
    Rational operator- (Rational B);
    Rational operator* (Rational B);
    Rational operator/ (Rational B);
    friend bool operator> (Rational A,Rational B);
    friend bool operator< (Rational A,Rational B);
    friend bool operator== (Rational A,Rational B);
};





#endif // RATIONAL_H
