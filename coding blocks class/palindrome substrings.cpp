// find all the palindrome substrings
#include<iostream>
using namespace std;
int stringLength(char input[])
{
    for (int i=0;i<256;i++)
    {
        if(input[i]=='\0')
        {
            return i;
        }
    }
    return -1;
}
int palindromeSubstrings(char input[],int pivot,int length,int count)
{

    int i=pivot;
    int j=pivot;

    if(input[pivot]=='\0')
    {
        return 0;
    }

    count=palindromeSubstrings(input,pivot+1,length,count);

    while(i>=0 && j<length)
    {
        if(input[i]==input[j])
        {
            count++;
            i--;
            j++;
        }
        else
        {
            break;
        }

    }
    i=pivot;
    j=pivot+1;
    while(i>=0 && j<length)
    {
        if(input[i]==input[j])
        {
            count++;
            i--;
            j++;
        }
        else
        {
            return count;
        }

    }
    return count;
}



int main()
{
    char input[100];
    cin>>input;
    int count=palindromeSubstrings(input,0,stringLength(input),0);
    cout<<count;
    return 0;

}
