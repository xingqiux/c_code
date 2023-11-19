#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100

//顺序表定义
typedef struct{                   
	int *elem;
	int length;
}SqList;
/*
函数功能：构造一个空的顺序表L
返回值：构造成功返回1，失败返回0
*/
int init(SqList &L)
{
	L.elem=(int *)malloc(sizeof(int)*MAXSIZE);
	if(!L.elem)
		return 0;
	L.length=0;
	return 1;
}
/*
函数功能：位置i前插入数据e
返回值：插入成功返回1，失败返回0
*/
int insert(SqList &L, int i, int e)    
{
	if(i<1|| i>L.length+1)
	{
		printf("插入位置非法!\n");
		return 0;
	}
	if(L.length==MAXSIZE)
	{
		printf("顺序表空间已满!\n");
		return 0;
	}
	for (int a = L.length; a>i-1;a--)
	{
		L.elem[a] = L.elem[a-1];
	}
	L.elem[i-1] = e;
	L.length++;
	return 1;	
}
/*
函数功能：删除位置i的数据
返回值：删除成功返回1，失败返回0
*/
int del(SqList &L, int i)          
{
	if(i<1 || i>L.length)
	{
		printf("删除位置非法!\n");
		return 0;
	}
	for(i = i-1;i<L.length-1;i++)
	{
		L.elem[i] = L.elem[i+1];
	}
	L.length--;
	return 1;
}
//函数功能：利用循环输出顺序表中的所有数据
void print(SqList L)  
{
	for (int i = 0;i<L.length;i++)
	{
		printf("%d ",L.elem[i]);
	}
}
int main()
{

	SqList L;
	 int i=1,x,e;
	// //1.调用init函数构造一个空顺序表L;	
	init(L);
	// //2.从键盘输入数据插入顺序表(建表)，以-1结束;
	printf("请依次输入顺序表的元素(以-1结束):");
	scanf("%d",&x);
	while (L.length != MAXSIZE &&x != -1 )
	{
		insert(L,i++,x);
		scanf("%d",&x);
	}
	print(L);

    printf("输入插入位置 元素:");
	scanf("%d %d",&i,&e);
	insert(L, i,e);   
	print(L);

	printf("输入删除位置:");
	scanf("%d",&i);
	if(	del(L,i))
	{
		printf("删除成功\n");
		print(L);
	}

	return 1;
}
