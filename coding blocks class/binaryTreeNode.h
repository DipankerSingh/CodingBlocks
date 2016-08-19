#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H 1

class binaryTreeNode
{
    public:
    int data;
    binaryTreeNode* left;
    binaryTreeNode* right;

    binaryTreeNode(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~binaryTreeNode()
    {
        if(right!=NULL)
        {
            delete right;
        }
        if(left!=NULL)
        {
            delete left;
        }
    }
};
#endif
