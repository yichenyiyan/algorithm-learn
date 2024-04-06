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




void insert_sort(int arr[], int len)
{
	int temp;
	int i, j;
	for(i = 1; i < len; i++){
		j = i - 1;
		temp = arr[i];
		while(arr[j] > temp && j >= 0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
		print_arr(arr, len);
	}
}



int main()
{
	int arr[] = {38,298,27,29,19,49,39,32,68};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("len:%d\n",len);
	print_arr(arr, len);
	insert_sort(arr, len);
	//print_arr(arr, len);
	return 0;
}
