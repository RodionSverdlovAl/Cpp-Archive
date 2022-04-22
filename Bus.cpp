#include "Bus.h"
#include <iostream>
#include <fstream>
#include <vector>

void Bus::search()
{
	ifstream InfFile;
	InfFile.open(RouteInformation);
	vector<Bus> BusArray;

	// ������ ���� ���� ����� � ������ �� ����� ��� ���������� ������ 
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
	// ������ � ��������
	int size = BusArray.size();
	int routenum; string typeofbus;
	cout << "�������� ��� ���������� ������� ������ �����" << endl;
	cout << "[1] �������" << endl << "[2] ���������" << endl << "[3] �������" << endl;
	int t; cin >> t;
	switch (t)
	{
	case 1: {
		typeofbus = "�������";
	}break;
	case 2: {
		typeofbus = "���������";
	}break;
	case 3: {
		typeofbus = "�������";
	}break;
	default:
		break;
	}
	cout << "������� ����� ��������: "; cin >> routenum;
	for (int i = 0; i < size; i++) {
		if (BusArray[i].type == typeofbus && BusArray[i].bus_number == routenum) {
			cout << "�������: " << BusArray[i].bus_number << "  " << endl;
			cout << BusArray[i].routeName << endl;
			cout << BusArray[i].type << endl;
			for (int k = 0; k < BusArray[i].size; k++) {
				cout << "���������: " << BusArray[i].BusArray[k].stop << "  �����: ";
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

	// ������ ���� ���� ����� � ������ �� ����� ��� ���������� ������ 
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
	// ������ � ��������
	int size = BusArray.size();
	cout << "1. ����������� �� ������ ��������" << endl;
	cout << "2. ����������� �� ���� ����������" << endl;
	int chouse; cin >> chouse;
	switch (chouse)
	{
	case 1: {
		system("cls");
		Bus temp;
		cout << "*** �������� ****" << endl;
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
		cout << "*** �������� ****" << endl;
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
	
	cout << "*** �������� ****" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << BusArray[i].type << " " << BusArray[i].bus_number << " " << BusArray[i].routeName << endl;
	}

	//------ �������� ����� ����� �� ���� ������ --------------------------------
	int chouse;
	bool check = true;
	while (check) {
		cout << "������� ���������� ����� �������� ������� ������ ���������������: ";
		cin >> chouse;
		if (chouse <= size && chouse >= 0) {
			check = false;
		}
	}
	// ----------------------------------------------------------------------------

	chouse = chouse - 1;
	cout << "�������: " << BusArray[chouse].bus_number << "  " << endl;
	cout << BusArray[chouse].routeName << endl;
	cout << BusArray[chouse].type << endl;
	for (int i = 0; i < BusArray[chouse].size; i++) {
		cout << "���������: " << BusArray[chouse].BusArray[i].stop << "  �����: ";
		for (int j = 0; j < 10; j++) {
			cout << BusArray[chouse].BusArray[i].Time[j].hour << ":" << BusArray[chouse].BusArray[i].Time[j].minute << " ";
		}
		cout << "\n";
	}
	cout << "***********************************" << endl;

	cout << "[1] ������������� ��������" << endl;
	cout << "[2] ������������� ����� ��������" << endl;
	cout << "[3] ������������� ��� ����������" << endl;
	cout << "[4] ������������� ��������� (�����)" << endl;
	cout << "[5] ������������� ��������� (��������)" << endl;
	int edit_menu; cin >> edit_menu;

	switch (edit_menu)
	{
	case 1: {
		cout << "������� ����� �������� ��������: "; string new_name; cin >> new_name;
		BusArray[chouse].routeName = new_name;
	}break;
	case 2: {
		cout << "������� ����� ����� ��������: "; int new_number; cin >> new_number;
		BusArray[chouse].bus_number = new_number;
	}break;
	case 3: {
		cout << "������� ����� ��� ����������: "; string new_type; cin >> new_type;
		BusArray[chouse].type = new_type;
	}break;
	case 4: {
		cout << "������� ��������� ������� ������ ���������������: "; string new_stop; cin >> new_stop;
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
				cout << "������� " << j + 1 << " ����� �������� �������� �� ��� ���������: " << endl;
				timeStop ts;
				cout << "���: "; cin >> ts.hour;
				cout << "������: "; cin >> ts.minute;
				BusArray[chouse].BusArray[index].Time[j] = ts;
			}
		}
		else {
			cout << "����� ��������� ���!" << endl;
		}
	}break;
	case 5: {
		cout << "������� ��������� ������� ������ ���������������: "; string new_stop; cin >> new_stop;
		int index;
		bool check = false;
		for (int i = 0; i < BusArray[chouse].size; i++) {
			if (BusArray[chouse].BusArray[i].stop == new_stop) {
				index = i;
				check = true;
			}
		}
		if (check == true) {
			cout << "������� ����� �������� ��� ���������: "; string NEW; cin >> NEW;
			BusArray[chouse].BusArray[index].stop = NEW;
		}
		else {
			cout << "����� ��������� ���!" << endl;
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

	// ���� ������ ��������
	// ���� ������ ��������
	// ��������� �� ���� ��������� � ���� � ����� �� �������� ��������� ��� ��������� �� ������� �������

	// ��� ����� -- >>
	string A, B;
	
	int k;
	cout << "������� ����� �����������: "; cin >> A;
	cout << "������� ����� ��������: "; cin >> B;
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
				/*cout << "�������: " << BusArray[i].bus_number << "  " << endl;
				cout << BusArray[i].routeName << endl;
				cout << BusArray[i].type << endl;
				for (int k = 0; k < BusArray[i].size; k++) {
					cout << "���������: " << BusArray[i].BusArray[k].stop << "  �����: ";
					for (int j = 0; j < 10; j++) {
						cout << BusArray[i].BusArray[k].Time[j].hour << ":" << BusArray[i].BusArray[k].Time[j].minute << " ";
					}
					cout << "\n";
				}*/
			}
		}
	}
	cout << "�� ������� ��������� �������! �������� ����� ��������� �� ���������� ���� �� ��������� ��������� �� ��� �� ����� (��� ���������)" << endl;
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
	cout << "*** �������� ****" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << BusArray[i].type << " " << BusArray[i].bus_number << " " << BusArray[i].routeName << endl;
	}
	//------ �������� ����� ����� �� ���� ������ --------------------------------
	int chouse;
	bool check = true;
	while (check) {
		cout << "������� ���������� ����� �������� ������� ������ �������: ";
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
	cout << "������� ������" << endl;
	system("pause");
	system("cls");
}

void Bus::add_route()
{
	cout << "������� ����� ��������: "; cin >> bus_number;
	cout << "������� �������� ��������: "; cin >> routeName;
	cout << "�������� ��� ����������";
	cout << "[1] �������" << endl << "[2] ���������" << endl << "[3] �������" << endl;
	int t; cin >> t;
	switch (t)
	{
	case 1: {
		type = "�������";
	}break;
	case 2: {
		type = "���������";
	}break;
	case 3: {
		type = "�������";
	}break;
	default:
		break;
	}

	// ---------------------------------------------------------------------------
	// �������� ���������� ����������� ���������
	bool check = true;
	int stop_size;
	while (check)
	{
		cout << "������� ����������� ��������� (�� 0 �� 50): ";  cin >> stop_size;
		if (stop_size >= 0 && stop_size <= 50) {
			check = false;
		}
	}
	//-----------------------------------------------------------------------------


	for (int i = 0; i < stop_size; i++) {
		busStop b;
		cout << "[" << i + 1 << "]" << " ���������" << endl;
		cout << "������� �������� ���������: "; cin >> b.stop;
		for (int i = 0; i < 10; i++) {
			cout << "������� " <<i+1<<" ����� �������� �������� �� ��� ���������: " << endl;
			timeStop ts;


			// ------------------------------------------------
			// �������� �� ������������ ��������� ����� � �����
			bool check_time = true;
			while (check_time)
			{
				cout << "���: "; cin >> ts.hour;
				if (ts.hour >= 0 && ts.hour < 24)
					check_time = false;
			}

			bool check_time2 = true;
			while (check_time2) {
				cout << "������: "; cin >> ts.minute;
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
	cout << "*** �������� ****" << endl;
	for (int i = 0; i < size; i++) {
		cout<<i+1<<". " << BusArray[i].type << " " << BusArray[i].bus_number << " " << BusArray[i].routeName << endl;
	}

	//------ �������� ����� ����� �� ���� ������ --------------------------------
	int chouse; 
	bool check = true;
	while (check) {
		cout << "������� ���������� ����� �������� ������� ������ ����������: ";
		cin >> chouse;
		if (chouse <= size && chouse >= 0) {
			check = false;
		}
	}
	// ----------------------------------------------------------------------------

	chouse = chouse - 1;
	cout << "�������: " << BusArray[chouse].bus_number << "  " << endl;
	cout << BusArray[chouse].routeName << endl;
	cout << BusArray[chouse].type << endl;
	for (int i = 0; i < BusArray[chouse].size; i++) {
		cout << "���������: " << BusArray[chouse].BusArray[i].stop << "  �����: ";
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