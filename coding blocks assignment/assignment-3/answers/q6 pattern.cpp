//q6 pattern
#include<iostream>
using namespace std;
int main()
{
    int row=1,col=1,n;
    cout<<"enter the no. of rows (odd no.) ";
    cin>>n;
    for(row=1;row<=n;row++)
    {
        for(col=1;col<=(n-row+1);col++)
        {
            cout<<"*";

        }
        col=1;
        for(col=1;col<=(2*(row-1));col++)
        {
           cout<<" ";
        }
        col=1;
        for(col=1;col<=(n-row+1);col++)
        {
        cout<<"*";
        }
        cout<<endl;
    }
    row=1;
        for(row=1;row<n;row++)
    {
        for(col=1;col<=row+1;col++)
        {
            cout<<"*";

        }
        col=1;
        for(col=1;col<=(2*(n-row-1));col++)
        {
           cout<<" ";
        }
        col=1;
        for(col=1;col<=(row+1);col++)
        {
        cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}

