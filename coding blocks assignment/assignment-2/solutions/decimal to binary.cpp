//binary conversion
#include<iostream>
using namespace std;
int main()
{
    int i=0,n,arr[100000],k,flag=0,j;
    cin>>n;
    while(flag!=1)
    {

       if(n==1)
       {
         arr[i]=1;
         k=i;
         flag=1;
       }
       arr[i]=n%2;
       i++;
       n=n/2;
    }

    while(k>=0)
    {
        cout<<arr[k];
        k--;
    }
    return 0;
}
