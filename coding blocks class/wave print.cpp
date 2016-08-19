//wave print
#include<iostream>
using namespace std;
void wavePrint(int input[][4])
{

    for(int i=0;i<4;i++)
    {
    if(i%2==0)
    {
     for(int j=0;j<4;j++)
     {cout<<input[j][i]<<" ";}
    }
    else
    {
      for(int j=3;j>=0;j--)
      {
          cout<<input[j][i]<<" ";
      }
    }
    }
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
    wavePrint(input);
    return 0;
}
