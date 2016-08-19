//bitset
#include<iostream>
using namespace std;
int main()
{
    int count=0;
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

        if(arr[k]==1)
        {
            count=count+1;
        }
        k--;

    }
    cout<<count;
    return 0;
}

