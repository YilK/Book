#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int arr[] = { 4,2,8,0,5,7,1,3,9,100,-1,90};
	int size=sizeof(arr)/sizeof(arr[0]);//计算出元素的个数
//	cout<<size<<endl;
	for(int i=size-1;i>0;i--)//排序的躺数
	{
		int flag=1;//设置标记位，如果一次排序中没有发生交换，那么就结束循环。
		for(int j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])//从小到大排序。
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=0;
			}
		}
		if(flag==1)
			break;
	}
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	
	return 0;
}