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

void shell_sort(int arr[], int len)
{
	int i, j, temp, mid;
	for(mid = len/2; mid > 0; mid/=2){
		for(i = mid; i < len; i++){
			temp = arr[i];
			for(j = i; j >= mid&&temp < arr[j-mid]; j-=mid){
				arr[j] = arr[j-mid];
			}
			arr[j] = temp;
		}
		print_arr(arr, len);
	}
}


int main()
{
	int arr[] = {23,21,34,12,34,54,65,11,15,19,27,28,20,10,20,24,34,45,28};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("arr len:%d\n\n",len);
	print_arr(arr, len);
	shell_sort(arr,len);
	return 0;
}
