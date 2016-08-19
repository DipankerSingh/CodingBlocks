//Given two Strings check if one is reverse of the other
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
bool reverse(char *string1,char *string2,int size)
{
    if(size==0)
    {
        return true;
    }

    if(*string1==*(string2+size-1))
    {
        return reverse(string1+1,string2,size-1);
    }
    else
        return 0;
}
int main()
{
    char string1[100],string2[100];
    cin>>string1;
    cin>>string2;
    if(stringLength(string1)!=stringLength(string2))
        cout<<0;
    else
    cout<<reverse(string1,string2,stringLength(string1));
    return 0;
}
