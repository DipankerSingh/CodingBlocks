// mean min max
#include<iostream>
using namespace std;
int main()
{
    float avg;
    int n,i=0,a,sum=0,max=-100000000,min=100000000;
    cin>>n;
    while(i<n)
    {
        cin>>a;
        sum=sum+a;
        if(a>max)
        {
            max=a;
        }
        if(a<min)
        {
            min=a;
        }
        i=i+1;
    }
    avg=(((float)sum)/n);
    cout<<avg<<endl<<min<<endl<<max<<endl;
    return 0;
}
