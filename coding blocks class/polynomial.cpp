#include<iostream>
#include"polynomial.h"
using namespace std;
int main()
{
    polynomial p1;

    p1.enterPolynomial();

    //cout<<"The value of the polynomial for x=1 is "<<p.evaluate(1);

    polynomial p2;

    p2.enterPolynomial();


    polynomial p3;
    p3=(p1+p2);

    int i=0;
    int size=p3.v.size();
    cout<<size;
    while(i<size)
    {
        cout<<p3.v[i].coefficient<<"x^"<<p3.v[i].power<<"+";
        i++;

    }







}
