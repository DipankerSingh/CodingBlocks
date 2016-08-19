//Given a string, compute recursively a new string where all the 'x' chars have been removed.
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
void removeX(char *source,char *destination,int size)
{
    if(size==0)
    {
        *destination='\0';
        return;
    }
    if(*source=='x')
    {
        removeX(source+1,destination,size-1);
    }
    else
    {
        *(destination)=*(source);
        removeX(source+1,destination+1,size-1);
    }
}
int main()
{
    char ch[1000];
    cin>>ch;
    char destination[1000];
    removeX(ch,destination,stringLength(ch));
    cout<<destination;
    return 0;

}
