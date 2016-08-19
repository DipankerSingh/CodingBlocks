// multiply two numbers using addition and recursion
#include<iostream>
using namespace std;
int Multiply(int m,int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return m;
    }
    if(n==-1)
    {
        return -m;
    }
    int multiply;
    if(n>0)
    multiply=m+ Multiply(m,n-1);
    if(n<0)
    multiply=-m + Multiply(m,n+1);
    return multiply;
}
int main()
{
    int m,n;
    cin>>m;
    cin>>n;
    cout<<Multiply(m,n);
    return 0;
}
