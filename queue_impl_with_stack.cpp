#include<iostream>
using namespace std;
#include<stack>

class Queue
{
    stack<int> enqueue_stack;
    stack<int> dequeue_stack;

    void transfer();
public:
    void enqueue(int element);
    void dequeue();
    int peek();
    bool empty() const;
    size_t size() const;

    void print() const;

};

void Queue::enqueue(int element)
{
    enqueue_stack.push(element);
}

void Queue::dequeue()
{
    if(dequeue_stack.empty())
    {
        transfer();
    }
    dequeue_stack.pop();
}
int Queue::peek()
{
    if(dequeue_stack.empty())
    {
        transfer();
    }
    return dequeue_stack.top();
}

bool Queue::empty() const
{
    return enqueue_stack.empty()&&dequeue_stack.empty();
}

size_t Queue::size() const
{
    return enqueue_stack.size() + dequeue_stack.size();
}

void Queue::transfer()
{
    while(!enqueue_stack.empty())
    {
        dequeue_stack.push(enqueue_stack.top());
        enqueue_stack.pop();
    }
}
