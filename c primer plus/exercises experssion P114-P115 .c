
////把用分钟表示的时间转换成小时和分钟表示的时间
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
//		printf("%d分钟转换后的时间是%d小时%d分钟\n", time, hour, minute);
//		scanf("%d", &time);
//	}		
//}


////输入一个整数打印他后面的10个数
//#include <stdio.h>
//
//void main(void)
//{
//	int user;
//	printf("输入一个整数");
//	scanf("%d", &user);
//	for (int i = user; i <= user + 10; i++)
//		printf("%d ", i);
//}



////用户输入天数转化成周数和天数
//#include <stdio.h>
//#define UNIT 7
//
//void main()
//{
//	int num;
//	printf("输入天数转化成周数加天数   ");
//	scanf("%d",&num);
//	printf("\n%d天也是%d周%d天",num,num/UNIT,num%UNIT );
//}


////输入一个double类型的值，然后打印该数立方
//#include <stdio.h>
//
//double cube(double a);
//
//void main()
//{
//	double num,answer;
//	scanf("%lf",&num);
//	answer = cube(num);
//	printf("%f的立方是%f", num, answer);
//}
//
//double cube(double a)
//{
//	return a * a * a;
//}

////输入的第一个整数是第二个运算对象，后面输入的是第一个运算对象，显示求模结果，非正值就停止
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