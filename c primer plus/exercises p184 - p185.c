
  
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
//	printf("�ո��� %d �������з��� %d ��, �ַ��� %d ��", spacesNum, linesNum, strsNum);
//	return 0;
//}
//

////��ȡ���룬#��ֹͣ�������ÿ���ִ�ӡASCLL�룬ÿ�д�ӡ8��
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


////�������֣���������ż����������ƽ������������������������ƽ��ֵ��0����
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
//	printf("ż���������� %d �� ƽ������ %f \n ������������ %d  ƽ������ %f \n", evenNum,sumEven/evenNum,oddNum,sumOdd/evenNum);
//}

////������䣬����ei���ֵĴ�����#�˳�
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