//Given k find the geometric Sum i.e. 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)
#include<iostream>
using namespace std;
float power(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    return a * power(a,b-1);


}
float geometricSum(int k)
{
    if(k==0)
    {
        return 1;
    }
    return 1/power(2,k)+geometricSum(k-1);

}
int main()
{
    int k;
    cin>>k;
    cout<<geometricSum(k);
    return 0;
}
