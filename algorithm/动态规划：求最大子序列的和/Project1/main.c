#include <stdio.h>

#define MAX 5

//����Ǳ����ݹ������������Ƕ೤,��������㷨�������ģ���ָ�����Ӷ�
//int max(int a, int b)
//{
//	if (a > b) return a;
//	else if (a < b) return b;
//	else return a;
//}
//
//int L(int* nums, int i)
//{
//	int max_len = 1; //������ĳ��ȿ϶���1
//
//	if (i == MAX - 1) return 1;
//
//	for (int j = i+1; j < MAX; j++)
//	{
//		if (nums[j] > nums[i])
//		{
//			max_len = max(max_len, L(nums, j)+1);
//		}
//	}
//	return max_len;
//}
//
//int length_of_LTS(int* nums)
//{
//	int max[5],max_a = 0;
//	for (int i = 0 ; i < 5;i++)
//	{
//		max[i] = L(nums, i,5);
//	}
//	for (int j = 0; j < 5; j++)
//	{
//		if (max[j] > max_a) max_a = max[j];
//		printf("%d  ", max[j]);
//	}
//	return max_a;
//}

//������������˱Ƚϼ���ģ�飬����������ȽϹ�����ֱ������,������Ƕ�̬�滮�ĵݹ����
//int memo[MAX];
//
//int max(int a, int b)
//{
//	if (a > b) return a;
//	else if (a < b) return b;
//	else return a;
//}
//
//int L(int* nums, int i)
//{
//	int max_len = 1; //������ĳ��ȿ϶���1
//
//	if (memo[i] != 0) return memo[i];	//��������֮ǰ���������ֱ�����������¼�ﷵ�ؾ�����
//
//	if (i == MAX - 1) return 1;
//
//	for (int j = i + 1; j < MAX; j++)
//	{
//		if (nums[j] > nums[i])
//		{
//			max_len = max(max_len, L(nums, j) + 1);
//		}
//	}
//	memo[i] = max_len;		//������ʱ���������ֵ������4��4�����1��ֱ�ӱ�������
//	return max_len;
//}
//
//int length_of_LTS(int* nums)
//{
//	int max[MAX], max_a = 0;
//	for (int i = 0; i < MAX; i++)
//	{
//		max[i] = L(nums, i, 5);
//	}
//	for (int j = 0; j < MAX; j++)
//	{
//		if (max[j] > max_a) max_a = max[j];
//		printf("%d  ", max[j]);
//	}
//	return max_a;
//}

//���������󻹿��Ըĳɵ�������ʽ��ֱ�ӾͿ��Լ������,�㷨���Ƕ�̬�滮�㷨

int max(int a, int b)
{
	if (a > b) return a;
	else if (a < b) return b;
	else return a;
}


int length_of_LTS(int* nums)
{
	int L[MAX] = {1,1,1,1,1}, maxL = 0;		//L�Ǽ��䱸��¼��ֱ�ӿ��������������


	for (int i = MAX - 1; i > 0; i--)		//i->4,3,2,1���б����β����ʼ��̬�滮
	{
		for (int j = i + 1; j < MAX;j++)	
		{
			if (nums[i] > nums[j])
			{
				L[i] = max(L[i], L[j] + 1);
			}
		}
	}
	for (int k= 0; k < MAX; k++)
	{
		if (L[k] > maxL) maxL = L[k];
		printf("%d ", L[k]);
	}
	return maxL;
}

void main()
{
	int nums[MAX] = {1,5,2,4,3};
	printf("\n%d", length_of_LTS(nums));
}