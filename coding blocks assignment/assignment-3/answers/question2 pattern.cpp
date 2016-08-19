//ABCDEEDCBA
//ABCDDCBA
//ABCCBA
//ABBA
//AA
#include<iostream>
using namespace std;
int main()
{

    int n,col=1,row=1;
    cin>>n;
    while(row<=n)
    {
        char ch=65;
        col=1;
        while(col<=(2*(n-row+1)))
        {

          if(col<=((n-row+1)))
          {
          cout<<ch;
          ch++;
          col++;
          }
          else if(col>(n-row+1))
          {
             ch--;
             cout<<ch;
             col++;
          }
        }
        cout<<endl;
        row++;
    }

}

