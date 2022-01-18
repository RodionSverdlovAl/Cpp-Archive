#include "Registration.h"
#include <iostream>
#include <fstream>

void Registration::RegistrationFunction()
{
	cout << "******* Регистрация *******" << endl;
	cout << "Введите логин: "; cin >> LoginUser;
	cout << "Введите пороль:"; cin >> PasswordUser;
	ofstream RegFile;
	RegFile.open(RegDATA, ofstream::app);
	RegFile << LoginUser << endl;
	RegFile << PasswordUser << endl;
	RegFile.close();
	system("pause");
	system("cls");
}

void Registration::EnterToProgram()
{
	int exit1 = true;
	while (exit1)
	{
		cout << "[0] Войти в режим пользователя" << endl;
		cout << "[1] Войти в режим администратора" << endl;
		cout << "[2] Назад" << endl;
		int change;
		cin >> change;
		system("cls");
		string log,log1, pass,pass1;
		ifstream fileIN;
		switch (change)
		{
		case 0:
			cout << "Логин: "; cin >> log;
			cout << "Пороль: "; cin >> pass;

			//ifstream fileIN;
			fileIN.open(RegDATA);
			if (!fileIN.is_open()){
				cout << "Ошибка открытия файла с логином и поролем!" << endl;
				Access = 0;
			}
			else{
				ifstream fileIN;
				fileIN.open(RegDATA);
				while (fileIN.peek() != EOF)
				{
					fileIN >> LoginUser; fileIN.get();  
					fileIN >> PasswordUser; fileIN.get();
					//fileIN.get();
					if (log == LoginUser && pass == PasswordUser){
						Access = 1;
						Role = 0;
						break;
					}
					else { Access = 0; Role = 0;}
				}
			}
			fileIN.close();
			system("cls");
		    exit1 = false; break;
		case 1:
			cout << "Логин: "; cin >> log;
			cout << "Пороль: "; cin >> pass;
			system("cls");
			if (log == LoginAdmin && pass == PasswordAdmin) {
				Access = 1; Role = 1;
			}; exit1 = false; break;
		case 2:
			exit1 = false; break;
		default:
			cout << "Ошибка! Такого пункта меню не существует. Введите 0 1 или же 2" << endl;
			break;
		}
	}
	
}

string Registration::getRegDATA()
{
	return RegDATA;
}