#include <stdio.h>
int main()
{
	int a[100],n,i,j;
	printf("�ж��ٸ�����Ҫ���򣿣�\n");
	scanf("%d",&n);	//�����ݵĸ�������� n �� 
	
	for(i=0;i<n;i++)	//ѭ������n�����ݵ�����a�� 
	{
		scanf("%d",&a[i]); 
	 }
	
	//ð������ĺ��Ĳ���
	for(i=1;i<n;i++)	//n����������Ҫ����n-1��
	{
		for(j=0;j<n-i;j++)	//n-i�ȽϵĴ������μ��� 
		{
			if (a[j]<a[j+1])	//�Ӵ�С���� 
			{
				#���� 
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
 
