#include <stdio.h>
struct student
{
	char name[21];
	int score;
 } ;	//���ﴴ����һ���ṹ�������洢�����ͷ���
 
 int main()
 {
 	struct student a[100],t;
 	int n,i,j; 
 	printf("����Ҫ�������������:");
 	scanf("%d",&n);	//�����ݵ����������n 
 	printf("���������ݣ�\n");
 	
 	//�������� 
	for(i=0;i<n;i++)
	{
		scanf("%s %d",a[i].name,&a[i].score);
		/*
			���ʹ��scanf()��ȡ�����������͵�ֵ���ڱ�����ǰ����һ��&
			���ʹ��scanf()���ַ������������У���Ҫʹ��&
		*/
	} 
	 
	//ð�����򣬽���
	for(i=1;i<n;i++)//n�����ݣ������n-1������
	{
		for(j=0;j<n-i;j++)//�����ȽϵĴ������μ���
		{
			if(a[j].score<a[j+1].score)
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				
			 } 
		} 
	} 
	printf("�����:\n");
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",a[i].name,a[i].score);
	}
	return 0;
  } 
  
  
  
  
  
  
  
