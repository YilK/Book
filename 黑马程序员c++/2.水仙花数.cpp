#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	int i=100;
	int a,b,c;
	do{
		a=i/100;
		b=i%100/10;
		c=i%10;
		if((pow(a,3)+pow(b, 3)+pow(c, 3))==i)
			cout<<i<<endl;
		i++;
//		cout<<a<<" "<<b<<" "<<c<<endl;
	}while(i<1000);
	return 0;
}