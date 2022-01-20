#include "Films.h"
#include <iostream>
#include <fstream>

void Films::Films_to_file(string n, string y, int t, string g, string sd, string st, int cost)
{
	FilmName = n; // название фильма
	Year = y; // год выпуска в прокат
	Timing = t; // хронометраж
	Genre = g; // Жанр
	SeanseData = sd;
	SeanseTime = st;
	Cost = cost;
	ofstream InfFile;
	InfFile.open(Information, ofstream::app);
	InfFile << FilmName << endl;
	InfFile << Year << endl;
	InfFile << Timing << endl;
	InfFile << Genre << endl;
	InfFile << SeanseData << endl;    
	InfFile << SeanseTime << endl;    
	InfFile << Cost << endl;          
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
		InfFile1 >> Film.SeanseData; InfFile1.get();
		InfFile1 >> Film.SeanseTime; InfFile1.get();
		InfFile1 >> Film.Cost; InfFile1.get();
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
		cout << "Дата сеанса: " << Search.SeanseData << "\n";
		cout << "Время сеанса: " << Search.SeanseTime << "\n";
		cout << "Цена билета: " << Search.Cost << "\n";
		system("pause");
		cout << endl;
	}
	else {
		cout << "Фильм(сеанс) не найден!" << endl;
	}
	InfFile1.close();
	system("pause");
	system("cls");
}

void Films::DeleteOneFilm()
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
		InfFile >> F.SeanseData; InfFile.get();
		InfFile >> F.SeanseTime; InfFile.get();
		InfFile >> F.Cost; InfFile.get();
		size++;
	}
	InfFile.close();
	
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
		InfFile1 >> arr[i].SeanseData; InfFile1.get();
		InfFile1 >> arr[i].SeanseTime; InfFile1.get();
		InfFile1 >> arr[i].Cost; InfFile1.get();
		cout << "#" << arr[i].FilmName << endl;
		i++;
	}
	InfFile1.close();

	string tmp;
	int n = -1;
	cout << "Введите название сеанса(фильма) который хотите удалить: "; cin >> tmp;
	for (int j = 0; j < size; j++) {
		if (arr[j].FilmName == tmp)
			n = j;
	}
	if (n == -1)
		cout << "Сеанса с таким названием нет!" << endl;
	else {
		for (int j = n; j < size - 1; j++)
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
		InfFile2 << arr[j].SeanseData << endl;
		InfFile2 << arr[j].SeanseTime << endl;
		InfFile2 << arr[j].Cost << endl;
	}
	InfFile2.close();
	cout << "Сеанс " << "[" << tmp << "] " << "удален" << endl;
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
		InfFile1 >> F.SeanseData; InfFile1.get();
		InfFile1 >> F.SeanseTime; InfFile1.get();
		InfFile1 >> F.Cost; InfFile1.get();
		cout << "Название фильма: " << F.FilmName << "\n";
		cout << "Год выхода в прокат: " << F.Year << "\n";
		cout << "Хронометраж: " << F.Timing << "\n";
		cout << "Жанр: " << F.Genre << "\n";
		cout << "Дата сеанса: " << F.SeanseData << "\n";
		cout << "Время сеанса: " << F.SeanseTime << "\n";
		cout << "Цена билета: " << F.Cost << "\n";
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
	while (InfFile.peek() != EOF)
	{
		InfFile >> F.FilmName; InfFile.get();
		InfFile >> F.Year; InfFile.get();
		InfFile >> F.Timing; InfFile.get();
		InfFile >> F.Genre; InfFile.get();
		InfFile >> F.SeanseData; InfFile.get();
		InfFile >> F.SeanseTime; InfFile.get();
		InfFile >> F.Cost; InfFile.get();
		size++;
	}
	InfFile.close();
	
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
		InfFile1 >> arr[i].SeanseData; InfFile1.get();
		InfFile1 >> arr[i].SeanseTime; InfFile1.get();
		InfFile1 >> arr[i].Cost; InfFile1.get();
		cout <<"#"<< arr[i].FilmName << endl;
		i++;
	}
	InfFile1.close();

	string tmp;
	int n = -1;
	cout << "Введите название сеанса который хотите редактировать: "; cin >> tmp;
	for (int j = 0; j < size; j++) {
		if (arr[j].FilmName == tmp) {
			n = j;
			cout << endl;
			cout << "Название фильма: " << arr[j].FilmName << "\n";
			cout << "Год выхода в прокат: " << arr[j].Year << "\n";
			cout << "Хронометраж: " << arr[j].Timing << "\n";
			cout << "Жанр: " << arr[j].Genre << "\n";
			cout << "Дата сеанса: " << arr[j].SeanseData << "\n";
			cout << "Время сеанса: " << arr[j].SeanseTime << "\n";
			cout << "Цена билета: " << arr[j].Cost << "\n";
			system("pause");
			cout << endl;
		}
			
	}
	if (n == -1)
		cout << "Сеанса с таким названием нет!" << endl;
	else {
		cout << "[1] Изменить название" << endl;
		cout << "[2] Изменить год" << endl;
		cout << "[3] Изменить хронометраж" << endl;
		cout << "[4] Изменить Жанр" << endl;
		cout << "[5] Изменить дату сеанса" << endl;
		cout << "[6] Изменить время сеанса" << endl;
		cout << "[7] Изменить цену билета" << endl;
		int change; cin >> change;
		string NewName;
		string NewYear;
		int NewTiming;
		string NewGenre;
		string NewSeanseData;
		string NewSeanseTime;
		int NewCost;
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
			cout << "Введите дату сеанса ДД:MM:ГГ: "; cin >> NewSeanseData;
			arr[n].SeanseData = NewSeanseData; break;
		case 6:
			cout << "Введите новые время мин:час : "; cin >> NewSeanseTime;
			arr[n].SeanseTime = NewSeanseTime; break;
		case 7:
			cout << "Введите новое количество серий: "; cin >> NewCost;
			arr[n].Cost = NewCost; break;

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
		InfFile2 << arr[j].SeanseData << endl;
		InfFile2 << arr[j].SeanseTime << endl;
		InfFile2 << arr[j].Cost << endl;
	}
	InfFile2.close();
	delete[] arr;
	system("pause");
	system("cls");
}

