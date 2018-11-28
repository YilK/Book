#include <stdio.h>
int a[101],n;	//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��
 
void quicksort(int left,int right)
{
	int i,j,t,temp;
	if(left>right)
	{
		return;
	}
	
	temp=a[left];	//temp�д���ǻ�׼�� 
	i=left;
	j=right; 
	
	
	//�������� 
	while(i!=j)
	{
		//���ұ߿�ʼ��������Ϊ������������Ҫ�ҵ�<temp���� 
		while(a[j]>=temp && i<j)	//������� 
		{
			j--; 
		}
		
		//�ٴ���߿�ʼ����,��Ҫ�ҵ�>temp���� 
		while(a[i]<=temp && i<j)
		{
			i++;
		 }
		
		//����λ��  
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t ;
		}
	}
	
	//ѭ������,����i==j,��Ҫ��a[j]��a[left](��׼��)����:
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
 
 
 
 
 
 
 
 
