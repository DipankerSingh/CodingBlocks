//merge sort using recursion
#include<iostream>
using namespace std;

void mergeSort(int input[],int n)
{

    if(n==1)
    {
        return;
    }
    int array1[n/2],array2[n-n/2];
    for(int i=0;i<n/2;i++)
    {
        array1[i]=input[i];
    }
    int j=0;
    for(int i=n/2;i<n;i++)
    {

        array2[j]=input[i];
        j++;
    }
    mergeSort(array1,n/2);
    mergeSort(array2,n-n/2);

    int t=n,k=0,count=0;
        int i=0,min;
        j=0;
    while((k<t))
        {

        if(array1[i]<array2[j])
        {
            input[count]=array1[i];
            count++;

            i++;

            k++;
        }
        else
        {

            input[count]=array2[j];
            count++;
            j++;
            k++;
        }
        if(j==n-n/2)
        {
            while(k<t)
            {
             input[count]=array1[i];
             count++;
             i++;
             k++;
            }
            return;
        }
        if(i==n/2)
        {
            while(k<t)
            {


             input[count]=array2[j];
             count++;
             j++;
             k++;
            }

        }
    }

    return;


}
int main()
{
    int input[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }

    mergeSort(input,n);
    for(int i=0;i<n;i++)
    {
        cout<<input[i]<<endl;
    }

    return 0;
}
