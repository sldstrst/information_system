#ifndef 视醒雷牙文_PATIENT_H
#define 视醒雷牙文_PATIENT_H
#include<string>
using namespace std;
struct patient
{
	string id_p,fio_p, home, work;
	int age; 
	char key;
};
void begin(patient Table[]);
int h(string key);
int add_p(patient Table[], patient Patient, int N);
int search_p();
int search_from_i(string key, bool &flag, patient Table[]);
void search_from_f(string b, bool &flag, patient Table[]);
int del_p(patient Table[], int h);
void print_p(patient Table[]);
#endif 视醒雷牙文_PATIENT_H