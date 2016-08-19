//reverse the linked list
#include<iostream>
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
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		cout << "Enter next element\n";
		cin >> currentInput;
	}
	return head;
}
Node* reverseLL(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->next=NULL)
        {
            temp->next=head;

            Node* newHead=head->next;
            head->next=NULL;

            return newHead;
        }
        else
        {
            temp=temp->next;
        }

    }

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
    Node* newhead=reverseLL(head);
    printLL(newhead);
    return 0;
}
