#include <iostream>

using namespace std;
void swap2(int &p1,int &p2)
{
	int temp=p1;
	p1=p2;
	p2=temp;
}
int main(int argc, char *argv[]) {
	int a=10;
	int b=20;
	
	swap2(a,b);//地址传递
	
	cout<<a<<endl;
	cout<<b<<endl;
	return 0;
}