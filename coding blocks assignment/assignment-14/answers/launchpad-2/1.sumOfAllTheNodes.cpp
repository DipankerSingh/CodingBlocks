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

int sumAllTheNodes(TreeNode* root)
{
    int sum=root->data;
    for(int i=0;i<root->children_count;i++)
    {
        sum=sum+sumAllTheNodes(root->children[i]);
    }
    return sum;
}

bool checkStructure(TreeNode* root1,TreeNode* root2)
{
    for(int i=0;i<root1->children_count;i++)
    {
        if(root1->data==root2->data)
        {
            if(root1->children_count==root2->children_count)
            {
               int BelowStatus=checkStructure(root1->children[i],root2->children[i]);
                if(BelowStatus==0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            return false;
        }

    }

    return true;

}

int justBigger(TreeNode* root,int x)
{
    int previousMax=-1;

    if(root->data>x)
    {
        previousMax=root->data;
    }

    for(int i=0;i<root->children_count;i++)
    {
        int currentMax=justBigger(root->children[i],x);
        if(currentMax!=-1&&previousMax!=-1)
        {
          if(currentMax<previousMax)
          {
            previousMax=currentMax;
          }
        }
        else
        {
            previousMax=currentMax;
        }

    }

    return previousMax;
}

int secondLargestValue(TreeNode* root)
{
    int max2=-1;
    int max1=root->data;

    for(int i=0;i<root->children_count;i++)
    {
        int max=secondLargestValue(root->children[i]);
        if(max>max1 && max>max2)
        {
            max2=max1;
            max1=max;
        }
        else if (max>max2 && max<max1)
        {
            max2=max;
        }
    }
    if(root->children_count==0)
    {
        return max1;
    }
    else
    {
        return max2;
    }
}

int numOfLeafNodes(TreeNode* root)
{
    int count=0;
    for(int i=0;i<root->children_count;i++)
    {
        count=count + numOfLeafNodes(root->children[i]);
    }

    if(root->children_count==0)
    {
        return 1;
    }
    else
    {
        return count;
    }
}
void addOne(TreeNode* root)
{
    root->data=root->data+1;
    for(int i=0;i<root->children_count;i++)
    {
        addOne(root->children[i]);
    }


}

void replaceEachNodeWithItsDepthValue(TreeNode* root)
{
    root->data=0;
    for(int i=0;i<root->children_count;i++)
    {

        replaceEachNodeWithItsDepthValue(root->children[i]);

    }
    for(int i=0;i<root->children_count;i++)
    {
      addOne(root->children[i]);
    }
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
    cout<<"The sum of All The Nodes is "<<sumAllTheNodes(root)<<endl;
    cout<<"Enter tree 2"<<endl;
    TreeNode* root2=takeLevelWiseInput();
    cout<<checkStructure(root,root2)<<endl;
    cout<<"enter the Number from which just bigger number is to be found"<<endl;
    int toBeSearched;
    cin>>toBeSearched;
    cout<<"Just bigger number in the Tree is "<<justBigger(root,toBeSearched)<<endl;
    cout<<"Second Largest Value In The Tree "<<secondLargestValue(root)<<endl;
    cout<<"The No. of Leaf Nodes Are "<<numOfLeafNodes(root)<<endl;
    replaceEachNodeWithItsDepthValue(root);
    printDataLevelWise(root);
    delete root;
    return 0;
}
