#include <iostream>
#include <string>
using namespace std;
int main() {
	string res="";
	string s;
	while(cin>>s)
	{
		if(s==res)
		{
			cout<<res<<endl;
			break;
		}
		else {
			res=s;
		}	
	}
}