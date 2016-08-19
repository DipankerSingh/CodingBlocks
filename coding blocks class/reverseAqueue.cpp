//reverseAQueue
#include<iostream>
#include "queueUsingLL.h"
using namespace std;
void reverseQueue(QueueUsingLL &q)
{
    int temp=q.dequeue();
    if (temp==-1) {
		return;
	}
    reverseQueue(q);
    q.enqueue(temp);
	return;
}
int main()
{
    QueueUsingLL q;
    for(int i=0;i<5;i++)
    {
        q.enqueue(i);
    }

    for(int i=0;i<5;i++)
    {
        cout<<q.dequeue()<<endl;
    }

    for(int i=0;i<5;i++)
    {
        q.enqueue(i);
    }

    cout<<"after reversing"<<endl;
    q.reverse();

    for(int i=0;i<5;i++)
    {
        cout<<q.dequeue()<<endl;
    }

    for(int i=0;i<5;i++)
    {
        q.enqueue(i);
    }
    cout<<"after reverse by method 2"<<endl;
    reverseQueue(q);
    for(int i=0;i<5;i++)
    {
        cout<<q.dequeue()<<endl;
    }

}
