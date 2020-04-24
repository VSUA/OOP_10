#include "rational.h"
#include"mainwindow.h"

Rational::Rational()
{
    Rational::changeAmount();
}

Rational::Rational(int a,int b)
{
    this->numerator = a;
    this->denominator = b;
    Rational::changeAmount();
}

void Rational::set_numerator(int a)
{
    this->numerator =  a;
}


void Rational::set_denominator(int a)
{
    this->denominator =  a;
}

int Rational::get_numerator()
{
    return this->numerator;
}

int Rational::get_denominator()
{
    return this->denominator;
}

Rational * Rational::Reduse(Rational * A)
{
    int a,b,r;
    Rational *C = new Rational;
    a = A->get_numerator();
    b = A->get_denominator();
//        if (a == 0)
//        {
//            C->set_numerator(a / b);
//            C->set_denominator(b / b);
//            return C;
//        }
    while (b) {
          r = a % b;
          a = b;
          b = r;
       }

    C->set_numerator(A->get_numerator() / double(a));
    C->set_denominator(A->get_denominator() / double(a));
    return C;

};

Rational * Rational::Sum(Rational * A, Rational *B)
{
    Rational *C = new Rational;
    C->set_numerator((A->get_numerator()*B->get_denominator())+(A->get_denominator()*B->get_numerator()));
    C->set_denominator(A->get_denominator()*B->get_denominator());
    C = C->Reduse(C);
    return C;
}

Rational * Rational::Sub(Rational * A, Rational *B)
{
    Rational *C = new Rational;
    C->set_numerator((A->get_numerator()*B->get_denominator())-(A->get_denominator()*B->get_numerator()));
    C->set_denominator(A->get_denominator()*B->get_denominator());
    C = C->Reduse(C);
    return C;
}

Rational * Rational::Mul(Rational * A, Rational *B)
{
    Rational *C = new Rational;
    C->set_numerator(A->get_numerator()*B->get_numerator());
    C->set_denominator(A->get_denominator()*B->get_denominator());
    C = C->Reduse(C);
    return C;
}

Rational * Rational::Div(Rational * A, Rational *B)
{
    Rational *C = new Rational;
    C->set_numerator(A->get_numerator()*B->get_denominator());
    C->set_denominator(A->get_denominator()*B->get_numerator());
    C = C->Reduse(C);
    return C;
}

bool TheyEqual(Rational *A, Rational *B)
{
    A = A->Reduse(A);
    B = B->Reduse(B);
    if(A->get_numerator() == B->get_numerator() && A->get_denominator() == B->get_denominator())
    {
        return true;
    }else{
        return false;
    }

}

Rational * Rational::Greate(Rational * A, Rational *B)
{
    Rational *tempA = new Rational;
    Rational *tempB = new Rational;

    tempA->set_numerator(A->get_numerator()*B->get_denominator());
    tempA->set_denominator(A->get_denominator()*B->get_denominator());

    tempB->set_numerator(B->get_numerator()*A->get_denominator());
    tempB->set_denominator(B->get_denominator()*A->get_denominator());


    if(tempA->get_numerator() > tempB->get_numerator())
    {

        delete tempA;
        delete tempB;
        return A;
    }else{
        delete tempA;
        delete tempB;
        return B;
    }


}

Rational * Rational::Less(Rational * A, Rational *B)
{
    Rational *tempA = new Rational;
    Rational *tempB = new Rational;

    tempA->set_numerator(A->get_numerator()*B->get_denominator());
    tempA->set_denominator(A->get_denominator()*B->get_denominator());

    tempB->set_numerator(B->get_numerator()*A->get_denominator());
    tempB->set_denominator(B->get_denominator()*A->get_denominator());


    if(tempA->get_numerator() < tempB->get_numerator())
    {

        delete tempA;
        delete tempB;
        return A;
    }else{
        delete tempA;
        delete tempB;
        return B;
    }


}

Rational Rational::operator+ (Rational B)
{
    Rational *C = new Rational;
    C->set_numerator((numerator*B.denominator)+(denominator*B.numerator));
    C->set_denominator(denominator*B.denominator);
    C=C->Reduse(C);
    return *C;
}

Rational Rational::operator- (Rational B)
{
    Rational *C = new Rational;
    C->set_numerator((numerator*B.denominator)-(denominator*B.numerator));
    C->set_denominator(denominator*B.denominator);
    C=C->Reduse(C);
    return *C;
}

Rational Rational::operator* (Rational B)
{
    Rational *C = new Rational;
    C->set_numerator(numerator*B.numerator);
    C->set_denominator(denominator*B.denominator);
    C=C->Reduse(C);
    return *C;
}

Rational Rational::operator/ (Rational B)
{
    Rational *C = new Rational;
    C->set_numerator(numerator*B.denominator);
    C->set_denominator(denominator*B.numerator);
    C=C->Reduse(C);
    return *C;
}

bool operator> (Rational A,Rational B)
{
        int num1, num2;
        num1 = A.numerator*B.denominator;
        num2 = A.denominator*B.numerator;
        if(num1 > num2)
        {
            return true;
        }else{
            return false;
        }
}

bool operator< (Rational A,Rational B)
{
        int num1, num2;
        num1 = A.numerator*B.denominator;
        num2 = A.denominator*B.numerator;
        if(num1 < num2)
        {
            return true;
        }else{
            return false;
        }
}

bool operator== (Rational A,Rational B)
{
    int num1, num2;
    num1 = A.numerator*B.denominator;
    num2 = A.denominator*B.numerator;
        if(num1 == num2)
        {
            return true;
        }else{
            return false;
        }
}

void Rational::changeAmount()
{
    amountOfObjects++;
}

//int Rational::get_amountOfObjects()
//{
//    return amountOfObjects;
//}

