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

void quick_sort(int *arr, int low, int high)
{
	//low：数组最小的下标，high: 数组最大的下标
    if (low < high)
    {
        int i = low;
        int j = high;
        int k = arr[low];
        while (i < j)
        {
            while(i < j && arr[j] >= k)     // 从右向左找第一个小于k的数
            {
                j--;
            }

            if(i < j)
            {
                arr[i++] = arr[j];
            }

            while(i < j && arr[i] < k)      // 从左向右找第一个大于等于k的数
            {
                i++;
            }

            if(i < j)
            {
                arr[j--] = arr[i];
            }
        }

        arr[i] = k;
       // 递归调用
        quick_sort(arr, low, i - 1);     // 排序k左边
        quick_sort(arr, i + 1, high);    // 排序k右边
    }
    
}


int main()
{
	int arr[] = {9,14,8,12,7,13,15,11,9,19};
	int len = sizeof(arr)/sizeof(arr[0]);
	print_arr(arr,len);
	quick_sort(arr, 0, len- 1);

	return 0;
}
