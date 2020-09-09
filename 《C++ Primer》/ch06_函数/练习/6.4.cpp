#include <iostream>

using namespace std;
int main() {
	#include <iostream>

	using namespace std;
	int fact(int n)
	{
		int res=1;
		for(int i=1;i<=n;i++)
			res*=i;
		return res;
	}
	int main() {
		int a;
		cin>>a;
		cout<<fact(a)<<endl;
		return 0;
	}
}