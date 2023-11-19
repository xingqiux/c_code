////这个程序输入一个数字，如果是素数就直接提示你是素数，但如果不是素数就返回给你一个他的约数
//
//
//#define _CRT_SECURE_NO_WARNINGS 
//# include <stdio.h>
//#include <stdbool.h>
//
//int main(void)
//{
//	unsigned long num;
//	unsigned long div;
//	bool isPrime;
//	printf("输入任何一个数字   ");
//	printf("输入q 停止\n");
//	while (scanf("%lu", &num) == 1)
//	{
//		for (div = 2,isPrime = true; (div * div) <= num;div++) 
//		{
//			if (num % div == 0)
//			{
//				if ((div * div) != num)
//					printf("%lu 关于 %lu 的的约数是%lu\n", num, div, num / div);
//				else
//					printf("%lu is divisible by %lu \n", num, div);
//				isPrime = false;
//			}
//		}
//		if (isPrime)
//			printf("%lu 是素数", num);
//		printf("请输入另一个数字");
//		printf("   按q退出");
//	}
//	printf("结束");
//	return 0;
//}
