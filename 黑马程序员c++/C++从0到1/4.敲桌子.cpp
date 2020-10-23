#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	for(int i=1;i<=100;i++)
	{
		if(i%10==7||i/10==7||i%7==0)
			cout<<i<<" 需要敲桌子"<<endl;
		else {
			cout<<i<<endl;
		}
	}
	return 0;
}