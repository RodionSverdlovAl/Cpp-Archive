#include "interface.h"

template <class T>
void Interface<T>::menu()
{
	int selection;

	do
	{
		system("cls");
		cout << "1. ������ � int ����������� �������" << endl;
		cout << "2. ������ � double ����������� �������" << endl;
		cout << "3. ������ � char ����������� �������" << endl;
		cout << "������ - �����" << endl;

		cin >> selection;
		
		switch (selection)
		{
		case 1:
		{
			Interface<int> object;
			object.functions();
			break;
		}
		case 2:
		{
			Interface<double> object;
			object.functions();
			break;
		}
		case 3:
		{
			Interface<char> object;
			object.functions();
			break;
		}
		default:
			return;
		}

	} while (true);
}

template <class T>
void Interface<T>::functions()
{
	Queue<T> queue;
	int selection;

	do
	{
		system("cls");
		cout << "1. �������� �������" << endl;
		cout << "2. ������� �������" << endl;
		cout << "3. ������� �������" << endl;
		cout << "4. ������� ������� �� �����" << endl;
		cout << "5. ����� ������� ������� �� ��������" << endl;
		cout << "������ - �����" << endl;

		cin >> selection;
		system("cls");

		switch (selection)
		{
		case 1:
		{
			T value;
			cout << "������� �������: ";
			cin >> value;
			queue.pushFront(value);

			cout << "������� ������� ��������!" << endl;
			system("pause");
			break;
		}
		case 2:
		{	
			queue.popFront();
			cout << "������� ������� �����!" << endl;

			system("pause");
			break;
		}
		case 3:
		{
			queue.deleteQueue();
			cout << "����������� ������ ������� �������!" << endl;

			system("pause");
			break;
		}
		case 4:
		{
			cout << "�������� ������������ ������: " << endl;
			queue.showQueue();

			system("pause");
			break;
		}
		case 5:
		{
			T value;

			cout << "������� ������� ��������: ";
			cin >> value;
			queue.findByValue(value);

			system("pause");
			break;
		}
		default:
			return;
		}

	} while (true);
}
