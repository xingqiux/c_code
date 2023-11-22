#include<stdio.h>

#define MAXSIZE 100

typedef struct
{
    int *base;//栈底指针
    int *top;//栈顶指针
    int stacksize;//栈可用的最大容量
}SqStack;

//初始化空栈，链栈时注意修改
int InitStack(SqStack &S)
{
    S.base=new int[MAXSIZE];
    if(!S.base)return 0;
    S.top=S.base;
    S.stacksize=MAXSIZE;
    return 1;
}

//将元素e进栈
int Push(SqStack &S,int e)
{
//进栈时，顺序栈需要判断是否栈满，链栈不需要
}

//将栈顶元素出栈并存入参数e中
int Pop(SqStack &S,int &e)
{
//出栈时，顺序栈和链栈都需要判断是否栈空，非空时才能出栈
}

//将十进制数n转换为二进制数并输出
void conversion(SqStack S,int n)
{
/*

(1)当十进制数n非零时，循环执行以下操作：

把n与2求余得到的余数压入栈S；

n更新为n与2的商。

(2)当栈S非空时，循环执行以下操作：

弹出栈顶元素e并输出e。

*/

}

void main()

{

SqStack S;

int n;

InitStack(S);

printf("输入一个整数:");

scanf("%d",&n);

printf("%d转化为二进制为:",n);

conversion(S,n);

}