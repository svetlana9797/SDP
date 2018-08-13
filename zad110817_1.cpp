//зад 7 от упражнение 2
#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

string repeat(string const& s, int n)
{
    string result;
    for(int i=0;i<n;i++)
    {
        result+=s;
    }
    return result;
}
string decompress(string const& expr)
{
    stack<string> s;
    s.push("");

    int length=expr.size();
    for(i=0;i<length;i++)
    {
        char c=expr[i];
        if( isdigit(c))//!!
        {
            string number;
            while(expr[i]!='(')
            {
                number+=c;
                ++i;
            }

            s.push(number);
            s.push("");
        }
        else
            if(c >='A'&&c <='Z')
        {
            s.top()+= c;   //s.top() returns a reference to the top element so we can change it
        }
        else if(c==')')
        {
            string current=string(s.top()); //string constructor
            s.pop();
            int n=stoi(s.top());
            s.pop();
            s.top()+=repeat(current,n);
        }
    }
    return s.top();
}
int main()
{
    string expr="3(AB2(B))";
    //cin>>expr;
    decompress(expr);
}
