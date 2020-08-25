#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(int argc, char *argv[]) {
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(ispunct(s[i]))
			continue;
		cout<<s[i];
	}
	return 0;
}