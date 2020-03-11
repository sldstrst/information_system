#ifndef 视醒雷牙文_DOCTORS_H
#define 视醒雷牙文_DOCRORS_H
#include<string>
using namespace std;
struct doctors
{
	string fio_d, prof, graf;
	int height, kab;
	doctors*left, *right;
};
doctors* search(doctors*head, string significance, bool &flag);
int height(doctors*ptr);
int bf(doctors*ptr);
void correct_height(doctors*ptr);
doctors* RIGHT(doctors*ptr);
doctors* LEFT(doctors*ptr);
doctors* balance(doctors*ptr);
doctors* add_value(doctors*head, doctors men);
doctors* findmin(doctors* ptr);
doctors* removemin(doctors* ptr);
doctors* delete_value(doctors*head, string element);
void show_d(doctors*&head);
void clear_all_d(doctors*&head);
void search_fio(doctors*head, string f, bool &flag);
void search_prof(doctors*head, string f, bool &flag);
#endif 视醒雷牙文_DOCTORS_H
