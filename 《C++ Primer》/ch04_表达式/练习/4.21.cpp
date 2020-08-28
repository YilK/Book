#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	vector<int> v;
	for(int i=1;i<=10;i++)
		v.push_back(i);
	for(int i=0;i<10;i++)
		cout<<v[i]<<" ";
	cout<<endl;
	for(auto it=v.begin();it<v.end();++it)
	{
		if((*it)%2==1)
			*it=(*it)*2;
	}
	for(int i=0;i<10;i++)
		cout<<v[i]<<" ";
	return 0;
}