/******************************
*  作者：拿得起更放得下(CSDN) *
*  Github:大小姐的小迷弟      *
*       yichenyan  QAQ        *
* 编程学习应该是简单且有趣的  *
*******************************/



#include<stdio.h>
#include<stdlib.h>

void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//合并数组（包含排序）
void merge(int arr[], int tempArr[],int left,int mid, int right)
{
	//标记左半区第一个未排序的元素
	int l_pos = left;
	//标记右半区第一个未排序的元素
	int r_pos = mid + 1;
	//tempArr(临时数组)元素的下标
	int pos = left;

	//进行合并
	while (l_pos <= mid && r_pos <= right)
	{
		if (arr[l_pos] < arr[r_pos])
			tempArr[pos++] = arr[l_pos++];
		else
			tempArr[pos++] = arr[r_pos++];
	}

	//合并左半区剩余元素
	while(l_pos <= mid)
		tempArr[pos++] = arr[l_pos++];

	//合并右半区剩余元素
	while (r_pos <= right)
		tempArr[pos++] = arr[r_pos++];

	//将排序所得结果拷贝到原数组arr中
	while (left <= right) 
	{
		arr[left] = tempArr[left];
		left++;
	}
}


//拆解数组
void Dismantling(int arr[], int tempArr[], int left, int right)
{
	if (left < right)
	{
		//计算中间点
		int mid = (left + right) / 2;
		//递归划分左半区
		Dismantling(arr, tempArr, left, mid);
		//递归划分右半区
		Dismantling(arr, tempArr, mid + 1, right);
		//合并已排序部分
		merge(arr, tempArr, left, mid, right);
	}
}


//归并排序入口
void sort_entry(int arr[], int n)
{
	int* tempArr = (int*)malloc(n * sizeof(int));
	if (tempArr) {
		Dismantling(arr, tempArr, 0, n - 1);
		free(tempArr);
	}
	else {
		printf("fail to create the tempArr\n");
	}
}

int main()
{
	int arr[] = { 1, 8, 7, 6, 9, 2, 4, 3, 11, 10 };
	int n = sizeof(arr)/sizeof(arr[0]);
	print_arr(arr, n);
	sort_entry(arr, n);
	print_arr(arr, n);
	return 0;
}
