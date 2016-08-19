//linear search
//search for an no. and find its index
#include<iostream>
using namespace std;
int linearSearch(int a[],int toBeSearched,int size)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==toBeSearched)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[10],a;
    for(int i=0;i<10;i++)
    {
        cin>>arr[i];
    }
    cin>>a;
    cout<<linearSearch(arr,a,10);
    return 0;
}
