#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int main() {
	vector<string> v;
	string s;
	while(cin>>s)
	{
		for(auto &c:s)
			c=toupper(c);
		v.push_back(s);
	}
	for(auto c:v)
		cout<<c<<endl;
	return 0;
}