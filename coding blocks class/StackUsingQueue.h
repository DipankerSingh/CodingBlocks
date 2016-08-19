//stackUsingQueue O(n) pop  o(1)push
#ifndef STACKUSINGQUEUE_H
#define STACKUSINGQUEUE_H 1
#include<iostream>
#include "queueUsingLL.h"
class stackq
{
    QueueUsingLL q1;
    QueueUsingLL q2;
    int size;
    public:
        stackq()
        {
            size=0;
        }
        int pop()
        {
            for(int i=0;i<size-1;i++)
            {
            q2.enqueue(q1.dequeue());
            }
            int toBeReturned=q1.dequeue();
            for(int i=0;i<size-1;i++)
            {
            q1.enqueue(q2.dequeue());
            }
            size--;
            return toBeReturned;
        }


        void push(int element)
        {
            q1.enqueue(element);
            size++;
        }

        int getSize()
        {
            return size;
        }

        bool isEmpty()
        {
            return (size==0);
        }

        int top()
        {
            return q1.front();
        }





};
#endif // STACKUSINGQUEUE_H

