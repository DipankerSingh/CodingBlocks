//read lines from the input and print the longest line
#include<iostream>
using namespace std;
char bestSoFar[100000];
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

void strcopy(char arr[],int length)
{
    for(int i=0;i<length;i++)
    {
        bestSoFar[i]=arr[i];
    }
}

int main()
{
    char input[100000];

    int n,max=0;
    cout<<"enter the number of lines to be entered"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    cin>>input;

    int length=stringLength(input,256);
    if(max<length)
    {

    max=length;
    strcopy(input,length);
    }

    }
    cout<<"the longest array is: ";
    for(int j=0;j<max;j++)
    {

        cout<<bestSoFar[j];
    }
}

