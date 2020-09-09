#include <iostream>
#include <string>
using namespace std;
int main() {
	string s1,s2;
	while(1)
	{
		cout<<"输入两个字符串："<<endl;
		cin>>s1>>s2;
		if(s1.size()>s2.size())
			cout<<s2<<endl;
		else 
			cout<<s1<<endl;
		cout<<endl;
	}
	return 0;
}