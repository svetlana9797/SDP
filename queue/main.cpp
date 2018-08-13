#include <iostream>
#include<queue>
#include"queue.h"
using namespace std;
void testQueue()
{
    Queue<int> q;
//    cout<<q.length()<<endl;
//    cout<<q.isEmpty()<<endl;
//    q.push(2);
//    q.push(3);
//    cout<<q.length()<<endl;
//    cout<<q.isEmpty()<<endl;
//    q.print();
//    q.pop();
//    cout<<q.isEmpty()<<endl;
//    q.pop();
//    cout<<q.isEmpty()<<endl;
for(int i=0;i<10;i++)
    q.push(i);
    cout<<"length="<<q.length()<<endl;
q.print();
for(int i=0;i<10;i++)
    q.pop();
cout<<"length="<<q.length()<<endl;
//q.pop();
//cout<<q.length();
}

int minimal(int x, int y)
{
   return (x<y)? x:y;
}

//n-тото по големина число, чиито прости делители са измежду 2, 3 и 5
void simpleNumber(int n)
{
    queue<int> q2;
    queue<int> q3;
    queue<int> q5;
    q2.push(2);
    q3.push(3);
    q5.push(5);
    int minElement;
    for(int i=0;i<n;i++)
    {
        minElement=minimal(minimal(q2.front(),q3.front()),q5.front());

        if(q2.front()==minElement) q2.pop();

        if(q3.front()==minElement) q3.pop();

        if(q5.front()==minElement) q5.pop();

        q2.push(minElement*2);
        q3.push(minElement*3);
        q5.push(minElement*5);
    }
    cout<<minElement<<endl;
}
int main()
{
    testQueue();
//    int n;
//    cin>>n;
//    simpleNumber(n);
    return 0;
}
