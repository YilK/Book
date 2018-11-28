#include <stdio.h>
void quick_sort(int array[],int left,int right)
{
	int i = left;
	int j = right;
	int base=array[left];//将数组首元素作为基准值
	int t;
	
	while(i<=j) 
	{
		while(array[i]<base)
		{
			i++;
		}
		while(array[j]>base)
		{
			j--;
		}
		
		if(i<=j)
		{
			t=array[i];
			array[i]=array[j];
			array[j]=t;
			i++;
			j--;
		}	
	}
	if(left<j)
	{
		quick_sort(array,left,j);	
	}
	if(i<right)
	{
		quick_sort(array,i,right);
	}

 } 
 int main()
 {
 	int i;
 	int a[]={6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
 	quick_sort(a,0,9);
 	for(i=0;i<=9;i++)
 	{
 		printf("%d ",a[i]);
	 }
	 return 0;
 }
