#include <stdio.h>
#include <stdlib.h>
#define InitSize 100

typedef struct
{
    char *data;
    int MaxSize, Length;
} SeqList;

void InitList(SeqList *L)
{
    L->data = (char *)malloc(InitSize * sizeof(char));
    L->Length = 0;
    L->MaxSize = InitSize;
}

int main()
{
    SeqList L;
    InitList(&L);
    L.data[0] = 'a';
    printf("%c\n", L.data[0]);
}