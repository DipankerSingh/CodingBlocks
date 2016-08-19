#include<iostream>
#include "binaryTreeNode.h"
#include "Queue.h"
using namespace std;

binaryTreeNode* takeInput()
{
    cout<<"enter root data"<<endl;
    int root_data;
    cin>>root_data;
    binaryTreeNode* root=new binaryTreeNode(root_data);
    Queue<binaryTreeNode*> q;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        binaryTreeNode* current_node=q.dequeue();
        int left_child;
        cout<<"Enter Left child Data for ";
        cout<<current_node->data<<endl;
        cin>>left_child;
        if(left_child!=-1)
        {
            binaryTreeNode* left=new binaryTreeNode(left_child);
            current_node->left=left;
            q.enqueue(left);

        }

        int right_child;
        cout<<"Enter Right child for ";
        cout<<current_node->data<<endl;
        cin>>right_child;
        if(right_child!=-1)
        {
            binaryTreeNode* right=new binaryTreeNode(right_child);
            current_node->right=right;
            q.enqueue(right);
        }
    }
    return root;
}

int sumAllTheNodes(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int sum=0;

    sum=sum+sumAllTheNodes(root->left);
    sum=sum+sumAllTheNodes(root->right);
    sum=sum+root->data;
    return sum;
}

binaryTreeNode* justGreater(binaryTreeNode* root,int x)
{
    if(root==NULL)
    {
        return NULL;
    }

    binaryTreeNode* output=NULL;
    if(root->data > x)
    {
        output=root;
    }

    binaryTreeNode* leftResult=justGreater(root->left,x);
    if(leftResult!=NULL)

    {
        if(output==NULL || output->data >leftResult->data)
    {
        output=leftResult;
    }
    }

    binaryTreeNode* rightResult=justGreater(root->right,x);
    if(rightResult!=NULL)
    {
    if(output==NULL || output->data >rightResult->data)
    {
        output=rightResult;
    }
    }
    return output;

}

int heightBinaryTree(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int heightLeft=0;
    int heightRight=0;
    heightLeft=heightLeft+heightBinaryTree(root->left);
    heightRight=heightRight+heightBinaryTree(root->right);
    if(heightLeft>heightRight)
    {
        return heightLeft+1;
    }
    else
    {
        return heightRight+1;
    }

}

void preOrder(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" " <<endl;
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    binaryTreeNode* root=takeInput();
    preOrder(root);
    int x;
    cout<<"enter X"<<endl;
    cin>>x;
    cout<<"Just greater Number in the tree is "<<justGreater(root,x)->data<<endl;
    cout<<"The Sum Of All The Nodes is "<<sumAllTheNodes(root)<<endl;
    cout<<"the height of the binary tree is "<<heightBinaryTree(root)<<endl;
    delete root;
}
