/******************************
*  作者：拿得起更放得下(CSDN) *
*  Github:大小姐的小迷弟      *
*       yichenyan  QAQ        *
* 编程学习应该是简单且有趣的  *
*******************************/



#include<stdio.h>
#include<stdlib.h>

void print_arr(int arr[],int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ",*(arr+i));
	printf("\n");
}

void swap(int* num1,int *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


void heapify(int arr[], int n, int i)
{
	int largest = i;
	int lnode = i * 2 + 1;
	int rnode = i * 2 + 2;

	if(lnode < n && arr[largest] < arr[lnode])
		largest = lnode;
	if(rnode < n && arr[largest] < arr[rnode])
		largest = rnode;
	if(largest != i){
		swap(&arr[largest], &arr[i]);
		heapify(arr, n, largest);
	}


}

void heap_sort(int arr[],int n)
{
	int i = n/2 - 1;
	for(i; i >= 0; i--)
		heapify(arr, n, i);

	for(i = n - 1; i > 0; i--){
		swap(&arr[i], &arr[0]);
		heapify(arr, i, 0);
	}
}


int main()
{
	int arr[] = {5, 19, 23, 2, 9, 15, 18, 21};
	int len = 8;
	printf("len:%d\n", len);
	print_arr(arr,len);
	heap_sort(arr, len);
	print_arr(arr,len);
	return 0;
}
