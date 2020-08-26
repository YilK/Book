#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	vector<int> v;
	for(int i=1;i<=10;i++)
	{
		cin>>n;
		v.push_back(n);
	}
	for(vector<int>::iterator it=v.begin();it!=v.end();++it)
		(*it)=(*it)*2;
	for(vector<int>::iterator it=v.begin();it!=v.end();++it)
		cout<<*it<<" ";
	return 0;
}