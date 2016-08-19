#ifndef QUEUE_H
#define QUEUE_H 1
template <typename T>
class Queue
{
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
public:
    Queue()
    {
        capacity =10;
        data=new T[capacity];
        firstIndex=-1;
        nextIndex=0;
        size=0;
    }
    ~Queue()
    {
        delete [] data;
    }

    T front()
    {
        if(size==0)
        {
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {
        if(size==0)
        {
            return 0;
        }

        T toBeReturned=data[firstIndex];
        data[firstIndex]=0;
        firstIndex=(firstIndex +1) % capacity;
        size--;
        if(size==0)
        {
            firstIndex=-1;
            nextIndex=0;
        }
        return toBeReturned;
    }

    void enqueue(T element)
    {
        if(firstIndex==-1)
        {
            firstIndex=0;
        }
        if(size==capacity)
        {
            T *temp=data;

            data=new T[2*capacity];
            int k=0;
            for(int i=0;i<capacity;i++)
            {
                int fromIndex=(firstIndex + i)%capacity;
                data[k]=temp[fromIndex];
                k++;
            }
            firstIndex=0;
            nextIndex=k;
            capacity=capacity * 2;
            delete [] temp;
        }
        data[nextIndex]=element;

        size++;
        nextIndex=(nextIndex + 1)%capacity;

    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return (size==0);
    }

};
#endif
