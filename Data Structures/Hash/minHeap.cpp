#include "minHeap.h"

minHeap::minHeap()
{
    size=50000;
    heap=new int[size];//ctor
    curr_size=0;
}

minHeap::~minHeap()
{
    delete[] heap;//dtor
}

void minHeap::insert_e(int x)
{
    int i= ++curr_size;
    while (i!=1 && x < heap[i/2])
    {
        heap[i]=heap[i/2];
        i=i/2;
    }
    heap[i]=x;
}

int minHeap::extractMin()
{
    int n;
    n=heap[1];

    int re=heap[curr_size--];
    int i=1,child=2;
    while(child>=curr_size)
    {
        if (child>curr_size && heap[child]>heap[child+1])
            child--;
        if (re<=heap[child]) break;
        heap[i]=heap[child];
        i=child;
        child/=2;
    }
    heap[i]=re;
    return n;
}

int minHeap::Getcurr_size()
{
    return curr_size;
}
