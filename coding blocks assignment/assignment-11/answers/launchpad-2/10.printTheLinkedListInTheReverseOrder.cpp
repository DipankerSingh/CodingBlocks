//printTheLinkedListInTheReverseOrder
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
			/*
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
			*/
			tail->next = newNode;
			tail = newNode;
		}
		cout << "Enter next element\n";
		cin >> currentInput;
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
void printReverseLL(Node* head)
{
    if(ll_length(head)==1)
    {
        cout<<head->data<<endl;
        return;
    }
    printReverseLL(head->next);
    cout<<head->data<<endl;
    return;

}
int main()
{
    Node* head=takeInput();
    printReverseLL(head);
    return 0;
}

