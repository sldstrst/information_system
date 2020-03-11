#include<iostream>
#include<Windows.h>
#include<string>
#include<iomanip>
#include<cstring>
#include<fstream>
#include"patient.hpp"
#include"doctors.hpp"
#include"poly.hpp"
using namespace std;
patient Table[350] = {};
int ck()
{
	int h = 0;
	while (!(cin >> h))
	{
		cout << "������. ������� ��������� \n";
		cin.clear();
		while (cin.get() != '\n'){}
	}
	return h;
}
bool A(char &a)
{
	bool flag = false;
	char A[10] = { '0','1','2','3','4','5','6','7','8','9'};
	for (int i = 0; i < 10; ++i)
	{
		if (A[i] == a) { flag = true; break; }
	}
	return flag;
}
bool N(char a)
{
	bool flag = false;
	if (a - 48 <= 9 && a - 48 >= 0) flag = true;
	return flag;
}
string check_p(string a)
{
	bool flag = false;
	while (!flag)
	{
		if (a.size() == 8)
		{
			if (!(A(a[0]) && A(a[4]) && A(a[5]) && N(a[1]) && N(a[2]) && N(a[3]) && N(a[6]) && N(a[7]))) { cout << "������� ������ "; cin >> a; }
			else flag = true;
		}
		else { cout << "������� ������ "; cin >> a; }
	}
	return a;
}
void menu1(int &N)// ��������
{
	int activity = -1, h, k; patient Patient; bool flag;
	while (activity != 0)
	{
		system("cls");
		cout << "1-���������� ������ ��������" << endl;
		cout << "2-�������� ������ � ��������" << endl;
		cout << "3-�������� ������ � ���������" << endl;
		cout << "4-����� ���� ��������� �� ����� �� �����" << endl;
		cout << "5-����� ��������" << endl;
		cout << "0-����� � ������� ����" << endl;
		cout << "�������� ��������: ";
		activity = ck();
		switch (activity)
		{
		case 1:
			if (N < 350)
			{
				cout << "��������������� �(�MM-NNNNNN�, ��� MM � ����� �������, NNNNNN � ���������� �����)\n";
				cin >> Patient.id_p;
				Patient.id_p = check_p(Patient.id_p);
				flag = false;
				search_from_i(Patient.id_p, flag, Table);
				if (!flag)
				{
					cout << "��� ��������\n";
					cin >> Patient.fio_p;
					cout << "��� ��������\n";
					cin >> Patient.age;
					cout << "����� ����������\n";
					cin >> Patient.home;
					cout << "����� ������(�����)\n";
					cin >> Patient.work;
					N += add_p(Table, Patient, N);
				}
				else cout << "��� ����������\n";
			}
			break;
		case 2:
			cout << "��������������� �(�MM-NNNNNN�, ��� MM � ����� �������, NNNNNN � ���������� �����)\n\n";
			cin >> Patient.id_p;
			Patient.id_p = check_p(Patient.id_p);
			flag = false;
			h = search_from_i(Patient.id_p, flag, Table);
			if (flag)  N -= del_p(Table, h);
			break;
		case 3:
			begin(Table);
			cout << "�������\n";
			system("pause");
			break;
		case 4:
			print_p(Table);
			system("pause");
			break;
		case 5:
			search_p();
			break;
		}
	}
}
void menu2(doctors*&tree) //�����
{
	int activity = -1;
	doctors man; bool flag; doctors *m = NULL;
	doctors*f = NULL;
	string c;
		while (activity != 0)
		{
			system("cls");
			cout << "1-���������� ������ �����" << endl;
			cout << "2-�������� ������ � �����" << endl;
			cout << "3-�������� ������ � ������" << endl;
			cout << "4-����� ���� ������ �� ����� �� �����" << endl;
			cout << "5-����� �����" << endl;
			cout << "0-����� � ������� ����" << endl;
			cout << "�������� ��������: ";
			activity = ck();
			switch (activity)
			{
			case 1:
				flag = false;
				if (!flag)
				{
					cout << "������� � �������� ����� ";
					cin >> man.fio_d;
					cout << "��������� ";
					cin >> man.prof;
					cout << "������� ";
					cin >> man.kab;
					cout << "������ ";
					cin >> man.graf;
					tree = add_value(tree, man);
				}
				else cout << "����� ���� ����������\n";
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			}
		}
}
void menu3(poly*&Poly, int &N, doctors *&tree)
{
	int activity = -1, i;
	string c;
	bool flag = false;
	poly *m = new poly, hosp;
	while (activity != 0)
	{
		system("cls");
		cout << "1-����������� ������ �������� ����������� � �����" << endl;
		cout << "2-����������� �������� ����������� � �����" << endl;
		cout << "3-���������� �����������" << endl;
		cout << "4-����� ����������� �� �����" << endl;
		cout << "5-������ � ����" << endl;
		cout << "6-������ �� �����" << endl;
		cout << "0-����� � ������� ����" << endl;
		cout << "�������� ��������: ";
		activity = ck();
		switch (activity)
		{
		case 1:
			if ()
			{
			cout << "������� ��������������� �����:\n";
			cin >> hosp.numb;
			cout << "������� ������� � ��������\n";
			cin >> hosp.fio_d;
			cout << "������� ���� ���������\n";
			cin >> hosp.date;
			cout << "������� ����� ���������\n";
			cin >> hosp.time;
			add_poly(Poly, hosp);
			}
			else cout << "��� ���� � ����� ��� ������. �������� ������ ���� ��� �����\n";
			system("pause");
			break;
		case 2:
			delete_poly(poly*head);
			break;
		case 3:
			sort_poly(Poly,Poly,Poly->prev);
			cout << "��������������\n";
			system("pause");
		case 4:
			print_poly(Poly);
			break;
		case 5:
			break;
		case 6:
			break;
		}
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int activity = -1, N = 0;
	doctors *tree = NULL;
	poly*Poly = NULL;
	while (activity != 0)
	{
		system("cls");
		cout << "����� ����������" << endl;
		cout << "1-��������" << endl;
		cout << "2-�����" << endl;
		cout << "3-������ � ������� ����������� � �����" << endl;
		cout << "0-����� �� ���������" << endl;
		cout << "�������� ��������: ";
		activity = ck();
		switch (activity)
		{
		case 1:
			menu1(N);
			break;
		case 2:
			menu2(tree);
			break;
		case 3:
			menu3(Poly, N, tree);
			break;
		}
	}
}