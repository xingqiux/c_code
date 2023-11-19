//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#define OUT 3
//#define WITHIN 5
//
//void main()
//{
//	int arr[OUT][WITHIN] =
//	{
//		{1,2,3,4,5},
//		{5,6,7},
//		{3,6,78,8,23}
//	};
//	for (int index_o = 0; index_o < OUT; index_o++)
//	{
//		printf("第%d维的数据有",index_o);
//		for (int index_w = 0; index_w < WITHIN ; index_w++)
//		{
//			printf("%d ", arr[index_o][index_w]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#define MONTHS 12
//
//int main()
//{
//	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	int index;
//	for (index = 0; index < MONTHS; index++)
//	{
//		printf("第%d月有 %d 天\n", index + 1, *(days + index));
//	}
//	return 0;
//}

//#include <stdio.h>
//#define SIZE 10 
//int sump(int* start, int* end);
//int main()
//{
//	int marbles[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
//	long answer;
//
//	answer = sump(marbles, marbles + SIZE);
//	printf("总计有 %d ", answer);
//}
//
//int sump(int* start, int* end)
//{
//	int total = 0;
//	while (start < end)
//	{
//		total += *start++;
//	}
//	return total;
//}

//
//#include <stdio.h>
//#define SIZE 10
//int sump(int* start, int* end);
//int main(void)
//{
//	int marbles[SIZE] = { 1,245,21,32,15,4221,12,22,3854,18 };
//	long answer;
//
//	answer = sump(marbles, marbles + SIZE);
//	printf("总和是 %5d", answer);
//	return 0;
//}
//
//int sump(int* start, int* end)
//{
//	int total = 0;
//	while (start < end)
//	{
//		total += *start++;
//	}
//	return total;
//}

//#define S 10
//void main()
//{
//	char words[S];
//	puts("输入字符串");
//	while (fgets(words, S, stdin) != NULL && words[0] != '\n')
//	{
//		fputs(words, stdout);
//		printf("\n%s", words);
//	}
//	puts("Done.");
//
//	return 0;
//}

//int put2(const char *string)
//{
//	int count = 0;
//	while (*string)
//	{
//		putchar(*string++);
//		count++;
//	}
//	putchar('\n');
//	return count;
//}
//
//int i = 0;
//int main()
//{
//	char  a[] = "hello world";
//	i = put2(&a);
//	printf("%d", i);
//	return 0;
//}



//void main()
//{
//	char flower[11] = "hello";
//	char flowers[] = "hello";
//	char  add[] = "world";
//	char lll[] = "you are very beutfull";
//	strcat(flower, add);
//	strncat(flowers, lll, strlen(lll));
//	printf("%s\n%s", flower, add);
//	printf("%s\n%s", flowers, lll);
//	return 0;
//}

///////////////////////////////////////////////////////////////////
//
//#include <string.h>
//#define LINE 8
//#define SIZE 10
//#define STOP ""
//
//void sort_str(char* string[], int num);
//void switch_str(char* a[], char* b[]);
//char * s_gets(char* st, int n);
//
//int main()
//{
//	char input[LINE][SIZE];
//	char* ptstr[LINE];
//	int ch = 0;
//	int k;
//	for (ch; ch < LINE && s_gets(input[ch], SIZE) != NULL && input[ch][0] != '\0'; ch++)
//		ptstr[ch] = input[ch];
//	sort_str(ptstr, ch);
//	puts("排序后的顺序是：");
//	for (k = 0; k < ch; k++)
//		puts(ptstr[k]);
//}
//
//void sort_str(char* string[], int num)
//{
//	int top, seek;
//	char*temp;
//	for (top = 0; top < num - 1; top++)
//		for (seek = top + 1; seek < num; seek++)
//		{
//			if (strcmp(string[top], string[seek]) > 0)
//				switch_str(&string[top], &string[seek]);
//			//{
//			//	temp = string[top];
//			//	string[top] = string[seek];
//			//	string[seek] = temp;
//			//}
//		}
//}
//
//void switch_str(char **a,char **b)
//{
//	char* temp = *a;  //用于临时存储指针
//	*a = *b;
//	*b = temp;
//}
//
//char * s_gets(char * st,int n)
//{
//	char* ret_val;
//	int i = 0;
//	ret_val = fgets(st,n,stdin);
//	if (ret_val)
//	{
//		while (st[i] != '\n' && st[i] != '\0')
//			i++;
//		if (st[i] == '\n')
//			st[i] = '\0';
//		else
//			while (getchar() != '\n')
//				continue;
//	}
//	return ret_val;
//}
//

////////////////////////////////////////////////////////