#include "Admin.h"
#include <iostream>
#include <fstream>
#include <string>
#include<fstream>

using namespace std;
void Admin::add_information()
{
	int t, cost;
	string y, n, g, sd, st;
	cout << "������� �������� ������: "; cin >> n;
	cout << "������� ���: "; cin >> y;
	cout << "������� ����������� (� �������): "; cin >> t;
	cout << "������� �������� �����: "; cin >> g;
	cout << "������� ���� ������ (��:��:��): "; cin >> sd;
	cout << "������� ����� ������ (��:��): "; cin >> st;
	cout << "������� ���� ������: "; cin >> cost;
	Films_to_file(n, y, t, g, sd, st, cost);//�������� ������ � ������ ��� � ����
}

void Admin::View_Users_Accounts()
{
	Registration R1;
	ifstream UserFile;
	string path = R1.getRegDATA();
	UserFile.open(path);
	if (!UserFile.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		char ch;
		cout << "[�������� ���� �������������]" << endl;
		while (UserFile.get(ch))
		{
			cout << ch;
		}
	}
	UserFile.close();
	system("pause");
	system("cls");
}

void Admin::Delete_information_about_films()
{
	ofstream InfFile;
	InfFile.open(Information, ofstream::trunc);
	cout << "���������� � ������� �������" << endl;
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
	cout << "�������� ���� ������������� �������" << endl;
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
	cout << "������� ����� ������������ �������� ������ �������: "; cin >> tmp;
	for (int j = 0; j < size; j++) {
		if (arr[j].LoginUser1 == tmp)
			n = j;
	}
	if (n == -1)
		cout << "������������ � ����� ������� ���!" << endl;
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
	cout << "������������ " << "[" << tmp << "] " << "������" << endl;
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
		cout << "���� ��������������" << endl;
		cout << "[1] �������� �����" << endl;
		cout << "[2] �������� ���������� � �������" << endl;
		cout << "[3] ������� ���������� � ���� �������" << endl;
		cout << "[4] ������� ���������� �� ������������ ������" << endl;
		cout << "[5] ����� ������" << endl;
		cout << "[6] ������� ������������� ������������" << endl;
		cout << "[7] ������� ���� �������������" << endl;
		cout << "[8] �������� ��������� ���� �������������" << endl;
		cout << "[9] ���������������� ������������" << endl;
		cout << "[10] ������������� ���������� � ������" << endl;
		cout << "[11] ����������" << endl;
		cout << "[0] �����" << endl;
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
		case 11:
			A.sortSeanse(); break;
		case 0:
			exitAM = false; break;
		default:
			cout << "Error" << endl;
			break;
		}
	}
}