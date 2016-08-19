// code for function power using recursion
#include<iostream>
using namespace std;
int power(int x,int n)
{
    if(n==1)
    {
        return x;
    }
    int answer=x*power(x,n-1);
}
int main()
{
    int n,x;
    cout<<"enter no."<<endl;
    cin>>x;
    cout<<"enter power"<<endl;
    cin>>n;
    int ans=power(x,n);
    cout<<ans;

}
