#include <stdio.h>
struct student
{
	char name[21];
	int score;
 } ;	//这里创建了一个结构体用来存储姓名和分数
 
 int main()
 {
 	struct student a[100],t;
 	int n,i,j; 
 	printf("你需要输入多少组数据:");
 	scanf("%d",&n);	//将数据的量存入变量n 
 	printf("请输入数据：\n");
 	
 	//输入数据 
	for(i=0;i<n;i++)
	{
		scanf("%s %d",a[i].name,&a[i].score);
		/*
			如果使用scanf()读取基本变量类型的值，在变量名前加上一个&
			如果使用scanf()把字符串读入数组中，不要使用&
		*/
	} 
	 
	//冒泡排序，降序
	for(i=1;i<n;i++)//n个数据，需进行n-1躺排序
	{
		for(j=0;j<n-i;j++)//两两比较的次数依次减少
		{
			if(a[j].score<a[j+1].score)
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				
			 } 
		} 
	} 
	printf("排序后:\n");
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",a[i].name,a[i].score);
	}
	return 0;
  } 
  
  
  
  
  
  
  
