#include "Admin.h"
#include <iostream>
#include <fstream>
#include <string>
#include<fstream>

void Admin::add_information()
{
	int t, e;
	string y, n, g, dn, a;
	cout << "Введите название фильма: "; cin >> n;
	cout << "Введите год: "; cin >> y;
	cout << "Введите хронометраж (в минутах): "; cin >> t;
	cout << "Введите название жанра: "; cin >> g;
	cout << "Введите имя режжисера (Имя_Фамилия): "; cin >> dn;
	cout << "Введите имена актеров(Имя_Фамилия:Имя_Фамилия): "; cin >> a;
	cout << "Введите колличество серий: "; cin >> e;
	Films_to_file(n,y,t,g,dn,a,e);//создание фильма и запись его в файл
}

void Admin::Delete_information_about_films()
{
	ofstream InfFile;
	InfFile.open(Information, ofstream::trunc);
	cout << "Информация о фильмах удалена" << endl;
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
			cout << "[1] Добавить фильм" << endl;
			cout << "[2] Просмотр информации о фильмах" << endl;
			cout << "[3] Удалить информацию о всех  фильмах" << endl;
			cout << "[4] Удалить информацию об определенном фильме" << endl;
			cout << "[5] Поиск фильма" << endl;
			cout << "[6] Удалить определенного пользователя" << endl;
			cout << "[7] Удалить всех пользователей" << endl;
			cout << "[8] Просмотр аккаунтов всех пользователей" << endl;
			cout << "[9] Зарегистрировать пользователя" << endl;
			cout << "[10] Редактировать информацию о фильме" << endl;
			cout << "[0] Назад" << endl;
			int change1; cin >> change1; system("cls");
			switch (change1)
			{
			case 1:
				A.add_information(); break;
			case 2:
				A.view_inf_about_films(); break;
			case 3:
				A.Delete_information_about_films(); break;
			case 4:
				A.DeleteOneFilm(); break;
			case 5:
				A.search_film(); break;
			case 6:
				A.DeteteUser(); break;
			case 7:
				A.Delete_All_Users(); break;
			case 8:
				A.View_Users_Accounts(); break;
			case 9:
				A.RegistrationFunction(); break;
			case 10:
				A.changeFilm(); break;
			case 0:
				exitAM = false; break;
			default:
				cout << "Error" << endl;
				break;
			}
		}
}