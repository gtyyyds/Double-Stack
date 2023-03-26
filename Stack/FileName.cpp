#include<iostream>
using namespace std; 
typedef int SElemtype;
typedef struct
{
	int top[2], bot[2];//ջ����ջ��ָ��
	SElemtype* V;     //ջ����
	int m;            //ջ��������Ԫ������

}DblStack;
bool initDblStack(DblStack& s, int m)
{
	s.V = new SElemtype[m];
	if (s.V == NULL)
	{
		return false;
	}
	s.top[0] = -1;
	s.bot[0] = -1;
	s.top[1] = m;
	s.bot[1] = m;
	return true;
}
bool isEmpty(DblStack &s, int dir)
{
	if (s.bot[dir] == s.top[dir])
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isFull(DblStack &s)
{
	if (s.top[1] == s.top[0] + 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool pushDblStack(DblStack& s, int dir, SElemtype& elem)
{
	if (isFull(s))
	{
		return false;
	}
	if (dir == 0)
	{
		s.V[++s.top[0]] = elem;
	}
	else
	{
		s.V[--s.top[1]] = elem;
	}
	return true;
}
bool popDblStack(DblStack& s, int dir, SElemtype& elem)
{
	if (isEmpty(s, dir))
	{
		return false;
	}
	if (dir == 0)
	{
		elem = s.V[s.top[0]--];
	}
	else
	{
		elem = s.V[s.top[1]++];
	}
}
int main()
{
	DblStack s;
	int select;
	while (true)
	{
		cout << "1����ʼ��˫ջ��" << endl;
		cout << "2���ж�˫ջ���" << endl;
		cout << "3���ж�˫ջ����" << endl;
		cout << "4����        ջ" << endl;
		cout << "5����        ջ" << endl;
		cout << "0����        ��" << endl;
		cout << "���������ѡ�" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "���봴��������ɶ���Ԫ�ص�ջ��" << endl;
			int size;
			cin >> size;
			if (initDblStack(s, size))
			{
				cout << "�����ɹ���" << endl;
			}
			else
			{
				cout << "����ʧ�ܣ�" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 2:
		{
			cout << "�����ж���ջ��0��������ջ��1��" << endl;
			int dir;
			while (true)
			{
				cin >> dir;
				if (dir == 0 || dir == 1)
					break;
				cout << "����������" << endl;
			}
			if (isEmpty(s, dir))
			{
				cout << "ջ��Ϊ�գ�" << endl;
			}
			else
			{
				cout << "ջ��Ϊ�գ�" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 3:
		{
			if (isFull(s))
			{
				cout << "ջ��������" << endl;
			}
			else
			{
				cout << "ջ��δ����" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 4:
		{
			cout << "��������ջ�����ݺ����ĸ�ջ��0��1��" << endl;
			SElemtype elem;
			int dir;
			cin >> elem;
			while (true)
			{
				cin >> dir;
				if (dir == 0 || dir == 1)
					break;
				cout << "ջ��ѡ������������0��1" << endl;
			}
			if (pushDblStack(s, dir, elem))
			{
				cout << elem << "����" << dir << "ջ" << endl;
			}
			else
			{
				cout << "��ջʧ�ܣ�" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 5:
		{
			cout << "������ĸ�ջ����г�ջ������0����1��" << endl;
			int dir;
			SElemtype elem;
			while (true)
			{
				cin >> dir;
				if (dir == 1||dir==0)
					break;
				cout << "������0����1" << endl;
			}
			if (popDblStack(s, dir, elem))
			{
				cout << elem << "�ѳ�" << dir << "ջ" << endl;
			}
			else
			{
				cout << "��ջʧ��!" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		default:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		}

	}
}