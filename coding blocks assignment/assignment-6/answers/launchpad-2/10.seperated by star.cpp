// compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*"
#include<iostream>
using namespace std;
int stringLength(char ch[])
{
    int i=0;
    for(i=0;i<=1000;i++)
    {
        if(ch[i]=='\0')
        return i;
    }
    return -1;
}
void seperateByStar(char *source,int size,char *destination)
{
    if(size==0)
    {
        *destination='\0';
        return;
    }
    if(*source==*(source+1))
    {
        *destination=*source;
        *(destination+1)='*';
        *(destination+2)=*source+1;
        seperateByStar(source+1,size-1,destination+2);
    }
    else
    {
        *destination=*source;
        seperateByStar(source+1,size-1,destination+1);
    }


}
int main()
{
    char ch[100];
    cin>>ch;
    char destination[100];
    seperateByStar(ch,stringLength(ch),destination);
    cout<<destination;
    return 0;
}
