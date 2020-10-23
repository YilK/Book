#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	//指针的定义
	int a=10;
	int *p;
	p=&a;
	cout<<&a<<endl;
	cout<<p<<endl;
	//指针的使用
	*p=1000;
	cout<<a<<endl;
	cout<<*p<<endl;

	return 0;
}