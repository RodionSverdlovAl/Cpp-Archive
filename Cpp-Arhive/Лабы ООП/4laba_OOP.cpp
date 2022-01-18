/*Проверить обработку исключительных ситуаций: выделение памяти,
удаление из пустого множества, проверка ввода. Реализовать
однонаправленный список с использованием сортировки Шелла.*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

bool CheckNum(string str) {					// проверка строки на ввод числа
	if (!str.empty()) {
		try {
			int num = stoi(str);
			return true;
		}
		catch (invalid_argument)
		{
			// если введено не число
			cout << "Only numbers are allowed! \n";
		}
		catch (out_of_range)
		{
			//Если число слишком большое
			cout << "Can't convert into int! \n";
		}
		catch (...)
		{
			//Если будет выброшено неизвестное исключение
			cout << "Unknown error! \n";
		}
	}
	return false;
}
class Footgear {									// класс очереди
private:
	struct Node								// структура, которая содержить поле inf и указатель на следующий элемент
	{
		string article;
		string name;
		int count;
		double price;
		Node* next;
	};
	int c;
	Node* root;								// корень (первый элемент) очереди
	Node* Prev(Node* node)					// Переход к предыдущему узлу
	{
		if (isEmpty()) return NULL;
		if (node == root) return NULL;
		Node* p = root;
		while (p->next != node)
			p = p->next;
		return p;
	}
public:
	Footgear() {
		root = NULL;						// инициализация корня значением NULL
		c = 0;
	}
	Node* getRoot() {						// функция, которая возвращает корень списка
		return root;
	}

	Node* Add(string article, string name, int count, double price, Node* node = NULL)		// функция добавления узла в очередь
	{
		Node* elem = new Node();
		elem->article = article;
		elem->name = name;
		elem->count = count;
		elem->price = price;
		elem->next = NULL;
		if (node == NULL)					// Добавление нового корня
		{
			if (root == NULL) {
				elem->next = NULL;
				root = elem;
			}
			else {
				elem->next = root;
				root = elem;
			}
			c++;
			return elem;
		}
		elem->next = node->next;			// Добавление узла после текущего
		node->next = elem;
		c++;
		return elem;
	}
	bool isEmpty() { return root == NULL; }	// Проверка, пуст ли список
	string getArticle(Node* p) { return p->article; } // Получение article узла списка
	string getName(Node* p) { return p->name; } // Получение name узла списка
	int getCount(Node* p) { return p->count; } // Получение count узла списка
	double getPrice(Node* p) { return p->price; } // Получение prise узла списка
	void setArticle(Node* p, string articlе, string name, int count, double price) {
		p->article = articlе;
		p->name = name;
		p->count = count;
		p->price = price;
	} // Установка значений узла списка
	int getC() { return c; }	// получить количества элементов
	Node* getFirst() { return root; }		// Получение корневого узла списка
	Node* getElement(int k) {
		if (k > getC()) {
			cout << "No such elem" << endl;
			return NULL;
		}
		Node* p = root;

		for (int i = 0; i < k; i++) {
			Node* d = p;
			p = Next(p);
		}
		return p;
	}
	Node* getLast()							// получение последнего узла
	{
		Node* p = root;
		while (Next(p) != NULL)
			p = Next(p);
		return p;
	}
	Node* Next(Node* node)					// переход на следующий узел
	{
		if (isEmpty()) return NULL;
		return node->next;
	}
	void Print()										// вывод очереди на экран
	{
		if (isEmpty()) { cout << "is Empty" << endl; return; }
		Node* p = root;
		do {
			cout << "Article: " << getArticle(p) << " ";
			cout << "Name: " << getName(p) << " ";
			cout << "Count: " << getCount(p) << " ";
			cout << "Prise: " << getPrice(p) << endl;
			p = Next(p);
		} while (p != NULL);
	}
	void Clear()									// очистка очереди
	{
		Node* p = root;
		if (p == NULL) return;
		do {
			Node* d = p;
			p = Next(p);
			delete d;
		} while (p != NULL);
		root = NULL;
		c = 0;
	}
	Node* Delete(Node* node)				// удаление узла из очереди
	{
		if (node == NULL) {
			throw "is empty";
		}	// В списке нет узлов

		if (node == root)					// Удаление корневого узла
		{
			root = node->next;
			delete node;
			c--;
			return root;
		}
		Node* prev = Prev(node);			// Удаление промежуточного узла
		prev->next = node->next;
		delete node;
		c--;
		return prev;
	}

	void sortShellByArticle() {
		int n = getC();
		if (n == 0)
			return;
		int step = n;
		int i, j;
		do {
			step = step / 3 + 1;
			for (i = step; i < n; i++) {
				string article = getElement(i)->article;
				string name = getElement(i)->name;
				int count = getElement(i)->count;
				double price = getElement(i)->price;

				for (j = i - step; j >= 0 && getElement(j)->article > article; j -= step) {
					getElement(j + step)->article = getElement(j)->article;
					getElement(j + step)->name = getElement(j)->name;
					getElement(j + step)->count = getElement(j)->count;
					getElement(j + step)->price = getElement(j)->price;
				}
				getElement(j + step)->article = article;
				getElement(j + step)->name = name;
				getElement(j + step)->count = count;
				getElement(j + step)->price = price;
			}

		} while (step != 1);

	}

	void sortShellByName() {
		int n = getC();
		if (n == 0)
			return;
		int step = n;
		int i, j;
		do {
			step = step / 3 + 1;
			for (i = step; i < n; i++) {
				string article = getElement(i)->article;
				string name = getElement(i)->name;
				int count = getElement(i)->count;
				double price = getElement(i)->price;
				for (j = i - step; j >= 0 && getElement(j)->name > name; j -= step) {
					getElement(j + step)->article = getElement(j)->article;
					getElement(j + step)->name = getElement(j)->name;
					getElement(j + step)->count = getElement(j)->count;
					getElement(j + step)->price = getElement(j)->price;
				}
				getElement(j + step)->article = article;
				getElement(j + step)->name = name;
				getElement(j + step)->count = count;
				getElement(j + step)->price = price;
			}
		} while (step != 1);
	}

	void sortShellByCount() {
		int n = getC();
		if (n == 0)
			return;
		int step = n;
		int i, j;
		do {
			step = step / 3 + 1;
			for (i = step; i < n; i++) {
				string article = getElement(i)->article;
				string name = getElement(i)->name;
				int count = getElement(i)->count;
				double price = getElement(i)->price;

				for (j = i - step; j >= 0 && getElement(j)->count > count; j -= step) {
					getElement(j + step)->article = getElement(j)->article;
					getElement(j + step)->name = getElement(j)->name;
					getElement(j + step)->count = getElement(j)->count;
					getElement(j + step)->price = getElement(j)->price;
				}
				getElement(j + step)->article = article;
				getElement(j + step)->name = name;
				getElement(j + step)->count = count;
				getElement(j + step)->price = price;
			}

		} while (step != 1);

	}

	void sortShellByPrice() {
		int n = getC();
		if (n == 0)
			return;
		int step = n;
		int i, j;
		do {
			step = step / 3 + 1;
			for (i = step; i < n; i++) {
				string article = getElement(i)->article;
				string name = getElement(i)->name;
				int count = getElement(i)->count;
				double price = getElement(i)->price;
				for (j = i - step; j >= 0 && getElement(j)->price > price; j -= step) {
					getElement(j + step)->article = getElement(j)->article;
					getElement(j + step)->name = getElement(j)->name;
					getElement(j + step)->count = getElement(j)->count;
					getElement(j + step)->price = getElement(j)->price;
				}
				getElement(j + step)->article = article;
				getElement(j + step)->name = name;
				getElement(j + step)->count = count;
				getElement(j + step)->price = price;
			}
		} while (step != 1);
	}

	void EditElem(Node* node, string article, string name, int count, double price) {
		if (node == NULL) {
			throw "is empty";
		}	// В списке нет узлов		
		node->article = article;
		node->name = name;
		node->count = count;
		node->price = price;
	}
	void PrintShellByNameWitnPriceAndCount(double price, int count) {
		int n = getC();
		if (n == 0)
			return;
		int step = n;
		int i, j;
		do {
			step = step / 3 + 1;
			for (i = step; i < n; i++) {
				string article = getElement(i)->article;
				string name = getElement(i)->name;
				int count = getElement(i)->count;
				double price = getElement(i)->price;
				for (j = i - step; j >= 0 && getElement(j)->name > name; j -= step) {
					getElement(j + step)->article = getElement(j)->article;
					getElement(j + step)->name = getElement(j)->name;
					getElement(j + step)->count = getElement(j)->count;
					getElement(j + step)->price = getElement(j)->price;
				}
				getElement(j + step)->article = article;
				getElement(j + step)->name = name;
				getElement(j + step)->count = count;
				getElement(j + step)->price = price;
			}
		} while (step != 1);
		Node* p = root;						// вывод
		while (true) {
			if (getPrice(p) <= price && getCount(p) >= count) {
				cout << "Article: " << getArticle(p) << " ";
				cout << "Name: " << getName(p) << " ";
				cout << "Count: " << getCount(p) << " ";
				cout << "Prise: " << getPrice(p) << endl;
			}
			p = Next(p);
			if (p == NULL)
				break;
		}
	}

	void PrintShellByNameWitnPrice(double value) {
		int n = getC();
		if (n == 0)
			return;
		int step = n;
		int i, j;
		do {
			step = step / 3 + 1;
			for (i = step; i < n; i++) {
				string article = getElement(i)->article;
				string name = getElement(i)->name;
				int count = getElement(i)->count;
				double price = getElement(i)->price;
				for (j = i - step; j >= 0 && getElement(j)->name > name; j -= step) {
					getElement(j + step)->article = getElement(j)->article;
					getElement(j + step)->name = getElement(j)->name;
					getElement(j + step)->count = getElement(j)->count;
					getElement(j + step)->price = getElement(j)->price;
				}
				getElement(j + step)->article = article;
				getElement(j + step)->name = name;
				getElement(j + step)->count = count;
				getElement(j + step)->price = price;
			}
		} while (step != 1);

		Node* p = root;						// вывод
		while (true) {
			if (getPrice(p) <= value) {
				cout << "Article: " << getArticle(p) << " ";
				cout << "Name: " << getName(p) << " ";
				cout << "Count: " << getCount(p) << " ";
				cout << "Prise: " << getPrice(p) << endl;
			}
			p = Next(p);
			if (p == NULL)
				break;
		};
	}

	void ReadFromFile() {
		ifstream File_Data("data.bin", ios::binary);
		if (!File_Data.is_open())
		{
			cout << "Error" << endl;
			return;
		}
		string article;
		string name;
		int count;
		double price;
		while (!File_Data.eof())
		{
			File_Data >> article >> name >> count >> price;
			Add(article, name, count, price, getLast());
		}
		File_Data.close();
	}

	void WriteInFile() {
		ofstream File_Data("data.bin", ios::binary);
		if (!File_Data.is_open())
		{
			cout << "Error!" << endl;
			return;
		}
		if (isEmpty()) { cout << "is Empty" << endl; return; }
		Node* p = root;
		do {
			File_Data << "\t" << p->article << "\t" << p->name << "\t" << p->count << "\t" << p->price;
			p = Next(p);
		} while (p != NULL);
		File_Data.close();
	}
};

template<typename T>

T Check(T& inf)
{
	while (!(cin >> inf) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Error! Try again! ";
	}
	return inf;
}

int menu()
{
	int i = 0;
	cout << endl;
	cout << "Choose:" << endl;
	cout << "1. Create footgear" << endl;
	cout << "2. Add data in footgear" << endl;
	cout << "3. View the footgear" << endl;
	cout << "4. Sort footgear by Article" << endl;
	cout << "5. Sort footgear by Name" << endl;
	cout << "6. Sort footgear by Count" << endl;
	cout << "7. Sort footgear by Price" << endl;
	cout << "8. Print footgear by Name with price" << endl;
	cout << "9. Filter footgear by count and price" << endl;
	cout << "10. Edit elem" << endl;
	cout << "11. Delete elem" << endl;
	cout << "12. Clear footgear" << endl;
	cout << "13. Read footgear from file" << endl;
	cout << "14. Write footgear in file" << endl;
	cout << "15. Exit" << endl;
	Check(i);
	return i;
}

int main()
{
	Footgear footgear;
	string k;
	int i, m, num;
	string article, name;
	int count;
	double price;
	while (true)
	{
		switch (menu())
		{
		case 1:
			if (footgear.isEmpty()) {
				cout << "Enter count of records:\t";
				while (!CheckNum(k)) {							// проверка на ввод
					cin >> k;
				}
				num = stoi(k);
				for (int i = 0; i < num; i++) {
					cout << "Enter article:" << endl;
					cin >> article;
					cout << "Enter name:" << endl;
					cin >> name;
					cout << "Enter count:" << endl;
					k.clear();
					while (!CheckNum(k)) {						// проверка на ввод
						cin >> k;
					}
					count = stoi(k);
					cout << "Enter price:" << endl;
					k.clear();
					while (!CheckNum(k)) {						// проверка на ввод
						cin >> k;
					}
					price = stod(k);
					footgear.Add(article, name, count, price, footgear.getLast());					// добавление в очередь
				}
			}
			else
				cout << "Created" << endl;
			break;
		case 2:
			cout << "Enter article:" << endl;
			cin >> article;
			cout << "Enter name:" << endl;
			cin >> name;
			cout << "Enter count:" << endl;
			k.clear();
			while (!CheckNum(k)) {						// проверка на ввод
				cin >> k;
			}
			count = stoi(k);
			cout << "Enter price:" << endl;
			k.clear();
			while (!CheckNum(k)) {						// проверка на ввод
				cin >> k;
			}
			price = stod(k);
			footgear.Add(article, name, count, price, footgear.getLast());					// добавление в очередь
			break;
		case 3:
			cout << "Your footgears:\n";
			footgear.Print();								// вывод очереди
			break;
		case 4:
			footgear.sortShellByArticle();							// сотрировка очереди
			break;
		case 5:
			footgear.sortShellByName();							// сотрировка очереди
			break;
		case 6:
			footgear.sortShellByCount();							// сотрировка очереди
			break;
		case 7:
			footgear.sortShellByPrice();							// сотрировка очереди
			break;
		case 8:
			cout << "Enter price:" << endl;
			k.clear();
			while (!CheckNum(k)) {						// проверка на ввод
				cin >> k;
			}
			price = stod(k);
			footgear.PrintShellByNameWitnPrice(price);							// сотрировка очереди
			break;
		case 9:
			cout << "Enter price:" << endl;
			k.clear();
			while (!CheckNum(k)) {						// проверка на ввод
				cin >> k;
			}
			price = stod(k);
			cout << "Enter count:" << endl;
			k.clear();
			while (!CheckNum(k)) {						// проверка на ввод
				cin >> k;
			}
			count = stoi(k);
			footgear.PrintShellByNameWitnPriceAndCount(price, count);							// сотрировка очереди
			break;
		case 10:
			cout << "Enter num elem" << endl;
			Check(i);
			cout << "Enter new values" << endl;
			cout << "Enter article:" << endl;
			cin >> article;
			cout << "Enter name:" << endl;
			cin >> name;
			cout << "Enter count:" << endl;
			k.clear();
			while (!CheckNum(k)) {						// проверка на ввод
				cin >> k;
			}
			count = stoi(k);
			cout << "Enter price:" << endl;
			k.clear();
			while (!CheckNum(k)) {						// проверка на ввод
				cin >> k;
			}
			price = stod(k);
			try {
				footgear.EditElem(footgear.getElement(--i), article, name, count, price);
			}
			catch (...) {}

			break;
		case 11:
			cout << "Enter num elem" << endl;
			Check(i);
			try {
				footgear.Delete(footgear.getElement(--i));
			}
			catch (...) {}
			break;
		case 12:
			footgear.Clear();								// очищаем очередь
			break;
		case 13:
			if (footgear.isEmpty())
				footgear.ReadFromFile();
			else
				cout << "Readed" << endl;
			break;
		case 14:
			footgear.WriteInFile();
			break;
		case 15:
			system("pause");
			return 0;
		default:
			cout << "Try again!" << endl;
		}
	}
}