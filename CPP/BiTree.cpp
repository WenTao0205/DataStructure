#include <iostream>
using namespace std;

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int main() {
    int n = 1;
    while(n<=10) {
        BiTree node;
        node->data = n;
        n++;
    }
}