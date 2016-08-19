// ques 4 roots of quadratic equation
#include <iostream>
using namespace std;
int main()
{
    float a,b,c,discriminant,r1,r2,p;
    cin>>a>>b>>c;
    discriminant=(b*b)-(4*a*c);
    if(discriminant>=0)
    {

    float min=100000;
    float i=5,j;

    while(!((min<0.00001)&&(min>-0.00001)))
    {
        j=i-((i*i-discriminant)/(2*i));
        min=j-i;
        i=j;
    }
        p=j;
        if(discriminant>0)
    {
        cout<<"the roots are real and distinct"<<endl;
        cout<<((-b+p)/(2*a))<<" "<<((-b-p)/(2*a));
    }
    else
    {
        cout<<"the roots are real and coincident"<<endl;
        cout<<(-b+p)/(2*a);
    }

    }
    else
    {
        cout<<"the roots are imaginary";
    }

    return 0;
}
