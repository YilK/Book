#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> scores(11,0);
	int n;
	vector<int>::iterator it=scores.begin();
	while(cin>>n)
	{
		if(n<=100)
		{
			int a=n/10;
			*(it+a)=*(it+a)+1;
		}
	}
	for(it;it<scores.end();++it)
		cout<<*it<<" ";
	return 0;
}