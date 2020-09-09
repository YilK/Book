#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin>>s;
	int count=0;
	for(char c:s)
	{
		if(c=='a'||c=='e'||c=='i'||c=='u'||c=='o')
			count++;
	}
	cout<<count<<endl;
	return 0;
}