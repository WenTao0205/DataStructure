#include <iostream>
#include <cstdlib>
#include <cstdio>
#define MaxSize 50
using namespace std;

typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

void InitList(SqList L)
{
    L.length = 0;
}

bool ListInsert(SqList L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

void printAddress(SqList L)
{
    cout << "-----------------------\n"
         << endl;
    char buffer[80];
    for (int i = 0; i < 10; i++)
        snprintf(buffer, 80, "L.data[%d]=%p\n", i, &L.data[i]);
}

int main()
{
    SqList L;
    InitList(L);
    printAddress(L);
}