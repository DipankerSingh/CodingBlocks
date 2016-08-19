//to find a substring of a string
#include<iostream>
using namespace std;
void substring(char source[],char destination[],int begin,int end)
{
    int j=0;
    for(int i=begin;i<=end;i++)
    {
        destination[j]=source[i];
        j++;
    }
    destination[j]='\0';
}
int main()
{
    char ch[1000];
    int start,end;
    cout<<"enter the start and the end of the substring"<<endl;
    cin>>start>>end;
    char finale[1000];
    cout<<"enter the string"<<endl;

    cin>>ch;

    substring(ch,finale,start,end);
    cout << finale <<endl;

    for(int j=0;j<=(end-start);j++)
    {
        cout<<finale[j];
    }
    return 0;
}
