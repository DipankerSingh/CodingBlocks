////string made of letters a and b only
#include<iostream>
using namespace std;
int stringLength(char arr[])
{
    for(int i=0;i<1000;i++)
    {
        if(arr[i]=='\0')
        {
            return i;
        }
    }
    return -1;
}
int checkRules(char *input,int size)
{
  if(*input=='\0')
  {

      return 1;
  }
  if(*input == 'a')
  {
  if((*(input+1)!='\0' && *(input+1)!='a'))
  {

      if(*(input+1)!='b' ||*(input+2)!='b')
      {
          if(size==1)
            return 1;
          else
            return 2;
      }
  }
  }
  if(*input=='b'&& *(input+1)=='b')
  {
    if((*(input+2)!='\0') && (*(input+2)!='a'))
  {
      if(size==2)
        return 1;
      else
        return 3;
  }
  }

  int error = checkRules(input+1,size-1);
  return error;


}
int main()
{
    char input[100];
    cin>>input;
    if(input[0]=='a')
    {
        cout<<"The String Begins With An a"<<endl;
        int error=checkRules(input,stringLength(input));
        if(error==2)
        {
            cout<<"BUT a is not followed by 'nothing' or 'a' or 'bb' "<<endl;
        }
        if(error==3)
        {
            cout<<" BUT each 'bb' is not followed by 'nothing' or an 'a' "<<endl;
        }
        if(error==1)
        {
            cout<<"and a is followed by 'nothing' or 'a' or 'bb' "<<endl;
            cout<<"each 'bb' is followed by 'nothing' or an 'a' "<<endl;
        }
    }

    else
    {
        cout<<"the String does not begin with a";
    }

    return 0;
}
