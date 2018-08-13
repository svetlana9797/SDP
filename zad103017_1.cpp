#include<iostream>
#include<stack>
using namespace std;

int smaller(int x, int y)
{
    return (x<y)? x:y;
}
int game(stack<int> s1,stack<int> s2)
{
    int x;
    cout<<"value=";
    cin>>x;
    int sum=0;
    int br=-1;
    int minElem;
    while(!(s1.empty()&&s2.empty())&&sum<=x)
    {
        if(!s1.empty())
           if(!s2.empty())
           {
               minElem=smaller(s1.top(),s2.top());
               if(s1.top()==minElem) s1.pop();
               else s2.pop();
           }
             else
             {
                 minElem=s1.top();
                 s1.pop();
             }

        else
        {
             minElem=s2.top();
             s2.pop();
        }

            br++;
         sum+=minElem;
    }
    return br;
}

int main()
{
    stack<int> s1;
    stack<int> s2;
//    int n1,n2;
//    cin>>n1>>n2;
//    int val;
//    for(int i=0;i<n1;i++)
//    {
//        cin>>val;
//        s1.push(val);
//    }
//
//    for(int i=0;i<n2;i++)
//    {
//        cin>>val;
//        s2.push(val);
//    }
s1.push(23);
s1.push(12);
s1.push(3);

s2.push(2);
s2.push(2);
s2.push(1);
s2.push(2);

cout<<game(s1,s2);
    return 0;
}
