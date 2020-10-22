#include<stdio.h>
#include<stdlib.h>
typedef struct tree {
    char ch;
    struct tree* lchild;
    struct tree* rchild;
}linkTree;
linkTree* CreateTree()//递归创建二叉树
{
    linkTree* t;
    char c;
    scanf_s("%c", &c);
    if (c == '/') {
        t = NULL;
    }
    else {
        t = (linkTree*)malloc(sizeof(linkTree));
        t->ch = c;
        t->lchild = CreateTree();
        t->rchild = CreateTree();
    }
    return t;
}
void pre_order(linkTree* t)//前序遍历
{
    if (t!=NULL)
    {
        printf("%c", t->ch);
        pre_order(t->lchild);
        pre_order(t->rchild);
    }
}
void mid_order(linkTree* t)//中序遍历
{
    if (t != NULL)
    {
        mid_order(t->lchild);
        printf("%c", t->ch);
        mid_order(t->rchild);
    }
}
void later_order(linkTree* t)//后序遍历
{
    if (t != NULL)
    {
        later_order(t->lchild);
        later_order(t->rchild);
        printf("%c", t->ch);
    }
}

void main()
{
    linkTree* t = CreateTree();//创建二叉树
    printf("该二叉树前序遍历为：\n");
    pre_order(t);
    printf("该二叉树中序遍历为：\n");
    mid_order(t);
    printf("该二叉树后序遍历为：\n");
    later_order(t);

}
