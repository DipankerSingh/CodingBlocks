//largest goes to the end in first iteration
#include<iostream>
using namespace std;
int main()
{
    int arr[100000]={0},temp,n;
    cout<<"enter the size of array"<<" ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int j=0;j<n;j++)
    {
    for(int i=0;i<=n-2;i++)
    {
        if(arr[i]>arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    }
    cout<<"the sorted array is"<<endl;
    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<" ";
    }
    return 0;
}
