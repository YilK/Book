#include <stdio.h>

int main()
{
	int a[11],i,j,t;
	for(i=0;i<=10;i++)
	{
		a[i]=0;	//��ʼ��Ϊ0 
	}
	printf("����������(0-10):\n");
	for(i=1;i<=5;i++)	//ѭ������5���� 
	{
		 
		scanf("%d",&t);	//��ÿ������������t��
		a[t]=a[t]+1; 
	} 
	 
	for(i=0;i<=10;i++)	//�����ж�a[0]-a[10] 
	{
		for(j=1;j<=a[i];j++)	//�����˼��ξʹ�ӡ���� 
		{
			printf("%d ",i); 
		}		
	 } 

	return 0;
 } 
