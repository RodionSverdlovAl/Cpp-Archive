#include "interface.h"

template <class T>
void Interface<T>::menu()
{
	int selection;

	do
	{
		system("cls");
		cout << "1. Работа с int односвязным списком" << endl;
		cout << "2. Работа с double односвязным списком" << endl;
		cout << "3. Работа с char односвязным списком" << endl;
		cout << "Другое - выход" << endl;

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
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Удалить очередь" << endl;
		cout << "4. Вывести очередь на экран" << endl;
		cout << "5. Найти элемент очереди по значению" << endl;
		cout << "Другое - выход" << endl;

		cin >> selection;
		system("cls");

		switch (selection)
		{
		case 1:
		{
			T value;
			cout << "Введите элемент: ";
			cin >> value;
			queue.pushFront(value);

			cout << "Элемент успешно добавлен!" << endl;
			system("pause");
			break;
		}
		case 2:
		{	
			queue.popFront();
			cout << "Элемент успешно удалён!" << endl;

			system("pause");
			break;
		}
		case 3:
		{
			queue.deleteQueue();
			cout << "Односвязный список успешно удалена!" << endl;

			system("pause");
			break;
		}
		case 4:
		{
			cout << "Элементы односвязного списка: " << endl;
			queue.showQueue();

			system("pause");
			break;
		}
		case 5:
		{
			T value;

			cout << "Введите искомое значение: ";
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
