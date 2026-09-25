#include <iostream>
#define InitSize 100
using namespace std;

typedef struct
{
    int *data;
    int length, MaxSize;
} SeqList;

void InitList(SeqList &L)
{
    L.data = new int[InitSize];
    L.length = 0;
    L.MaxSize = InitSize;
}

int Length(SeqList L)
{
    return L.length;
}

int LocateElem(SeqList L, int e)
{
    for (int i = 0; i < L.length; i++)
        if (e == L.data[i])
            return i + 1;
    return -1;
}

int GetElem(SeqList L, int i)
{
    if (i < 1 || i > L.length)
        return -1;
    return L.data[i - 1];
}

bool ListInsert(SeqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= L.MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SeqList &L, int i, int &e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

void PrintList(SeqList L)
{
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
}

bool Empty(SeqList L)
{
    return L.length == 0;
}

void DestoryList(SeqList &L)
{
    free(L.data);
    L.length = 0;
    L.MaxSize = 0;
}