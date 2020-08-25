#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	string s;
	string a;
	while(getline(cin,a))
	{
		if(a=="")
			break;
		else {
			s+=a;
			s+=" ";
		}
	}
	cout<<s<<endl;
	return 0;
}