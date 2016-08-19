#include <iostream>
#include "BinaryTree.cpp"
#include "Triplet.h"
using namespace std;

int findMax(BinaryTreeNode* root) {
	if (root == NULL)
		return -1;
	
	int max = root->data;
	int leftMax = findMax(root->left);
	if (leftMax != -1 && leftMax > max) {
		max = leftMax;
	}
	int rightMax = findMax(root->right);
	if (rightMax != -1 && rightMax > max)
		max = rightMax;
	return max;
}

int findMin(BinaryTreeNode* root) {
	if (root == NULL)
		return -1;
	
	int min = root->data;
	int leftMin = findMin(root->left);
	if (leftMin != -1 && leftMin < min) {
		min = leftMin;
	}
	int rightMin = findMin(root->right);
	if (rightMin != -1 && rightMin < min)
		min = rightMin;
	return min;
}

void getInorder(BinaryTreeNode* root, int* arr, int& index) {
	if (root == NULL)
		return;
	getInorder(root->left, arr, index);
	arr[index] = root->data;
	index++;
	getInorder(root->right, arr, index);
}

bool isBST2(BinaryTreeNode* root) {
	int a[100];
	int index = 0;
	getInorder(root, a, index);
	for (int i = 1; i < index; i++) {
		if (a[i] < a[i-1]) {
			return false;
		}
	}
	return true;
}

Triplet* isBST3(BinaryTreeNode* root) {
	if (root == NULL) {
		return new Triplet(10000,-10000,true);
	}
	
	Triplet* leftOutput = isBST3(root->left);
	Triplet* rightOutput = isBST3(root->right);
	
	int min1 = min(min(root->data, leftOutput->min)
			, rightOutput->min);
	int max1 = max(max(root->data, leftOutput->max)
			, rightOutput->max);
	int isBSTFlag = true;
	if (!leftOutput->isBST || !rightOutput->isBST) {
		isBSTFlag = false;
	}

	if (root->data < leftOutput->max ||
			root->data >= rightOutput->min) {
		isBSTFlag = false;
	}
	delete leftOutput;
	delete rightOutput;
	return new Triplet(min1, max1, isBSTFlag);
}

bool isBST(BinaryTreeNode* root) {
	if (root == NULL)
		return true;

	int leftMax = findMax(root->left);
	int rightMin = findMin(root->right);
	if (leftMax > root->data || rightMin <= root->data)
		return false;

	bool leftBST = isBST(root->left);
	bool rightBST = isBST(root->right);
	return leftBST && rightBST;
}


void printBetweenK1K2(BinaryTreeNode* root, int k1, int k2) {
	if (root == NULL) {
		return;
	}

	if (root->data >= k1)
		printBetweenK1K2(root->left, k1, k2);
	
	if (root->data >= k1 && root->data <= k2) {
		cout << root->data << endl;
	}
	
	if (root->data <= k2)
		printBetweenK1K2(root->right, k1, k2);

}

bool search(BinaryTreeNode* root, int element) {
	if (root == NULL) {
		return false;
	}
	if (root->data == element) {
		return true;
	} else if (root->data > element) {
		return search(root->left, element);
	} else {
		return search(root->right, element);
	}
}

bool isBST4(BinaryTreeNode* root, int &prev) {
	if (root == NULL)
		return true;

	bool checkLeft = isBST4(root->left, prev);
	if (!checkLeft) 
		return false;
	
	if (prev > root->data) {
		return false;
	}
	prev = root->data;
	bool checkRight = isBST4(root->right, prev);
	return checkRight;
}

int main() {
	BinaryTreeNode* root = takeInput();
	//printBetweenK1K2(root,3,7);
	delete root;
}

