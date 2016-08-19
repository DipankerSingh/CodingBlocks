//armstrong number
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int temp,sum=0,a;
    temp;
    a=n;
    while(n>0)
    {
        temp=n%10;
        sum=sum+((temp)*(temp)*(temp));
        n=n/10;
    }
    if(sum==a)
        {cout<<"the no. is armstrong";}
        return 0 ;



}
