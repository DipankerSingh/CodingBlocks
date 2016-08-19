//quick sort
#include<iostream>
using namespace std;
int pivotIndex(int input[],int start,int end)
{

    int count=0;
    for(int i=(start+1);i<=end;i++)
    {
        if(input[start]>input[i])
        {
            count++;
        }
    }
    int pivot=count;
     int temp=input[start];
    input[start]=input[start+pivot];
    input[start+pivot]=temp;
    int i=start;
    int j=end;
    while(i<(start+pivot)&&(j>start+pivot))
    {
        if((input[i]>input[start+pivot])&&(input[j]<input[start+pivot]))
           {
               int change=input[i];
               input[i]=input[j];
               input[j]=change;
               i++;
               j--;
           }
        else if((input[i]>input[start+pivot])&&(input[j]>input[start+pivot]))
            {
                j--;
            }
        else if((input[i]<input[start+pivot])&&(input[j]>input[start+pivot]))
            {
                i++;
                j--;
            }
        else if((input[i]<input[start+pivot])&&(input[j]<input[start+pivot]))
            {
                i++;

            }


    }
    return count;

}
void quickSort(int input[],int size,int start,int end)
{
    if(start>=end)
    {
            return;
    }

    int pivot=pivotIndex(input,start,end);

    quickSort(input,pivot,start,pivot-1);
    quickSort(input,size-pivot-1,start+pivot+1,end);


}
int main()
{
    int input[100],n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    quickSort(input,n,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<input[i]<<endl;
    }
    return 0;

}
