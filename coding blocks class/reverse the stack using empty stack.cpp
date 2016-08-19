//reverse the stack using an empty stack
#include<iostream>
#include "stacks.h"
void reverseStack(Stack s)
{
    if(s.get_size()==1)
    {
        return;
    }
    int temp=s.pop();
    reverseStack(s);
    Stack empty(50);
    while(s.get_size()!=0)
    {
    empty.push(s.pop());
    }
    s.push(temp);
    while(empty.get_size()!=0)
    {
    s.push(empty.pop());
    }

    return;


}
using namespace std;
int main()
{
    Stack s(50);
    for(int i=1;i<=50;i++)
    {
        s.push(i);
    }
    reverseStack(s);
    for(int i=1;i<=50;i++)
    {
        cout<<s.pop()<<endl;
    }
    return 0;

}

