#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int a=10;
	int *p=&a;
	cout<<sizeof(int *)<<endl;
	cout<<sizeof(double *)<<endl;
	cout<<sizeof(float *)<<endl;
	return 0;
}