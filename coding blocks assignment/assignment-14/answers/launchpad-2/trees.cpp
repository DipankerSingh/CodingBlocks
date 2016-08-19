#include<iostream>
#include "TreeNode.h"
#include "Queue.h"
using namespace std;

TreeNode* takeLevelWiseInput()
{
    cout<<"Enter Root Data"<<endl;
    int data;
    cin>>data;


    cout<<"Enter the number of children for "<<data<<endl;
    int num_children;
    cin>>num_children;

    TreeNode* root=new TreeNode(data,num_children);
    Queue<TreeNode*> q;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        TreeNode* currentNode=q.dequeue();
        int num_children=currentNode->children_count;
        for(int i=0;i<num_children;i++)
        {
            cout<<"Enter "<<i+1<<"th child of "<<currentNode->data<<endl;
            int nextChildData;
            cin>>nextChildData;

            cout<<"Enter child count for "<<nextChildData<<endl;
            int childNumChildren;
            cin>>childNumChildren;

            TreeNode* child=new TreeNode(nextChildData,childNumChildren);
            currentNode->children[i]=child;
            q.enqueue(child);
        }

    }



}

void printDataLevelWise(TreeNode*root)
{

    int data;
    int num_children;

    Queue<TreeNode*> q;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        TreeNode* currentNode=q.dequeue();
        int num_children=currentNode->children_count;
        cout<<currentNode->data<<":";
        for(int i=0;i<num_children;i++)
        {
            cout<<currentNode->children[i]->data;
            if(i<num_children-1)
            {
                cout<<",";
            }
            q.enqueue(currentNode->children[i]);
        }
        if(num_children!=0)
        {
            cout<<";";
        }
        cout<<endl;


    }

}


TreeNode* takeTreeInput()
{
    cout<<"Enter root data"<<endl;
    int data;
    cin>>data;
    cout<<"Enter the number of children for "<<data<<endl;
    int num_children;
    cin>>num_children;
    // can't allocate on stack
    //TreeNode root(data,num_children);
    TreeNode* root=new TreeNode(data,num_children);
    for(int i=0;i<num_children;i++)
    {
        TreeNode* nextChild=takeTreeInput();
        (*root).children[i]=nextChild;
    }
    return root;
}

void printTree(TreeNode* root)
{
    cout<<root->data<<":";
    for(int i=0;i<root->children_count;i++)
    {
        TreeNode* ithChild=root->children[i];
        cout<<ithChild->data<<",";
    }

    cout<<endl;

    for(int i=0;i<root->children_count;i++)
    {
        printTree(root->children[i]);
    }

}

int height(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int maxChildHeight=0;
    for(int i=0;i<root->children_count;i++)
    {
        int currentChildHeight=height(root->children[i]);
        if(currentChildHeight>maxChildHeight)
        {
            maxChildHeight=currentChildHeight;
        }
    }

    return 1+maxChildHeight;
}


int maxData(TreeNode* root)
{
    if(root==NULL)
    {
        return -1;
    }


    int max = root->data;
    for(int i=0;i<root->children_count;i++)
    {
        int currentChildMax=maxData((root->children[i]));
        if(currentChildMax>max)
        {
            max=currentChildMax;
        }
    }
    return max;
}

void printAtK(TreeNode* root,int k)
{
    if(k==0)
    {
        cout<<root->data;
        return;
    }

    for(int i=0;i<root->children_count;i++)
    {
        printAtK(root->children[i],k-1);
    }
}

TreeNode* nodeWithMaxDegree(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }

    TreeNode* maxNode=root;
    int maxDegree=maxNode->children_count;
    for(int i=0;i<root->children_count;i++)
    {
        TreeNode* currentMaxNode=nodeWithMaxDegree(root->children[i]);
    if((currentMaxNode->children_count)>(maxNode->children_count))
    {
        maxNode=currentMaxNode;
    }

    }
    return maxNode;

}

int numberOfNodes(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int toBeReturned=0;
    for(int i=0;i<root->children_count;i++)
    {
        toBeReturned = toBeReturned + (numberOfNodes(root->children[i]));

    }

    return 1+toBeReturned;
}

int greaterThanX(TreeNode* root,int x)
{
    int count=0;
    for(int i=0;i<(root->children_count);i++)
    {

            count=count+greaterThanX(root->children[i],x);

    }

        if((root->data)>x)
        {
            return 1+count;
        }
        else
        {
            return count;
        }

}

TreeNode* sumParentChildren(TreeNode* root)
{
    int maxSum=0;
    TreeNode* maxSumNode=root;
    for(int i=0;i<root->children_count;i++)
    {
        maxSum=maxSum+root->children[i]->data;
    }
    maxSum=maxSum+root->data;

    for(int i=0;i<root->children_count;i++)
    {
        int currentSum=0;
        TreeNode* currentNode=sumParentChildren(root->children[i]);
        if(currentNode->children_count==0)
        {
            currentSum=currentNode->data;
        }
        else
        {
            for(int i=0;i<currentNode->children_count;i++)
            {
                currentSum=currentSum+currentNode->children[i]->data;
            }
            currentSum=currentSum+currentNode->data;
        }
        if(currentSum>maxSum)
        {
            maxSum=currentSum;
            maxSumNode=currentNode;
        }


    }

    return maxSumNode;
}

int main()
{
    TreeNode* root=takeLevelWiseInput();
    //TreeNode* root=takeTreeInput();

    printDataLevelWise(root);
    //printTree(root);
    cout<<"No. Of Nodes in the tree "<<numberOfNodes(root)<<endl;
    cout<<"Height Of the Tree "<<height(root)<<endl;
    TreeNode* maxNode=nodeWithMaxDegree(root);
    cout<<"Node with Highest Degree "<<maxNode->data<<endl;
    int x;
    cout<<"Enter the value of X"<<endl;
    cin>>x;
    cout<<"No. Of Nodes Greater Than "<<x<<" are "<<greaterThanX(root,x)<<endl;

    TreeNode* maxSumNode=sumParentChildren(root);
    cout<<maxSumNode->data<<endl;

    return 0;
}
