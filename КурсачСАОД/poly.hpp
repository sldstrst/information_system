#ifndef ����������_POLY_H
#define ����������_POLY_H
#include<string>
using namespace std;
struct poly 
{
	string numb; //��������������� �����
	string fio_d; //��� �����
	string date, time; //���� � ����� ���������
	poly *prev; // ��������� �� ���������� �������
	poly *next; // ��������� �� ��������� �������
};
void add_poly(poly*& head, poly hosp);
void print_poly(poly* head);
void sort_poly(poly*headhead, poly*head, poly*end);
poly*delete_poly(poly*head);
poly* search_poly(poly*head, bool &flag, string A);
#endif ����������_POLY_H
