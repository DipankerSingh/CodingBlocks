#include <iostream>
#include "Node.h"
#include "DoubleNode.h"

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

int ll_lengthR(Node* head) {
	if (head == NULL)
		return 0;
	return 1 + ll_lengthR(head->next);
}

int ll_length(Node* head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}
	return count;
}

Node* delete_nodeR(Node* head, int position) {
	if (position == 0) {
		Node* temp=head->next;
		head->next = NULL;
		delete head;
		return temp;
	}
	head->next = delete_nodeR(head->next, position - 1);
	return head;
}

Node* midpoint(Node* head) {
	if (head == NULL)
		return NULL;
	Node* slow = head;
	Node* fast = head->next;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow; 
}

Node* bubble_sort(Node* head) {
	if (head == NULL || head->next == NULL)
		return head;

	int n = ll_length(head);
	for (int i = 0; i < n - 1; i++) {
		Node* temp = head;
		Node* prev = NULL;
		while (temp != NULL && temp->next != NULL) {
			if (temp->data > temp->next->data) {
				if (prev == NULL) {
					Node* next1 = temp->next;
					temp->next = next1->next;
					next1->next = temp;
					head = next1;
					prev = head;
				} else {
					Node* nextNext = temp->next->next;
					prev->next = temp->next;
					temp->next->next = temp;
					temp->next = nextNext;
					prev = prev->next;
				}

			} else {
				prev = temp;
				temp = temp->next;
			}
		}
	}
	return head;
}


int find_position(Node* head, int element) {
	if (head == NULL)
		return -1;
	if (head->data == element)
		return 0;
	int smallerIndex = find_position(head->next, element);
	if (smallerIndex == -1)
		return -1;
	return 1 + smallerIndex;
}

Node* delete_node(Node* head, int position) {
	if (position == 0) {
		Node* temp=head->next;
		head->next = NULL;
		delete head;
		return temp;
	}

	Node* prev = head;
	while (position != 1) {
		prev = prev->next;
		position--;
	}
	Node* temp = prev->next;
	prev->next = prev->next->next;
	temp->next = NULL;
	delete temp;
	return head;
}

void printLL(Node* head) {
	while (head != NULL) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << endl;
}

Node* insertR(Node* head, int position, int element) {
	if (position == 0) {
		Node* newNode = new Node(element);
		newNode->next = head;
		return newNode;
	}

	head->next = insertR(head->next, position - 1, element);
	return head;
}

Node* insert(Node* head, int position, int element) {
	Node* newNode = new Node(element);
	if (position == 0) {
		newNode->next = head;
		return newNode;
	}

	Node* temp = head;
	while (position != 1) {
		temp = temp->next;
		position--;
	}

	newNode->next = temp->next;
	temp->next = newNode;

	return head;
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

Node* reverseRec3(Node * head, Node* &tail) {
	if (head == NULL || head->next == NULL) {
		tail = head;
		return head;
	}

	Node* smallerHead = reverseRec3(head->next, tail);
	tail->next = head;
	head->next = NULL;
	tail = head;
	return smallerHead;
}

DoubleNode* reverseRec2(Node* head) {
	if (head == NULL || head->next == NULL) {
		DoubleNode* output = new DoubleNode;
		output->head = head;
		output->tail = head;
		return output;
	}
	
	DoubleNode* smallerOutput = reverseRec2(head->next);
	smallerOutput->tail->next = head;
	head->next = NULL;
	DoubleNode* output = new DoubleNode;
	output->head = smallerOutput->head;
	output->tail = head;
	return output;
}

Node* reverseRec(Node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node* smallerHead = reverseRec(head->next);
	Node* temp = smallerHead;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return smallerHead;
}	

void test(Node* head) {
	delete head->next;
	head->next = NULL;
}

int main() {
	Node* head = takeInput();
	printLL(head);
	head = insert(head, 0, 1000);
	printLL(head);
	head = bubble_sort(head);
	printLL(head);
	delete head;
}

