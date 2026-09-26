#include <iostream>
using namespace std;

struct DNode {
    char data;
    DNode *prev, *next;
};

void InitList(DNode *&L) 
{
    L = new DNode;
    L -> next = nullptr;
    L -> prev = nullptr;
};

bool ListInsert(DNode *&L, int i, char e) 
{
    DNode *p = L;
    int j = 0;
    while(p != nullptr && j < i - 1)
    {
        p = p -> next;
        j++;
    }

    if(p == nullptr)
        return false;
    
    DNode *s = new DNode;
    s -> data = e;
    if(p -> next == nullptr)
    {
        s -> prev = p;
        s -> next = nullptr;
        p -> next = s;
        return true;
    }
    s -> next = p -> next;
    s -> prev = p;
    p -> next = s;
    s -> next -> prev = s;
    return true;
};

bool ListDelete(DNode *&L, int i, char &e)
{
    DNode *p = L;
    int j = 0;
    while(p != nullptr && j < i - 1) {
        p = p -> next;
        j++;
    }
    if(p == nullptr)
        return false;
    
    DNode *s = p -> next;
    if(s == nullptr)
        return false;

    if(s -> next) 
        s -> next -> prev = p;
    p -> next = s -> next;
    e = s -> data;
    free(s);
    return true;
};

void PrintList(DNode *L)
{
    DNode *p = L -> next;
    while(p != nullptr)
    {
        cout << p -> data << "<—>";
        p = p -> next;
    }
    cout << "null" << endl;

    DNode *q = L -> next;
    while(q -> next != nullptr)
        q = q -> next;
    while(q != L){
        cout << q -> data << " ";
        q = q -> prev;
    }
    cout << endl;
};

int main() 
{
    // 测试Insert
    DNode *L;
    InitList(L);
    ListInsert(L, 1, 'a');
    ListInsert(L, 2, 'b');
    ListInsert(L, 3, 'c');
    ListInsert(L, 2, 'd');
    PrintList(L);

    // 测试Delete
    char e;
    ListDelete(L, 4, e);
    PrintList(L);
    cout << e << endl;
}