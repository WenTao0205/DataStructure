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
    if (i < 1)
        return false;
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

    s -> next = p -> next;
    s -> prev = p;
    p -> next = s;
    if(s -> next)
        s -> next -> prev = s;
    return true;
};

bool ListDelete(DNode *&L, int i, char &e)
{
    if(i < 1) 
        return false;
    DNode *p = L;
    int j = 0;
    while(p != nullptr && j < i - 1) {
        p = p -> next;
        j++;
    }
    if(p == nullptr || p -> next == nullptr)
        return false;
    
    DNode *s = p -> next;
    if(s -> next) 
        s -> next -> prev = p;
    p -> next = s -> next;
    e = s -> data;
    delete s;
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

    // 逆向输出，测试prev
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
    ListDelete(L, 3, e);
    PrintList(L);
    cout << e << endl;
}