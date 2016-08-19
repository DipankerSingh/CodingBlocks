//removing duplicate
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
void strcopy(char arr[],int length)
{
    for(int i=0;i<length;i++)
    {
        char bestSoFar[1000];
        bestSoFar[i]=arr[i];
    }
}
int main()
{
    char ch[1000],finale[1000];
    int j=0,flag=0;
    cout<<"enter the string"<<endl;
    cin>>ch;
    int length=stringLength(ch,256);
    for(int i=0;i<length;i++)
    {

        if(ch[i]==ch[i+1]&&flag==0)
        {
          flag=1;
          finale[j]=ch[i];
          j++;
        }
        if(ch[i]!=ch[i+1])
        {
            flag=0;
            finale[j]=ch[i+1];
            j++;
            if(ch[i+1]==ch[i+2]&&flag==0)
            {
                flag=1;
            }
        }
        if(ch[i+1]=='\0')
        {
            finale[j]='\0';
            break;
        }
    }
    cout<<finale;
    return 0 ;

}