void Films::sortSeanse()
{
	int size = 0;
	ifstream InfFile;
	InfFile.open(Information);
	Films F;
	while (InfFile.peek() != EOF)
	{
		InfFile >> F.FilmName; InfFile.get();
		InfFile >> F.Year; InfFile.get();
		InfFile >> F.Timing; InfFile.get();
		InfFile >> F.Genre; InfFile.get();
		InfFile >> F.SeanseData; InfFile.get();
		InfFile >> F.SeanseTime; InfFile.get();
		InfFile >> F.Cost; InfFile.get();
		size++;
	}
	InfFile.close();

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
		InfFile1 >> arr[i].SeanseData; InfFile1.get();
		InfFile1 >> arr[i].SeanseTime; InfFile1.get();
		InfFile1 >> arr[i].Cost; InfFile1.get();
		i++;
	}
	InfFile1.close();


	cout << "[1] сортировка по названию " << endl;
	cout << "[2] сортировка по хронометражу " << endl;
	cout << "[3] сортировка по цене билета " << endl;
	int searchMenu;
	cin >> searchMenu;
	switch (searchMenu)
	{
	case 1: {
		system("cls");
		Films temp;
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++) {
				if (arr[i].FilmName > arr[j].FilmName) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			cout << "Название фильма: " << arr[i].FilmName << endl;
			cout << "Год выхода в прокат: " << arr[i].Year << endl;
			cout << "Хронометраж: " << arr[i].Timing << endl;
			cout << "Жанр: " << arr[i].Genre << endl;
			cout << "Дата сеанса: " << arr[i].SeanseData << endl;
			cout << "Время сеанса: " << arr[i].SeanseTime << endl;
			cout << "Цена билета: " << arr[i].Cost << endl;
			cout << "\n";
		}
		system("pause");
		system("cls");
	}break;
	case 2: {
		
		system("cls");
		Films temp;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j].Timing > arr[j + 1].Timing) {
					// меняем элементы местами
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			cout << "Название фильма: " << arr[i].FilmName << endl;
			cout << "Год выхода в прокат: " << arr[i].Year << endl;
			cout << "Хронометраж: " << arr[i].Timing << endl;
			cout << "Жанр: " << arr[i].Genre << endl;
			cout << "Дата сеанса: " << arr[i].SeanseData << endl;
			cout << "Время сеанса: " << arr[i].SeanseTime << endl;
			cout << "Цена билета: " << arr[i].Cost << endl;
			cout << "\n";
		}
		system("pause");
		system("cls");
	}break;
	case 3: {
		system("cls");
		Films temp;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j].Cost > arr[j + 1].Cost) {
					// меняем элементы местами
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			cout << "Название фильма: " << arr[i].FilmName << endl;
			cout << "Год выхода в прокат: " << arr[i].Year << endl;
			cout << "Хронометраж: " << arr[i].Timing << endl;
			cout << "Жанр: " << arr[i].Genre << endl;
			cout << "Дата сеанса: " << arr[i].SeanseData << endl;
			cout << "Время сеанса: " << arr[i].SeanseTime << endl;
			cout << "Цена билета: " << arr[i].Cost << endl;
			cout << "\n";
		}
		system("pause");
		system("cls");
	}
	default:
		break;
	}
}