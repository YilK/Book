#include <iostream>

using namespace std;

double abs(double number)
{
	if(number<0)
		number=-number;
	return number;
}
int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	cout<<abs(n)<<endl;
	return 0;
}