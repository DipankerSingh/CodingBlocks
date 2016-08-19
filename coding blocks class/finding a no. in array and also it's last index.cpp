//finding a no. in array and also it's last index
#include<iostream>
using namespace std;
int findNumber(int *array,int toBeSearched,int size,int b)
{
    if(size==0)
    {
        return b;
    }
    if(array[0]==toBeSearched)
    {
        b=size;

    }
    int a=findNumber(array+1,toBeSearched,size-1,b);
    if(a>=0)
        return a;
    else
        return -1;
}
int main()
{
    int input[100],n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    cout<<"enter the number to be searched"<<endl;
    int a;
    cin>>a;
    int b=findNumber(input,a,n,-1);
    if(b>=0)
    cout<<n-b;
    else
        cout<<b;
}


