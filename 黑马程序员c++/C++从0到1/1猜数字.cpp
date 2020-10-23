#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int num=rand()%100+1;	//目的生成一个1-100的一个数；
//	cout<<num<<endl;
	int i=-1;
	while(i!=num)
	{
		cout<<"请输入：";
		cin>>i;
		if(i==num)
		{
			cout<<"right"<<endl;
			break;
		}
		else if(i<num)
			cout<<"too small"<<endl;
		else
			cout<<"too big"<<endl;
	}
	return 0;
}