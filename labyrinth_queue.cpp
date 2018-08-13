#include<iostream>
#include<iomanip>
using namespace std;
#include<queue>
#include<vector>
#include<string>

using Position = tuple<int,int,int>;//each position holds its coordinates and the distance from the start point
using Labyrinth = vector<vector<string>>;

void print(Labyrinth const& lab)
{
    for(auto const& row:lab) //auto detect the type of the variable row
    {
        for(auto const& cell: row)
        {
            cout<<cell<<' ';
        }
        cout<<endl;
    }
}

bool insideLabyrinth(Position const& p, Labyrinth const& lab)
{
    int x,y, distance;
    tie(x,y, distance)= p; //unpacks a tuple into individual objects

    return x<lab.size() && x>0 && y<lab.size() && y>0;//lab is a vector so it has the .size() member function
}

bool isEmpty(Position const& p,Labyrinth const& lab)//check if the position is empty
{
    int x,y,distance;
    tie(x,y,distance)=p;
    return lab[x][y]=="o";
}

void traverse(Labyrinth& lab, int x, int y) //x,y are the coordinates of the beginning
{
    queue<Position> q;
    q.push(Position(x,y,0));
    while(!q.empty())
    {
        Position curr = q.front();
        q.pop();

        int x,y,distance;
        tie(x,y,distance)=curr;

        Position next_positions[]={
          Position(x+1,y,distance+1),
          Position(x-1,y,distance+1),
          Position(x,y+1,distance+1),
          Position(x,y-1,distance+1)
        };

        for(Position const&pos: next_positions)
        {
            if(insideLabyrinth(pos,lab)&&isEmpty(pos,lab))
            {
                q.push(pos);
                //write in the labyrinth that we walked through this position
                //extract from each position the information and write it in the labyrinth
                int x,y,distance;
                tie(x,y,distance)=pos;
                lab[x][y]=to_string(distance);
            }
        }

        //in the end write the positions we cannot reach
        for(auto &row:lab)
        {
            for(auto& cell:row)
            {
                if(cell=="o")
                    cell="u";
            }
        }

    }

    //for all the possible positions
    //check if they are correct
    //and then for each new position write the distance
    //and put them in a queue to check for every one of them the new possible positions
    //if there are no more positions
}


int main()
{
     Labyrinth labyrinth = {
    { "o", "o", "o", "o", "o", "x", "x", "o" },
    { "o", "x", "o", "x", "x", "o", "x", "x" },
    { "o", "o", "x", "o", "x", "o", "o", "o" },
    { "o", "o", "o", "o", "x", "x", "x", "o" },
    { "o", "*", "o", "x", "o", "o", "o", "o" },
    { "o", "x", "x", "o", "o", "o", "o", "o" },
    { "o", "o", "o", "o", "x", "x", "x", "o" },
    { "x", "o", "x", "o", "o", "o", "o", "o" },
  };

  print(labyrinth);
    return 0;
}
