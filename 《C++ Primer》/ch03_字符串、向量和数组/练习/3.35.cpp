#include <iostream>
using namespace std;
int main() {
	int a[10]={1,2,3,4};
	int* p=begin(a);
	int* q=end(a);
	while(p!=q)
	{
		*p=0;
		++p;
	}
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	return 0;
}