#ifndef КУРСАЧСАОД_POLY_H
#define КУРСАЧСАОД_POLY_H
#include<string>
using namespace std;
struct poly 
{
	string numb; //регистрационный номер
	string fio_d; //фио врача
	string date, time; //дата и время посещения
	poly *prev; // указатель на предыдущий элемент
	poly *next; // указатель на следующий элемент
};
void add_poly(poly*& head, poly hosp);
void print_poly(poly* head);
void sort_poly(poly*headhead, poly*head, poly*end);
poly*delete_poly(poly*head);
poly* search_poly(poly*head, bool &flag, string A);
#endif КУРСАЧСАОД_POLY_H
