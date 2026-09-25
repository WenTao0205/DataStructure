#include <iostream>
using namespace std;

struct LNode
{
    char data;
    LNode *next;
};

using LinkList = LNode *;

bool InitList(LNode *&L)
{
    L = new LNode;
    L->next = nullptr;
    return true;
}

int Length(LNode *L)
{
    int length = 0;
    LNode *p = L;
    while (p->next != nullptr)
    {
        p = p->next;
        length++;
    }
    return length;
}

LNode *GetElem(LNode *L, int i)
{
    LNode *p = L;
    int j = 0;
    while (p != nullptr && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}