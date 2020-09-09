#include <iostream>

using namespace std;
void change(int *w,int *e)
{
	int q;
	q=*w;
	*w=*e;
	*e=q;
}
int main(int argc, char *argv[]) {
	int a,b;
	cin>>a>>b;
	change(&a,&b);
	cout<<a<<" "<<b<<endl;
	return 0;
}