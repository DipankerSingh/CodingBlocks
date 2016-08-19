// a program to convert a string to lower case
#include<iostream>
using namespace std;
int stringLength(char arr[],int max_size)
{
    for(int i=0;i<max_size;i++)
    {
        if(arr[i]=='\0')
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    char input[100];
    cin>>input;
    int length=stringLength(input,256);
    int i=0;
    while(i<length)
    {
        if(input[i]>64 && input[i]<91)
        {
            input[i]=input[i]+32;
        }
        i++;
    }
    cout<<input;
}
