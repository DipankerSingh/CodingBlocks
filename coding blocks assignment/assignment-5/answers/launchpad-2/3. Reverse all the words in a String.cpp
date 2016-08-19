// Reverse all the words in a String
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
    char input;
    char ch[1000];
    int p=0;
   while((input=cin.get())!='\n')
   {
      ch[p]=input;
      p++;
   }
    ch[p]='\0';
    int length=stringLength(ch,256);

    int i=0;
    int initial=0;
    for(i=0;i<=length;i++)
    {
        if((ch[i]==' ')||(ch[i]=='\0'))
        {

            for(int j=i-1;j>=initial;j--)
            {
                cout<<ch[j];
            }
            cout<<" ";
            initial=i+1;

        }
    }
}
