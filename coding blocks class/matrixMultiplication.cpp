//matrixMultiplication
#include<iostream>
using namespace std;

int minMatrixMultiplicatonSteps(int*input,int start,int end)
{
    int min=-1;
    if(start>=end-1)
    {
        return 0;
    }

    int k=start+1;
    for(;k<end;k++)
    {
        int smaller=input[start]*input[end]*input[k]+minMatrixMultiplicatonSteps(input,start,k)+minMatrixMultiplicatonSteps(input,k,end);
        if(smaller<min||min==-1)
        {
            min=smaller;
        }
    }

    return min;
}

int main()
{

}
