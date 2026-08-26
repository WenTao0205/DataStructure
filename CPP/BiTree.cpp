#include <iostream>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void createBiTree(BiTree node) {
    char ch;
    cin >> ch;
    if(ch == '#') node = NULL;
    else {
        node = new BiTNode;
        node->data = ch;
        createBiTree(node->lchild);
        createBiTree(node->rchild);
    }
}

int main() {
    BiTree tree;
    createBiTree(tree);
}