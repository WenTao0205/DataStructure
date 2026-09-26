#include <iostream>
using namespace std;

struct LNode
{
    char data;
    LNode *next;
};

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

LNode *LocateElem(LNode *L, char e)
{
    LNode *p = L -> next;
    while(p != nullptr && p -> data != e) 
    {
        p = p->next;
    }
    return p;
}

bool ListInsert(LNode *&L, int i, char e) // 声明类型：*指针 &引用  表达式：*解引用 &取地址
{
    LNode *p = L;
    int j = 0;
    while (j < i - 1 && p != nullptr)
    {
        p = p -> next;
        j++;
    }
    if (p == nullptr)
        return false;
    LNode *q = new LNode; // new操作符返回指针类型
    q -> data = e;
    q -> next = p -> next;
    p -> next = q;
    return true;
}

bool ListDelete(LNode *&L, int i, char &e) 
{
    LNode *p = L;
    int j = 0;
    while (j < i - 1 && p -> next != nullptr) 
    {
        p = p -> next;
        j++;
    }
    if (p -> next == nullptr || j > i - 1) 
        return false;
    LNode *d = p -> next;
    e = d -> data;
    p -> next = d -> next;
    d -> next = nullptr;
    free(d);
    return true;
}

void PrintList(LNode *L) 
{
    for(LNode *p=L->next;p!=nullptr;p=p->next)
        cout << p->data << "——>";
    cout << "null" << endl;
}

int main() {
    // 测试Init和Insert
    LNode *L;
    InitList(L);
    ListInsert(L, 1, 'a');
    ListInsert(L, 2, 'b');
    ListInsert(L, 3, 'c');
    ListInsert(L, 2, 'd');
    PrintList(L);

    // 测试Delete
    char e;
    ListDelete(L, 2, e);
    PrintList(L);
    cout << e << endl;

    // 测试Locate
    char a = LocateElem(L, 'b') ? LocateElem(L, 'b') -> data : '\0';
    char b = LocateElem(L, 'd') ? LocateElem(L, 'd') -> data : '\0';
    cout << a << endl;
    cout << b << endl;

    // 测试GetElem
    char c = GetElem(L, 3) ? GetElem(L, 3) -> data : '\0';
    char d = GetElem(L, 4) ? GetElem(L, 4) -> data : '\0';
    cout << c << endl;
    cout << d << endl;
}