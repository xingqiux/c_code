////�����������һ�����֣������������ֱ����ʾ������������������������ͷ��ظ���һ������Լ��
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
//	printf("�����κ�һ������   ");
//	printf("����q ֹͣ\n");
//	while (scanf("%lu", &num) == 1)
//	{
//		for (div = 2,isPrime = true; (div * div) <= num;div++) 
//		{
//			if (num % div == 0)
//			{
//				if ((div * div) != num)
//					printf("%lu ���� %lu �ĵ�Լ����%lu\n", num, div, num / div);
//				else
//					printf("%lu is divisible by %lu \n", num, div);
//				isPrime = false;
//			}
//		}
//		if (isPrime)
//			printf("%lu ������", num);
//		printf("��������һ������");
//		printf("   ��q�˳�");
//	}
//	printf("����");
//	return 0;
//}
