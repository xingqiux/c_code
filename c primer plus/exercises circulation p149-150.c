#define _CRT_SECURE_NO_WARNINGS 
////��дһ������26��Сд��ĸ�����鲢��ӡ����
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

////��ӡͼ��
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


////��ӡͼ��
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
//		for (char j = 'F', x = j-i; j >= x; j--)   //�����x������forѭ����ʼ��ֻ����һ�ε����ԣ�������char���͵�x
//		{
//			printf("%c", j);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}


////��ӡͼ��
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


////�û������д��ĸ���硰E��ʱ����ӡ
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
//	printf("�����д��ĸ");
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

////�û�����һ����ʼֵ��һ������ֵ����ӡ����ʼֵ������ֵ�м������������ƽ���������ı��
//#include <stdio.h>
//
//int square(int a);
//int cube(int a);
//
//void main()
//{
//	int a, b;
//	printf("����һ����ʼֵ��һ������ֵ\n");
//	scanf("%d", &a);
//	scanf("%d", &b);
//	printf("����   ƽ��   ����\n");
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
////������������8������Ȼ���������
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


////�˷�������do while ѭ����ӡ
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
//void main()�߸�
//{
//	double arr1[8], arr2[8];  /*���Ҫ��scanf����һ��double���͵ĸ�������Ҫ��f,e,g,a ǰ�����l*/
//	for (int i = 0; i < 8; i++)
//	{
//		printf("�����һ������ĵ�%d��ֵ   ", i);
//		scanf("%lf", &arr1[i]);
//	}
//	arr2[0] = arr1[0];
//	for (int i = 1; i < 8; i++)
//		arr2[i] = arr2[i - 1] + arr1[i];
//
//	printf("\n\n��һ��������  ");
//	for (int i = 0; i < 8; i++)
//		printf("%f  ", arr1[i]);
//	printf("\n\n�ڶ���������  ");
//	for (int i = 0; i < 8; i++)
//		printf("%f  ", arr2[i]);
//}