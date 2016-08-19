//count the no. of zeroes in integer using recursion
#include<iostream>
using namespace std;
int Zeroes(int n)
{
    int count=0;
   if(n<10)
   {
       if(n==0){
        return 1;
       }
       return count;
   }
   if(n%10==0)
    return count=Zeroes(n/10)+1;
   else
    return count=Zeroes(n/10)+0;
}
int main()
{
   int n;
   cin>>n;
   cout<< Zeroes(n);
   return 0;
}
