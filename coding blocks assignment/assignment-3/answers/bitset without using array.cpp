//bitset without using array
#include<iostream>
using namespace std;
int main()
{
    int n,i=1,binary=0,count=0;
    cin>>n;
    while(n>0)
    {
        binary=binary+(n%2)*i;
        if ((n%2)==1)
        {
            count++;
        }
        i=i*10;
        n=n/2;
    }
 cout<<binary<<" and the bitset is "<<count;
 return 0;
}
