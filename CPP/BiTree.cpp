#include <iostream>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void createBiTree(BiTree &node) {
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

void PreOrder(BiTree node) {
    if(node == NULL) return;
    cout << node->data;
    PreOrder(node->lchild);
    PreOrder(node->rchild);
}

void InOrder(BiTree node) {
    if(node == NULL) return;
    InOrder(node->lchild);
    cout << node->data;
    InOrder(node->rchild);
}

int main() {
    BiTree tree = NULL;
    createBiTree(tree);
    PreOrder(tree);
    cout << endl;
    InOrder(tree);
}