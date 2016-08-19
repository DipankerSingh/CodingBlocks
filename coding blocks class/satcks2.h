#ifndef Stack
#define Stack Stack
#include "Node.h"
class Stack
{
    Node* head;
    int size;
    public:
        Stack()
        {
            size=0;
            Node* head=NULL;
        }

        int getSize()
        {
            return size;
        }

        bool isEmpty()
        {
            if(size==0)
            {
                return true;
            }
            else
                return false;
        }

        int top()
        {

            if(isEmpty())
            {
               {
                   return -1;
               }
            }
            else
            return head->data;
        }

        void push(int newElement)
        {
            Node* newHead=new Node(newElement);
            newHead->next=head;

            head=newHead;
            size++;
        }

        int pop()
        {
            if(isEmpty())
            {
                return -1;
            }
            int toBeReturned=head->data;
            size--;
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
            return toBeReturned;
        }

};
#endif // Stack
