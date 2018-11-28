#include <stdio.h>
int a[101],n;	//定义全局变量，这两个变量需要在子函数中使用
 
void quicksort(int left,int right)
{
	int i,j,t,temp;
	if(left>right)
	{
		return;
	}
	
	temp=a[left];	//temp中存的是基准数 
	i=left;
	j=right; 
	
	
	//升序排列 
	while(i!=j)
	{
		//从右边开始搜索，因为是升序，所以需要找到<temp的数 
		while(a[j]>=temp && i<j)	//与运算符 
		{
			j--; 
		}
		
		//再从左边开始搜索,需要找到>temp的数 
		while(a[i]<=temp && i<j)
		{
			i++;
		 }
		
		//交换位置  
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t ;
		}
	}
	
	//循环结束,表明i==j,需要将a[j]与a[left](基准数)交换:
	a[left]=a[j];
	a[j]=temp;
	
	quicksort(left,j-1);
	quicksort(j+1,right);

	return;
	 
 } 
 
 int main()
 {
 	int i;
 	for(i=0;i<=10;i++)
 	{
 		a[i]=10-i;
	 }
	
	for(i=0;i<=10;i++)
	{
		printf("%d ",a[i]);
	}
	quicksort(0,10);
		for(i=0;i<=10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
 }
 
 
 
 
 
 
 
 
