#include<string>
#include<iostream>
#include <cstdlib>
#include"patient.hpp"
#include<cmath>
using namespace std;
void begin(patient Table[])
{
	for (int j(0); j < 350; j++)
	{
		Table[j].key = '-'; // призна, что ячейка не занята
	}
}
int h(string key)
{
	int address(0), h(3), code;
	for (int i(0); i<6; i++)
	{
		code = int(key[i]);
		address += code*pow(h, i);
	}
	address = int(sqrt(address));
	address %= 350;
	return address;
}
int add_p(patient Table[], patient Patient, int N)
{
	int i = h(Patient.id_p);
	if (Table[i].key == 'd' || Table[i].key == '-')
	{
		Table[i] = Patient;
		Table[i].key = '+';//пометили, что ячейка заполнена
		return 1;
	}
	else
	{
		while (true)
		{
			i--;
			if (i < 0) i += 350;
			if (i == h(Patient.id_p))  break;
			else
			{
				if (Table[i].key == '-' || Table[i].key == 'd')
				{
					Table[i] = Patient;
					Table[i].key = '+';
					return 1;
				}
			}
		}
	}
	return 0;
}
int search_from_i(string key, bool &flag, patient Table[])// поиск по id
{
	return 0;///////////////////////////
};
void search_from_f(string b, bool &flag, patient Table[])//поиск по фио
{

};
int search_p()
{
		int b;
		cout << "1-Поиск по регистрауионному номеру" << endl;
		cout << "2-Поиск по ФИО";
		cin >> b;
		while (cin.fail() || b<0 || b>2)
		{
			cout << "Ошибка.\nВведите заного : ";
			cin.clear();
			cin.sync();
			cin >> b;
		}
		switch (b)
		{
		case 1:
			int search_from_i(string key, bool &flag, patient Table[]);
			break;
		case 2:
			void search_from_f(string b, bool &flag, patient Table[]);
			break;
		}
		return 0;/////////////////
}
int del_p(patient Table[], int h)
{
	Table[h].key = 'd';
	return 1;
}
void print_p(patient Table[]) 
{
	for (int j(0); j < 350; j++)
	{
		if (Table[j].key != '-' &&Table[j].key != 'd') cout << Table[j].id_p << " " << Table[j].fio_p << " " << Table[j].home << " " << Table[j].work << ((Table[j].age == true)) << endl;
	}
}

