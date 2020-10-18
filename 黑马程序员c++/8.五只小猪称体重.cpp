#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int arr[5] = {300,350,200,400,250};
	int max=arr[0];
	for(int i=1;i<(sizeof(arr)/sizeof(arr[0]));i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	cout<<max<<endl;
	return 0;
}