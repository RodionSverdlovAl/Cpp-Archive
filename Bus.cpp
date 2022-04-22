#include "Bus.h"
#include <iostream>
#include <fstream>
#include <vector>

void Bus::search()
{
	ifstream InfFile;
	InfFile.open(RouteInformation);
	vector<Bus> BusArray;

	// запись всей этой хуйни в массив из файла для дальнейшей работы 
	while (InfFile.peek() != EOF)
	{
		Bus B;
		InfFile >> B.bus_number; InfFile.get();
		InfFile >> B.routeName; InfFile.get();
		InfFile >> B.type; InfFile.get();
		InfFile >> B.size; InfFile.get();

		for (int i = 0; i < B.size; i++) {
			busStop b;
			InfFile >> b.stop; InfFile.get();
			for (int j = 0; j < 10; j++) {
				timeStop ts;
				InfFile >> ts.hour; InfFile.get();
				InfFile >> ts.minute; InfFile.get();
				b.Time.push_back(ts);
			}
			B.BusArray.push_back(b);
		}
		BusArray.push_back(B);
	}
	// работа с массивом
	int size = BusArray.size();
	int routenum; string typeofbus;
	cout << "выберите тип транспорта который хотите найти" << endl;
	cout << "[1] Автобус" << endl << "[2] Тролейбус" << endl << "[3] Трамвай" << endl;
	int t; cin >> t;
	switch (t)
	{
	case 1: {
		typeofbus = "Автобус";
	}break;
	case 2: {
		typeofbus = "Тролейбус";
	}break;
	case 3: {
		typeofbus = "Трамвай";
	}break;
	default:
		break;
	}
	cout << "Введите номер маршрута: "; cin >> routenum;
	for (int i = 0; i < size; i++) {
		if (BusArray[i].type == typeofbus && BusArray[i].bus_number == routenum) {
			cout << "Маршрут: " << BusArray[i].bus_number << "  " << endl;
			cout << BusArray[i].routeName << endl;
			cout << BusArray[i].type << endl;
			for (int k = 0; k < BusArray[i].size; k++) {
				cout << "Остановка: " << BusArray[i].BusArray[k].stop << "  время: ";
				for (int j = 0; j < 10; j++) {
					cout << BusArray[i].BusArray[k].Time[j].hour << ":" << BusArray[i].BusArray[k].Time[j].minute << " ";
				}
				cout << "\n";
			}
		}
	}
	InfFile.close();
	system("pause");
	system("cls");
}

