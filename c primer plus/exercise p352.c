

/////////////////////////////////////////////////////
// Ëæ»úÊýºÍÃ°ÅÝÅÅÐò
//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#include <stdlib.h>
//
//int  hundred_rand(int *arr);
//int  quick(int *arr);
//
//void main()
//{
//	int total[100];
//	hundred_rand(total);
//	sorted_quick(total);
//	for (int i = 0; i < 100; i++)
//	{
//		printf("%d  ", total[i]);
//	}
//	return 0;
//}
//
//int hundred_rand(int* arr)
//{
//	int randnum;
//	srand((unsigned int)time(0));
//	for (int i = 0; i < 100; i++)
//	{
//		*arr = rand()%100+1;
//		arr++;
//	}
//	return 0;
//}
//
//int sorted_quick(int* arr)
//{
//	int k;
//	for (int i = 0; i < 99; i++)
//		for (int j = i + 1; j <= 99; j++)
//		{
//			if (*(arr + i) < *(arr + j))
//			{
//				k = *(arr + i);
//				*(arr + i) = *(arr + j);
//				*(arr + j) = k;
//			}
//		}
//}
///////////////////////////////////////////////////////////

//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int ch;
//	FILE* fp;
//	fp = fopen("D:\\words.txt", "r");
//	while ((ch = getc(fp)) != EOF)
//	{
//		putchar(ch);
//	}
//}