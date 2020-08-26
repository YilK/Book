#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v;
	int n;
	while (cin>>n) {
		v.push_back(n);
	}
	for(vector<int>::iterator it=v.begin();it!=v.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	return 0;
}