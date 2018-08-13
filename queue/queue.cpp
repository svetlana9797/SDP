#include<iostream>
#include"queue.h"
using namespace std;

template <class T>
Queue<T>::Queue():first(nullptr),last(nullptr){}

template <class T>
void Queue<T>::push(T const& value)
{
    if(!first)
    {
        first=new Box<T>(value);
        last=first;
    }
    else
    {
        Box<T>* temp=new Box<T>(value);
        last->next=temp;
        last=temp;
    }
}

template <class T>
T Queue<T>::top() const
{
    if(!isEmpty()) return first->inf;
    cerr<<"Queue is Empty!Cannot return top()!\n"; exit(1);
}

template <class T>
void Queue<T>::pop()
{
    if(first) // if(first!=nullptr)
    {
        Box<T>* temp=first;
        first=first->next;
        delete temp;
    }
    else
    {
        cerr<<"Queue is Empty!Cannot pop()!"<<endl; exit(1);
    }
}

template <class T>
int Queue<T>::length() const
{
    if(!first) return 0;
    int br=0;
    Box<T>* temp=first;
    while(temp)
    {
        temp=temp->next;
        br++;
    }
    return br;
}

template <class T>
bool Queue<T>::isEmpty() const
{
    if(!first) return true; // if(first==nullptr)
    return false;
}

template <class T>
void Queue<T>::print() const
{
    Box<T>* temp=first;
    while(temp)
    {
        cout<<temp->inf<<' ';
        temp=temp->next;
    }
    cout<<endl;
}

template <class T>
Queue<T>::~Queue()
{
    while(!isEmpty())
    {
        pop();
    }
}
