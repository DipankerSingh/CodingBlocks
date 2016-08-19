#include <iostream>
#include "BinaryTreeNode.h"
#include "Node.h"
#include "Queue.h"
#include <queue>
using namespace std;

BinaryTreeNode* takeInput() {
	cout << "Enter root data " << endl;
	int root_data;
	cin >> root_data;

	BinaryTreeNode* root = new BinaryTreeNode(root_data);
	Queue<BinaryTreeNode*> q;
	q.enqueue(root);

	while (!q.is_empty()) {
		BinaryTreeNode* current_node = q.dequeue();
		int left_child;
		cout << "Enter left child data for ";
		cout << current_node->data << endl;
		cin >> left_child;
		if (left_child != -1) {
			BinaryTreeNode* left = new BinaryTreeNode(left_child);
			current_node->left = left;
			q.enqueue(left);
		}	

		int right_child;
		cout << "Enter right child for ";
		cout << current_node->data << endl;
		cin >> right_child;
		if (right_child != -1) {
			BinaryTreeNode* right = new BinaryTreeNode(right_child);
			current_node->right = right;
			q.enqueue(right);
		}
	}
	return root;	
}

void preorder(BinaryTreeNode* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " " << endl;
	preorder(root->left);
	preorder(root->right);
}

vector<Node*> level_wise_ll(BinaryTreeNode* root) {	
	vector<Node*> output;
	queue<BinaryTreeNode*> q;
	q.push(root);
	Node* currentHead = NULL;
	Node* currentTail = NULL;
	int current_level_count = 1;
	int next_level_count = 0;
	while (!q.empty()) {
		BinaryTreeNode* currentNode = q.front();
		q.pop();

		Node* newNode = new Node(currentNode->data);

		if (currentHead == NULL) {
			currentHead = newNode;
			currentTail = newNode;
		} else {
			currentTail->next = newNode;
			currentTail = newNode;
		}
		if (currentNode->left != NULL) {
			q.push(currentNode->left);
			next_level_count++;
		}	
		
		if (currentNode->right != NULL) {
			q.push(currentNode->right);
			next_level_count++;
		}
 	
		current_level_count--;
		if (current_level_count == 0) {

			output.push_back(currentHead);
			currentHead = NULL;
			currentTail = NULL;
			current_level_count = next_level_count;
			next_level_count = 0;
		}
	 }
	return output;
}
void level_wise(BinaryTreeNode* root) {	
	queue<BinaryTreeNode*> q;
	q.push(root);
	int current_level_count = 1;
	int next_level_count = 0;
	while (!q.empty()) {
		BinaryTreeNode* currentNode = q.front();
		q.pop();
		cout << currentNode->data;
		if (currentNode->left != NULL) {
			q.push(currentNode->left);
			next_level_count++;
		}	
		
		if (currentNode->right != NULL) {
			q.push(currentNode->right);
			next_level_count++;
		}
 	
		current_level_count--;
		if (current_level_count == 0) {
			cout << endl;
			current_level_count = next_level_count;
			next_level_count = 0;
		}
	 }

}
/*
int main() {
	BinaryTreeNode* root = takeInput();
	preorder(root);
	level_wise(root);
	vector<Node*> output = level_wise_ll(root);
	cout << "printing lls" << endl;
	for (int i = 0; i < output.size(); i++) {
		Node* head = output[i];
		Node* temp = head;
		while (head != NULL) {
			cout << head->data << "-->";
			head = head->next;
		}
		cout << endl;
		delete temp;
	 }
	delete root;
}

*/




