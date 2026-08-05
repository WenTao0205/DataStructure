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

int main()
{
    SeqList L;
    InitList(L);
    L.data[0] = 'a';
    cout << "L.data[0]: " << L.data[0] << endl;
}