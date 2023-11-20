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
int ListInsert(LinkList &L,int i,int e)

{ LNode *p=L;

int j=0;

//补充完整，实现p指向第i-1个结点
for(j = 0; p && j < i-1; ++j)
{
    p = p->next;
}

if(!p||j>i-1)

{

printf("插入位置非法\n");

return 0;

}

LNode *s=new LNode();//新元素结点
    //补充完整，修改新结点的数据域，并建立其与前驱和后继的关系
    s->data = e;
    s->next = p->next;
    p->next = s;


return 1;

}
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
    ListCreate_F(L,5);

    
    
    ListPrint(L);

    //2.在第i个结点前插入新数据

    printf("依次输入插入位置和数据：");
    scanf("%d\n%d",&i,&x);
    ListInsert(L,i,x);

    ListPrint(L);

    // //3.调用ListDelete函数，删除位置i的节点;

    // printf("输入删除位置：");

    // //补充完整

    // ListPrint(L);

    // //4.调用ListMax函数，输出最大值；

    // //补充完整
    return 1;
}