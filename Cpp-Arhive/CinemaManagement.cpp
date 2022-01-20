#include <iostream>
#include <string>
#include <fstream>


#include "Registration.h"
#include "Films.h"
#include "Admin.h"
#include"User.h"
using namespace  std;

int main()
{
	setlocale(LC_ALL, "ru");
	int change22; bool exit = true;
	Registration R;
	Admin A;
	User U;

	while (exit)
	{
		cout << "[****Управление кинотеатром****]" << endl;
		cout << "[1] Вход в программу" << endl; cout << "[2] Регистрация пользователя" << endl; cout << "[3] Выход из программы" << endl;; cin >> change22;
		system("cls");
		switch (change22)
		{
		case 1:
			R.EnterToProgram();
			if (R.Access == 1 && R.Role == 1) {
				A.MenuAmin();
				R.Role = 0;
				R.Access = 0;
			}
			else if (R.Access == 1 && R.Role == 0) {
				U.User_Menu();
				R.Role = 0;
				R.Access = 0;
			}
			else {
				cout << "Неверно введен логин или пороль!!!" << endl;
				system("pause");
				system("cls");
			}break;
		case 2:
			R.RegistrationFunction(); break;
		case 3:
			exit = false; break;
		default:
			cout << "Error choose 1 or 2 or 3" << endl;
			break;
		}
	}
}