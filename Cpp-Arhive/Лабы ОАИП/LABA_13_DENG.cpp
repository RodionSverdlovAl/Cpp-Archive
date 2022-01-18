#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>

//Генератор случайных чисел в диапазоне -100-0 сведения о разработчике, выход из приложени

using namespace std;

void p1() {
	system("cls");
	cout <<"Случайное чисто в диапазоне от 0 до 100:  "<<rand() % 101 << endl;
	 system("pause");
	 system("cls");
}
void p2() {
	system("cls");
	cout << "Разработчик: Пинчук Денис" << endl;
	cout << "ИПФ - БНТУ" << endl;
	cout << "Senior C++ Developer :)" << endl;
	system("pause");
	system("cls");
}


int main()
{
	system("mode con cols=50 lines=20"); // размер консоли

	const int NotUsed = system("color 3A"); // цвет текста и фона

    setlocale(LC_ALL, "ru");
	bool key = true;
	while (key)
	{
		cout << "[1] - Гениратор случайных чисел" << endl;
		cout << "[2] - Сведения о разработчике" << endl;
		cout << "[3] - Выйти из программы" << endl;

		switch (_getche())
		{
		case '1': {
			p1();
		}break;
		case '2': {
			p2();
		}break;
		case '3': {
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

