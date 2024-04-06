/******************************
*  作者：拿得起更放得下(CSDN) *
*  Github:大小姐的小迷弟      *
*       yichenyan  QAQ        *
* 编程学习应该是简单且有趣的  *
*******************************/



#include<stdio.h>

void print_arr(int arr[], int len)
{
	
	int i = 0;
	for(i; i < len; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void bubble_sort(int arr[], int len)
{
	int i = 0;
	int j = 0;
	for(i = len - 1; i >= 0; i--)
	{
		for(j = 0; j < i; j++)
		{
			if(arr[j] > arr[j + 1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}


int main()
{
	int arr[] = {3,49,48,39,2,39,20,40};
	int len = sizeof(arr)/sizeof(arr[0]);
	print_arr(arr, len);
	bubble_sort(arr, len);
	print_arr(arr, len);
	return 0;
}
