#include <iostream>
#include <string>
using namespace std;
int main() {
	string a,b;
	getline(cin,a);
	getline(cin,b);
	if(a.size()>b.size())
		cout<<a<<endl;
	else if (a.size()==b.size()) {
		cout<<"等长"<<endl;
	}
	else {
		cout<<b<<endl;
	}
	return 0;
}