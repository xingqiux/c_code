#include<stdio.h>
#define MAXQSIZE  50   //�����г���
typedef  struct
{
	char* base;          //����ַ 
	int  front;          //��ͷָ��
	int  rear;           //��βָ��
} SqQueue;
//��ʼ������
int InitQueue(SqQueue& Q)
{
	Q.base = new char[MAXQSIZE];
	if (!Q.base) return 0;
	Q.front = Q.rear = 0;
	return 1;
}
//��Ԫ��e���
int EnQueue(SqQueue& Q, char e)
{
	if ((Q.rear + 1 )% MAXQSIZE == Q.front) return 0;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;	//���ȡ���˵�������������MAX�ķ�Χֱ�Ӿʹ�0��ʼ����Ϊһ��ѭ������
	return 1;
}
//����ͷԪ�س��ӣ��������ڲ���e�С�
int DeQueue(SqQueue& Q, char& e)
{
	if (Q.front == Q.rear) return 0;
	 e = Q.base[Q.front];
	 Q.front = (Q.front+1)%MAXQSIZE;
	return	1;
}

//���ض�ͷԪ��
char GetHead(SqQueue Q)
{
	return	Q.base[Q.front];
}
//����г��ȣ���Ԫ�ظ�����
int LenQueue(SqQueue Q)
{
	return	(Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
}
//���ն�ͷ����β˳���������Ԫ��
void Print(SqQueue Q)
{
	int temp = Q.front;
	while (temp != Q.rear)
	{
		printf("%c ", Q.base[temp]);
		temp = (temp + 1) % MAXQSIZE;	//���ȡ���˵�������������MAX�ķ�Χֱ�Ӿʹ�0��ʼ����Ϊһ��ѭ������
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
	printf("\n ��ǰͷ�ڵ��� %c", GetHead(q));
	printf("\n ��ǰ�ӳ����� %d", LenQueue(q));
	
	return	1;
}






