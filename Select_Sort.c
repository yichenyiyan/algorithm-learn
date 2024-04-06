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
       for(i; i < len; i++){
	  printf("%d ", arr[i]);     
       }	
       printf("\n");
}

void swap(int *num1, int *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


void select_sort(int arr[], int len)
{
	int i = 0;
	int j = 0;
	int min_index = 0;
	for(i; i < len; i++){
		min_index = i;
		for(j = i + 1; j < len; j++){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		swap(&arr[i], &arr[min_index]);
	}
}



int main()
{
	int arr[] = {24,56,23,45,13,56,76,46};
	int len = sizeof(arr)/sizeof(arr[0]);
	print_arr(arr, len);
	select_sort(arr, len);
	print_arr(arr, len);
	return 0;
}
