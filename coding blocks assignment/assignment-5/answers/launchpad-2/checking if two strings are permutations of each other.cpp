//checking if two strings are permutations of each other
#include<iostream>
using namespace std;
void createHashTable(char arr[],int hashTable[],int length)
{
    for(int i=0;i<length;i++)
    {
        int j=arr[i];
        hashTable[j]++;
    }
}
void updateHashTable(char arr[],int hashTable[],int length)
{
    for(int i=0;i<length;i++)
    {
        int j=arr[i];
        hashTable[j]--;
    }
}

int stringLength(char arr[],int max_size)
{
    for(int i=0;i<max_size;i++)
    {
        if(arr[i]=='\0')
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    char arr1[10000],arr2[10000];
    int hashtable[256]={0};
    cout<<"Enter String 1";
    cin>>arr1;
    cout<<"Enter String 2";
    cin>>arr2;
    int l1=stringLength(arr1,256);

    int l2=stringLength(arr2,256);

    if(l1!=l2)
    {
        cout<<"No,These are not the permutations of each other";
    }
    else
    {
        //creating a hash table
        createHashTable(arr1,hashtable,l1);
        updateHashTable(arr2,hashtable,l2);

    int i=0;
    for(i=0;i<256;i++)
    {
        if(hashtable[i]!=0)
        {
            cout<<"these are not the permutations of each other"<<endl;
            break;
        }
    }
    if(i==256)
    {
        cout<<"these are permutations of each other";
    }
    }

    return 0;
}
