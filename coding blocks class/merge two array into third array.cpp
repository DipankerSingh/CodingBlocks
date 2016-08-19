//merge two sorted arrays into the third array
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
    int arr1[1000]={0},arr2[10000]={0},arr3[10000]={0},count=0;
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"enter the second sorted array"<<endl;
    for(int j=0;j<n2;j++)
    {
        cin>>arr2[j];
    }





        int t=n1+n2,k=0;
        int i=0,j=0,min;
        while((k<t))
        {

        if(arr1[i]<arr2[j])
        {
            arr3[count]=arr1[i];
            count++;

            i++;

            k++;
        }
        else
        {

            arr3[count]=arr2[j];
            count++;
            j++;
            k++;
        }
        if(j==n2)
        {
            while(k<t)
            {


             arr3[count]=arr1[i];
             count++;
             i++;
             k++;
            }

        }

        if(i==n1)
        {
            while(k<t)
            {


             arr3[count]=arr2[j];
             count++;
             j++;
             k++;
            }

        }
    }

    for(int p=0;p<count;p++)
    {
        cout<<arr3[p]<<endl;
    }
  return 0;
}
