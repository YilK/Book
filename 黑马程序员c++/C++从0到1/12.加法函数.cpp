#include <iostream>

using namespace std;
double sum(double n1,double n2)
{
	return n1+n2;
}
int main(int argc, char *argv[]) {
	double a,b;
	cin>>a>>b;
	cout<<sum(a,b);
	return 0;
}