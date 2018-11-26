//对数据范围在0-1000的整数进行排序
#include <stdio.h>

int main()
{

	int a[1001],t;
	for(int i=0;i<=1000;i++)
	{
		a[i]=0;	//初始化为0 
	}
	
	printf("请输入5个整数(0-1000):\n");
	
	for(int i=1;i<=5;i++)	//读入数据,进行桶排序 
	{
		scanf("%d",&t);	//把每个一个数读入到变量t中 
		a[t]++;	//数组下标为t的变量+1
			
	} 
	 
	//输出排序后的内容
	for(int i=0;i<=1000;i++)//遍历数组 
	{
		for(int j=1;j<=a[i];j++) 
		{
			printf("%d ",i); 
		} 
	 } 
}
