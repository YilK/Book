#include <stdio.h>
int main()
{
	int a[100],n,i,j;
	printf("有多少个数需要排序？：\n");
	scanf("%d",&n);	//将数据的个数存放在 n 中 
	
	for(i=0;i<n;i++)	//循环读入n个数据到数组a中 
	{
		scanf("%d",&a[i]); 
	 }
	
	//冒泡排序的核心部分
	for(i=1;i<n;i++)	//n个数排序，需要进行n-1躺
	{
		for(j=0;j<n-i;j++)	//n-i比较的次数依次减少 
		{
			if (a[j]<a[j+1])	//从大到小排序 
			{
				#交换 
				int t;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	} 
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	 } 
	
	return 0;
}
 
