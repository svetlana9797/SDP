#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
template<typename T>
struct Box
{
    T data;
    Box* next;
    Box():next(nullptr){}
    Box(int d):data(d),next(nullptr){}
};

template<typename T>
class List
{
    Box<T>* Start;
    Box<T>* End;
    Box<T>* Curr;

public:
    List();
    List(List const& l);
    List operator=(List const& l);
    ~List();
    void Copy(List const& l);

    int length() const;
    bool isEmpty() const;
    void print() const;

    void deleteBefore(Box<T>* p);
    void deleteAfter(Box<T>* p);
    void deleteCurrent(Box<T>* p);

    void insertBefore(Box<T>* p, const T& x);
    void insertAfter(Box<T>* p, const T& x);
    void insertCurrent(Box<T>* p, const T& x);
    void toEnd(const T& x);

    void iterStart(Box<T>* p = NULL); //put cur on place p
    Box<T>* iter(Box<T>* p);
};

#endif // LIST_H_INCLUDED
