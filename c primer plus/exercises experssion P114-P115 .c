
////���÷��ӱ�ʾ��ʱ��ת����Сʱ�ͷ��ӱ�ʾ��ʱ��
//#include <stdio.h>
//#define NUIT 60
//
//int main(void)
//{
//	int time;
//	int hour, minute;
//	scanf("%d", &time);
//	while (time > 0)
//	{
//		hour = time / NUIT;
//		minute = time % NUIT;
//		printf("%d����ת�����ʱ����%dСʱ%d����\n", time, hour, minute);
//		scanf("%d", &time);
//	}		
//}


////����һ��������ӡ�������10����
//#include <stdio.h>
//
//void main(void)
//{
//	int user;
//	printf("����һ������");
//	scanf("%d", &user);
//	for (int i = user; i <= user + 10; i++)
//		printf("%d ", i);
//}



////�û���������ת��������������
//#include <stdio.h>
//#define UNIT 7
//
//void main()
//{
//	int num;
//	printf("��������ת��������������   ");
//	scanf("%d",&num);
//	printf("\n%d��Ҳ��%d��%d��",num,num/UNIT,num%UNIT );
//}


////����һ��double���͵�ֵ��Ȼ���ӡ��������
//#include <stdio.h>
//
//double cube(double a);
//
//void main()
//{
//	double num,answer;
//	scanf("%lf",&num);
//	answer = cube(num);
//	printf("%f��������%f", num, answer);
//}
//
//double cube(double a)
//{
//	return a * a * a;
//}

////����ĵ�һ�������ǵڶ���������󣬺���������ǵ�һ�����������ʾ��ģ���������ֵ��ֹͣ
//#include <stdio.h>
//
//void main(void)
//{
//	int a, b;
//	scanf("%d", &b);
//	scanf("%d", &a);
//	while (a > 0) 
//	{
//		printf("\n%d %% %d = %d", a, b, a % b);
//		scanf("%d", &a);
//	}
//}