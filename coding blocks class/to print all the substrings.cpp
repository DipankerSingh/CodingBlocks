//to print all the substrings
#include<iostream>
using namespace std;
char bestSoFar[10000];
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
void strcopy(char arr[],int length,int sizeOfsubstring)
{
    int start=0,end=length-1,j=0;
    char bestSoFar[1000];

    int i=0;
    while((i<(start+sizeOfsubstring))&&((start+sizeOfsubstring-1)<length))
    {

        bestSoFar[j]=arr[i];

        j++;
        if(i==(start+sizeOfsubstring-1))
        {
            bestSoFar[j]='\0';
            cout<<bestSoFar<<endl;
            start++;
            j=0;
            i=start-1;
        }
        i++;
    }



    sizeOfsubstring--;
    if(sizeOfsubstring>0)
    {
        strcopy(arr,length,sizeOfsubstring);
    }
}

int main()
{
  char ch[10000];
  cout<<"Enter the string"<<endl;
  cin>>ch;
  int length=stringLength(ch,256);
  strcopy(ch,length,length);
  return 0;
}
