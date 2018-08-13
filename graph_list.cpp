#include<iostream>
#include<string>
#include<set>
#include<stack>
#include<queue>
#include<list>
using namespace std;

template<typename T>
print(list<T> l)
{
    for(auto i: l)
        cout<<i<<' ';

    cout<<endl;
}

template<typename T>
printList(list<list<T>> l)
{
    cout<<"list successors\n";
    int br=0;
    for(auto i:l)
    {
        cout<<br++<<':';
        print(i);

    }
    cout<<endl;
}

template<typename T>
void BFS(list<list<T>> g,T s)
{
    set<T> visited;
    queue<T> q;
    q.push(s);
    visited.insert(s);

    while(!q.empty())
    {
        s=q.front();
        cout<<s<<' ';
        q.pop();

        auto pos=g.begin();
        for(int i=0;i<s;i++)
        {
           pos++;
        }

        for(auto i=(*pos).begin();i!=(*pos).end();i++)
        {
            if(visited.count(*i)==0)
            {
                q.push(*i);
                visited.insert(*i);
            }
        }
    }
}

void DFSRec(list<list<int>> g, int s, set<int>& visited)
{
    visited.insert(s);
    cout<<s<<' ';
    auto pos=g.begin();
    for(int i=0;i<s;i++)
        {
           pos++;
        }
    for(auto i=(*pos).begin();i!=(*pos).end();i++)
    {
        if(!visited.count(*i))
        {
            DFSRec(g,(*i),visited);
        }

    }
}

void DFS(list<list<int>> g, int s)
{
    set<int> visited;
    DFSRec(g,s,visited);
}

printPath(stack<int> path)
{
    stack<int> res;
    while(!path.empty())
    {
        res.push(path.top());
        path.pop();
    }
    while(!res.empty())
    {
        cout<<res.top()<<' ';
        res.pop();
    }
}

//finds the path from start to end
bool findDFS(list<list<int>> g, int start, int end, set<int>& visited, stack<int>& path)
{
    path.push(start);
    visited.insert(start);
    auto pos = g.begin(); //go from the start until you reach the start vertex

    if(start==end)
        return true;

    for(int i=0;i<start;i++)
    {
        pos++;
    }
    //we have reached the start position ->pos is an iterator so to access the list we use *pos
    for(auto i=(*pos).begin();i!=(*pos).end();i++) //get the successors of the position
    {
        if(!visited.count(*i)&&findDFS(g,(*i),end,visited,path)) //i is an iterator pointing towards the position
            return true;
    }
    path.pop();

}
void findPathDFS(list<list<int>> g, int start, int end)
{
    set<int> visited;
    stack<int> path;
    findDFS(g,start,end,visited,path);
    printPath(path);
}

bool element(list<int> const& l, int i)
{
    for(auto it=l.begin();it!=l.end();it++)
    {
        if(*it==i) return true;
    }
    return false;
}
bool isIsolated(list<list<int>> const& g, int i)
{
    for(auto it = g.begin();it!=g.end();it++) //for every list<int>
    {
        if(element(*it,i)) //if it contains the vertex i
            return false;  //means that it is not isolated
    }
    return true;
}
//finds the isolated vertexes
void findIsotated(list<list<int>> g)
{
    int i=0;
    stack<int> vertexes;
    for(auto it = g.begin();it!=g.end();it++)
    {
        if(isIsolated(g,i)) vertexes.push(i);
            i++;
    }

    while(!vertexes.empty())
    {
        cout<<vertexes.top()<<' ';
        vertexes.pop();
    }

}
int main()
{
    list<int> l0={1,2,3};
    list<int> l1 ={0};
    list<int> l2 ={3};
    list<int> l3 ={1};
    list<int> l4 = {};
    list<int> l5 = {};
    list<list<int>> g = {l0,l1,l2,l3,l4,l5};
    //cout<<boolalpha<<element(l3,3)<<endl;
    //cout<<boolalpha<<isIsolated(g,5)<<endl;
    findIsotated(g);

    //printList(g);
    //findPathDFS(g,4,5);
    return 0;
}
