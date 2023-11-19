//#include <stdio.h>
//#include <string.h>
//char* s_gets(char* st, int n);
//#define MAXTITL 41
//#define MAXAUTL 31
//
//struct book
//{
//	char title[MAXTITL];
//	char author[MAXAUTL];
//	float value;
//};
//
//int main(void)
//{
//	struct book library;
//	printf("请输入书名\n");
//	s_gets(library.title, MAXTITL);
//	printf("输入作者\n");
//	s_gets(library.author, MAXAUTL);
//	printf("输入价格\n");
//	scanf("%f", &library.value);
//	printf("这本《%s》的作者是%s  这本书的售价是%f元",library.title,library.author,library.value);
//	return 0;
//}
//
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	char* find;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)
//	{
//		find = strchr(st, '\n');
//		if (find)
//			*find = '\0';
//		else
//			while (getchar() != '\n')
//				continue;		
//	}
//	return ret_val;
//}

//#include <stdio.h>
//#define FUNDLEN 50
//#define N 2
//
//struct funds {
//	char   bank[FUNDLEN];
//	double bankfund;
//	char   save[FUNDLEN];
//	double savefund;
//};
//
//double sum(const struct funds money[], int n);
//
//int main()
//{
//	struct funds jones[N] = {                             /*这是一个以结构为元素的数组，里面 的两个成员就是两个元素 ，传递的是结构数组的地址*/
//		{
//			"G_M",
//			4032.27,
//			"Lucky's",
//			8543.94
//		},
//		{
//			"H_J",
//			3620.88,
//			"Party",
//			3802.91
//		}
//	};
//
//	printf("两个用户一起的存款%.2f", sum(jones, N));
//	return 0;
//}
//
//double  sum(const struct funds money[], int n)
//{
//	double total =  0;
//	int i;
//	for (i = 0; i < N; i++)
//		total += money[i].bankfund + money[i].savefund;
//	return total;
//}