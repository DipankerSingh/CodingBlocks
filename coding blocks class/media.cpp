//function  to return median of two sorted arrays of n elements each
#include<iostream>
using namespace std;
int main()
{
    int n1,n2,temp;
    cout<<"Enter the size of array1 ";
    cin>>n1;
    cout<<"Enter the size of array2 ";
    cin>>n2;
    cout<<"enter the sorted array 1"<<endl;
    int arr1[1000]={0},arr2[10000]={0};
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"enter the second sorted array"<<endl;
    for(int j=0;j<n2;j++)
    {
        cin>>arr2[j];
    }

    if(n1==n2)
    {
    int n=n1;
    int k=0,i=0,j=0,min;
    while(k<n)

    {
        if(arr1[i]<arr2[j])
        {
            i++;
            if(k==(n-1))
            {
                min=arr1[i-1];
            }
            k++;
        }
        else
        {
            j++;
            if(k==(n-1))
            {
                min=arr2[j-1];
            }
            k++;
        }


    }

    cout<<"The Median is "<<min;
    }

    else if(n1<n2)
    {
        int t=((n1+n2)/2)+1,k=0;
        int i=0,j=0,min;
        while((k<t))
        {

        if(arr1[i]<arr2[j])
        {
            i++;
            if(k==(t-1))
            {
                min=arr1[i-1];
            }
            k++;
        }
        else
        {
            j++;
            if(k==(t-1))
            {
                min=arr2[j-1];
            }
            k++;
        }


        if(i==n1)
        {



            while(k<t)
            {
             if(k==t-1)
             {
                 min=arr2[j];
             }
             j++;
             k++;
            }

        }
    }
    cout<<min;
    }
  return 0;
}
