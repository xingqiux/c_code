#include <stdio.h>

//���ֲ��ҷ���
//ÿ��ȡ�м�������бȽϣ�������˵Ļ�������������м�ֵ������������С�˾������м�ֵǰ�����������ѭ�����ó��������λ��
//ֻ����һ��˳�������в���ʹ��
//
//int search();
//
//int main()
//{
//	int nums[] = { 1,2,3,5,7,11,13,17,19,23 };
//	printf("����Ҫ���ҵ�����");
//	int b;
//	scanf("%d", &b);
//	printf("%d��λ����%d",b,search(nums,b));
//	//printf("%d,%d,%d", nums[0], nums[1], nums[2]);
//}
//
//int search(int nums[], int b)
//{
//	int low = 0;
//	int high = 9;
//	int mid;
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		if (nums[mid] == b)
//		{
//			return mid;
//		}
//		if (nums[mid] > b)
//		{
//			high = mid - 1;
//		}
//		else
//		{
//			low = mid + 1;
//		}
//	}
//	return -1;
//}

//ָ��ѧϰ����
//int main()
//{
//	int a = 11;
//	char c = 'w';
//	int* pa = &a;      //�����pa��һ��ָ�����͵ı���
//	printf("%p\n", pa);    //%p��ָ���ת����־
//	*pa = 70;
//	printf("%d\n", a);
//	return 0;
//}
//
////���ڽṹ���ѧϰ�Լ�ָ���ʹ��
//struct Book
//{
//	char name[20];
//	float pay;
//	char id[20];
//};
//
//int main()
//{
//	struct Book text = { "�����������ɵ�", 55.9,"335566600"};
//	printf("%s  %lf  %s \n", text.name, text.pay, text.id);    // �ṹ�����.��Ա����
//	struct Book* pa = &text;
//	printf(" % s %lf % s \n", (*pa).name, (*pa).pay, (*pa).id);   //   ʹ��ָ�������ֻ�����ֵ�����鷳��
//	printf("%s  %lf  %s \n", pa->name, pa->pay, pa->id);                    //���ṹ���ָ�룩"->"��ָ��һ���ṹ��ľ���ֵ
//	return 0;
//}

//
////(��������)���1-100������
//
//void main()
//{
//	int a = 0;
//	while (a <=100)
//	{
//		if (1 == a % 2)
//		{
//			printf("%d\n",a);
//		}
//		a++;
//	}
//
//}


//�����������c����ʵ��
#include <stdlib.h>
#include <time.h>

int main()
{
	int nums[10];
	srand((unsigned int)time(0));   //?ֻ��Ҫ����һ�Σ������������ʲô�߼�û����
	for (int i=0; i < 10; i++)
	{
		nums[i] = rand() %100 ;         //"%100"�ǽ�������ɵ�����ȡģ0-99֮��
		printf("%d ", nums[i]);
	}
    quicksort(nums);
	//printf("\n");
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d ", nums[i]);
	//}
	//
}


int  quicksort(int arr[])             
{
	int len=sizeof(arr) / sizeof(arr[0]);     //����ʹ��sizeof()�����arr[]ռ���ڴ���ֽڣ�Ȼ�����һ��Ԫ��ռ�е��ֽڳ���
	int less[10];             //����Ȼ�׼ֵ���������С������
	int greater[10];
	if (len<=1)
	{
		return arr[0];           //��������
	}
	else                          //�ݹ�����
	{
		int a = 0;                 //less��greater��0�±�λ��
		int b = 0;
		for (int i = 1; i <= len; i++)
		{
			if (arr[i]<arr[0])
			{
				less[a] = arr[i];
				a++;
			}
			else
			{
				greater[b] = arr[i];
				b++;
			}
		}
		return quicksort(less) + arr[0] + quicksort(greater);
}