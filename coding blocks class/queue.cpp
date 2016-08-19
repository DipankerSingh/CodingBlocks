#include<iostream>
#include "Queue.h"
using namespace std;
int main()
{

    Queue <int>q;
    cout<<"Press 1 for enqueue"<<endl;
    cout<<"Press 2 for dequeue"<<endl;
    cout<<"Press 3 for front"<<endl;
    cout<<"Press 4 for display all"<<endl;
    cout<<"Press 0 for Exit"<<endl;

    int n;
    cin>>n;
    while(n!=0)
    {
        if(n==1)
        {
            int a;
            cin>>a;
            q.enqueue(a);
        }
        else if(n==2)
        {
            int a;
            a=q.dequeue();
            cout<<a<<endl;
        }
        else if(n==3)
        {
            int a;
            a=q.front();
            cout<<a<<endl;
        }
        else if(n==4)
        {
            int size=q.getSize();
            if(size==0)
            {
                cout<<"empty"<<endl;
            }
            for(int i=0;i<size;i++)
            {
                cout<<q.dequeue()<<endl;
            }
        }
        cout<<"enter next action"<<endl;
        cin>>n;
    }

    return 0;
}