void Bus::sort()
{
	ifstream InfFile;
	InfFile.open(RouteInformation);
	vector<Bus> BusArray;

	// запись всей этой хуйни в массив из файла для дальнейшей работы 
	while (InfFile.peek() != EOF)
	{
		Bus B;
		InfFile >> B.bus_number; InfFile.get();
		InfFile >> B.routeName; InfFile.get();
		InfFile >> B.type; InfFile.get();
		InfFile >> B.size; InfFile.get();

		for (int i = 0; i < B.size; i++) {
			busStop b;
			InfFile >> b.stop; InfFile.get();
			for (int j = 0; j < 10; j++) {
				timeStop ts;
				InfFile >> ts.hour; InfFile.get();
				InfFile >> ts.minute; InfFile.get();
				b.Time.push_back(ts);
			}
			B.BusArray.push_back(b);
		}
		BusArray.push_back(B);
	}
	// работа с массивом
	int size = BusArray.size();
	cout << "1. Сортировать по номеру маршрута" << endl;
	cout << "2. Сортировать по типу транспорта" << endl;
	int chouse; cin >> chouse;
	switch (chouse)
	{
	case 1: {
		system("cls");
		Bus temp;
		cout << "*** Маршруты ****" << endl;
		for (int i = 0; i < size; i++) {

			for (int j = i + 1; j < size; j++) {
				if (BusArray[i].bus_number > BusArray[j].bus_number) {
					temp = BusArray[i];
					BusArray[i] = BusArray[j];
					BusArray[j] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ". " << BusArray[i].type << " " << BusArray[i].bus_number << " " << BusArray[i].routeName << endl;
		}
	}break;
	case 2: {
		system("cls");
		Bus temp;
		cout << "*** Маршруты ****" << endl;
		for (int i = 0; i < size; i++) {

			for (int j = i + 1; j < size; j++) {
				if (BusArray[i].type > BusArray[j].type) {
					temp = BusArray[i];
					BusArray[i] = BusArray[j];
					BusArray[j] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ". " << BusArray[i].type << " " << BusArray[i].bus_number << " " << BusArray[i].routeName << endl;
		}
	}break;
	default:
		break;
	}

	InfFile.close();
	system("pause");
	system("cls");
}

void Bus::edit()
{
	ifstream InfFile;
	InfFile.open(RouteInformation);
	vector<Bus> BusArray;

	while (InfFile.peek() != EOF)
	{
		Bus B;
		InfFile >> B.bus_number; InfFile.get();
		InfFile >> B.routeName; InfFile.get();
		InfFile >> B.type; InfFile.get();
		InfFile >> B.size; InfFile.get();

		for (int i = 0; i < B.size; i++) {
			busStop b;
			InfFile >> b.stop; InfFile.get();
			for (int j = 0; j < 10; j++) {
				timeStop ts;
				InfFile >> ts.hour; InfFile.get();
				InfFile >> ts.minute; InfFile.get();
				b.Time.push_back(ts);
			}
			B.BusArray.push_back(b);
		}
		BusArray.push_back(B);
	}

	InfFile.close();

	int size = BusArray.size();
	
	cout << "*** Маршруты ****" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << BusArray[i].type << " " << BusArray[i].bus_number << " " << BusArray[i].routeName << endl;
	}

	//------ Проверка ввода чтобы не было ошибки --------------------------------
	int chouse;
	bool check = true;
	while (check) {
		cout << "Введите порядковый номер маршрута который хотите отредактировать: ";
		cin >> chouse;
		if (chouse <= size && chouse >= 0) {
			check = false;
		}
	}
	// ----------------------------------------------------------------------------

	chouse = chouse - 1;
	cout << "Маршрут: " << BusArray[chouse].bus_number << "  " << endl;
	cout << BusArray[chouse].routeName << endl;
	cout << BusArray[chouse].type << endl;
	for (int i = 0; i < BusArray[chouse].size; i++) {
		cout << "Остановка: " << BusArray[chouse].BusArray[i].stop << "  время: ";
		for (int j = 0; j < 10; j++) {
			cout << BusArray[chouse].BusArray[i].Time[j].hour << ":" << BusArray[chouse].BusArray[i].Time[j].minute << " ";
		}
		cout << "\n";
	}
	cout << "***********************************" << endl;

	cout << "[1] Редактировать название" << endl;
	cout << "[2] Редактировать номер маршрута" << endl;
	cout << "[3] Редактировать тип транспорта" << endl;
	cout << "[4] Редактировать остановку (время)" << endl;
	cout << "[5] Редактировать остановку (название)" << endl;
	int edit_menu; cin >> edit_menu;

	switch (edit_menu)
	{
	case 1: {
		cout << "Введите новое название маршрута: "; string new_name; cin >> new_name;
		BusArray[chouse].routeName = new_name;
	}break;
	case 2: {
		cout << "Введите новый номер маршрута: "; int new_number; cin >> new_number;
		BusArray[chouse].bus_number = new_number;
	}break;
	case 3: {
		cout << "Введите новый тип транспорта: "; string new_type; cin >> new_type;
		BusArray[chouse].type = new_type;
	}break;
	case 4: {
		cout << "Введите остановку которую хотите отредактировать: "; string new_stop; cin >> new_stop;
		int index;
		bool check = false;
		for (int i = 0; i < BusArray[chouse].size; i++) {
			if (BusArray[chouse].BusArray[i].stop == new_stop) {
				index = i;
				check = true;
			}
		}
		if (check == true) {
			BusArray[chouse].BusArray[index].stop = new_stop;
			for (int j = 0; j < 10; j++) {
				cout << "Введите " << j + 1 << " время прибытия автобуса на эту остановку: " << endl;
				timeStop ts;
				cout << "Час: "; cin >> ts.hour;
				cout << "Минута: "; cin >> ts.minute;
				BusArray[chouse].BusArray[index].Time[j] = ts;
			}
		}
		else {
			cout << "Такой остановки нет!" << endl;
		}
	}break;
	case 5: {
		cout << "Введите остановку которую хотите отредактировать: "; string new_stop; cin >> new_stop;
		int index;
		bool check = false;
		for (int i = 0; i < BusArray[chouse].size; i++) {
			if (BusArray[chouse].BusArray[i].stop == new_stop) {
				index = i;
				check = true;
			}
		}
		if (check == true) {
			cout << "Введите новое название для остановки: "; string NEW; cin >> NEW;
			BusArray[chouse].BusArray[index].stop = NEW;
		}
		else {
			cout << "Такой остановки нет!" << endl;
		}
	}break;
	default:
		break;
	}

	ofstream InfFile1;
	InfFile1.open(RouteInformation);
	
	for (int k = 0; k < BusArray.size(); k++) {
		InfFile1 << BusArray[k].bus_number << endl;
		InfFile1 << BusArray[k].routeName << endl;
		InfFile1 << BusArray[k].type << endl;
		InfFile1 << BusArray[k].size << endl;

		for (int i = 0; i < BusArray[k].size; i++) {
			InfFile1 << BusArray[k].BusArray[i].stop << endl;

			for (int j = 0; j < 10; j++) {
				InfFile1 << BusArray[k].BusArray[i].Time[j].hour << endl;
				InfFile1 << BusArray[k].BusArray[i].Time[j].minute << endl;
			}

		}
	}
	
	InfFile.close();

	system("pause");
	system("cls");
}

int Bus::bild_route()
{
	ifstream InfFile;
	InfFile.open(RouteInformation);
	vector<Bus> BusArray;

	while (InfFile.peek() != EOF)
	{
		Bus B;
		InfFile >> B.bus_number; InfFile.get();
		InfFile >> B.routeName; InfFile.get();
		InfFile >> B.type; InfFile.get();
		InfFile >> B.size; InfFile.get();

		for (int i = 0; i < B.size; i++) {
			busStop b;
			InfFile >> b.stop; InfFile.get();
			for (int j = 0; j < 10; j++) {
				timeStop ts;
				InfFile >> ts.hour; InfFile.get();
				InfFile >> ts.minute; InfFile.get();
				b.Time.push_back(ts);
			}
			B.BusArray.push_back(b);
		}
		BusArray.push_back(B);
	}
	int size = BusArray.size();
	InfFile.close();

	// Ввод пункта отправки
	// Ввод пункта прибытия
	// пробегаем по всем маршрутам и если в каком то маршруте совпадают эти остановки то выводим маршрут

	// Код здесь -- >>
	string A, B;
	
	int k;
	cout << "Введите пункт отправления: "; cin >> A;
	cout << "Введите пункт прибытия: "; cin >> B;
	for (int i = 0; i < size; i++) {
		bool check_A = false;
		bool check_B = false;
		int stopA, stopB;
		for (int j = 0; j < BusArray[i].size; j++) {
			if (BusArray[i].BusArray[j].stop == A) {
				check_A = true;
				stopA = j;
			}
			if (BusArray[i].BusArray[j].stop == B) {
				check_B = true;
				stopB = j;
			}
			if (check_A == true && check_B == true) {
				k = i;
				cout << BusArray[k].bus_number << " "<<BusArray[k].routeName<<endl;
				if (stopA < stopB) {
					for (int index = stopA; index < stopB + 1; index++) {
						cout << BusArray[k].BusArray[index].stop<<endl;
					}
				}
				if (stopA > stopB) {
					for (int index = stopA; index > stopB - 1; index--) {
						cout<<BusArray[k].BusArray[index].stop<<endl;
					}
				}

				system("pause");
				system("cls");
				return -1;
				/*cout << "Маршрут: " << BusArray[i].bus_number << "  " << endl;
				cout << BusArray[i].routeName << endl;
				cout << BusArray[i].type << endl;
				for (int k = 0; k < BusArray[i].size; k++) {
					cout << "Остановка: " << BusArray[i].BusArray[k].stop << "  время: ";
					for (int j = 0; j < 10; j++) {
						cout << BusArray[i].BusArray[k].Time[j].hour << ":" << BusArray[i].BusArray[k].Time[j].minute << " ";
					}
					cout << "\n";
				}*/
			}
		}
	}
	cout << "Не удалось построить маршрут! Возможно таких остановок не существует либо же имеющийся транспорт на них не ходит (без пересадок)" << endl;
	system("pause");
	system("cls");
	return -1;
}

void Bus::delete_route()
{
	ifstream InfFile;
	InfFile.open(RouteInformation);
	vector<Bus> BusArray;

	while (InfFile.peek() != EOF)
	{
		Bus B;
		InfFile >> B.bus_number; InfFile.get();
		InfFile >> B.routeName; InfFile.get();
		InfFile >> B.type; InfFile.get();
		InfFile >> B.size; InfFile.get();

		for (int i = 0; i < B.size; i++) {
			busStop b;
			InfFile >> b.stop; InfFile.get();
			for (int j = 0; j < 10; j++) {
				timeStop ts;
				InfFile >> ts.hour; InfFile.get();
				InfFile >> ts.minute; InfFile.get();
				b.Time.push_back(ts);
			}
			B.BusArray.push_back(b);
		}
		BusArray.push_back(B);
	}
	int size = BusArray.size();
	cout << "*** Маршруты ****" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << BusArray[i].type << " " << BusArray[i].bus_number << " " << BusArray[i].routeName << endl;
	}
	//------ Проверка ввода чтобы не было ошибки --------------------------------
	int chouse;
	bool check = true;
	while (check) {
		cout << "Введите порядковый номер маршрута который хотите удалить: ";
		cin >> chouse;
		if (chouse <= size && chouse >= 0) {
			check = false;
		}
	}
	// ----------------------------------------------------------------------------
	chouse = chouse - 1;
	int n = chouse;
	for (int j = n; j < size - 1; j++)
		BusArray[j] = BusArray[j + 1];
	size--;
	ofstream InfFile1;
	InfFile1.open(RouteInformation);

	for (int k = 0; k < size; k++) {
		InfFile1 << BusArray[k].bus_number << endl;
		InfFile1 << BusArray[k].routeName << endl;
		InfFile1 << BusArray[k].type << endl;
		InfFile1 << BusArray[k].size << endl;

		for (int i = 0; i < BusArray[k].size; i++) {
			InfFile1 << BusArray[k].BusArray[i].stop << endl;

			for (int j = 0; j < 10; j++) {
				InfFile1 << BusArray[k].BusArray[i].Time[j].hour << endl;
				InfFile1 << BusArray[k].BusArray[i].Time[j].minute << endl;
			}

		}
	}

	InfFile.close();
	cout << "Маршрут удален" << endl;
	system("pause");
	system("cls");
}

void Bus::add_route()
{
	cout << "Введите номер маршрута: "; cin >> bus_number;
	cout << "Введите название маршрута: "; cin >> routeName;
	cout << "Выберите тип транспорта";
	cout << "[1] Автобус" << endl << "[2] Тролейбус" << endl << "[3] Трамвай" << endl;
	int t; cin >> t;
	switch (t)
	{
	case 1: {
		type = "Автобус";
	}break;
	case 2: {
		type = "Тролейбус";
	}break;
	case 3: {
		type = "Трамвай";
	}break;
	default:
		break;
	}

	// ---------------------------------------------------------------------------
	// Проверка введенного колличества остановок
	bool check = true;
	int stop_size;
	while (check)
	{
		cout << "Введите колличество остановок (от 0 до 50): ";  cin >> stop_size;
		if (stop_size >= 0 && stop_size <= 50) {
			check = false;
		}
	}
	//-----------------------------------------------------------------------------


	for (int i = 0; i < stop_size; i++) {
		busStop b;
		cout << "[" << i + 1 << "]" << " остановка" << endl;
		cout << "Введите название остановки: "; cin >> b.stop;
		for (int i = 0; i < 10; i++) {
			cout << "Введите " <<i+1<<" время прибытия автобуса на эту остановку: " << endl;
			timeStop ts;


			// ------------------------------------------------
			// Проверка на правельность введенных часов и минут
			bool check_time = true;
			while (check_time)
			{
				cout << "Час: "; cin >> ts.hour;
				if (ts.hour >= 0 && ts.hour < 24)
					check_time = false;
			}

			bool check_time2 = true;
			while (check_time2) {
				cout << "Минута: "; cin >> ts.minute;
				if (ts.minute >= 0 && ts.minute < 60)
					check_time2 = false;
			}
			//---------------------------------------------------
			b.Time.push_back(ts);
		}
		BusArray.push_back(b);
	}
	ofstream InfFile;
	InfFile.open(RouteInformation, ofstream::app);
	InfFile << bus_number << endl;
	InfFile << routeName << endl;
	InfFile << type << endl;
	InfFile << stop_size << endl;

	for (int i = 0; i < stop_size; i++) {
		InfFile << BusArray[i].stop << endl;

		for (int j = 0; j < 10; j++) {
			InfFile << BusArray[i].Time[j].hour << endl;
			InfFile << BusArray[i].Time[j].minute << endl;
		}
		
	}
	InfFile.close();
}

void Bus::view_route()
{
	ifstream InfFile;
	InfFile.open(RouteInformation);
	vector<Bus> BusArray;
	
	while (InfFile.peek() != EOF)
	{
		Bus B;
		InfFile >> B.bus_number; InfFile.get();
		InfFile >> B.routeName; InfFile.get();
		InfFile >> B.type; InfFile.get();
		InfFile >> B.size; InfFile.get();

		for (int i = 0; i < B.size; i++) {
			busStop b;
			InfFile >> b.stop; InfFile.get();
			for (int j = 0; j < 10; j++) {
				timeStop ts;
				InfFile >> ts.hour; InfFile.get();
				InfFile >> ts.minute; InfFile.get();
				b.Time.push_back(ts);
			}
			B.BusArray.push_back(b);
		}
		BusArray.push_back(B);
	}
	int size = BusArray.size();
	cout << "*** Маршруты ****" << endl;
	for (int i = 0; i < size; i++) {
		cout<<i+1<<". " << BusArray[i].type << " " << BusArray[i].bus_number << " " << BusArray[i].routeName << endl;
	}

	//------ Проверка ввода чтобы не было ошибки --------------------------------
	int chouse; 
	bool check = true;
	while (check) {
		cout << "Введите порядковый номер маршрута который хотите посмотреть: ";
		cin >> chouse;
		if (chouse <= size && chouse >= 0) {
			check = false;
		}
	}
	// ----------------------------------------------------------------------------

	chouse = chouse - 1;
	cout << "Маршрут: " << BusArray[chouse].bus_number << "  " << endl;
	cout << BusArray[chouse].routeName << endl;
	cout << BusArray[chouse].type << endl;
	for (int i = 0; i < BusArray[chouse].size; i++) {
		cout << "Остановка: " << BusArray[chouse].BusArray[i].stop << "  время: ";
		for (int j = 0; j < 10; j++) {
			cout << BusArray[chouse].BusArray[i].Time[j].hour << ":" << BusArray[chouse].BusArray[i].Time[j].minute << " ";
		}
		cout << "\n";
	}
	cout << "***********************************" << endl;
	InfFile.close();
	system("pause");
	system("cls");
}