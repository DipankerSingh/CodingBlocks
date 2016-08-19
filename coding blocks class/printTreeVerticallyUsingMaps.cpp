//printTreeVerticallyUsingMaps
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include "binaryTreeNode.h"
#include"Node.h"
#include "Queue.h"
using namespace std;
binaryTreeNode* takeInput()
{
    cout<<"enter The Root Data"<<endl;
    int data;
    cin>>data;
    binaryTreeNode*root=new binaryTreeNode(data);
    queue<binaryTreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        binaryTreeNode* currentNode=q.back();
        q.pop();
        int leftChild;
        cout<<"Enter Left child Data for ";
        cout<<current_node->data<<endl;
        cin>>left_child;
        if(left_child!=-1)
        {
            binaryTreeNode* left=new binaryTreeNode(left_child);
            current_node->left=left;
            q.push(left);

        }
        int right_child;
        cout<<"Enter Right child for ";
        cout<<current_node->data<<endl;
        cin>>right_child;
        if(right_child!=-1)
        {
            binaryTreeNode* right=new binaryTreeNode(right_child);
            current_node->right=right;
            q.push(right);
        }
    }

    return root;

}


void printBinaryTreeVertically(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    Queue <binaryTreeNode*>q;
    q.enqueue(root);
    q.enqueue(NULL);
    unordered_map<int,Node*> map;
    int k=0;
    while(!q.isEmpty())
    {
        binaryTreeNode* currentNode=q.dequeue();
        if(currentNode!=NULL)
        {
            Node* newNode=new Node(currentNode->data);
            if(map[k]==NULL)
            {
                Node* head=new Node(currentNode->data);
                map[k]=head;
            }
            else
            {
                Node*temp=map[k];
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
            }

            if(currentNode->left!=NULL)
            {
                q.enqueue(currentNode->left);
                k--;
                if(map[k]==NULL)
                {
                Node* head=new Node(currentNode->left->data);
                map[k]=head;
                }
                else
                {
                Node* newNode=new Node(currentNode->left->data);
                Node*temp=map[k];
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
                }
                k++;
            }
            if(currentNode->right!=NULL)
            {
                q.enqueue(currentNode->right);
                k++;
                if(map[k]==NULL)
                {
                Node* head=new Node(currentNode->left->data);
                map[k]=head;
                }
                else
                {
                Node* newNode=new Node(currentNode->left->data);
                Node*temp=map[k];
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
                }
                k--;
            }
        }
        if(q.isEmpty())
        {
           return;
        }
        if(currentNode==NULL)
        {
            q.enqueue(NULL);
        }
    }

}


using namespace std;
int main()
{
  binaryTreeNode* root=takeInput();

}
