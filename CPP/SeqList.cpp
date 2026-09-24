#include <iostream>
#define InitSize 100
using namespace std;

template <typename T>
struct SeqList
{
    T *data;
    int MaxSize, Length;

    void InitList()
    {
        L.data = new T[InitSize];
        Length = 0;
        L.MaxSize = InitSize;
    }

    int Length()
    {
        return Length;
    }

    int LocateElem(T e)
    {
    }

    T GetElem(SeqList L, int i)
    {
    }

    bool ListInsert(int i, T e)
    {
        if (i < 1 || i > Length + 1)
            return false;
        if (Length >= L.MaxSize)
            return false;
        for (int j = Length; j >= i; j--)
            L.data[j] = L.data[j - 1];
        L.data[i - 1] = e;
        Length++;
        return true;
    }

    T ListDelete(int i, T &e)
    {
    }

    void PrintList()
    {
    }

    bool Empty()
    {
    }

    bool DestroyList()
    {
    }
};

int main()
{
}