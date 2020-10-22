#include<stdio.h>
#include<stdlib.h>

int depth = 0;

typedef struct node {
    char ch;
    struct node* lchild, * rchild;
}linkTree;

linkTree* createTree()
{
    linkTree* t;
    char temp;
    scanf_s("%c", &temp);
    if (temp == '#') {
        t = NULL;
    }
    else {
        t = (linkTree*)malloc(sizeof(linkTree));
        t->ch = temp;
        t->lchild = createTree();
        t->rchild = createTree();
    }
    return t;
}

int preOrder(linkTree* t)
{
    if (t != NULL) {
        printf("%c", t->ch);
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}

int inOrder(linkTree* t)
{
    if (t != NULL) {
        inOrder(t->lchild);
        printf("%c", t->ch);
        inOrder(t->rchild);
    }
}

int postOrder(linkTree* t)
{
    if (t != NULL) {
        postOrder(t->lchild);
        postOrder(t->rchild);
        printf("%c", t->ch);
    }
}

int treeDeep(linkTree* t, int level)
{
    if (t) {
        if (level > depth) {
            depth = level;
        }
        treeDeep(t->lchild, level + 1);
        treeDeep(t->rchild, level + 1);
    }
}

int main()
{
    linkTree* t = createTree();
    int level = 1;
    printf("\n");
    preOrder(t);
    printf("\n");
    inOrder(t);
    printf("\n");
    postOrder(t);
    printf("\n");
    treeDeep(t, level);
    printf("depth:%d", depth);
    system("pause");
    return 0;
}