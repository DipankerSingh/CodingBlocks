//priorityQueue
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include<vector>
#include<iostream>
template <typename T>;
using namespace std;
class PriorityQueue
{
    vector<pair<int,T>*>*data;
public:
    PriorityQueue()
    {
        data=new vector<pair<int,T>*>();
        data->push_back(NULL);
    }
    int size()
    {
        return data->size()-1;
    }

    bool is_empty()
    {
        if(size()==0)
        {
            return true;
        }
        return false;
    }

    T* min()
    {
        if(is_empty())
        {
            return NULL;
        }
        return &(data->at(1));
    }

    void insert(int priority,T value)
    {
        pair<int,T>*newEntry=new pair<int,T>();
        newEntry->first=priority;
        newEntry->second=value;
        data->push_back(newEntry);
        int childIndex=data->size()-1;
        int parentIndex=childIndex/2;
        while(childIndex>1)
        {
            pair<int,T>*child=data->at(childIndex);
            pair<int,T>*parent=data->at(parentIndex);
            if(parent->first<child->first)
            {
                return;
            }
            (*data)[childIndex]=parent;
            (*data)[parentIndex]=child;
            childIndex=parentIndex;
            parentIndex=childIndex/2;
        }
    }

    void removeMin()
    {
        if(is_empty())
        {
            return;
        }

        pair<int,T>*temp=(*data)[1];
        delete temp;
        (*data)[1]=(*data)[data->size()-1];
        data->pop_back();
        int parentIndex=1;
        while(parentIndex*2<=data->size()-1)
        {
            int leftChildIndex=2*parentIndex;
            int rightChildIndex=2*parentIndex+1;
            int toBeSwappedIndex=parentIndex;
            if(data->at(paremtindex)->first>data->at(leftChildIndex)->first)
            {
                toBeSwappedIndex=leftChildIndex;
            }
            if(rightChildIndex<=data->size()-1)
            {
                if(data->at(toBeSwappedIndex)->first>data->at(rightChildIndex)->first)
                {
                    toBeSwappedIndex=rightChildIndex;
                }
            }
            if(toBeSwappedIndex==parentIndex)
            {
                return;
            }
            swap(data->at(parentIndex),data->at(toBeSwappedIndex));
            parentIndex=toBeSwappedIndex;
        }



    }

    ~PriorityQueue()
    {
        for(int i=1;i<data->size();i++)
        {
            delete data->at(i);
        }
        delete data;
    }


};
#endif // PRIORITY_QUEUE_H
