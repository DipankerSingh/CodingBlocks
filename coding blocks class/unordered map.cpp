#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int a[]={1,2,3,1,1,-1,-1,-3,-4,-5};
    unordered_map<int,int> map;

    for(int i=0;i<10;i++)
    {
        if(map[a[i]]>0)
        {
            map[a[i]]=map[a[i]]+1;
        }
        else{
            map[a[i]]=1;
        }
    }

    int numOfPairs=0;

    for(int i=0;i<10;i++)
    {
        if(map[-a[i]]>0)
        {
            numOfPairs=numOfPairs+(map[a[i]]*map[-a[i]]);
            int minFrequency=min(map[a[i]],map[-a[i]]);
            map[a[i]]=map[a[i]]-minFrequency;
            map[-a[i]]=map[-a[i]]-minFrequency;
        }
    }

    cout<<numOfPairs;
}
