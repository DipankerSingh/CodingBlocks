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
    head=insert(head,0,1000);
    printLL(head);
    delete head;

}
