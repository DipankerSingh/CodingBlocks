//determining row having the largest sum in 2-D array
#include<iostream>
using namespace std;
int largestSum(int input[][4])
{
    int max1=-10000,row,max2=-10000,column;

    for(int i=0;i<4;i++){
            int sum1=0;
        for(int j=0;j<4;j++)
        {
           sum1=sum1+input[i][j];
        }
        if(sum1>max1)
        {
            max1=sum1;
            row=i;
        }
    }
    for(int i=0;i<4;i++){
            int sum1=0;
        for(int j=0;j<4;j++)
        {
           sum1=sum1+input[j][i];
        }
        if(sum1>max2)
        {
            max2=sum1;
            column=i;
        }
    }
    if(max1>max2)
    return row;
    else
    return column;
}
int main()
{
    int input[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        {
            cout<<"enter element in "<<i<<"th row and "<<j<<"th column"<<endl;
            cin>>input[i][j];
        }
    }

    int row=largestSum(input);
    cout<<row;
}
