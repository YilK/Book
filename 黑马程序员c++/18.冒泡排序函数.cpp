#include <iostream>

using namespace std;

void bubbleSort(int arr[], int len)
{
	for(int i=len-1;i>0;i--)
	{
		int flag=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
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
}
int main(int argc, char *argv[]) {
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
	int size=sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, size);
	for(int i=0;i<size;i++)
		cout<<arr[i]<<endl;
	return 0;
}