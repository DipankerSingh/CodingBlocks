class TreeNode
{
    public:
    int data;
    TreeNode** children;
    int children_count;
    TreeNode(int data,int numberOfChildren)
    {
           this->data=data;
           this->children_count=numberOfChildren;
           children=new TreeNode*[numberOfChildren];
    }

    ~TreeNode()
    {
        for(int i=0;i<children_count;i++)
        {
            delete children[i];
        }
        delete [] children;
    }
};
