#include<string>
#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<char> v03 = {'k','r','a'};
vector<char> v12 = {'v','i','c', 'a'};
vector<char> v13 = {'r','a'};
vector<char> v21 = {'k'};
vector<char> v31 = {'s','t','a'};
vector<char> G[4][4] = {vector<char>(), vector<char>(), vector<char>(),   v03,
                         vector<char>(), vector<char>(),  v12,v13,
                         vector<char>(),v21, vector<char>(),  vector<char>(),
                         vector<char>(),v31,vector<char>(),vector<char>()};

void findWordFrom(vector<char> g[4][4],int n, int start_vertex, string word, int& counter, list<int>& path)
{
    path.push_back(start_vertex);
    if(word.size()==0) //when we have read the word
    {
        counter++;
        for(auto i: path)
            cout<<i<<' ';
            cout<<endl;
    }

    for(int j=0;j<n;j++)
    {
        int sizeSubword = g[start_vertex][j].size();//get the size of the subword

        vector<char> v = g[start_vertex][j];//take the vector from the position
        string tmp(v.begin(),v.end());//construct a string from the vector

        if(!tmp.empty()&& tmp == word.substr(0,sizeSubword))//if the string is not empty&&it matches the word
        {
            findWordFrom(g,n,j,word.substr(sizeSubword),counter,path);//recursion with what's left from the word
        }
    }
    path.pop_back();//at the end we have to go one step back in case the rec didn't give the proper result
                    //and we have to go on
}

int countPaths(vector<char> g[4][4],int n, string word)
{
    int counter=0;
    list<int> path;
    for(int i=0;i<n;i++)
    {
        findWordFrom(g,n,i,word,counter,path);
    }
    return counter;
}
int main()
{
     cout<<countPaths(G,4,"krastavica");
    return 0;
}
