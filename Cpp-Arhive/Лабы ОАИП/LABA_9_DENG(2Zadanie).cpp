//Реализовать программу работы с классом согласно варианта. Программа должна обеспечивать ввод вывод данных из объектов класса на примере 1-го объекта.
//Класс Korpusa_BNTU. Содержит: Номер корпуса, факультет, адрес

#include <iostream>
using namespace std;

class Korpusa_BNTU
{
public:
	void setDATA();
	void getDATA();
private:
	int NumberCumpus;
	char Facultet[50];
	char adress[70];
};

void Korpusa_BNTU::setDATA()
{
		cout << "Введите Номер корпуса:"; cin >> NumberCumpus;
		cin.ignore();
		cout << "Введите Факультет: "; cin.getline(Facultet, 50);
		cout << "Введите Адресс: "; cin.getline(adress, 70);
	
}

void Korpusa_BNTU::getDATA()
{
		cout << "Номер корпуса: " <<NumberCumpus << endl;
		cout << "Факультет: " << Facultet << endl;
		cout << "Адресс: " <<adress << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Korpusa_BNTU k;
	cout << "Ввод---------------" << endl;
	k.setDATA();
	cout << "Вывод--------------" << endl;
	k.getDATA();
}
