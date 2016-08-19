//checkingDuplicateParenthesis
#include<iostream>
#include<cstring>
#include "stacks.h"
using namespace std;
int duplicateParenthesis(char ch[],int length)
{
    Stack s(100);
    int count1=0,count2=0;
    int flag=0;
    for(int i=0;i<length;i++)
    {
        char c = ch[i];

		if (c == '(' || c == '{' || c == '[') {
            flag=0;
			s.push(c);
			count1++;
		} else if (c == ')') {
		    flag=0;

			if (s.pop() != '(') {
				return -1;
			}

		} else if (c == '}') {
		    flag=0;

			if (s.pop() != '{') {
				return -1;
			}
		} else if (c == ']') {
		    flag=0;

			if (s.pop() != '[') {
				return -1;
			}
		}
		else
        {
            if(flag==0)
            {
            count2++;
            flag=1;
            }
        }
    }
    if (s.isEmpty())
    {
        if(count1>count2)
        {

            return 1;
        }
        else
        {
        return 0;
        }
	}
	else
	{
		return -1;
	}

}
int main()
{
    char ch[100];
    cin>>ch;
    cout<<duplicateParenthesis(ch,strlen(ch));
    return 0;
}
