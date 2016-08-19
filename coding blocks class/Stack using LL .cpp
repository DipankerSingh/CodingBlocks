#include<iostream>
#include"StackUsingQueue.h"
using namespace std;
int main()
{
    stackq s;
    for(int i=0;i<5;i++)
    {
        s.push(i);
    }
    for(int i=0;i<5;i++)
    {
        cout<<s.pop()<<endl;
    }
    return 0;
}
