//pattern
#include<iostream>
using namespace std;
int main ()
{
    int n,row=0,col=0,value=1;
    cin>>n;
    while(row<n)
    {
        col=0;
        while(col<=row)
        {
            cout<<value<<' ';
            value=value+1;
            col++;
        }
     cout<<endl;
     row++;
    }

}
