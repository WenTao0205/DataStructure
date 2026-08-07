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
    cout << "-----------------------\n";
    for (int i = 0; i < 10; i++)
        printf("&L.data[%d]=%p\n", i, &L.data[i]);
}

int main()
{
    SqList L;
    InitList(L);
    printf("L.data的地址计算：\n");
    printf("&L.data=%p\n", &L.data);
    printf("&L.data+1=%p\n", &L.data + 1);
    printf("-----------------------\n");
    printf("L.data[0]的地址计算：\n");
    printf("&L.data[0]%p\n", &L.data[0]);
    printf("&L.data[0]+1=%p\n", &L.data[0] + 1);
    printf("&L.data[1]=%p\n", &L.data[1]);
    printf("-----------------------\n");
    printf("int类型所占字节：\n");
    printf("int space=%lu\n", sizeof(int));

    printAddress(L);
}