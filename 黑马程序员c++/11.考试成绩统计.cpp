#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int scores[3][3] =//定义了每个学生的数据。
	{
		{100,100,100},
		{90,50,100},
		{60,70,80},
	};
	string names[3]={"张三","李四","王五"};
	for(int i=0;i<3;i++)
	{
		int number=0;
		for(int j=0;j<3;j++)
			number+=scores[i][j];
		cout<<names[i]<<"的成绩为："<<number<<endl;
	}
	return 0;
}