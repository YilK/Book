#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	vector<string> v;
	string s;
	while(cin>>s)
		v.push_back(s);
	int a=0,b=0,d=0;
	for(string c:v)
	{
		if(c=="ff")	a++;
		else if(c=="f1")	b++;
		else if(c=="f2") 	d++;
 	}
	cout<<a<<endl;
	return 0;
}