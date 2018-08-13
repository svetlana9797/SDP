#include"LinkedStack.h"
#include<iostream>
using namespace std;

template <class T>
LinkedStack<T>::LinkedStack()
{
    head=nullptr;
}

template <class T>
void LinkedStack<T>::push(const T& x)
{
    Box<T>* temp= new Box<T>(x);
    if(!head) head=temp;
    else
    {
        temp->next=head;
        head=temp;
    }
}

template <class T>
void LinkedStack<T>::pop()
{
    if(isEmpty()) {cerr<<"Stack is empty!\n"; return;}
    else
    {
        Box<T>* temp=head;
        head=head->next;
        delete temp;
    }
}

template <class T>
 T LinkedStack<T>::top()
{
    if(isEmpty())
    {
        cerr<<"Stack is empty!\n";exit(1);
    }
    else
    return head->data;
}

template <class T>
bool LinkedStack<T>::isEmpty()
{
    if(!head) return true;
    return false;
}

template <class T>
int LinkedStack<T>::length()
{
    int br=0;
    Box<T>* temp=head;
    while(temp)
    {
        br++;
        temp=temp->next;
    }
    return br;
}

template <class T>
LinkedStack<T>::~LinkedStack()
{
    while(head)
    {
        pop();
    }
}
