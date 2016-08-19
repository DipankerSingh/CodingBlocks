//mergeTwoSortedLinkedListIntoSingleSortedLinkedList
#include<iostream>
#include "Node.h"
using namespace std;
Node* takeInput()
{
    int currentInput;
    cout<<"Enter the first element"<<endl;
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
            tail->next=newNode;
            tail=newNode;
        }
        cout<<"Enter Next Element"<<endl;
        cin>>currentInput;
    }
    return head;
}
void printLL(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head=head->next;
        if(head==NULL)
        {
            cout<<"NULL";
        }
    }
}
Node* mergeLL(Node* head1,Node* head2)
{
    Node* head=NULL;
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;

    }
    if(head1->data < head2->data)
    {
        head=head1;
        head->next=mergeLL(head1->next,head2);
    }
    else
    {
        head=head2;
        head->next=mergeLL(head1,head2->next);
    }

    return head;
}


int main()
{
    Node* head1=takeInput();
    Node* head2=takeInput();
    Node* head=mergeLL(head1,head2);
    printLL(head);
    return 0;
}
