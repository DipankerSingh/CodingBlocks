//ques 5 square root of a no. using long division method
#include<iostream>
using namespace std;
int main()
{
    int n,i=1,k;
    float sum=0,p=1,t;
    cin>>n;

    while((i*i)<=n)
    {
        i=i+1;
    }
    i=i-1;
    cout<<i<<'.';
    sum=i;

    int dividend,divisor,remainder;
    float j=1;
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
        if(k==0)
        {
            j=1;
            float z=10;
            cout<<k;
            t=(k);
            while(j<p)
            {
                z=z*10;
                j++;
            }
            sum=sum+(t/(z));
        }
        else
        {
            j=1;
            int z=10;
            cout<<k-2;
            t=(k-2);
            while(j<p)
            {
                z=z*10;
                j++;
            }
            sum=sum+(t/(z));
        }

        p=p+1;

    }
    cout<<endl;
    cout<<sum;
    return 0;
}
