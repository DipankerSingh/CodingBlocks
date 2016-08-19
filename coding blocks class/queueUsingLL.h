//QueueUsingLL
#ifndef QUEUEUSINGLL_H
#define QUEUEUSINGLL_H 1
#include "Node.h"

class QueueUsingLL
{

    Node *head;
    Node *tail;
    int size;
public:
    QueueUsingLL()
    {
        size=0;
        head=NULL;
        tail=NULL;
    }

    ~QueueUsingLL()
    {
        delete head;
    }

    Node* reverseRec4(Node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node* smallerHead = reverseRec4(head->next);
	head->next->next = head;
	head->next = NULL;
	return smallerHead;
    }

    int dequeue()
    {
        if(head==NULL)
        {
            return -1;
        }
        int toBeReturned=head->data;
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        size--;
        return toBeReturned;

    }

    void enqueue(int element)
    {

       Node* newNode=new Node(element);


       if(head==NULL)
       {
           head=newNode;
           tail=newNode;


       }
       else
       {

           tail->next=newNode;
           tail=newNode;
       }


       size++;
    }


    int front()
    {
        if(size==0)
        {
            return -1;
        }
        return head->data;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return(size==0);
    }

    void reverse()
    {
        head=reverseRec4(head);
    }

};
#endif // QUEUEUSINGLL_H
