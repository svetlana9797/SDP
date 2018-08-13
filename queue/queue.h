#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
template <class T>
class Box
{
public:
    T inf;
    Box<T>* next;
    Box():next(nullptr), inf(T()){}
    Box(T const&_inf):inf(_inf),next(nullptr){}
};
template <class T>
class Queue
{
    Box<T>* first;
    Box<T>* last;

public:
    //add operator= and copy constructor
    Queue();
    void push(T const& value);
    T top() const;
    void pop();
    int length() const;
    bool isEmpty() const;
    void print() const;
    ~Queue();
};

#endif // QUEUE_H_INCLUDED
