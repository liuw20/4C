#include<stdio.h>
#include<stdlib.h>
typedef struct tree {
    char ch;
    struct tree* lchild;
    struct tree* rchild;
}linkTree;
linkTree* CreateTree()//�ݹ鴴��������
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
void pre_order(linkTree* t)//ǰ�����
{
    if (t!=NULL)
    {
        printf("%c", t->ch);
        pre_order(t->lchild);
        pre_order(t->rchild);
    }
}
void mid_order(linkTree* t)//�������
{
    if (t != NULL)
    {
        mid_order(t->lchild);
        printf("%c", t->ch);
        mid_order(t->rchild);
    }
}
void later_order(linkTree* t)//�������
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
    linkTree* t = CreateTree();//����������
    printf("�ö�����ǰ�����Ϊ��\n");
    pre_order(t);
    printf("�ö������������Ϊ��\n");
    mid_order(t);
    printf("�ö������������Ϊ��\n");
    later_order(t);

}
