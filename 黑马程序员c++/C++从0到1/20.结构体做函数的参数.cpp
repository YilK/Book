#include <iostream>
#include <string>
using namespace std;
struct student{
	string name;
	int age;
	int score;	
};
//值传递
void p1(struct student s)
{
	cout<<s.name<<" "<<s.age<<" "<<s.score<<endl;
}
//地址传递
void p2(struct student &s)
{
	s.age=100;
}
int main(int argc, char *argv[]) {
	student s;
	cin>>s.name;
	cin>>s.age;
	cin>>s.score;
	p1(s);
	p2(s);
	cout<<s.age<<endl;
	return 0;
}