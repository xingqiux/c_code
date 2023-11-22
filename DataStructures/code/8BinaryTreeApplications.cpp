#include<stdio.h>

//定义二叉链表结点

typedef struct BiNode{
    char data;
    struct BiNode *lchild,*rchild; //左右孩子指针
}BiNode,*BiTree;

//先序遍历的顺序建立二叉树

void CreateTree(BiTree &T)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#') T=NULL; //递归结束，建空树
    else
    {
        T = new BiNode;
        T->data = ch;
        CreateTree(T->lchild);
        CreateTree(T->rchild);
    }
}

//先序遍历二叉树T,输出序列

void PreOrder(BiTree T)
{
    if (!T) return ;
    else 
    {
        printf("%c",T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//中序遍历二叉树T,输出序列

void InOrder(BiTree T)
{
    if (!T) return ;
    else 
    {
        InOrder(T->lchild);
        printf("%c",T->data);
        InOrder(T->rchild);
    }
}

//后序遍历二叉树T,输出序列

void PostOrder(BiTree T)
{
    if (!T) return ;
    else 
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c",T->data);
    }
}

//求二叉树的深度
int Depth(BiTree &T)
{
    //当二叉树为空时，节点返回0;
    if (T == NULL) return 0;
    else 
    {
        //递归获取左节点和右节点的深度，然后将左右节点深度最大的那一个返回然后加一
        int Ldep = Depth(T->lchild);
        int Rdep = Depth(T->rchild);
        return ( Ldep>Rdep ? Ldep : Rdep)+1;
    }
}

//求二叉树的结点总数
int NodeCount(BiTree T)
{ // 如果二叉树为空，节点总数为0
    if (T == NULL) return 0;
    else 
    {
         // 否则，节点总数为1（当前节点）加上左子树和右子树的节点总数
        return 1+NodeCount(T->lchild)+NodeCount(T->rchild);
    }
}

//求二叉树的叶子结点数
int LeafCount(BiTree T)
{
    //如果为空节点就返回0
    if (T == NULL)return 0;
    //如果左右为空节点说明是叶节点返回1
    else if (T->lchild == NULL && T->rchild == NULL)return 1;
    //如果不是叶节点，那就将左子树的叶节点和右子树的叶节点加起来
    else return LeafCount(T->lchild)+LeafCount(T->rchild);
}


//求二叉树度为1的结点数

//一个节点的度可以是0、1或2，这取决于它有多少个子节点。
// 如果一个节点没有子节点，那么它的度就是0，我们也称这样的节点为叶子节点。
// 如果一个节点有一个子节点，那么它的度就是1。如果一个节点有两个子节点，
// 那么它的度就是2。这就是"度"的含义。
int Du1(BiTree T)
{
    if (T == NULL) return 0;    //如果二叉树为空，度为1的节点数为0
    else 
    {
        int count = 0;
        //如果左子树或右子树只有一个不空，那么度就为1
        if ((T->lchild != NULL && T->rchild == NULL) 
            || (T->lchild == NULL && T->rchild != NULL))
                count = 1;
         //返回当前节点的计数（如果它的度为1则为1，否则为0）加上左子树和右子树中度为1的节点数
        return count +Du1(T->lchild) + Du1(T->rchild);
    }
}

//求二叉树度为2的结点数
int Du2(BiTree T)
{
    if (T == NULL)return 0;
    else 
    {
        int count = 0;
        if (T->lchild != NULL && T->rchild != NULL) count = 1;
        return count + Du2(T->lchild)+Du2(T->rchild);
    }
}

//交换二叉树每个结点的左孩子和右孩子

void ChangeLR(BiTree &T)
{
    if (T == NULL ) return ;
    else 
    {
        ChangeLR(T->lchild);
        ChangeLR(T->rchild);
        BiTree temp;
        temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}

int main()
{

    BiTree T;
    printf("建树,请输入T的先序序列:");  //AB#DF###CEG##H###创建节点算出来得到这个
    CreateTree(T);

    printf("先序遍历序列为:");
    PreOrder(T);
    printf("\n中序遍历序列为:");
    InOrder(T);
    printf("\n后序遍历序列为:");
    PostOrder(T); 

    printf("\n总结点数为:%d",NodeCount(T));
    printf("\n深度为:%d",Depth(T));
    printf("\n叶子节点数为:%d",LeafCount(T));
    printf("\n度为1节点数为:%d",Du1(T));
    printf("\n度为2节点数为:%d",Du2(T));

    ChangeLR(T);
    printf("\n交换左右子树之后先序遍历序列为:");
    PreOrder(T);
    printf("\n交换左右子树之后先序遍历序列为:");
    InOrder(T);
    return 1;
}