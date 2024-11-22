#include<iostream>
#define MAX 1000
using namespace std;

struct Person//�����ϵ��{�ṹ��}��������ϵ�˵�[��������],�����������Ա����䡢�绰����ַ
{
	string m_Name;
	int m_Gender;//1����  2��Ů
	int m_Age;
	string m_Phone;
	string m_Address;
};

struct AddressBooks//���ͨѶ¼{�ṹ��}�����ڱ���"��ϵ�˽ṹ��[����]"��"��ǰ�������ϵ�˵�[����]"
{
	struct Person personArray[MAX];
	int m_Size;
};

void showMenu()//�˵�����{����}
{
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
}

void addPerson(AddressBooks* abs)//�����ϵ��{����}
{
	if (abs->m_Size == MAX)
	{
		cout << "���ˣ����" << endl;
		return; 
	}
	else
	{
		//��Ӿ�����ϵ�ˣ������������Ա����䡢�绰����ַ
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;//������˫��Ƕ��ʽ�����ã����Կ��ź��鷳�����ýṹ������ĵ�������ʱ����ʽΪ�����ô˽ṹ���������ı�������+��->/.��+������Ҫ�����Ǹ��ṹ����Ǹ����ݣ�

		int gender;
		cout << "�������Ա�" << endl;
		cout << "����1Ϊ���ԣ�����2ΪŮ��" << endl;
		while (true)//�û���ֹ�û���������
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->personArray[abs->m_Size].m_Gender = gender;
				break;
			}
			cout << "�밴Ҫ������" << endl;//�������else����Ҳ����
		}						

		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "������绰����" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;

		abs->m_Size++;//���ڸ���ͨѶ¼��Ա��ʹÿ��Ӧ�õ���ϵ�������ܶ�Ӧ����
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(AddressBooks* abs)//��ʾ������ϵ��{����}
{
	if (abs->m_Size == 0)	//�ж�ͨѶ¼����
	{
		cout << "ͨѶ¼�տ���Ҳ" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "����:" << abs->personArray[i].m_Name << "\t\t";
			cout << "�Ա�:" << (abs->personArray[i].m_Gender == 1 ? "��":"Ů") << "\t\t";//<<����������ȼ�������Ŀ���������˲������ţ��ͱ����ˣ�<<���Ҳ����Լ���Ҫ��ֵ�����������ţ��Ƚ�����Ŀ��Ȼ����������ŵ��ַ��������ܱ�<<������
			cout << "����:" << abs->personArray[i].m_Age << "\t\t";
			cout << "�绰:" << abs->personArray[i].m_Phone << "\t\t";
			cout << "סַ:" << abs->personArray[i].m_Address << endl;
		}
	}
	system("pause");
	system("cls");
}

int inExist(AddressBooks* abs, string name)////���������ϵ���Ƿ���ڵ�{����}��[�����ڣ�������λ�ã��������ڣ�����-1]������1�Ǵ��ڵ�����������2�������Ҫɾ��������
{
	for (int i = 0; i < abs->m_Size; i++)//���������Բ�ѯ
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(AddressBooks* abs)//ɾ��ָ����ϵ��{����}
{
	cout << "������Ҫɾ��֮�˵�����" << endl;
	string name;
	cin >> name;
	//�����е��ú���,����result���շ���ֵ,����ֵΪҪɾ�����Ǹ��˵��Ǹ��������±ꣻ����ֵΪ-1Ϊû�鵽����֮�鵽��
	int result = inExist(abs, name);
	if (result != -1)
	{
		//���ҵ��˺�Ҫ����ɾ������
		for (int i = result; i < abs->m_Size; i++)
		{
			//����Ǩ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//���ڸ���ͨѶ¼ͳ�Ƶ�����
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBooks* abs)//������ϵ��{����}
{
	string name;
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	cin >> name;
	
	int result = inExist(abs, name);//��֮ǰ��װ�õĺ������ж���ϵ���Ƿ����
	if (result != -1)//�ҵ���
	{
		cout << "����:" << abs->personArray[result].m_Name << "\t\t";
		cout << "�Ա�:" << (abs->personArray[result].m_Gender == 1 ? "��" : "Ů") << "\t\t";
		cout << "����:" << abs->personArray[result].m_Age << "\t\t";
		cout << "�绰:" << abs->personArray[result].m_Phone << "\t\t";
		cout << "סַ:" << abs->personArray[result].m_Address << endl;
	}
	else
	{
		cout << "����֮�˲�����" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBooks* abs)//�޸���ϵ�˵�{����}
{
	string name;
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	cin >> name;

	int result = inExist(abs, name);
	if (result != -1)//�ҵ���Ҫ�޸ĵ���ϵ��
	{
		cout << "����:" << abs->personArray[result].m_Name << "\t\t";//�Ȱ��ҵ����Ǹ��˵���Ϣ��ӡ���������û�֪��һ��
		cout << "�Ա�:" << (abs->personArray[result].m_Gender == 1 ? "��" : "Ů") << "\t\t";
		cout << "����:" << abs->personArray[result].m_Age << "\t\t";
		cout << "�绰:" << abs->personArray[result].m_Phone << "\t\t";
		cout << "סַ:" << abs->personArray[result].m_Address << endl;

		cout << "��������Ҫ�޸ĵ��˵�����" << endl;
		string name;
		cin >> name;
		abs->personArray[result].m_Name = name;

		cout << "��������Ҫ�޸ĵ��˵��Ա�,��1��Ů2" << endl;
		int gender;
		while (true)//��ֹ�û�����
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->personArray[result].m_Gender = gender;
				break;
			}
			else { cout << "��������ȷ��ʽ" << endl; }
		}
		abs->personArray[result].m_Gender = gender;

		cout << "��������Ҫ�޸ĵ��˵�����" << endl;
		int age;
		cin >> age;
		abs->personArray[result].m_Age = age;

		cout << "��������Ҫ�޸ĵ��˵ĵ绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[result].m_Phone = phone;

		cout << "��������Ҫ�޸ĵ��˵�סַ" << endl;
		string address;
		cin >> address;
		abs->personArray[result].m_Address = address;

		cout << "�޸����" << endl;;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(AddressBooks* abs)//�����ϵ�˺���
{
	abs->m_Size = 0;
	cout << "������" << endl;
	system("pause");
	system("cls");
}

int main()
{
	AddressBooks abs;	//����ͨѶ¼�ṹ�����,����"AddressBooks",��ǰ�洴���Ľṹ�壬����[����]����"abs"�Ǳ�����
	abs.m_Size = 0;	//��ʼ��ͨѶ¼�е�ǰ��Ա����

	int select = 0;//��ʼ���������û�ѡ������ֵĵط�
	while (true)
	{
		showMenu();//�˵�����
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);//���õ�ַ�����ܸı�ʵ��
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}