
#include<iostream>
#include "binaryTreeNode.h"
#include "Queue.h"
#include"pair.h"
#include"stacks.h"
#include "Node.h"
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

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}



int diameterOfBinaryTree(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int lh=heightBinaryTree(root->left);
    int rh=heightBinaryTree(root->right);
    int ld=diameterOfBinaryTree(root->left);
    int rd=diameterOfBinaryTree(root->right);
    return max(lh+rh,max(ld,rd));
}

pair1* diameter_height(binaryTreeNode* root)
{
    if(root==NULL)
    {
        pair1* output=new pair1(0,0);
        return output;
    }

    pair1* leftOutput=diameter_height(root->left);
    pair1* rightOutput=diameter_height(root->right);

    int height=max(leftOutput->height,rightOutput->height)+1;
    int option1=leftOutput->height+rightOutput->height;
    int option2=leftOutput->diameter;
    int option3=rightOutput->diameter;

    int diameter=max(option1,max(option2,option3));

    pair1* output=new pair1(height,diameter);
    return output;

    //another option
    //return new pair(height,diameter);



}

binaryTreeNode* findNode(binaryTreeNode* root,int x)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==x)
    {
        return root;
    }

    binaryTreeNode* toBeReturned=findNode(root->left,x);
    if(toBeReturned==NULL)
    {
        toBeReturned=findNode(root->right,x);
    }
    return toBeReturned;
}

void mirrorBinaryTree(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return;
    }

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    binaryTreeNode* temp=root->left;
    root->left=root->right;
    root->right=temp;

}

