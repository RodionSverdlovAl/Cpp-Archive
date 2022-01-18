#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <clocale>
#include <conio.h>
using namespace std;

string Wday(int tm) {
	switch (tm)
	{
	case 1: {
		return "Понедельник";
	}break;
	case 2: {
		return "Вторник";
	}break;
	case 3: {
		return "Среда";
	}break;
	case 4: {
		return "Четверг";
	}break;
	case 5: {
		return "Пятница";
	}break;
	case 6: {
		return "Суббота";
	}break;
	case 7: {
		return "Воскресенье";
	}break;

	default:
		break;
	}
}


void p1() {
	system("cls");
	time_t t = time(NULL);
	struct tm* T = localtime(&t);
	cout << T->tm_min << endl;
	system("pause");
	system("cls");
}

void p2() {
	system("cls");
	time_t t = time(NULL);
	struct tm* T = localtime(&t);
	cout << T->tm_hour << endl;
	system("pause");
	system("cls");
}

void p3() {
	system("cls");
	time_t t = time(NULL);
	struct tm* T = localtime(&t);
	cout << T->tm_sec << endl;
	system("pause");
	system("cls");
}

void p4() {
	system("cls");
	time_t t = time(NULL);
	struct tm* T = localtime(&t);
	cout << Wday(T->tm_wday)<< endl;
	system("pause");
	system("cls");
}


int main() {
	setlocale(LC_ALL, "ru");
	bool key = true;
	time_t t = time(NULL);
	struct tm* T = localtime(&t);



	while (key)
	{
		cout << "[1] - Минута" << endl;
		cout << "[2] - Час" << endl;
		cout << "[3] - Секунда" << endl;
		cout << "[4] - День недели" << endl;
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
