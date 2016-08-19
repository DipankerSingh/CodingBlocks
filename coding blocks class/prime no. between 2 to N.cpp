// prime no. between 2 to N
#include<iostream>
using namespace std;
int main()
{
    int n,i=2;
    cin>>n;
    while(i<=n)
    {
            int j=1,count=0;
            while(j<=i)
            {
                    if(i%j==0)
                    {
                        count=count+1;
                        j++;
                    }
                    else
                    {
                        j++;
                    }
            }
    if(count==2)
        {cout<<i<<endl;}
    i=i+1;
    }
    return 0;

}
