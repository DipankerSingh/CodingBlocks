//largestSubarrayWIthEqualZeroesAndOnes
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int universalBestStart=0;
    int universalBestEnd=0;
    int bestSoFar=0;

    int count1=0,count0=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
                {
                    count0++;
                }
            else
                {
                    count1++;
                }
        for(int j=i+1;j<n;j++)
        {

            if(a[j]==0)
            {
                count0++;
            }
            else
            {
                count1++;
            }

                if(count0==count1)
                {
                    int currentBest=j-i+1;
                    if(currentBest>bestSoFar)
                    {
                        universalBestStart=i;
                        universalBestEnd=i+currentBest;
                    }

                }

        }
    }

    for(int k=universalBestStart;k<universalBestEnd;k++)
    {
        cout<<a[k]<<endl;
    }
}
