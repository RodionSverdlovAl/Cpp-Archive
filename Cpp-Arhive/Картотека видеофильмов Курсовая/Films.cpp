#include "Films.h"
#include <iostream>
#include <fstream>

void Films::Films_to_file(string n, string y, int t, string g, string dn, string a, int e)
{
	FilmName = n; // название фильма
	Year = y; // год выпуска в прокат
	Timing = t; // хронометраж
	Genre = g; // Жанр
	DerectorName = dn; // Имя режисера
	Actors = a; // имена актеров
	Eposodes = e; // кол-во серий
	ofstream InfFile;
	InfFile.open(Information, ofstream::app);
	InfFile << FilmName << endl;
	InfFile << Year << endl;
	InfFile << Timing << endl;
	InfFile<< Genre << endl;
	InfFile<< DerectorName << endl;
	InfFile<< Actors << endl;
	InfFile<< Eposodes << endl;
	InfFile.close();
	system("pause");
	system("cls");
}

void Films::search_film()
{
	Films Film;
	int trueSearch = 0;
	string newName;
	ifstream InfFile1;
	InfFile1.open(Information);
	cout << "Введите название фильма: "; cin >> newName;
	Films Search;
	while (InfFile1.peek() != EOF)
	{
		InfFile1 >> Film.FilmName; InfFile1.get();
		InfFile1 >> Film.Year; InfFile1.get();
		InfFile1 >> Film.Timing; InfFile1.get();
		InfFile1 >> Film.Genre; InfFile1.get();
		InfFile1 >> Film.DerectorName; InfFile1.get();
		InfFile1 >> Film.Actors; InfFile1.get();
		InfFile1 >> Film.Eposodes; InfFile1.get();
		if (newName == Film.FilmName)
		{
			newName = Film.FilmName;
			Search = Film;
			trueSearch = 1;
		}
	}
	if (trueSearch == 1) {
		cout << endl;
		cout << "Название фильма: " << Search.FilmName << "\n";
		cout << "Год выхода в прокат: " << Search.Year << "\n";
		cout << "Хронометраж: " << Search.Timing << "\n";
		cout << "Жанр: " << Search.Genre << "\n";
		cout << "Имя режиссера: " << Search.DerectorName << "\n";
		cout << "Актеры: " << Search.Actors << "\n";
		cout << "Количество серий: " << Search.Eposodes << "\n";
		system("pause");
		cout << endl;
	}
	else {
		cout << "Фильм не найден" << endl;
	}
	InfFile1.close();
	system("pause");
	system("cls");
}

void Films::DeleteOneFilm()
{
	int size=0;
	ifstream InfFile;
	InfFile.open(Information);
	Films F;
	// делаем считывание файла чтобы узнать какой size
	while (InfFile.peek() != EOF)
	{
		InfFile >> F.FilmName; InfFile.get();
		InfFile >> F.Year; InfFile.get();
		InfFile >> F.Timing; InfFile.get();
		InfFile >> F.Genre; InfFile.get();
		InfFile >> F.DerectorName; InfFile.get();
		InfFile >> F.Actors; InfFile.get();
		InfFile >> F.Eposodes; InfFile.get();
		size++;
	}
	InfFile.close();
	//------------------------------------------------------
	int i = 0;
	Films* arr = new Films[size];
	ifstream InfFile1;
	InfFile1.open(Information);
	while (InfFile1.peek() != EOF)
	{
		InfFile1 >> arr[i].FilmName; InfFile1.get();
		InfFile1 >> arr[i].Year; InfFile1.get();
		InfFile1 >> arr[i].Timing; InfFile1.get();
		InfFile1 >> arr[i].Genre; InfFile1.get();
		InfFile1 >> arr[i].DerectorName; InfFile1.get();
		InfFile1 >> arr[i].Actors; InfFile1.get();
		InfFile1 >> arr[i].Eposodes; InfFile1.get();
		i++;
	}
	InfFile1.close();
	
	string tmp;
	int n=-1;
	cout << "Введите название фильма который хотите удалить: "; cin >> tmp;
	for (int j = 0; j < size; j++) {
		if (arr[j].FilmName == tmp)
			n = j;
	}
	if (n == -1)
		cout << "Фильма с таким названием нет!" << endl;
	else {
		for (int j = n; j < size-1; j++)
			arr[j] = arr[j + 1];
		size--;
	}
	// перезапись в файл
	ofstream InfFile2;
	InfFile2.open(Information);
	for (int j = 0; j < size; j++) {
		InfFile2 << arr[j].FilmName << endl;
		InfFile2 << arr[j].Year << endl;
		InfFile2 << arr[j].Timing << endl;
		InfFile2 << arr[j].Genre << endl;
		InfFile2 << arr[j].DerectorName << endl;
		InfFile2 << arr[j].Actors << endl;
		InfFile2 << arr[j].Eposodes << endl;
	}
	InfFile2.close();
	cout << "Фильм " << "[" << tmp << "] " << "удален" << endl;
	delete[] arr;
	system("pause");
	system("cls");
}

