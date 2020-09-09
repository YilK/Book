#include <iostream>

using namespace std;
void change(int &i)
{
	i++;
}
int main(int argc, char *argv[]) {
	int a=10;
	change(a);
	cout<<a<<endl;
	return 0;
}