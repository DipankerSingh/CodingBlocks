#ifndef STACKUSINGLL_H
#define STACKUSINGLL_H 1
#include "Node.h"

class StackUsingLL {
	Node* head;
	int size;

	public:
	StackUsingLL() {
		head = NULL;
		size = 0;
	}
	
	int get_size() {
		return size;
	}

	bool is_empty() {
		if (size == 0)
			return true;
		return false;
	}

	void push(int element) {
		Node* newNode = new Node(element);
		newNode->next = head;
		head = newNode;
		size++;
	}

	int pop() {
		if (size == 0)
			return -1;
		
		Node* temp = head;
		int to_b_r = temp->data;
		temp->next = NULL;
		delete temp;
		head = head->next;
		size--;
		return to_b_r;
	}

	int top() {
		if (size == 0)
			return -1;
		return head->data;
	}

};
#endif
