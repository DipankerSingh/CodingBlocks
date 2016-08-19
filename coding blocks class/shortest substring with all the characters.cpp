//shortest substring with all the characters
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char S[100];
    cin.getline(S,100,'\n');
    char T[100];
    cin.getline(T,100,'\n');
    int frequency[256];
    for(int i=0;i<strlen(T);i++)
    {
        frequency[T[i]]++;
    }

    for(int i=0;i<strlen(T);i++)
    {
        cout<<frequency[i]<<endl;
    }

}
