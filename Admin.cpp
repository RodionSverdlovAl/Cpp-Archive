#include "Admin.h"
#include <iostream>
#include <fstream>
#include <string>
#include<fstream>

using namespace std;

void Admin::View_Users_Accounts()
{
	Registration R1;
	ifstream UserFile;
	string path = R1.getRegDATA();
	UserFile.open(path);
	if (!UserFile.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		char ch;
		cout << "[Аккаунты всех пользователей]" << endl;
		while (UserFile.get(ch))
		{
			cout << ch;
		}
	}
	UserFile.close();
	system("pause");
	system("cls");
}

void Admin::Delete_information_about_routes()
{
	ofstream InfFile;
	InfFile.open(RouteInformation, ofstream::trunc);
	cout << "Информация о всех рейсах удалена" << endl;
	system("pause");
	system("cls");
	InfFile.close();
}

void Admin::Delete_All_Users()
{
	Registration R1;
	ofstream UFile;
	string path = R1.getRegDATA();
	UFile.open(path, ofstream::trunc);
	cout << "Аккаунты всех пользователей удалены" << endl;
	system("pause");
	system("cls");
	UFile.close();
}

void Admin::DeteteUser()
{
	int size = 0;
	ifstream InfFile;
	InfFile.open(getRegDATA());
	Registration R;
	while (InfFile.peek() != EOF)
	{
		InfFile >> R.LoginUser1; InfFile.get();
		InfFile >> R.PasswordUser1; InfFile.get();
		size++;
	}
	InfFile.close();

	int i = 0;
	Registration* arr = new Registration[size];
	ifstream InfFile1;
	InfFile1.open(getRegDATA());
	while (InfFile1.peek() != EOF)
	{
		InfFile1 >> arr[i].LoginUser1; InfFile1.get();
		InfFile1 >> arr[i].PasswordUser1; InfFile1.get();
		i++;
	}
	InfFile1.close();

	string tmp;
	int n = -1;
	cout << "Введите логин пользователя которого хотите удалить: "; cin >> tmp;
	for (int j = 0; j < size; j++) {
		if (arr[j].LoginUser1 == tmp)
			n = j;
	}
	if (n == -1)
		cout << "Пользователя с таким логином нет!" << endl;
	else {
		for (int j = n; j < size - 1; j++)
			arr[j] = arr[j + 1];
		size--;
	}
	ofstream InfFile2;
	InfFile2.open(getRegDATA());
	for (int j = 0; j < size; j++) {
		InfFile2 << arr[j].LoginUser1 << endl;
		InfFile2 << arr[j].PasswordUser1 << endl;
	}
	InfFile2.close();
	cout << "Пользователь " << "[" << tmp << "] " << "удален" << endl;
	delete[] arr;
	system("pause");
	system("cls");
}

void Admin::MenuAmin()
{
	Registration R;
	bool exitAM = true;
	Admin A;
	while (exitAM)
	{
		cout << "Меню Администратора" << endl;
		cout << "[1] Добавить маршрут в расписание" << endl; // сделал
		cout << "[2] Просмотр информации о маршрутах" << endl; // сделал
		cout << "[3] Удалить информацию о маршрутах" << endl; // сделал
		cout << "[4] Удалить информацию об определенном маршруте" << endl; // ---------------------------------
		cout << "[5] Поиск маршрута" << endl; // сделал
		cout << "[6] Удалить определенного пользователя" << endl; // готово
		cout << "[7] Удалить всех пользователей" << endl; // готово
		cout << "[8] Просмотр аккаунтов всех пользователей" << endl; // готово
		cout << "[9] Зарегистрировать пользователя" << endl; // готово
		cout << "[10] Редактировать информацию о рейсе" << endl; // ---------------------------------------
		cout << "[11] Сортировка" << endl; // сделал
		cout << "[12] Построить маршрут" << endl; // сделал
		cout << "[0] Назад" << endl;
		int change1; cin >> change1; system("cls");
		switch (change1)
		{
		case 1:
			add_route(); break;
		case 2:
			view_route(); break;
		case 3:
			A.Delete_information_about_routes(); break;
		case 4:
			delete_route(); break;
		case 5:
			search(); break;
		case 6:
			A.DeteteUser(); break;
		case 7:
			A.Delete_All_Users(); break;
		case 8:
			A.View_Users_Accounts(); break;
		case 9:
			A.RegistrationFunction(); break;
		case 10:
			edit(); break;
		case 11:
			sort(); break;
		case 12: { // индивидуальное задание
			bild_route(); break;
		}
		case 0:
			exitAM = false; break;
		default:
			cout << "Error" << endl;
			break;
		}
	}
}