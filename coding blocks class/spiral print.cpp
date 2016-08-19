//spiral print
#include<iostream>
using namespace std;
void spiralPrint(int input[][4],int top,int bottom,int left,int right)
{

    if(left>right)
    {
        return;
    }
    else
    {


    for(int i=left;i<=right;i++)
    {
        cout<<input[top][i];
    }
    top++;
    }
    if(top>bottom)
    {
        return;
    }
    else
    {
        for(int i=top;i<=bottom;i++)
    {
        cout<<input[i][right];
    }
    right--;
    }
    if(right<left)
    {
        return;
    }
    else
    {
    for(int i=right;i>=left;i--)
    {
        cout<<input[bottom][i];
    }
    bottom--;
    }
    if(bottom<top)
    {
        return;
    }
    else
    {

    for(int i=bottom;i>=top;i--)
    {
        cout<<input[i][left];
    }
    left++;
    }
    spiralPrint(input,top,bottom,left,right);
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
    spiralPrint(input,0,3,0,3);
    return 0;
}
