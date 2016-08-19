#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long n,w;
	cin>>n>>w;
	long long *cups=new long long [2*n];

	for(long long i = 0; i < 2*n; i++)
		    cin>>cups[i];
	    sort(cups,cups+2*n);                  //just write the starting index and ending index;

			  long double  water=cups[n]/2.0>cups[0]?cups[0]:cups[n]/2.0;
				  water=water*3*n;
					 water=water<w?water:w;

					  cout<<water;
						return 0;
}
