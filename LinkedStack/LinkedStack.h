#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED
template <class T>
class Box
{
public:
    T data;
    Box<T>* next;
    Box():next(nullptr){};
    Box(T const& x):data(x),next(nullptr){};
};

template <class T>
class LinkedStack
{
    Box<T>* head;
public:
    LinkedStack();
    void push(const T& x);
    void pop();
     T top();
    bool isEmpty();
    int length();
    ~LinkedStack();
};



#endif // LINKEDSTACK_H_INCLUDED
