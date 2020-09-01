#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string s;
	vector<string> v;
	while(cin>>s)
		v.push_back(s);		//数据的输入
		
	int a[100]={0};
	for(int i=0;i<v.size();i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			if(v[i]==v[j])
				a[i]++;
			else {
				break;
			}
		}
	}
	for(int i=0;i<v.size();i++)
		cout<<a[i]+1<<endl;
	return 0;
}