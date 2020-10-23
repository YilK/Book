#include <iostream>
#include <string>
#define MAX 1000//�������
using namespace std;
//��ϵ�˽ṹ��
struct Person	
{
	string m_name;//����
	int m_sex;//�Ա� 1��2Ů
	int m_age;//����
	string m_phone;//�绰
	string m_addr;//סַ
};
//ͨѶ¼�ṹ��
struct addressbooks
{
	struct Person personArray[MAX];//��ϵ������
	int m_Size;//ͨѶ¼����Ա�ĸ��� 
};
//�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}
//1.�����ϵ����Ϣ
void addperson(addressbooks& abs)
{
	if (abs.m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		cout << "������������" << endl;
		cin >> abs.personArray[abs.m_Size].m_name;

		cout << "�������Ա�\n1 -- ��\n2 -- Ů" << endl;
		cin >> abs.personArray[abs.m_Size].m_sex;

		cout << "���������䣺" << endl;
		cin >> abs.personArray[abs.m_Size].m_age;

		cout << "������绰��" << endl;
		cin >> abs.personArray[abs.m_Size].m_phone;

		cout << "������סַ" << endl;
		cin >> abs.personArray[abs.m_Size].m_addr;

		//����ͨѶ¼�е�����
		abs.m_Size++;
		
		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//����
	}
}

//2.��ʾ��ϵ��
void showPerson(addressbooks *abs)
{
	//�����ж�ͨѶ¼�е������Ƿ�Ϊ0��
	if (abs->m_Size == 0)
		cout << "��ǰ����Ϊ0" << endl;
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
			//cout << abs->personArray[i].m_name << " " << abs->personArray[i].m_sex << " " << abs->personArray[i].m_age << " " << abs->personArray[i].m_phone << " " << abs->personArray[i].m_addr<<endl;
		{
			cout << "����:" << abs->personArray[i].m_name << "\t";
			if (abs->personArray[i].m_sex == 1)
				cout << "�Ա�:��" << "\t";
			else
				cout<< "�Ա�:Ů" << "\t";
			cout << "����:" << abs->personArray[i].m_age << "\t";
			cout << "�绰����:" << abs->personArray[i].m_phone << "\t";
			cout<<"��ַ:"<< abs->personArray[i].m_addr << endl;
		}
	}
	system("pause");//�밴���������
	system("cls");//����
}
//�����ϵ���Ƿ����
int isExist(addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_name == name)
			return i;
	}
	return -1;
}
//3.ɾ����ϵ��
void deletePerson(addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret + 1; i < abs->m_Size; i++)
		{
			abs->personArray[i - 1] = abs->personArray[i];
		}
		abs->m_Size--;
	}
	else
		cout << "���޴���" << endl;
	system("pause");//�밴���������
	system("cls");//����
}
//4.������ϵ��
void findPerson(addressbooks *abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	//�ж�ָ������ϵ���Ƿ����ͨѶ¼��
	int i = isExist(abs, name);
	if (i != -1)
	{
		cout << "����:" << abs->personArray[i].m_name << "\t";
		if (abs->personArray[i].m_sex == 1)
			cout << "�Ա�:��" << "\t";
		else
			cout << "�Ա�:Ů" << "\t";
		cout << "����:" << abs->personArray[i].m_age << "\t";
		cout << "�绰����:" << abs->personArray[i].m_phone << "\t";
		cout << "��ַ:" << abs->personArray[i].m_addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");//�밴���������
	system("cls");//����
}
//5.�޸���ϵ��
void modifyPerson(addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������������" << endl;
		cin >> abs->personArray[ret].m_name;

		cout << "�������Ա�\n1 -- ��\n2 -- Ů" << endl;
		cin >> abs->personArray[ret].m_sex;

		cout << "���������䣺" << endl;
		cin >> abs->personArray[ret].m_age;

		cout << "������绰��" << endl;
		cin >> abs->personArray[ret].m_phone;

		cout << "������סַ" << endl;
		cin >> abs->personArray[ret].m_addr;

		cout << "�޸ĳɹ���" << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");//�밴���������
	system("cls");//����
}
//6.�����ϵ��
void cleanPerson(addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");//�밴���������
	system("cls");//����
}
int main()
{
	//����ͨѶ¼�Ľṹ�����
	addressbooks abs;
	//��ʼ��ͨѶ¼������
	abs.m_Size = 0;
	int select = 0;//�����û�ѡ������ı���
	while (true)
	{
		//�˵�����
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1�������ϵ��
			addperson(abs);
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://4��������ϵ�� 
			findPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;//ֱ���˳�
			break;
		}
	}
	return 0;
}