// Use recursion to check if a given String is palindrome or not
#include<iostream>
using namespace std;
int stringLength(char ch[])
{
    int i=0;
    for(i=0;i<=1000;i++)
    {
        if(ch[i]=='\0')
        return i;
    }
    return -1;
}

bool palindrome(char *array,int size)
{
    if(size<=0)
    {
        return 1;
    }
    if(array[0]==array[size-1])
    {
        return palindrome(array+1,size-2);
    }
    else
    {
        return 0;
    }
}
int main()
{
    char ch[100];
    cin>>ch;
    cout<<palindrome(ch,stringLength(ch));
    return 0;
}
