//removing dupicates upto 15 without losing data
#include<iostream>
using namespace std;
int calculateCount(char finale[],int count,int j)
{
    int numberOfDigits=0;
    int temp1=count;
    while(temp1>0)
    {
        numberOfDigits++;
        temp1/=10;
    }
    int temp=j+numberOfDigits-1;
    while(count>0)
    {
        finale[temp]=48+count%10;
        temp--;
        j++;
        count=count/10;
    }
    return j;

}
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
    char ch[1000],finale[1000],count=0,start=0,end=0;
    int j=0,flag=0;
    cout<<"enter the string"<<endl;
    cin>>ch;
    int length=stringLength(ch,256);
    if(ch[0]!=ch[1])
        {
            finale[0]=ch[0];
            j++;
        }

    for(int i=0;i<length;i++)
    {



        if(ch[i]==ch[i+1]&&flag==0)
        {
          start=i;
          flag=1;
          finale[j]=ch[i];
          j++;
        }
        if(ch[i]!=ch[i+1])
        {
            end=i+1;
            count=end-start;
            start=end;
            flag=0;
            j=calculateCount(finale,count,j);
            //finale[j]=count+48;
            //j++;
            finale[j]=ch[i+1];
            j++;
            if(ch[i+1]==ch[i+2]&&flag==0)
            {
                start=i+1;
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
