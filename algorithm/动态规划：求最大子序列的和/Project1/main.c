#include <stdio.h>

#define MAX 5

//这个是暴力递归求解最长子序列是多长,不过这个算法是最慢的，是指数复杂度
//int max(int a, int b)
//{
//	if (a > b) return a;
//	else if (a < b) return b;
//	else return a;
//}
//
//int L(int* nums, int i)
//{
//	int max_len = 1; //最基础的长度肯定有1
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

//下面这个加上了比较记忆模块，如果这个数组比较过，就直接跳过,这个就是动态规划的递归调用
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
//	int max_len = 1; //最基础的长度肯定有1
//
//	if (memo[i] != 0) return memo[i];	//如果这个数之前计算过，那直接在这个备忘录里返回就行了
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
//	memo[i] = max_len;		//当计算时计算了这个值，例如4，4的最长是1，直接保存下来
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

//对于这个最后还可以改成迭代的形式，直接就可以计算出来,算法就是动态规划算法

int max(int a, int b)
{
	if (a > b) return a;
	else if (a < b) return b;
	else return a;
}


int length_of_LTS(int* nums)
{
	int L[MAX] = {1,1,1,1,1}, maxL = 0;		//L是记忆备忘录，直接可以在这里面查找


	for (int i = MAX - 1; i > 0; i--)		//i->4,3,2,1从列表的最尾部开始动态规划
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