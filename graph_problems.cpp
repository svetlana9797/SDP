#include<iostream>
#include<list>
#include<set>
#include<stack>
using namespace std;

bool DFSRec(list<list<int>> const& g, int p, set<int>& visited,stack<int>& recStack)
{

    if(!visited.count(p))//if the vertex is not in the set
    {
         visited.insert(p); //insert it
         recStack.push(p);
         auto pos = g.begin();

         for(int i=0;i<p;i++)  //go to the position pointed ->pos
            pos++;

         for(auto i = (*pos).begin();i!=(*pos).end();i++) //check the list on position pos
         {
             if(!visited.count(*i)&&DFSRec(g,(*i), visited,recStack)) //if we see a cycle return true
                 return true;
             else if(contains(recStack,(*i))) //if the vertex is already in the recStack
                return true;
         }
         removeFromStack(recStack,p);
            return false;
    }

    return false;
}

bool isCyclic(list<list<int>> const& g)
{
    set<int> visited;
    for(int i = 0;i!=g.size();i++)
        if(DFSRec(g,i,visited))
           return true;
    return false;
}

int main()
{
    list<int> l0={1,2,3};
    list<int> l1 ={4};
    list<int> l2 ={};
    list<int> l3 ={5};
    list<int> l4 = {};
    list<int> l5 = {};
    list<list<int>> g = {l0,l1,l2,l3,l4,l5};
    cout<<boolalpha<<isCyclic(g);
}
