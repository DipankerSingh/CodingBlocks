//Reverse a string keeping the words intact
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
void reverseString(char input[],char reverse1[],int length,int initial,int j)
{
    int i=initial;

    while(input[i]!=32 || input[i]!='\0')
    {
        i++;
    }

    int l2=i-initial;
    while(j<(initial+l2))
    {
       reverse1[length-l2+j]=input[j];
       j++;
       if(j==initial+l2-1)
       {
           reverse1[length-l2+j+1]=32;
           j++;
           i++;
       }
    }
    if(i<length)
    {
        reverseString(input,reverse1,length,i,j);
    }
    if(i>length)
    {
        reverse1[length-1]='\0';
        cout<<reverse1;
    }

}
int main()
{
   char ch;
   char input1[1000];
   int i=0;
   while((ch=cin.get())!='\n')
   {
      input1[i]=ch;
      i++;
   }
    input1[i]='\0';

   int length=stringLength(input1,256);
   char reverse1[1000];

   reverseString(input1,reverse1,length,0,0);

    return 0;
}
