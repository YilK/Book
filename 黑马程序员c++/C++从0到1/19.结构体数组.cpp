#include <iostream>
#include <string>
using namespace std;
//定义结构体
struct Student
{
	string name;
	int age;
	int score;
};
int main(int argc, char *argv[]) {
	//定义结构体变量
	Student s1;
	cin>>s1.name;
	cin>>s1.age;
	cout<<s1.name<<" "<<s1.age<<endl;
	return 0;
}