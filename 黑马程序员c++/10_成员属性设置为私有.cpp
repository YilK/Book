#include <iostream>
#include <string>
using namespace std;
//成员属性设置为私有
//1.可以自己控制读写权限
//2.对于写可以检测数据的有效性

//设计人类
class Person
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name=name;
	}
	//获取姓名
	string getName()
	{
		return m_Name;
	}
private:
	string m_Name;
	int m_Age;
	string m_Lover;
	
};
int main(int argc, char *argv[]) {
	Person p;
	p.setName("hjk");
	cout<<"姓名为："<<p.getName()<<endl;
	return 0;
}