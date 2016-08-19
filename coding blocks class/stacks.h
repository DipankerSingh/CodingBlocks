#ifndef Stack_H
#define Stack_H 1
class Stack
{

    int size;
    int* data;
    public:
    Stack(int n)
    {
        size=0;
        data=new int[n];
    }

    ~Stack()
    {
        delete[]data;
    }

    int get_size()
    {
        return  size;
    }

    bool isEmpty()
    {
        if(size==0)
            return true;
        else
            return false;
    }

    int top()
    {
        if(isEmpty())
        {
            {
                return -1;
            }
        }
        return data[size-1];
    }
    void push(int newElement)
    {
        if(size==50)
        {
            return;
        }
        data[size]=newElement;
        size++;
    }

    int pop()
    {
        if(isEmpty())
        {
            return -1;
        }
        int toBeReturned=data[size-1];
        data[size-1]=0;
        size--;
        return toBeReturned;
    }
};
#endif
