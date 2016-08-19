// finding global minima
#include<iostream>
using namespace std;
int main()
{
    int n,i=0;
    cin>>n;
    int arr[n];
    while(i<n)
    {
        cin>>arr[i];
        i++;
    }
    i=0;
    int count=0;
    while(i<n)
    {
     if(arr[i]<arr[i+1])
     {
        count++;
        i=i+1;
     }
     i=i+1;
    }
 if(count==1)
 {
     cout<<"yes";
 }
 else
 {
     cout<<"no";
 }

}
