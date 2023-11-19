
  
//#include <stdio.h>
//#include <stdbool.h>
//  
//int main(void)
//{
//	char c;
//	int spacesNum = 0;
//	int linesNum = 0;
//	int strsNum = 0;
//	while ((c = getchar()) != '#')
//	{
//		if (isspace(c))
//			spacesNum++;
//		if (c == '\n')
//			linesNum++;
//		if (!isspace(c) && c != '\n')
//			strsNum++;
//	}
//	printf("空格有 %d 个，换行符有 %d 个, 字符有 %d 个", spacesNum, linesNum, strsNum);
//	return 0;
//}
//

////读取输入，#字停止，输入的每个字打印ASCLL码，每行打印8个
//#include <stdio.h>
//
//int main()
//{
//	char c;
//	int line = 0;
//	while ((c = getchar()) != '#')
//	{
//		if (line % 8 == 0)
//			printf("\n");
//		printf("%d  ", c);
//		line++;
//		
//	}
//}


////输入数字，报告输入偶数的数量，平均数，奇数的数量，奇数的平均值，0结束
//
//#include <stdio.h>
//
//int main()
//{
//	float sumEven=0;
//	float sumOdd=0;
//	int num=0;
//	int evenNum=0;
//	int oddNum=0;
//	while (1)
//	{
//		scanf("%d",&num);
//		if (num == 0)
//			break;
//		if ((num % 2) == 0)
//		{
//			evenNum++;
//			sumEven += num;
//		}
//		else
//		{
//			oddNum++;
//			sumOdd += num;
//		}		
//	}
//	printf("偶数的数量有 %d 个 平均数是 %f \n 奇数的数量是 %d  平均数是 %f \n", evenNum,sumEven/evenNum,oddNum,sumOdd/evenNum);
//}

////输入段落，报告ei出现的次数，#退出
//
//#include <stdio.h>
//#include <stdbool.h>
//
//int main()
//{
//	bool one = false;
//	bool two = false;
//	char c;
//	int time=0;
//	while ((c = getchar()) != '#')
//	{
//		if (c == 'e')
//		{
//			one = true;
//		}
//		if (c == 'i')
//		{
//			two = true;
//		}
//		if (two && one)
//		{
//			time++;
//			one = false;
//			two = false;
//		}
//	}
//	printf("%d",time);
//	return 0;
//}