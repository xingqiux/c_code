#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
    int data;   //数据域
    struct LNode* next; //指针域
}LNode,*LinkList;

/*采用前插法建立n个元素的单链表*/
void ListCreate_F(LinkList &L,int n)
{
    L=new LNode;
    L->next = NULL;
    LNode *p;
    for (int i = 0 ; i < n ; i++)
    {
        p = new LNode;
        scanf("%d",&p->data);
        p->next = L->next;
        L->next = p;
        
    }
}
/*在第i个结点前插入元素e，插入成功返回1，失败返回0*/
/*删除第i个结点,删除成功返回1，失败返回0*/

/*输出链表中所有结点的数据值*/
void ListPrint(LinkList L)
{
    if (!L) return;
    while (L -> next)
    {
        L = L->next;
        printf("%d ",L->data);
    }
}
/*返回链表中数据值最大的存储位置*/

int main()
{
    LinkList L;

    int i,x;

    //1.采用前插法创建具有5个元素的单链表

     printf("采用前插法输入链表的5个数据:");
    // LNode *p = (LNode*)malloc(sizeof(LNode));
    // scanf("%d",&p->data);
    // printf("%d",p->data);
    ListCreate_F(L,1);

    
    
    ListPrint(L);

    // //2.在第i个结点前插入新数据

    // printf("依次输入插入位置和数据：");

    // //补充完整

    // ListPrint(L);

    // //3.调用ListDelete函数，删除位置i的节点;

    // printf("输入删除位置：");

    // //补充完整

    // ListPrint(L);

    // //4.调用ListMax函数，输出最大值；

    // //补充完整
    return 1;
}