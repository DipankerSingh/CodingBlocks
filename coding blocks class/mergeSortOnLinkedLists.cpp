//merge Sort On Linked LIST
#include <iostream>
#include "Node.h"
using namespace std;
Node* takeInput() {
	int currentInput;
	cout << "Enter first element";
	cin >> currentInput;
	Node* head = NULL;
	Node* tail = NULL;

	while (currentInput != -1) {
		Node* newNode = new Node(currentInput);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		} else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cout << "Enter next element\n";
		cin >> currentInput;
	}
	return head;
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
Node* mergeSortLL(Node* head)
{
    if(ll_length(head)==1)
    {
        return head;
    }
    Node* midPoint=midpoint(head);
    Node* newHead=midPoint->next;
    midPoint->next=NULL;
    head=mergeSortLL(head);
    newHead=mergeSortLL(newHead);
    head=mergeLL(head,newHead);
    return head;
}
void printLL(Node* head){
Node* temp=head;
while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
    if(temp==NULL)
    {
        cout<<"NULL";
    }
}
}
int main()
{
    Node* head=takeInput();
    head=mergeSortLL(head);
    printLL(head);
    return 0;
}
