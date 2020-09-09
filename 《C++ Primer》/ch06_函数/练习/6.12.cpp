#include <iostream>

using namespace std;
void change(int &a,int &b)
{
	int c=a;
	a=b;
	b=c;
}
int main(int argc, char *argv[]) {
	int m,n;
	cin>>m>>n;
	change(m,n);
	cout<<m<<" "<<n;
	return 0;
}