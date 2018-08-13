#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

void print(stack<int> s)
{
    while(!s.empty())
        {
            cout<<s.top()<<' ';
            s.pop();
        }
    cout<<endl;
}

bool removeValue(stack<int>& s,int val)
{
    if(s.top()==val) {s.pop(); return 1;}
    return 0;
}

void fillUp(stack<int>& s, stack<int>& s1)
{
    while(!s1.empty())
    {
        s.push(s1.top());
        s1.pop();
    }
}

stack<int> append(stack<int> s1, stack<int> s2)
{
    stack<int> s;
    int x;
    while(!s1.empty()&&!s2.empty()) //докато имаме елементи и в двата стека
    {
        x=max(s1.top(),s2.top()); //взимаме по-малкия от върховете

        if(!removeValue(s1,x)) removeValue(s2,x); //и го махаме от стека като гледаме за повторение

         s.push(x); //слагаме х в новия стек
    }
    if(s1.empty()) fillUp(s,s2); //допълваме s със стека, който е останал пълен след цикъла
    else fillUp(s,s1);

    return s; //връщаме s
}

int main()
{
    stack<int> s1;
    stack<int> s2;
    s1.push(1);
    s1.push(3);
    s1.push(5);
    print(s1);

    s2.push(1);
    s2.push(2);
    s2.push(6);
    print(s2);

    stack<int> s=append(s1,s2);
    print(s);
    return 0;
}