void inOrder(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

binaryTreeNode* createBinaryTree(int* inorder,int* preorder,int inorderStart,int inorderEnd)
{
    if(inorderStart==inorderEnd)
    {
        binaryTreeNode*root=new binaryTreeNode(preorder[0]);
        return root;
    }
    binaryTreeNode*root=new binaryTreeNode(preorder[0]);
    int found;
    for(int i=0;i<(inorderEnd-inorderStart+1);i++)
    {
        if(inorder[i]==preorder[0])
        {
            found=i;
        }
    }
    if(found!=inorderStart)
    {
        root->left=createBinaryTree(inorder,preorder+1,inorderStart,inorderStart+found-1);
    }
    if(found!=inorderEnd)

    {
        root->right=createBinaryTree(inorder+found+1,preorder+found+1,inorderStart+found+1,inorderEnd);
    }
    return root;
}
int findDepth(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftDepth=findDepth(root->left);
    int rightDepth=findDepth(root->right);
    return max(leftDepth,rightDepth)+1;

}


bool checkIfBalanced(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return true;
    }
    int leftDepth=findDepth(root->left);
    int rightDepth=findDepth(root->right);
    if(leftDepth-rightDepth==0 || leftDepth-rightDepth==1 || rightDepth-leftDepth==1)
    {
        int check = checkIfBalanced(root->left);
        if(check==1)
        {
            check = checkIfBalanced(root->right);
            if(check==0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }

    }
    else
    {
        return false;
    }
}

bool checkIfStructurallyIdentical(binaryTreeNode* root1,binaryTreeNode* root2)
{
    if(root1==NULL)
    {
        if(root2==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }



      if(root2==NULL)
    {
        if(root1==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }



    if((root1->data)==(root2->data))
    {

        if(checkIfStructurallyIdentical(root1->left,root2->left))
            {
                if(checkIfStructurallyIdentical(root1->right,root2->right))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
           else
            {
                return false;
            }
    }
    else
    {
        return false;
    }

}

void printLeaves(binaryTreeNode* root)
{
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);

}

binaryTreeNode* removeAllLeaves(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }


        root->left=removeAllLeaves(root->left);


        root->right=removeAllLeaves(root->right);


    return root;

}

void printLevelTraversal(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    Queue <binaryTreeNode*>q;
    q.enqueue(root);
    q.enqueue(NULL);

    while(!q.isEmpty())
    {
        binaryTreeNode* currentNode=q.dequeue();
        if(currentNode!=NULL)
        {
            cout<<currentNode->data<<" ";

            if(currentNode->left!=NULL)
            {
                q.enqueue(currentNode->left);
            }
            if(currentNode->right!=NULL)
            {
                q.enqueue(currentNode->right);
            }
        }
        if(q.isEmpty())
        {
           return;
        }
        if(currentNode==NULL)
        {
            q.enqueue(NULL);
            cout<<endl;
        }
    }
}

void printZigZag(binaryTreeNode* root)
{
   if(root==NULL)
    {
        return;
    }
    Queue <binaryTreeNode*>q;
    q.enqueue(root);
    q.enqueue(NULL);
    Stack <binaryTreeNode*>s(20);
    int flag=0;
    while(!q.isEmpty())
    {
        if(flag==1)
        {
            while(q.front()!=NULL)
        {
            binaryTreeNode* currentNode=q.dequeue();
            s.push(currentNode);
            if(currentNode->left!=NULL)
            {
                q.enqueue(currentNode->left);
            }
            if(currentNode->right!=NULL)
            {
                q.enqueue(currentNode->right);
            }

        }
        while(!s.isEmpty())
        {
            cout<<s.pop()->data<<" ";
        }
        q.enqueue(q.dequeue());
        flag=0;
        cout<<endl;
        }
        binaryTreeNode* currentNode=q.dequeue();
        if(currentNode!=NULL)
        {
            cout<<currentNode->data<<" ";

            if(currentNode->left!=NULL)
            {
                q.enqueue(currentNode->left);
            }
            if(currentNode->right!=NULL)
            {
                q.enqueue(currentNode->right);
            }
        }
        if(q.isEmpty())
        {
           return;
        }
        if(currentNode==NULL)
        {
            q.enqueue(NULL);
            cout<<endl;
            flag=1;
        }
    }


}

void printLL(Node* head){
Node* temp=head;
while(temp!=NULL){
    cout<<temp->data<<endl;
    temp=temp->next;
}
}

void createLevelWiseLL(Node** level,binaryTreeNode*root)
{

}
int main()
{
    binaryTreeNode* root=takeInput();
    preOrder(root);
    /*int x;
    cout<<"enter X"<<endl;
    cin>>x;
    cout<<"Just greater Number in the tree is "<<justGreater(root,x)->data<<endl;
    cout<<"The Sum Of All The Nodes is "<<sumAllTheNodes(root)<<endl;
    cout<<"the height of the binary tree is "<<heightBinaryTree(root)<<endl;
    cout<<"the diameter of the binary tree is "<<diameter_height(root)->diameter<<endl;
    binaryTreeNode* nodeFound=findNode(root,x);
    if(nodeFound==NULL)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<nodeFound->data<<endl;
    }
    mirrorBinaryTree(root);
    preOrder(root);
    int inorder[100],preorder[100];
    cout<<"Enter the Inorder "<<endl;
    for(int i=0;i<7;i++)
    {
        cin>>inorder[i];
    }

    cout<<"Enter the Preorder "<<endl;
    for(int i=0;i<7;i++)
    {
        cin>>preorder[i];
    }
    binaryTreeNode* root1=createBinaryTree(inorder,preorder,0,6);
    cout<<"the Preorder is ";
    preOrder(root1);
    cout<<endl<<"The Inorder Is ";
    inOrder(root1);
    delete root1;*/
    //cout<<"Balanced "<<checkIfBalanced(root);
    /*cout<<endl;
    binaryTreeNode* root2=takeInput();
    preOrder(root2);
    cout<<endl;

    cout<<"Structurally Identical "<<checkIfStructurallyIdentical(root,root2);*/
    //printLeaves(root);
    //root=removeAllLeaves(root);
    //cout<<endl;
    //preOrder(root);
    //cout<<endl;
    //printLevelTraversal(root);
    //cout<<endl;
    //printZigZag(root);
    Node* level[100];
    createLevelWiseLL(level,root);
    for(int i=0;i<100;i++)
    {
        if(level[0]==NULL)
        {
            break;
        }
        printLL(level[0]);

    }
    delete root;
}
