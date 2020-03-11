#include"doctors.hpp"
#include<iostream>
using namespace std;
doctors* search(doctors*head, string significance, bool &flag)
{
	doctors*ptr = head;
	if (!flag)
	{
		if (ptr != NULL)
		{
			if (significance == ptr->prof) { flag = true; return ptr; }
			else
			{
				if (significance < ptr->prof) { return search(ptr->left, significance, flag); }
				else { return search(ptr->right, significance, flag); }
			}
		}
		else return ptr;
	}
	else return ptr;
}
int height(doctors*ptr)
{
	if (ptr != NULL)
	{
		return ptr->height;
	}
	else return 0;
}
int bf(doctors*ptr)
{
	return height(ptr->right) - height(ptr->left);
}
void correct_height(doctors*ptr)
{
	int L = height(ptr->left), R = height(ptr->right);
	ptr->height = (L > R ? L : R) + 1;
}
doctors* RIGHT(doctors*ptr)
{
	doctors*ptr1 = ptr->left;
	ptr->left = ptr1->right;
	ptr1->right = ptr;
	correct_height(ptr1);
	correct_height(ptr);
	return ptr1;
}
doctors* LEFT(doctors*ptr)
{
	doctors*ptr1 = ptr->right;
	ptr->right = ptr1->left;
	ptr1->left = ptr;
	correct_height(ptr1);
	correct_height(ptr);
	return ptr1;
}
doctors* balance(doctors*ptr)
{
	correct_height(ptr);
	if (bf(ptr) == 2)
	{
		if (bf(ptr->right) < 0) ptr->right = RIGHT(ptr->right);
		return LEFT(ptr);
	}
	if (bf(ptr) == -2)
	{
		if (bf(ptr->left) > 0) ptr->left = LEFT(ptr->left);
		return RIGHT(ptr);
	}
	return ptr;
}
doctors* add_value(doctors*head, doctors man)
{
	if (head == NULL)
	{
		head = new doctors;
		head->fio_d = man.fio_d;
		head->prof = man.prof;
		head->graf = man.graf;
		head->kab = man.kab;
		head->height = 1;
		head->left = NULL; head->right = NULL;
	}
	if (head->prof > man.prof) head->left = add_value(head->left, man);
	if (head->prof < man.prof) head->right = add_value(head->right, man);
	return balance(head);
}
doctors* findmin(doctors* ptr)
{
	if (ptr->left != NULL)
	{
		return findmin(ptr->left);
	}
	else return ptr;
}
doctors* removemin(doctors* ptr)
{
	if (ptr->left == NULL) return ptr->right;
	ptr->left = removemin(ptr->left);
	return balance(ptr);
}
doctors* delete_value(doctors*head, string elemant)
{
	if (head == NULL) return NULL;
	if (head->prof > elemant) head->left = delete_value(head->left, elemant);
	else if (head->prof<elemant) head->right = delete_value(head->right, elemant);
	else
	{
		doctors*L = head->left, *R = head->right;
		delete head;
		if (R == NULL) return L;
		doctors*m = findmin(R);
		m->right = removemin(R);
		m->left = L;
		return balance(m);
	}
	return balance(head);
}
void show_d(doctors*&head)
{
	if (head == NULL) return;
	show_d(head->left);
	show_d(head->right);
	cout << head->fio_d << " " << head->prof << head->kab << " " << head->graf << endl;
}
void clear_all_d(doctors*&head)
{
	if (head == NULL) return;
	clear_all_d(head->left);
	delete head;
	clear_all_d(head->right);
}
bool search_word(string fio, string f)
{
	int i = -1, j;
	do {
		i++; j = 0;
		while (j < f.size() && fio[i + j] == f[j])
		{
			j++;
		}
	} while (j != f.size() || i > fio.size() - f.size());
	return (j != f.size()) ? false : true;
}
void search_fio(doctors*head, string f, bool &flag)
{
	if (head == NULL) return;
	search_fio(head->left, f, flag);
	if (search_word(head->fio_d, f)) { cout << head->fio_d << " " << head->prof << head->kab << " " << head->graf << endl; flag = true; }
	search_fio(head->right, f, flag);
}
void search_prof(doctors*head, string f, bool &flag)
{
	if (head == NULL) return;
	search_prof(head->left, f, flag);
	if (search_word(head->prof, f)) { cout << head->fio_d << " " << head->prof << head->kab << " " << head->graf << endl; flag = true; }
	search_prof(head->right, f, flag);
}