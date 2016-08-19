#include<iostream>
#include "satcks2.h"
using namespace std;
int main()
{
    Stack *s=new Stack();
    for(int i=1;i<=6;i++)
    {

        s->push(i);
    }

    for(int i=1;i<=6;i++)
    {

        cout<<s->pop()<<endl;
    }
}
