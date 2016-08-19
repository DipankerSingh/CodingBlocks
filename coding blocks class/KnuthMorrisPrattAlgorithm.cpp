//TEXT PROCESSING(pattern matching)
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void createHFunction(char* pattern,vector<int> &hFunction)
{
    hFunction.push_back(0);
    int len=0;
    int i=1;
    while(i<strlen(pattern))
    {
        if(pattern[len]==pattern[i])
        {
            len=len+1;
            hFunction.push_back(len);
            i++;
        }
        else
        {
            if(len==0)
            {
                i++;
                hFunction.push_back(len);
            }
            else
            {
                len=hFunction[len-1];
            }
        }
    }
    return;
}
int main()
{
    char text[1000];
    cin>>text;
    char pattern[1000];
    cin>>pattern;
    vector<int> hFunction;
    createHFunction(pattern,hFunction);



}

