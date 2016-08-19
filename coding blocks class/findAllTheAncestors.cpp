//find all the ancestors
#include<iostream>
#include"BST.h"

#include<vector>
using namespace std;
vector<binaryTreeNode*>* findAllAncestors(binaryTreeNode* root,int data)
{

    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==data)
    {
        vector<binaryTreeNode*>* output=new vector<binaryTreeNode*>();
        v.push_back(root);
        return output;
    }

    vector<binaryTreeNode*>* leftO=findAllAncestors(root->left,element);
    if(left!=NULL)
    {
        leftO->push_back(root);
        return leftO;
    }
    vector<binaryTreeNode*>* rightO=findAllAncestors(root->right,element);
    if(rightO)!=NULL)
    {
        rightO->push_back(root);
        return rightO;
    }
    return NULL;
}


int main()
{

}
