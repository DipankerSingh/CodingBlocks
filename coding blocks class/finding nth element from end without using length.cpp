//finding nth element from end without using length function in a linked list
#include<iostream>
#include"Node.h"
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
Node* fromEnd(int n,Node* head)
{
    Node* referencePointer=head;
    Node* mainPointer=head;


    for(int i=1;i<=n;i++)
    {
        referencePointer=referencePointer->next;
    }
    while(referencePointer!=NULL)
    {
        referencePointer=referencePointer->next;
        mainPointer=mainPointer->next;
    }
    return mainPointer;

}
int main()
{
    Node* head=takeInput();
    int elementFromEnd;
    cout<<"Enter the element from end to be found out"<<endl;
    cin>>elementFromEnd;
    Node *found=fromEnd(elementFromEnd,head);
    cout<<found->data;
    return 0;

}
