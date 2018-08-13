#include<iostream>
using namespace std;

struct Box{
    int element;
    Box* next;
    Box(int _element,Box* _next):element(_element), next(_next){}
};

int count(Box* l,int x) //counts the number of times x is in the list
{
    int br=0;
    while(l)
    {
        if(l->element==x) br++;
        l=l->next;
    }

    return br;
}

void printList(Box *head)
{
    while(head)
    {
        cout<<head->element<<' ';
        head=head->next;
    }
    cout<<endl;
}

Box* range(int x, int y) //създава списък с елементи от х до у
{
    if(x>y) return nullptr;
    Box* head=new Box(x,nullptr);
    Box*prev=head;

    for(int num=x+1;num<=y;num++)
    {
        Box* curr=new Box(num,nullptr);
        prev->next=curr;
        prev=curr;
    }
    return head;
}

void removeAll(Box* &head, int x) //маха от списъка всички клетки със стойност х
{
    Box* prev=head;
    Box* curr = head->next;
    while(curr)
    {
        if(curr->element==x)
        {
            prev->next=prev->next->next;
        }
        curr=curr->next;
        prev=prev->next;
    }
}

void append(Box* &list1, Box* &list2) //конкатенация на 2 списъка
{
    if(!list1) list1=list2;
    else
    {
        Box* prev =list1;
    Box* last=list1->next;
    while(last)
    {
        last=last->next;
        prev=prev->next;
    }
    prev->next=list2;
    }

}
Box* concat(Box* l1, Box* l2)
{
    if(!l1) return l2;
    Box* head=new Box(l1->element, nullptr);
    Box* prev=head;
    l1=l1->next;
    while(l1->next)
    {
        Box* curr= new Box(l1->element, nullptr);
        prev->next=curr;
        prev=prev->next;
        l1=l1->next;
    }
    Box* curr= new Box(l1->element, nullptr);
    prev->next=curr;
    prev=prev->next;
    while(l2)
    {
         Box* curr= new Box(l2->element, l2->next);
    prev->next=curr;
    prev=prev->next;
    l2=l2->next;
    }
    return head;
}

int main()
{
    Box a(1, new Box(3, new Box(3, new Box(4,nullptr))));//making the list of boxes
//    cout<<"counting ";
//    cout<<count(&a,3);
Box*a1=range(6,10);
Box *b = range(1,5);
//printList(b);
//removeAll(b,3);
//printList(b);
//append(b,a1);
Box* c = concat(a1,b);
printList(c);
    return 0;
}