void Films::view_inf_about_films()
{
	Films F;
	ifstream InfFile1;
	InfFile1.open(Information);
	while (InfFile1.peek() != EOF)
	{
		InfFile1 >> F.FilmName; InfFile1.get();
		InfFile1 >> F.Year; InfFile1.get();
		InfFile1 >> F.Timing; InfFile1.get();
		InfFile1 >> F.Genre; InfFile1.get();
		InfFile1 >> F.DerectorName; InfFile1.get();
		InfFile1 >> F.Actors; InfFile1.get();
		InfFile1 >> F.Eposodes; InfFile1.get();
		cout << "Название фильма: " << F.FilmName << "\n";
		cout << "Год выхода в прокат: " << F.Year << "\n";
		cout << "Хронометраж: " << F.Timing << "\n";
		cout << "Жанр: " << F.Genre << "\n";
		cout << "Имя режиссера: " << F.DerectorName << "\n";
		cout << "Актеры: " << F.Actors << "\n";
		cout << "Количество серий: " << F.Eposodes << "\n";
		cout << "***********************************" << endl;
	}
	InfFile1.close();
	system("pause");
	system("cls");
}

void Films::changeFilm()
{
	int size = 0;
	ifstream InfFile;
	InfFile.open(Information);
	Films F;
	// делаем считывание файла чтобы узнать какой size
	while (InfFile.peek() != EOF)
	{
		InfFile >> F.FilmName; InfFile.get();
		InfFile >> F.Year; InfFile.get();
		InfFile >> F.Timing; InfFile.get();
		InfFile >> F.Genre; InfFile.get();
		InfFile >> F.DerectorName; InfFile.get();
		InfFile >> F.Actors; InfFile.get();
		InfFile >> F.Eposodes; InfFile.get();
		size++;
	}
	InfFile.close();
	//------------------------------------------------------
	int i = 0;
	Films* arr = new Films[size];
	ifstream InfFile1;
	InfFile1.open(Information);
	while (InfFile1.peek() != EOF)
	{
		InfFile1 >> arr[i].FilmName; InfFile1.get();
		InfFile1 >> arr[i].Year; InfFile1.get();
		InfFile1 >> arr[i].Timing; InfFile1.get();
		InfFile1 >> arr[i].Genre; InfFile1.get();
		InfFile1 >> arr[i].DerectorName; InfFile1.get();
		InfFile1 >> arr[i].Actors; InfFile1.get();
		InfFile1 >> arr[i].Eposodes; InfFile1.get();
		i++;
	}
	InfFile1.close();

	string tmp;
	int n = -1;
	cout << "Введите название фильма который хотите редактировать: "; cin >> tmp;
	for (int j = 0; j < size; j++) {
		if (arr[j].FilmName == tmp)
			n = j;
	}
	if (n == -1)
		cout << "Фильма с таким названием нет!" << endl;
	else {
		cout << "[1] Изменить название" << endl;
		cout << "[2] Изменить год" << endl;
		cout << "[3] Изменить хронометраж" << endl;
		cout << "[4] Изменить Жанр" << endl;
		cout << "[5] Изменить имя режиссера" << endl;
		cout << "[6] Изменить актеров" << endl;
		cout << "[7] Изменить колличество серий" << endl;
		int change; cin >> change;
		string NewName;
		string NewYear;
		int NewTiming;
		string NewGenre;
		string NewDerectorName;
		string NewActors;
		int NewEposodes;
		switch (change)
		{ 
		case 1:
			cout << "Введите новое название фильма: "; cin >> NewName;
			arr[n].FilmName = NewName; break;
		case 2:
			cout << "Введите новый год: "; cin >> NewYear;
			arr[n].Year = NewYear; break;
		case 3:
			cout << "Введите новый хронометраж: "; cin >> NewTiming;
			arr[n].Timing = NewTiming; break;
		case 4:
			cout << "Введите новый жанр: "; cin >> NewGenre;
			arr[n].Genre = NewGenre; break;
		case 5:
			cout << "Введите новое имя режиссера: "; cin >> NewDerectorName;
			arr[n].DerectorName = NewDerectorName; break;
		case 6:
			cout << "Введите новые имена актеров(а): "; cin >> NewActors;
			arr[n].Actors = NewActors; break;
		case 7:
			cout << "Введите новое количество серий: "; cin >> NewEposodes;
			arr[n].Eposodes = NewEposodes; break;
			
		default:
			cout << "Такой функции нет!" << endl;
			break;
		}
		cout << "Фильм " << "[" << tmp << "] " << "редактирован!" << endl;
	}
	// перезапись в файл
	ofstream InfFile2;
	InfFile2.open(Information);
	for (int j = 0; j < size; j++) {
		InfFile2 << arr[j].FilmName << endl;
		InfFile2 << arr[j].Year << endl;
		InfFile2 << arr[j].Timing << endl;
		InfFile2 << arr[j].Genre << endl;
		InfFile2 << arr[j].DerectorName << endl;
		InfFile2 << arr[j].Actors << endl;
		InfFile2 << arr[j].Eposodes << endl;
	}
	InfFile2.close();
	delete[] arr;
	system("pause");
	system("cls");
}

string Films::GetFilmName()
{
	return FilmName;
}

string Films::GetYear()
{
	return Year;
}

int Films::GetTiming()
{
	return Timing;
}

string Films::GetGenre()
{
	return Genre;
}

string Films::GetDerectorName()
{
	return DerectorName;
}

string Films::GetActors()
{
	return Actors;
}

int Films::GetEposodes()
{
	return Eposodes;
}
