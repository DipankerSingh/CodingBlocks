//finding a no. in array
#include<iostream>
using namespace std;
bool findNumber(int *array,int toBeSearched,int size)
{
    if(size==0)
    {
        return false;
    }
    if(array[0]==toBeSearched)
    {
        return true;
    }
    bool isPresent=findNumber(array+1,toBeSearched,size-1);
    if(isPresent)
        return true;
    else
        return false;
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
    bool b=findNumber(input,a,n);
    cout<<b;
}
