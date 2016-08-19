//pascal's triangle
#include<iostream>
using namespace std;
int main()
{
  int row=0;
  int n;
  cin>>n;
  while(row<n)
  {
      int value=1,j,i,col=0;
      float multiplier;
      while(col<(n-row-1))
      {
          cout<<" ";
          col=col+1;
      }
      col=0;
      j=row;
      while(col<=row)
      {

          i=col+1;
          cout<<value<<" ";
          multiplier=(float)j/i;
          value=value*(multiplier);
          j=j-1;
          col=col+1;
      }
      cout<<endl;
      row=row+1;
  }

}
