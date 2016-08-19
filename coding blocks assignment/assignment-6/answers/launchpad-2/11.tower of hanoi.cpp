//tower of hanoi
#include<iostream>
using namespace std;
void towers(char source,char helper,char destination,int n)
{
    if(n==1)
    {
        cout<<"move disk 1 from "<<source<<" to "<<destination<<endl;
        return;
    }
    towers(source,destination,helper,n-1);
    cout<<"move "<<n<<"th disc from "<<source << " to "<< destination << endl;
    towers(helper,source,destination,n-1);
}
int main()
{
    char a,b,c;
    cin>>a>>b>>c;
    int n;
    cin>>n;
    towers(a,b,c,n);
    return 0;
}
