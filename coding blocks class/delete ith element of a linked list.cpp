//delete ith element of a linked list
#include<iostream>
#include "Node.h"
using namespace std;
Node* takeInput()
{
    int currentInput;
    cout<<"Enter the first element";
    cin>>currentInput;
    Node* head=NULL;
    Node* tail=NULL;
    while(currentInput!=-1)
    {
        Node* newNode=new Node(currentInput);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            /*Node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;*/
            tail->next=newNode;
            tail=newNode;
        }
        cout<<"enter next element"<<endl;
        cin>>currentInput;
    }
    return head;

}
//using recursion
Node* insertR(Node* head,int position,int element)
{

    if(position==0)
    {
        Node * newNode=new Node(element);
        newNode->next=head;
        return newNode;
    }

    head->next=insertR(head->next,position-1,element);
    return head;
}
Node* insert(Node* head,int position,int element)
{
    Node * newNode=new Node(element);
    if(position==0)
    {
        newNode->next=head;
        return newNode;
    }

    Node *temp=head;
    while(position !=1)
    {
        temp=temp->next;
        position--;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}
Node *remove(Node*head,int position)
{
    int fake=position;
    if(position==0)
    {
        Node * temp=head->next;
        return temp;
    }


        Node*temp=head;
        Node*temp2=head;

        while(position!=1)
        {
            temp=temp->next;

            position--;
        }
        while(fake!=2)
        {
            temp2=temp2->next;

            fake--;
        }

        temp2->next=temp->next;
        temp->next=NULL;
        delete temp;


    return head;
}

int ll_lengthR(Node *head)
{
    if(head==NULL)
        return 0;
    return 1 + ll_lengthR(head->next);
}

int ll_length(Node* head)
{
    int count =0;
    while(head!=NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}

int find_position(Node *head,int element)
{
    if(head==NULL)
    {
        return -1;
    }
    if(head->data==element)
        return 0;
        int smallerIndex=find_position(head->next,element);
    if(smallerIndex==-1)
        return -1;
    else
    return 1+smallerIndex;
}


Node*midpoint(Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node*slow=head;
    Node*fast=head->next;

    while( fast!=NULL && fast->next!=NULL )
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node*delete_nodeR(Node* head,int position)
{
    if(position==0)
    {
        Node *temp=head->next;
        head->next=NULL;
        delete head;
        return temp;
    }

}


Node * bubble_sort(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    int n=ll_length(head);
    for(int i=0;i<n-1;i++)
    {
        Node*temp=head;
        Node *prev=NULL;
        while(temp!=NULL && temp->next!=NULL)
        {
            if(temp->data>temp->next->data)
            {
                if(prev==NULL)
                {
                   Node* next=temp->next;
                   temp->next=next->next;
                   next->next=temp;
                   head=next;
                   prev=head;
                }
                else
                {
                    Node*nextNext=temp->next->next;
                    prev->next=temp->next;
                    temp->next->next=temp;
                    temp->next=nextNext;
                    prev=prev->next;
                }
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
        }



    }
    return head;
}


void printLL(Node* head){
Node* temp=head;
while(temp!=NULL){
    cout<<temp->data<<endl;
    temp=temp->next;
}
}
int main()
{
    Node*head=takeInput();
    // head=insert(head,0,1000);
    head=remove(head,2);
    printLL(head);
    delete head;

}

