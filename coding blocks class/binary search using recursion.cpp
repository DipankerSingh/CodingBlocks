// binary search using recursion
#include<iostream>
using namespace std;

int index(int input[],int start,int end,int toBesearched)
{
    if(end<start)
    {
        return -1;
    }
    if(input[(start+end)/2]==toBesearched)
    {
        return (start+end)/2;
    }
    if(input[(start+end)/2+1]>toBesearched)
    {
        end=(start+end)/2-1;
        return index(input,start,end,toBesearched);
    }
    else
    {
        start=(start+end)/2+1;
        return index(input,start,end,toBesearched);
    }
}
int main()
{
    int input[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    int a;
    cin>>a;
    int found=index(input,0,n-1,a);
    cout<<found;

}
