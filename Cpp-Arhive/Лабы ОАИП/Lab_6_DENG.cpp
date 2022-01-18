#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <clocale>
#include <iostream>
using namespace std;
//Минута:час:секунда:день_недели

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

int main()
{
	setlocale(LC_ALL, "ru");
	time_t t = time(NULL);
	struct tm* T = localtime(&t);
	/*printf("Текущая дата: %d.%02d.%04d\n", T->tm_mday, T->tm_mon+1, 1900 + T->tm_year);
	cout << ctime(&t)<< T->tm_hour;*/

	cout<<T->tm_min<<":" << T->tm_hour << ":" << T->tm_sec << ":" << Wday(T->tm_wday);
	return 0;
}