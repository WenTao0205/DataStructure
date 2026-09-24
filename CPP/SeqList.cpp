#include <iostream>
#include <cstdlib>
#define InitSize 100
using namespace std;

typedef struct
{
    char *data;
    int MaxSize, Length;
} SeqList;

void InitList(SeqList &L)
{
    L.data = (char *)malloc(InitSize * sizeof(char));
    L.Length = 0;
    L.MaxSize = InitSize;
}

bool ListInsert(SeqList &L, int i, int e)
{
    if (i < 1 || i > L.Length + 1)
        return false;
    if (L.Length >= L.MaxSize)
        return false;
    for (int j = L.Length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.Length++;
    return true;
}

int main()
{
}