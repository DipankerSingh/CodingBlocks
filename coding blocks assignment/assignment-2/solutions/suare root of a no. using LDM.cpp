//ques 5 square root of a no. using long division method
#include<iostream>
using namespace std;
int main()
{
    int n,i=1,k;
    cin>>n;

    while((i*i)<=n)
    {
        i=i+1;
    }
    i=i-1;
    cout<<i<<'.';

    int dividend,divisor,remainder,j=0;
    divisor=2*i;
    dividend=n-(i*i);

    while(j<5)
    {
        k=0,remainder=dividend;
        while(remainder>0)
        {
            remainder=(dividend*100)-(((divisor*10)+k)*k);
            k++;

            if(remainder>0)
            {
                remainder=dividend;
            continue;
            }
            else if(remainder<=0)
            {
            dividend=(dividend*100)-(((divisor*10)+(k-2))*(k-2));
            divisor=(divisor*10)+2*(k-2);
            }

        }
        cout<<k-2;
        j++;
    }
    return 0;
}
