#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
class BST
{
    int size;
    binaryTreeNode* root;
    //non object specific function
    //we make them static

    static bool find(binaryTreeNode* currentRoot,int element)
    {
        if(currentRoot==NULL)
            return false;
        if(currentRoot->data==element)
        {
            return find(currentRoot->left,element);
        }
        else
        {
            return find(currentRoot->right,element);
        }

    }

    static void insert(binaryTreeNode* &root,int element)
    {
        if(root==NULL)
        {
            root=new binaryTreeNode(element);
            return;
        }

        if(root->data>=element)
        {
            insert(root->left,element);
            return;
        }

        else
        {
            insert(root->right,element);
            return ;
        }

    }


    static void remove(binaryTreeNode*root &root,int element)
    {
        if(root==NULL)
        {
            return ;
        }

        if(root->data == element)
        {
            if(root->left==NULL && root->right == NULL)
            {
                delete root;
                root=NULL;
                return ;
            }
            else if(root->left==NULL)
            {
                binaryTreeNode* temp=root->right;
                root->left=NULL;
                root->right=NULL;
                delete root;
                root=temp;
                return;

            }
            else if(root->right==NULL)
            {
                binaryTreeNode* temp=root->left;
                root->left=NULL;
                root->right=NULL;
                delete root;
                left=temp;
                return;
            }
            else
            {
                binaryTreeNode* leftMax;
                while(leftMax->right!=NULL)
                {
                    leftMax=leftMax->right;
                }

                root->data=leftMax->data;
                remove(root->left,leftMax->data);
            }

        }else if(root->data>element)
        {
            remove(root->left,element);
        }
        else
        {
            remove(root->right,element);
        }
    }

    static void print(binaryTreeNode* root)
    {
        if(root==NULL)
            return;
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }

public:
    BST()
    {
        size=0;
        root=NULL;
    }


    void print()
    {
        print(root);
        return;
    }
    void remove(int element)
    {
        if(!find(element))
        {
            return;
        }
        remove(root,element);

    }

    int get_size()
    {
        return size;
    }

    bool isEmpty()
    {
        return size==0;
    }


    bool find(int element)
    {

     return find(root,element);

    }

    void insert(int element)
    {
        insert(root,element);
    }
}
