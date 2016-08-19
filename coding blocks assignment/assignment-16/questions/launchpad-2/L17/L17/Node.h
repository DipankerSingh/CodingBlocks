#ifndef NODE_H
#define NODE_H 1
class Node {
	public:
	int data;
	Node* next;

	public:
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}

	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};
#endif
