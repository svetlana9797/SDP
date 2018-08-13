#include<iostream>
using namespace std;
//delete all columns containing a negative number
struct Cell
{
    int data;
    Cell* right;
    Cell* down;

    Cell():data(0),right(nullptr),down(nullptr){}

    Cell(int data, Cell* right=nullptr, Cell* down=nullptr):data(data),right(right), down(down){}

};

bool includes_negative(Cell*& column)
{
    while(column!=nullptr)
    {
        if(column->data<0)
            return true;

        column=column->down;
    }
    return false;
}

void delete_cell_after(Cell*& cell)
{
    Cell* temp = cell->right;
    cell->right=cell->right->right;
    delete temp;
}

void delete_column_after(Cell*& column)
{
    if(column==nullptr)
        return;
    delete_cell_after(column);
    delete_column_after(column->down);

}

void delete_leftest_column(Cell*& M)
{
    if(M==nullptr) //base case of the recursion
        return;

    delete_leftest_column(M->down); //go down until we can

        Cell* temp = M;
        M=temp->right;
        delete temp;
}
void deleteNegative(Cell*& M) //pointer towards the first cell
{
    if(M==nullptr)
        return;

    if(includes_negative(M))
        delete_leftest_column(M);

    Cell* column_top = M;
    while(column_top->right!=nullptr)
    {
        if(includes_negative(column_top->right))
            delete_column_after(column_top);

        else column_top = column_top->right;
    }

}
void print(Cell* m)
{
    if(m==nullptr)
        return;
    Cell* curr= m;
    while(curr!=nullptr)
    {
        cout<<curr->data<<' ';
        curr=curr->right;
    }
    cout<<endl;
    print(m->down);
}
int main()
{
    Cell* m1 = new Cell(9,nullptr,nullptr);
    Cell* m2 = new Cell(1);
    Cell* m3=new Cell(2);
    Cell* m4=new Cell(3);
    Cell* m5= new Cell(-1);
    Cell* m6 = new Cell(4);
    Cell* m7 = new Cell(5);
    Cell* m8 = new Cell(6);
    Cell* m9 = new Cell(7);

    m1->right = m2;
    m2->right = m3;
    m1->down = m4;
    m2->down = m5;
    m3->down = m6;

    m4->right = m5;
    m5->right = m6;
    m4->down = m7;
    m5->down = m8;
    m6->down =m9;

    m7->right = m8;
    m8->right = m9;

    print(m1);
    cout<<boolalpha<<includes_negative(m1)<<endl;
    cout<<boolalpha<<includes_negative(m2);
    delete_cell_after(m1);
    delete_cell_after(m4);
    delete_cell_after(m7);
    print(m1);
    return 0;
}
