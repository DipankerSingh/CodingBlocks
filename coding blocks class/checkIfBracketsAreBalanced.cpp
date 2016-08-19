//checkIfBracketsAreBalanced
#include<iostream>
#include "stacks.h"
using namespace std;
bool bracketsBalanced(char input[])
{
    Stack s(50);
    for(int i=0;input[i]!='\0';i++)
    {
        char c=input[i];
        if(c=='(' || c=='{' || c=='[')
            {
                s.push(c);
            }
        else if (c==')')
        {
            if(s.pop()!='(')
            {
                return false;
            }


        }
        else if (c=='}')
        {
            if(s.pop()!='{')
            {
                return false;
            }

        }
        else if (c==']')
        {
            if(s.pop()!='[')
            {
                return false;
            }

        }
    }
    if(s.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char n[]="{}";
    cout<<bracketsBalanced(n);
    return 0;
}
