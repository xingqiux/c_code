#include <stdio.h>

typedef struct BiNode{
	char data;
	struct BiNode *lchild , * rchild;
}BiNode,*BiTree;

void CreateTree(BiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if (ch == '#')
		T=NULL;
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
	if (T == NULL) return;
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
	if (T == NULL) return;
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
	if (T == NULL) return;
	else 
	{

		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c",T->data);
	}
}

//判断两颗树是否相等，相等返回1，不等返回0
int IsEqual(BiTree T1,BiTree T2)
{
	if(T1 == NULL && T2 == NULL) return 1;
	if (T1 && T2 )
	{
		if (T1->data == T2->data)
			if (IsEqual(T1->lchild ,T2->lchild))
				if (IsEqual(T1->rchild ,T2->rchild))
					return 1;
	}
	return 0;
}

//寻找孩子结点child的双亲结点，返回双亲结点的位置
BiNode* FindParent(BiTree T, char child)
{
    // 如果树为空，则返回NULL
    if (T == NULL) return NULL;

    // 如果当前节点的左子节点或右子节点的数据等于child，那么当前节点就是我们要找的父节点
    if((T->lchild && T->lchild->data == child) || (T->rchild && T->rchild->data == child)) 
    {
        return T;
    }

    // 在左子树中递归查找
    BiNode* left = FindParent(T->lchild, child);
    // 如果在左子树中找到了父节点，那么就返回这个节点
    if(left != NULL) return left;

    // 在右子树中递归查找
    BiNode* right = FindParent(T->rchild, child);
    // 如果在右子树中找到了父节点，那么就返回这个节点
    if(right != NULL) return right;

    // 如果在整个树中都没有找到父节点，那么返回NULL
    return NULL;
}




int main()
{
    BiTree T1,T2,f;
    char x;
    printf("建树，请输入T1的先序序列:");
    CreateTree(T1);
    getchar();//建完树之后还要把最后的\n回车给消除
    printf("建树，请输入T2的先序序列：");
    CreateTree(T2);
    getchar();//建完树之后还要把最后的\n回车给消除
    printf("T1先序遍历序列为：");
    PreOrder(T1);
    printf("\nT1中序遍历序列为：");
    InOrder(T1);
    printf("\nT1后序遍历序列为：");
    PostOrder(T1);
    if(IsEqual(T1,T2))
    {
        printf("\nT1和T2是相等的两棵树");
    }else printf("\nT1和T2不是相等的两棵树");
    printf("\n请输入一个字符：");
    scanf("%c",&x);
    f = FindParent(T1,x);
    printf("%c在T1树中的双亲节点为：%c",x,f->data);
    return 1;
}