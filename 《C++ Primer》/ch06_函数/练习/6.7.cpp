#include <iostream>

using namespace std;
void count()
{
	static int n=0;
	n++;
	cout<<n<<endl;
}
int main(int argc, char *argv[]) {
	for(int i=1;i<=3;i++)
		count();
	return 0;
}