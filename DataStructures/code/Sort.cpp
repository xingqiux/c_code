// 排序
// 一、实验目的
// 1.熟悉并掌握各种排序方法的设计思路。
// 2.掌握各种具体排序算法在计算机上的实现。
// 3.掌握各种排序方法的性能比较。
// 二、实验内容
// 输入同样一组整型数据,作为待排序记录的关键字序列，进行如下排序（递增）
// (1)直接插入排序
// (2)折半插入排序
// (3)冒泡排序
// (4)简单选择排序
 
#include<stdio.h>
#define MAXSIZE 50
typedef struct{
	int r[MAXSIZE];
	int length;
}SqList;
void PrintList(SqList l);//输出顺序表的所有元素


//直接插入排序
void InsertSort(SqList l)
 {
    //  在这个程序中是以l.r[1]为数据开始的位置
    // 为O(n^2)
    int i,j;
    for (int i = 2 ; i <= l.length ;i++) //  1为元素1 所以length 不需要-1
    {
        if (l.r[i] < l.r[i-1])  //这一段说的是如果当前的这个数和前面一个数并不构成递增序列，就说明要插到前面去
        {
            l.r[0] = l.r[i];
            l.r[i] = l.r[i-1];
            for (int j = i - 2;l.r[0]<l.r[j];j--)
            {
                l.r[j-1] = l.r[j];    
            }
            l.r[j+1] = l.r[0];  //为什么这里加一?
        }
       // PrintList(l);
    }
    
}
//折半插入排序
void BinInsertSort(SqList l) {
    int i, j, low, high, mid, temp;
    for (i = 1; i < l.length; i++) {
        temp = l.r[i];
        low = 0;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (temp < l.r[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= low; j--) {
            l.r[j + 1] = l.r[j];
        }
        l.r[low] = temp;
    }
PrintList(l);

}
//冒泡排序
void BubbleSort(SqList l)
{
    int i, j, temp;
    for (i = 0; i < l.length - 1; i++) {
        for (j = 0; j < l.length - i - 1; j++) {
            if (l.r[j] > l.r[j + 1]) {
                temp = l.r[j];
                l.r[j] = l.r[j + 1];
                l.r[j + 1] = temp;
            }
        }
    }

	PrintList(l);
}
//简单选择排序
void SelectSort(SqList l) {
    int i, j, min, temp;
    for (i = 0; i < l.length - 1; i++) {
        min = i;
        for (j = i + 1; j < l.length; j++) {
            if (l.r[j] < l.r[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = l.r[i];
            l.r[i] = l.r[min];
            l.r[min] = temp;
        }
    }
	PrintList(l);
}
//输出顺序表各记录
void PrintList(SqList l)
{
	for(int i=1;i<=l.length;i++)
		printf("%3d",l.r[i]);
	printf("\n");
}
int main()
{
	SqList l;
	printf("请输入记录数:");
	scanf("%d",&l.length);
	printf("请依次输入关键字:");
	for(int i=1;i<=l.length;i++)
		scanf("%d",&l.r[i]);
	InsertSort(l);
	// BubbleSort(l);
	// SelectSort(l);
	// BinInsertSort(l);
    return 1;
}
