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
		cout << "[----����----]" << endl;
		cout << "[1] �������� ���������� � �������" << endl;
		cout << "[2] ����� ������" << endl;
		cout << "[0] �����" << endl;
		int change0;
		cin >> change0;
		system("cls");
		switch (change0)
		{
		case 1:
			U.view_inf_about_films(); break;
		case 2:
			U.search_film(); break;
		case 0:
			exitUM = false;
			system("cls");
			break;
		default:
			cout << "������� ������ ����� ����" << endl;
			break;
		}
	}

}
