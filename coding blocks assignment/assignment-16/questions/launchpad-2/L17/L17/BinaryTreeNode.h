#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H 1
class BinaryTreeNode {
	public:
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		if (left != NULL)
			delete left;
		if (right != NULL) 
			delete right;
	}

};
#endif
