//finding largest element in 2-D array
#include<iostream>
using namespace std;
int largestNumber(int input[][4])
{
    int max=-10000;
   for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        {
            if(input[i][j]>max)
                max=input[i][j];
        }

    }
    return max;
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
    int max=largestNumber(input);
    cout<<max;

}
