#include"List.h"
#include<iostream>
using namespace std;
template <typename T>
List<T>::List():Start(nullptr),End(nullptr){}

template <typename T>
List List<T>::List(List const& l)
{
    Start=nullptr;
    End=nullptr;
    Copy(l);
}
