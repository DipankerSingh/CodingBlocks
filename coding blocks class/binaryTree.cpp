#include<iostream>
#include "binaryTreeNode.h"
#include "Queue.h"
#include"pair.h"
#include "Node.h"
#include "triplet.h"
using namespace std;

void printBetweenK1K2(binaryTreeNode* root,int k1, int k2)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->data>=k1)

    {
        printBetweenK1K2(root->left,k1,k2);
    }
    if(root->data>=k1 && root->data<=k2)
    {
        cout<<root->data<<endl;
    }

    if(root->data<=k2)
    {
        printBetweenK1K2(root->right,k1,k2);
    }
}

bool search(binaryTreeNode* root,int element)
{
    if(root==NULL)
    {
        return false;
    }

    if(root->data==element)
    {
        return true;
    }
    else if(root->data>element)
    {
        return search(root->left,element);
    }
    else
    {
        return search(root->right,element);
    }
}

/*binaryTreeNode* takeInput()
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
*/
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

int findMax(binaryTreeNode* root)
{

    if(root==NULL)
    {
        return -1;
    }

    int max=root->data;

    int currentMaxLeft=findMax(root->left);
    int currentMaxRight=findMax(root->right);

    if(currentMaxLeft>=max && currentMaxLeft>=currentMaxRight)
    {
        return currentMaxLeft;
    }
    else if(currentMaxRight>=max && currentMaxRight>=currentMaxLeft)
    {
        return currentMaxRight;
    }
    else
    {
        return max;
    }


}

int findMin(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return 10000;
    }
    int min=root->data;

    int currentMinLeft=findMin(root->left);
    int currentMinRight=findMin(root->right);

    if(currentMinLeft<=min && currentMinLeft<=currentMinRight)
    {
        return currentMinLeft;
    }
    else if(currentMinRight<=min && currentMinRight<=currentMinLeft)
    {
        return currentMinRight;
    }
    else
    {
        return min;
    }



}

bool isBST(binaryTreeNode*root)
{
    if(root==NULL)
        return true;

    int maxLeft= findMax(root->left);
    int minRight=findMin(root->right);

    if(maxLeft< root->data && minRight>root->data)
    {
        if(isBST(root->left))
        {
            if(isBST(root->right))
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

void getInorder(binaryTreeNode* root,int* arr,int&index)
{
    if(root==NULL)
        return;
    getInorder(root->left,arr,index);
    arr[0]=root->data;
    index++;
    getInorder(root->right,arr+1,index);

}

bool isBST2(binaryTreeNode* root)
{
    int a[100];
    int index=0;
    getInorder(root,a,index);
    for(int i=1;i<index;i++)
    {
        if(a[i]<a[i-1])
        {
            return false;
        }
    }

    return true;
}

Triplet* isBST3(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return new Triplet(10000,-10000,true);
    }

    Triplet* leftOutput=isBST3(root->left);
    Triplet* rightOutput=isBST3(root->right);

    int min1=min(min(root->data,leftOutput->min),rightOutput->min);
    int max1=max(max(root->data,leftOutput->max),rightOutput->max);

    if(!leftOutput->isBST || !rightOutput->isBST)
    {

        return new Triplet(min1,max1,false);
    }

    if(root->data < leftOutput->max || root->data >= rightOutput->min)
    {
        return new Triplet(min1,max1,false);
    }

    return new Triplet(min1,max1,true);
}

bool isBST4(binaryTreeNode* root,int &prev)
{
    if(root==NULL)
    {
        return true;
    }

    bool checkLeft=isBST4(root->left,prev);
    if(!checkLeft)
    {
        return false;
    }

    if(prev > root->data)
    {
        return false;
    }
    else
    {
        prev=root->data;
    }

    bool checkRight=isBST4(root->right,prev);
    return checkRight;
}

Node* createSortedLL(binaryTreeNode* root)
{
    if(root==NULL)
    {
        return NULL;
    }


    Node* headLeft=createSortedLL(root->left);

    Node* newNode=new Node(root->data);
    if(headLeft==NULL)
    {
        headLeft=newNode;
    }else

    {
        Node* temp=headLeft;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
    }


    newNode->next=createSortedLL(root->right);

    return headLeft;

}
void printLL(Node* head)
{
Node* temp=head;
while(temp!=NULL){
    cout<<temp->data<<endl;
    temp=temp->next;
}
}

Node* takeInput()
{
    int currentInput;
    cout<<"Enter the first element";
    cin>>currentInput;
    Node* head=NULL;
    Node* tail=NULL;
    while(currentInput!=-1)
    {
        Node* newNode=new Node(currentInput);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            /*Node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;*/
            tail->next=newNode;
            tail=newNode;
        }
        cout<<"enter next element"<<endl;
        cin>>currentInput;
    }
    return head;

}

int ll_lengthR(Node *head)
{
    if(head==NULL)
        return 0;
    return 1 + ll_lengthR(head->next);
}
binaryTreeNode* createBinaryTreeUsingSortedLL(Node* head)
{
   if(ll_lengthR(head)==1)
   {
        binaryTreeNode* root=new binaryTreeNode(head->data);
        return root;
   }

   Node* temp=head;
   int currentLength=(ll_lengthR(head))/2;
   for(int i=0;i<currentLength;i++)
   {
       temp=temp->next;
   }


   binaryTreeNode* root=new binaryTreeNode(temp->data);
    if(temp->next!=NULL)
   root->right=createBinaryTreeUsingSortedLL(temp->next);


   Node* temp2=head;
    for(int i=0;i<currentLength-1;i++)
   {
       temp2=temp2->next;
   }
   temp2->next=NULL;

   root->left=createBinaryTreeUsingSortedLL(head);

   return root;
}

int main()
{
    //binaryTreeNode* root=takeInput();
    // preOrder(root);
    //cout<<endl;

    //Node* head=createSortedLL(root);
    //printLL(head);
    //cout<<isBST(root);
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
    // delete root;
    delete root1;*/
    cout<<"enter the Sorted linked list "<<endl;
    Node* head=takeInput();
    binaryTreeNode* root=createBinaryTreeUsingSortedLL(head);

    preOrder(root);
    cout<<endl;
    inOrder(root);
    delete root;

}
