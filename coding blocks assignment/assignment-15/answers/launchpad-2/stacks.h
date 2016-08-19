#ifndef Stack_H
#define Stack_H 1
template <typename T>
class Stack
{

    int size;
    T* data;
    public:
    Stack(int n)
    {
        size=0;
        data=new T[n];
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

    T top()
    {
        if(isEmpty())
        {
            {
                return 0;
            }
        }
        return data[size-1];
    }
    void push(T newElement)
    {
        if(size==50)
        {
            return;
        }
        data[size]=newElement;
        size++;
    }

    T pop()
    {
        if(isEmpty())
        {
            return 0;
        }
        T toBeReturned=data[size-1];
        data[size-1]=0;
        size--;
        return toBeReturned;
    }
};
#endif
