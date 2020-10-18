#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int arr[10];
	for(int i=0;i<10;i++)
		arr[i]=i;
	for(int i=0;i<10;i++)
		cout<<arr[i]<<endl;
	cout<<sizeof(arr)<<endl;		//整个数组的大小
	cout<<sizeof(arr[1])<<endl;		//数组中每个元素的大小
	cout<<sizeof(arr)/sizeof(arr[1])<<endl; //计算出数组的长度。
	
	cout<<arr<<endl; //数组的首地址
	cout<<&arr[1]<<endl;
	return 0;
}