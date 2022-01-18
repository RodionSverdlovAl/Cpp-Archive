#include <iostream>
#include <conio.h>
using namespace std;


void p1() {
	system("cls");
	cout << "Пинчук Денис Батькович" << endl;
	system("pause");
	system("cls");
}

void p2(){
	system("cls");
	cout << "2348918" << endl;
	system("pause");
	system("cls");
}

void p3(){
	system("cls");
	cout << "ИПФ" << endl;
	system("pause");
	system("cls");
}

void p4() {
	system("cls");
	cout << "БНТУ" << endl;
	system("pause");
	system("cls");
}


int main() {
	setlocale(LC_ALL, "ru");
	bool key = true;
	

	while (key)
	{
		cout << "[1] - ФИО" << endl;
		cout << "[2] - Номер группы" << endl;
		cout << "[3] - Факультет" << endl;
		cout << "[4] - ВУЗ" << endl;
		cout << "[5] - Выйти из программы" << endl;
		
		switch (_getche())
		{
		case '1': {
			p1();
		}break;
		case '2': {
			p2();
		}break;
		case '3': {
			p3();
		}break;
		case '4': {
			p4();
		}break;
		case '5': {
			key = false;
		}break;
		default:
			cout << " НЕВЕРНО ВЫБРАН ПУНКТ МЕНЮ !!!!" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}
