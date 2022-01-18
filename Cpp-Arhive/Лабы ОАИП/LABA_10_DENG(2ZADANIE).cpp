//Реализовать программу работы с классом согласно варианта. Программа должна обеспечивать ввод вывод данных из объектов класса на примере 1-го объекта.
//Класс Korpusa_BNTU. Содержит: Номер корпуса, факультет, адрес

#include <iostream>
using namespace std;

class Korpusa_BNTU
{
public:
	void setDATA(Korpusa_BNTU* DATA, int N);
	void getDATA(Korpusa_BNTU* DATA, int N);
private:
	int NumberCumpus;
	char Facultet[50];
	char adress[70];
};

void Korpusa_BNTU::setDATA(Korpusa_BNTU* DATA, int N)
{
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		system("cls");
		cout << "Номер корпуса:"; cin >> DATA[i].NumberCumpus;
		cin.ignore();
		cout << "Факультет: "; cin.getline(DATA[i].Facultet, 50);
		cout << "Адресс: "; cin.getline(DATA[i].adress, 70);
	}
}

void Korpusa_BNTU::getDATA(Korpusa_BNTU* DATA, int N)
{
	system("cls");
	for (int i = 0; i < N; i++)
	{
		cout << "[" << i + 1 << "]" << "------------" << endl;
		cout << "Номер корпуса: " << DATA[i].NumberCumpus << endl;
		cout << "Факультет: " << DATA[i].Facultet << endl;
		cout << "Адресс: " << DATA[i].adress << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int N; 
	cout << "Введите колличество позиций: "; cin >> N;
	Korpusa_BNTU* M = new Korpusa_BNTU[N];
	
	while (true)
	{
		int key;
		cout << "[1] - отчистить консоль" << endl;
		cout << "[2] - заполнить" << endl;
		cout << "[3] - вывести" << endl;
		cin >> key;
		switch (key)
		{
		case 1: {
			system("cls");
		}break;
		case 2: {
			M->setDATA(M, N);
		}break;
		case 3: {
			M->getDATA(M, N);
		}break;
		default:
			break;
		}
	}
}