//find a small string inside a bigger string
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
    char ch[1000];
    cin>>ch;
    char sub[100];
    cin>>sub;
    int l1=stringLength(ch,256);
    int l2=stringLength(sub,256);
    int address;
    int flag;
    for(int i=0;i<l1;i++)
    {

        if(sub[0]==ch[i])
        {
        flag=0;
        address=i;
        int temp=i;
        for(int j=0;j<l2;j++)
        {
         if(sub[j]!=ch[temp])
         {
          break;
          flag=1;
         }

          temp++;
        }
        }

    }
    if(flag==0)
    {
        cout<<"Yes it's a substring"<<endl;
        cout<<address;
    }

}

