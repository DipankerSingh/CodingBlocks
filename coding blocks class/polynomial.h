//polynomial
#include<iostream>
#include<vector>
#include <math.h>
#include"pair3.h"
using namespace std;
class polynomial
{

    public:
    vector<pair1> v;
    void enterPolynomial()
    {
    pair1 currentInput(0,0);
    cout<<"Enter The Power of x"<<endl;
    cin>>currentInput.power;

    while(currentInput.power!=-1)
    {
        cout<<"Enter The Coefficient of x^"<<currentInput.power<<endl;
        cin>>currentInput.coefficient;
        v.push_back(currentInput);
        cout<<"Enter The Power of x"<<endl;
        cin>>currentInput.power;

    }
    }

    int evaluate(int x)
    {
        int value=0;
        while(v.size()!=0)
        {
            value=value+ ((v.back().coefficient)* pow(x,v.back().power));
            v.pop_back();
        }
        return value;
    }



    polynomial operator=(const polynomial&p2)
    {
        int size=p2.v.size();
        int i=0;
        pair1 p(0,0);
        while(i<size)
        {
            p.power=p2.v[i].power;
            p.coefficient=p2.v[i].coefficient;
            this->v.push_back(p);

            i++;
        }
        return *this;

    }


    polynomial operator+ (polynomial&p2)const
    {
        int i=0,j=0;
        polynomial p3;
        pair1 p(0,0);

        while(i<(this->v.size()-1) || (j<p2.v.size()-1))
        {

            if(this->v[i].power==p2.v[j].power)
            {

                p.coefficient=this->v[i].coefficient+p2.v[j].coefficient;
                p.power=p2.v[j].power;
                i++;
                j++;
                p3.v.push_back(p);

            }

            else if(this->v[i].power>p2.v[j].power)
            {
                p.coefficient=p2.v[j].coefficient;
                p.power=p2.v[j].power;
                j++;
                p3.v.push_back(p);
            }
            else
            {
                p.coefficient=this->v[i].coefficient;
                p.power=this->v[i].power;
                i++;
                p3.v.push_back(p);

            }
        }
    }
};
