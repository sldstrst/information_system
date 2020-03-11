#include"poly.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

poly * unique_key(poly *head, string numb, string fio_d, string date, string time;)
{
	poly *temp;
	for (temp = head; temp != NULL; temp = temp->next)
		if (Aa(temp->numb, numb) && Aa(temp->fio_d, date) && temp->cost == cost) break;
	return temp;

void add_poly(poly*& head, poly hosp) {
	poly *cur = head;
	if (head == NULL) {
		head = new poly;
		head->date = hosp.date;
		head->fio_d = hosp.fio_d;
		head->numb = hosp.numb;
		head->time = hosp.time;
		head->next = head->prev = head;
	}
	else {
		poly *temp = new poly;
		temp->date = hosp.date;
		temp->fio_d = hosp.fio_d;
		temp->numb = hosp.numb;
		temp->time = hosp.time;
		temp->next = head;
		head->prev->next = temp;
		temp->prev = head->prev;
		head->prev = temp;
	}
}
poly* mid(poly*head, poly*end,bool flag)
{
	if (head == end) return head;
	if (flag == true) { flag = false; mid(head->next, end,flag); }
	else { flag = true; mid(head, end->prev, flag); }
}
int kol(poly*headhead,poly*head)
{
	int k = 0;
	while (head != headhead)
	{
		k++;
		head = head->prev;
	}
	return k;
}
poly*ptr(poly*headhead, int i)
{
	poly*temp = headhead;
	for (int j = i; j > 0; j--)
		temp = temp->next;
	return temp;
}
void sort_poly(poly*headhead, poly*head, poly*end)
{
	if (end == head) return;
	if (end == head->next)
	{
		if (end->fio_d < head->fio_d)
		{
			poly temp;
			temp.date = end->date;
			temp.fio_d = end->fio_d;
			temp.numb = end->numb;
			temp.time = end->time;
			end->date = head->date;
			end->fio_d = head->fio_d;
			end->numb = head->numb;
			end->time = head->time;
			head->date = temp.date;
			head->fio_d = temp.fio_d;
			head->numb = temp.numb;
			head->time = temp.time;
		}
		return;
	}
	bool flag = true;
	poly*m = mid(head, end, flag);
	sort_poly(headhead,head,m);
	sort_poly(headhead,m->next, end);
	poly*buf = NULL;
	poly h;
	int start=kol(headhead,head),b1=start, e1=kol(headhead,m->next), b2=e1, endk= kol(headhead, end);
	int bufsize = 0;
	while (bufsize < endk - start)
	{
		if (b1 > e1 || (b2 < endk && ptr(headhead, b2)->fio_d <= ptr(headhead, b1)->fio_d))
		{
			h = *ptr(headhead, b2);
			add_poly(buf, h);
			++b2;
		}
		else
		{
			h = *ptr(headhead, b1);
			add_poly(buf, h);
			++b1;
		}
	}
	
	for (int i = kol(headhead, head); i < endk; ++i)
	{
		ptr(headhead, i)->date = ptr(buf, i - start)->date;
		ptr(headhead, i)->fio_d = ptr(buf, i - start)->fio_d;
		ptr(headhead, i)->numb = ptr(buf, i - start)->numb;
		ptr(headhead, i)->time = ptr(buf, i - start)->time;
	}
}

void print_poly(poly*head)
{
	poly*temp = head;
	if (head != NULL)
	{
		cout << "\n ----------------------------------------------------------------------------------" << endl;
		cout << " | Регистрационный № |      ФИО врача      |  Дата посещения    |  Время посещения  |" << endl;
		cout << " ------------------------------------------------------------------------------------" << endl;
		cout << " " << temp->numb << " " << temp->fio_d << endl;
		temp = temp->next;
	}
	while (temp!=head)
	{
		cout << temp->fio_d << " " << temp->numb << endl;
		temp = temp->next;
	}
}
poly*delete_poly(poly*head)
{
	poly*temp = head;
	while (temp->next != head)
		temp = temp->next;
	temp->next = head->next;
	delete head;
	return temp;
}
poly* search_poly(poly*head, bool &flag, string A)
{
	poly*temp = head;
	if (temp != NULL)
	{
		if (temp->fio_d == A) { flag = true; }
		else
		{
			temp = temp->next;
			while (temp != head)
			{
				if (temp->fio_d == A) { flag = true; break; }
				temp = temp->next;
			}
		}
	}
	return temp;
}
