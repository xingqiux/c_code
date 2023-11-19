#include <stdio.h>

//二分查找法：
//每次取中间的数进行比较，如果大了的话，就舍弃这个中间值后面的数，如果小了就舍弃中间值前面的数，依次循环，得出这个数的位置
//只能在一个顺序数组中才能使用
//
//int search();
//
//int main()
//{
//	int nums[] = { 1,2,3,5,7,11,13,17,19,23 };
//	printf("输入要查找的数字");
//	int b;
//	scanf("%d", &b);
//	printf("%d的位置是%d",b,search(nums,b));
//	//printf("%d,%d,%d", nums[0], nums[1], nums[2]);
//}
//
//int search(int nums[], int b)
//{
//	int low = 0;
//	int high = 9;
//	int mid;
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		if (nums[mid] == b)
//		{
//			return mid;
//		}
//		if (nums[mid] > b)
//		{
//			high = mid - 1;
//		}
//		else
//		{
//			low = mid + 1;
//		}
//	}
//	return -1;
//}

//指针学习代码
//int main()
//{
//	int a = 11;
//	char c = 'w';
//	int* pa = &a;      //这里的pa是一个指针类型的变量
//	printf("%p\n", pa);    //%p是指针的转换标志
//	*pa = 70;
//	printf("%d\n", a);
//	return 0;
//}
//
////关于结构体的学习以及指针的使用
//struct Book
//{
//	char name[20];
//	float pay;
//	char id[20];
//};
//
//int main()
//{
//	struct Book text = { "钢铁怎样炼成的", 55.9,"335566600"};
//	printf("%s  %lf  %s \n", text.name, text.pay, text.id);    // 结构体变量.成员变量
//	struct Book* pa = &text;
//	printf(" % s %lf % s \n", (*pa).name, (*pa).pay, (*pa).id);   //   使用指针变量来只想具体值（较麻烦）
//	printf("%s  %lf  %s \n", pa->name, pa->pay, pa->id);                    //（结构体的指针）"->"来指向一个结构体的具体值
//	return 0;
//}

//
////(基础代码)输出1-100内奇数
//
//void main()
//{
//	int a = 0;
//	while (a <=100)
//	{
//		if (1 == a % 2)
//		{
//			printf("%d\n",a);
//		}
//		a++;
//	}
//
//}


//快速排序代码c语言实现
#include <stdlib.h>
#include <time.h>

int main()
{
	int nums[10];
	srand((unsigned int)time(0));   //?只需要播种一次，但这个播种是什么逻辑没明白
	for (int i=0; i < 10; i++)
	{
		nums[i] = rand() %100 ;         //"%100"是将随机生成的数字取模0-99之间
		printf("%d ", nums[i]);
	}
    quicksort(nums);
	//printf("\n");
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d ", nums[i]);
	//}
	//
}


int  quicksort(int arr[])             
{
	int len=sizeof(arr) / sizeof(arr[0]);     //这里使用sizeof()计算出arr[]占有内存的字节，然后除以一个元素占有的字节长度
	int less[10];             //定义比基准值大的数组与小的数组
	int greater[10];
	if (len<=1)
	{
		return arr[0];           //基线条件
	}
	else                          //递归条件
	{
		int a = 0;                 //less和greater的0下标位置
		int b = 0;
		for (int i = 1; i <= len; i++)
		{
			if (arr[i]<arr[0])
			{
				less[a] = arr[i];
				a++;
			}
			else
			{
				greater[b] = arr[i];
				b++;
			}
		}
		return quicksort(less) + arr[0] + quicksort(greater);
}