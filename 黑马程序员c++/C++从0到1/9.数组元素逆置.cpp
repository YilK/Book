#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int arr[5]={1,3,2,5,4};
	int i=0,j=4;
	while(i<=j)
	{
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;
	}
	for(int i=0;i<5;i++)
		cout<<arr[i]<<" ";
	return 0;
}