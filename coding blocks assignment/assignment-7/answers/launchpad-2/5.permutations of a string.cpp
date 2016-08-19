//print all the permutations of a string
#include<iostream>
using namespace std;
int stringLength(char arr[])
{
    for(int i=0;i<1000;i++)
    {
        if(arr[i]=='\0')
        {
            return i;
        }
    }
    return -1;
}
int permutations(char input[],char output[][100],int size)
{
    if(*input=='\0')
    {
        output[0][0]='\0';
        return 1;
    }
    int numberOfRows=permutations(input+1,output,size-1);
    for(int i=0;i<numberOfRows;i++)
    {
        for(int j=0;j<size;j++)
        {


            for(int k=0;k<size-1;k++)
            {
              output[i][k+1]=output[k];
            }
            output[i][j]=input[0];

        }
        output[i][j]='\0';
    }


}
int main()
{
    char input[100];
    cin>>input;
    char output[100][100];
    int numberOfRows=permutations(input,output,stringLength(input));
    for(int i=0;i<numberOfRows;i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}
