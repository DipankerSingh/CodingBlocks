//Given a string, compute recursively (no loops) a new string where all appearances of "pi" have been replaced by "3.14"
//changePi("xpix") → "x3.14x"
//changePi("pipi") → "3.143.14"
//changePi("pip") → "3.14p"
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
void replacePie(char *source,int size,char *destination)
{
    if(size==0)
    {
        destination[0]='\0';
        return;
    }
    if(size==1)
    {
        destination[0]=source[0];
        destination[1]='\0';
        return;
    }
    if(source[0]=='p' && source[1]=='i')
    {
        destination[0]='3';
        destination[1]='.';
        destination[2]='1';
        destination[3]='4';
        replacePie(source+2,size-2,destination+4);
    }
    else
    {
        destination[0]=source[0];
        replacePie(source+1,size-1,destination+1);
    }


}
int main()
{
    char ch[1000],destination[1000];
    cin>>ch;
    replacePie(ch,stringLength(ch),destination);
    cout<<destination;
    return 0;
}
