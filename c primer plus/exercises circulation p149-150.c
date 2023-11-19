#define _CRT_SECURE_NO_WARNINGS 
////编写一个包含26个小写字母的数组并打印出来
//#include <stdio.h>
//#include <stdlib.h>
//
//void main()
//{
//	char arr[26];
//	int a;
//	for (a = 'a'; a <= 'z'; a++)
//	{
//		arr[a - 'a'] = a;
//	}
//	for (int i = 0; i <= sizeof(arr)/1; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	printf("\n");
//}

////打印图形
////$
////$$
////$$$
////$$$$
////$$$$$
//#include <stdio.h>
//
//int main()
//{
//	for (int i = 0; i <= 4; i++)
//	{
//		for (int j = 0; j < i + 1; j++)
//			printf("$");
//		printf("\n");
//	}
//}


////打印图形
////F
////FE
////FED
////FEDC
////FEDCB
////FEDCBA
//#include <stdio.h>
//
//void main()
//{
//	for (int i = 0; i <= 5; i++)
//	{
//		for (char j = 'F', x = j-i; j >= x; j--)   //这里的x利用了for循环初始化只运行一次的特性，定义了char类型的x
//		{
//			printf("%c", j);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}


////打印图形
////A
////BC
////DEF
////GHIJ
////KLMNO
////PQRSTU
//#include <stdio.h>
//
//void main()
//{
//	char x = 'A';
//	for (int i = 0; i < 6; i++)
//	{
//		for (char j = 0; j <= i; j++)
//		{
//			printf("%c", x);
//			x++;
//		}
//		printf("\n");
//	}
//}


////用户输入大写字母，如“E”时，打印
////    A
////   ABA
////  ABCBA
//// ABCDCBA
////ABCDEDCBA
//#include <stdio.h>
//
//void main()
//{
//	char user;
//	char l;
//	printf("输入大写字母");
//	scanf("%c", &user);
//	for (char i = 'A'; i <= user; i++)
//	{
//		for (int j = 0,x=user-i; j < x; j++)
//			printf(" ");
//		for (char k = 'A'; k <= i; k++)
//		{
//			printf("%c", k);
//			l = k;
//		}
//		for (l-=1; l >= 'A'; l--)
//			printf("%c", l);
//		printf("\n");
//	}
//}

////用户输入一个起始值和一个结束值，打印从起始值到结束值中间的所有整数的平方和立方的表格
//#include <stdio.h>
//
//int square(int a);
//int cube(int a);
//
//void main()
//{
//	int a, b;
//	printf("输入一个起始值和一个结束值\n");
//	scanf("%d", &a);
//	scanf("%d", &b);
//	printf("整数   平方   立方\n");
//	for (a; a <= b; a++)
//	{
//		printf("   %d     ", a);
//		printf("%d     ",square(a));
//		printf("%d\n", cu be(a));
//	}
//}
//
//int square(int a)
//{
//	return a * a;
//}
//
//int cube(int a)
//{
//	return a * a * a;
//}
//
// 
////向数组中输入8个数字然后逆向输出
//#include <stdio.h>
//
//int main(void)
//{
//	int arr[8];
//	for (int i = 0; i < 8;i++)
//		scanf("%d",&arr[i]);
//	for (int j = 7; j > -1; j--)
//		printf("%d", arr[j]);
//}


////乘方函数和do while 循环打印
//#include <stdio.h>
//
//int power(int a);
//
//int main()
//{
//	int arr[8];
//	int a = 0;
//	for (int i = 0; i < 8; i++)
//		arr[i] = power(i);
//	do
//	{
//		printf("%d\n",arr[a]);
//		a++;
//	} while (a < 8);
//}
//
//int power(int a)
//{
//	int towpower = 1;
//	for (int i = 0; i < a; i++)
//	{
//		towpower *= 2;
//	}
//	return towpower;
//}
//
//
//
//#include <stdio.h>
//
//void main()线稿
//{
//	double arr1[8], arr2[8];  /*如果要用scanf输入一个double类型的浮点数需要在f,e,g,a 前面加上l*/
//	for (int i = 0; i < 8; i++)
//	{
//		printf("输入第一个数组的第%d的值   ", i);
//		scanf("%lf", &arr1[i]);
//	}
//	arr2[0] = arr1[0];
//	for (int i = 1; i < 8; i++)
//		arr2[i] = arr2[i - 1] + arr1[i];
//
//	printf("\n\n第一个数列是  ");
//	for (int i = 0; i < 8; i++)
//		printf("%f  ", arr1[i]);
//	printf("\n\n第二个数列是  ");
//	for (int i = 0; i < 8; i++)
//		printf("%f  ", arr2[i]);
//}