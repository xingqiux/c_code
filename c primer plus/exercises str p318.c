
///////////////////////////////////////////////////////
////µÚ3£¬4Ìâ
//#include <stdio.h>
//#include <string.h>
//#define SIZE 100
//
//void str_input(char string[]);
//void str_input_t(char string[] , int size);
//
//void str_input(char string[])
//{
//	char ch;
//	while ((ch = getchar()) == ' ')
//		continue;
//	while (1)
//	{
//		if (ch == '\t' || ch == ' ' || ch == '\n')
//			break;
//		*string = ch;
//		string++;
//		ch = getchar();
//	}
//	*string = '\0';
//}
//
//void str_input_t(char string[], int size)
//{
//	char ch;
//	int counter = 0;
//	while ((ch = getchar()) == ' ')
//		continue;
//	while (1)
//	{
//		if (ch == '\t' || ch == ' ' || ch == '\n' || counter >= size)
//			break;
//		*string = ch;
//		string++;
//		counter++;
//		ch = getchar();
//	}
//	*string = '\0';
//}
//
//
//void main()
//{
//	char str[SIZE];
//	str_input_t(str,5);
//	puts(str);
//}
//
////////////////////////////////////////////////

/////////////////////////////////////////////

//5
//#include <stdio.h>
//#include <string.h>
//char* search_str(char string[], char ch);
//
//void main()
//{
//	char* strp;
//	char ch;
//	char string[] = "apples";
//	while (1)
//	{
//		ch = getchar();
//		if (ch == '~')
//			break;
//		else if (ch == '\n')
//			continue;
//		
//		strp = search_str(string, ch);
//		printf("%p\n", strp);
//	}
//
//	
//
//}
//
//char* search_str(char string[], char ch)
//{
//	char* s_str =NULL;
//	int i = 0, x = strlen(string);
//	printf("%d", x);
// 	while (*string != ch && i != x)
//	{
//		string++;
//		i++;
//	}
//	if (*string == '\0')
//	{
//		return  NULL;
//	}
//	else
//		return string;
//}
//////////////////////////////////////////////


