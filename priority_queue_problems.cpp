#include<iostream>
#include<iomanip>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
class Elem
{
    string name;
    int var1;
    int var2;
public:
    Elem(string name,int var1, int var2):name(name),var1(var1),var2(var2){}

    friend ostream& operator<<(ostream& os, Elem const& elem)
    {
        return os<<elem.name<<' '<<elem.var1<< ' '<<elem.var2<<endl;
    }

    friend bool operator<(Elem const& el1,Elem const& el2)
    {
        if(el1.name<el2.name) return true;
        if(el1.var1<el2.var1) return true;
        if(el1.var2<el2.var2) return true;
        return false;

    }
    friend bool operator>(Elem const& el1,Elem const& el2)
    {
        if(el1.name>el2.name) return true;
        if(el1.var1>el2.var1) return true;
        if(el1.var2>el2.var2) return true;
        return false;
    }
};
int main()
{
    string aa="ananas";
    Elem a(aa,1,2);
    Elem b("banan",3,4);
    Elem c("cherry",-4,-6);
    Elem d("cheresha",-4,-6);
    Elem e("cherry",6,8);


    priority_queue<Elem,vector<Elem>,greater<Elem>> q;
    q.push(a);
    q.push(b);
    q.push(c);
    q.push(d);
    q.push(e);
    for(int i=0;i<5;i++)
    {
        cout<<q.top();
    q.pop();
    }

    return 0;
}
