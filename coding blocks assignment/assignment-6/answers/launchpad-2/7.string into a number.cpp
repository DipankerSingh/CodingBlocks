// Write a recursive function to convert a String into the number it represents. e.g. for input “1231” you should return integer 1231
#include<iostream>
using namespace std;
float power(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    return a * power(a,b-1);


}
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
int returnNumber(char *source,int size)
{
    if(size==1)
    {
        return *source-48;
    }
    int number;
    number=((*source-48)*(power(10,size-1)))+ returnNumber(source+1,size-1);
    return number;
}
int main()
{
    char ch[100];
    cin>>ch;
    cout<<returnNumber(ch,stringLength(ch));
    return 0;
}
