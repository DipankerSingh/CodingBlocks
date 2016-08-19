//square root of a no.using newton rapson method
#include<iostream>
using namespace std;
int main()
{
    float n;
    cin>>n;
    float min=100000;
    float i=5,j;

    while(!((min<0.00001)&&(min>-0.00001)))
    {
        j=i-((i*i-n)/(2*i));
        min=j-i;
        i=j;
    }

cout<<j;


}
