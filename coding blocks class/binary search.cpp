//binary search
#include<iostream>
using namespace std;
int main()
{
    int n,a;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    cout<<"enter the elements in ascending order"<<endl;
    int arr[10000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter the element to be searched"<<endl;
    cin>>a;
    int flag=0,address;
    int start=0,end=n-1;
    while(flag!=1&&flag!=2)
    {

        if(arr[start+((end-start)/2)]>a)
        {
            if(end==start)
            {
                flag=2;
            }
            end=start+((end-start)/2)-1;

        }
        else if (arr[start+((end-start)/2)]<a)
        {
            if(end==start)
            {
                flag=2;
            }
            start=1+start+((end-start)/2);

        }
        else if (arr[start+((end-start)/2)]==a)
        {
            address=start+((end-start)/2);
            flag=1;
        }


    }

    if(flag==1)
    cout<<"the index of the element is "<<address;
    else
    cout<<"there is no such element";

}
