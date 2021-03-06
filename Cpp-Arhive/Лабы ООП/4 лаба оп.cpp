#include <string.h>
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <conio.h>

using namespace std;

class Man 
{
protected:
	string Name;
	string Surname;
	string Patronymic;
	int Year;
	void changeName();
	void changeSurname();
	void changePatronymic();
	void changeYear(int manYear);
public:
	Man(string, string, string, int);
	~Man()
	{
		cout << "Вызван деструктор Man" << endl;
	}
	void info();
};


//---------------------------------------

class Tax_payment : public Businessman
{
	int sum;
	string date;
};

class Businessman : public Man
{
private:
	int	license_number;
	string registration_address;
	string taxpayer_identification_number;
	string scientific_works;

public:
	Businessman(string Name, string Surname, string Patronymic, int Year, int	license, string address, string identification_number, string works) :Man(Name, Surname, Patronymic, Year)
	{
		cout << "Вызван конструктор Businessman" << endl;
		license_number = license;
		registration_address = address;
		taxpayer_identification_number = identification_number;
		scientific_works = works;
	}
	~Businessman()
	{
		cout << "Вызван деструктор Businessman" << endl;
	}
	void inf()
	{
		cout << "Имя: " << Name << " " << "Фамилия: " << Surname << " " << "Отчество:" << Patronymic << " " << "Год:" << Year << "Номер лицензии" << license_number << "Адрес регистрации" << registration_address << "Идентификационный номер" << taxpayer_identification_number << "Научные работы" << scientific_works << endl;
	}

};


class Trips : public Tourist
{
	string country;
	string date;
};

class Tourist : public Man
{
	string passport_data;
	string scientific_works;
public:
	Tourist(string Name, string Surname, string Patronymic, int Year, string passport, string scientific):Man(Name, Surname, Patronymic, Year)
	{
		cout << "Вызван конструктор Tourist" << endl;
		passport_data = passport;
		scientific_works = scientific;
	}
	~Tourist()
	{
		cout << "Вызван деструктор Tourist" << endl;
	}
	void inf()
	{
		cout << "Имя: " << Name << " " << "Фамилия: " << Surname << " " << "Отчество:" << Patronymic << "Год:" << Year << "Паспортные данные" << passport_data << "Научные работы" << scientific_works << endl;
	}
};

class Shuttle : public Businessman, public Tourist
{
	string adress;

};

Man :: Man (string N, string S,string P, int Y)
{
	cout << "Вызван конструктор Man" << endl;
	Name = N;
	Surname = S;
	Patronymic = P;
	Year = Y;
}

//-----------------------------------------
//void Man::changeName()
//{
//	char n[50];
//	cout << "Input name: \n";
//	cin >> n;
//	memset(Name, ' ', strlen(Name) + 1);
//	strcpy(Name, n);
//}

//void show()
//{
//	cout << "\nName: " << Name;
//	cout << "\nSurame: " << Surname;
//	cout << "\nPatronymic: " << Patronymic;
//	cout << "\nYear: " << Year;
//
//}

//void Man::changeSurname()
//{
//	char s[50];
//	cout << "Input surname: \n";
//	cin >> s;
//	memset(Surname, ' ', strlen(Surname) + 1);
//	strcpy(Surname, s);
//
//}

//void Man::changePatronymic()
//{
//	char p[50];
//	cout << "Input patronymic: \n";
//	cin >> p;
//	memset(Patronymic, ' ', strlen(Patronymic) + 1);
//	strcpy(Patronymic, p);
//}

//void Man::changeYear(int manYear)
//{
//	cout << "Input year: \n";
//	cin >> Year;
//}

//Businessman::Businessman(char *n, char *s, char *p, int Year)
//{
//	strcpy(Name, n);
//	strcpy(Surname, s);
//	strcpy(Patronymic, p);
//	year = Year;
//}

//void  Businessman::changeYear()
//{
//	cout << "Input year: \n";
//	cin >> year;
//}

//Tourist::Tourist(char *n, char *s, char *p, int Year)
//{
//	strcpy(Name, n);
//	strcpy(Surname, s);
//	strcpy(Patronymic, p);
//	year = Year;
//}



int main()
{
	{
		setlocale(LC_ALL, "Russian");
		Businessman a( "Name","Surname", "Patronymic","Year")
		a.inf();
		Tourist b();
		b.inf();
		Shuttle c();
		c.inf;
		
		return 0;

	}
}