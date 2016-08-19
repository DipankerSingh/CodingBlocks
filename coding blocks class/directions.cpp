//directions.cpp
#include<iostream>
using namespace std;
int main()
{
    char ch;
    int n=0,e=0;
    while((ch=cin.get())!='\n')
    {
        if(ch=='N')
            n++;
        else if(ch=='S')
            n--;
        else if(ch=='E')
            e++;
        else
            e--;
    }
    if(n>0)
    {
        while(n!=0)
        {
            cout<<"N";
            n--;
        }

    }
    else
    {
        while(n!=0)
        {
            cout<<"S";
            n++;
        }
    }
     if(e>0)
    {
        while(e!=0)
        {
            cout<<"E";
            e--;
        }

    }
    else
    {
        while(e!=0)
        {
            cout<<"W";
            e++;
        }
    }

    return 0;
}
