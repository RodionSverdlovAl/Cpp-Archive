#include "User.h"
#include <iostream>
#include<fstream>
#include<string>
using namespace std;


void User::User_Menu()
{
	User U;
	bool exitUM = true;
	while (exitUM)
	{
		cout << "[----МЕНЮ----]" << endl;
		cout << "[1] Просмотр информации о рейсах" << endl;
		cout << "[2] Поиск рейса" << endl;
		cout << "[3] Сортировка рейсов" << endl;
		cout << "[4] Построить маршрут" << endl;
		cout << "[0] Назад" << endl;
		int change0;
		cin >> change0;
		system("cls");
		switch (change0)
		{
		case 1:
			view_route(); break;
		case 2:
			search(); break;
		case 3:
			sort(); break;
		case 4:
			bild_route(); break;
		case 0:
			exitUM = false;
			system("cls");
			break;
		default:
			cout << "Неверно выбран пункт меню" << endl;
			break;
		}
	}

}
