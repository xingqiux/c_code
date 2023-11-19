#include<stdio.h>
#define MAXQSIZE  50   //最大队列长度
typedef  struct
{
	char* base;          //基地址 
	int  front;          //队头指针
	int  rear;           //队尾指针
} SqQueue;
//初始化队列
int InitQueue(SqQueue& Q)
{
	Q.base = new char[MAXQSIZE];
	if (!Q.base) return 0;
	Q.front = Q.rear = 0;
	return 1;
}
//将元素e入队
int EnQueue(SqQueue& Q, char e)
{
	if ((Q.rear + 1 )% MAXQSIZE == Q.front) return 0;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;	//这个取余就说明了如果超过了MAX的范围直接就从0开始，作为一个循环队列
	return 1;
}
//将队头元素出队，并保存在参数e中。
int DeQueue(SqQueue& Q, char& e)
{
	if (Q.front == Q.rear) return 0;
	 e = Q.base[Q.front];
	 Q.front = (Q.front+1)%MAXQSIZE;
	return	1;
}

//返回队头元素
char GetHead(SqQueue Q)
{
	return	Q.base[Q.front];
}
//求队列长度（即元素个数）
int LenQueue(SqQueue Q)
{
	return	(Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
}
//按照队头到队尾顺序输出队列元素
void Print(SqQueue Q)
{
	int temp = Q.front;
	while (temp != Q.rear)
	{
		printf("%c ", Q.base[temp]);
		temp = (temp + 1) % MAXQSIZE;	//这个取余就说明了如果超过了MAX的范围直接就从0开始，作为一个循环队列
	}
}
int main()
{
	SqQueue q;
	char a;
	InitQueue(q);
	EnQueue(q, 'a');
	EnQueue(q, 'b');
	EnQueue(q, 'c');
	Print(q);
	DeQueue(q, a);
	printf("\n");
	Print(q);
	printf("\n 当前头节点是 %c", GetHead(q));
	printf("\n 当前队长度是 %d", LenQueue(q));
	
	return	1;
}






