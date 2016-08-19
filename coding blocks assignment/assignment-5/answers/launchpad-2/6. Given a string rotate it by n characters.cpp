 //Given a string rotate it by n characters
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
     char temp;
     int n;
     cout<<"rotate it by how many characters"<<endl;
     cin>>n;
     int length=stringLength(ch,256);
     temp=ch[length-1];
     int j=0;
     while(j<n)
     {
     for(int i=length-2;i>=0;i--)
     {
         ch[i+1]=ch[i];
     }
     ch[0]=temp;
     temp=ch[length-1];
     j++;
     }
     cout<<ch;
     return 0;
 }
