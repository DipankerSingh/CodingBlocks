//frequecy of characters
#include<iostream>
using namespace std;
int main()
{
    int frequency[256]={0};
    char ch;
    while((ch=cin.get())!='\n')
    {
    frequency[ch]++;
    }
    cout<<"the frequency of various characters are as follows"<<endl;
    for(int i=0;i<256;i++)
    {
        ch=i;
        if(frequency[i]!=0)
        {cout<<ch<<" "<<frequency[i]<<endl;}
    }

}
