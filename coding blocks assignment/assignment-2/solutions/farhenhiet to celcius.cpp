//farhehiet to celcius
#include<iostream>
using namespace std;
int main()
{
    int initial,finale,step;
    cin>>initial>>finale>>step;
    while(initial<=finale)
    {
        int celcius=0;
        celcius=((5/9.0)*(initial-32));
        cout<<initial<<"\t"<<celcius<<endl;
        initial=initial+step;
    }
    return 0;
}

