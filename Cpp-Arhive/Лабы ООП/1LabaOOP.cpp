/*Проверить обработку исключительных ситуаций: выделение памяти,
удаление из пустого множества, проверка ввода. Реализовать
однонаправленный список с использованием сортировки Шелла.*/

#include <iostream>
#include <string>
using namespace std;

class Och {									// класс очереди
private:
	struct Node								// структура, которая содержить поле inf и указатель на следующий элемент
	{
		int inf;
		Node* next;
	};

	int count;
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

	Och() {
		root = NULL;						// инициализация корня значением NULL
		count = 0;
	}


	Node* getRoot() {						// функция, которая возвращает корень списка
		return root;
	}

	Node* Add(int inf, Node* node = NULL)		// функция добавления узла в очередь
	{
		Node* elem = new Node();

		elem->inf = inf;
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
			count++;
			return elem;
		}
		elem->next = node->next;			// Добавление узла после текущего
		node->next = elem;
		count++;
		return elem;
	}

	bool isEmpty() { return root == NULL; }	// Проверка, пуст ли список

	int getValue(Node* p) { return p->inf; } // Получение значения узла списка

	void setValue(Node* p, int val) { p->inf = val; } // Установка значения узла списка

	int getCount() { return count; }	// получить количества элементов

	Node* getFirst() { return root; }		// Получение корневого узла списка

	Node* getElement(int k) {
		if (k > getCount()) {
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
			cout << getValue(p) << " ";
			p = Next(p);
		} while (p != NULL);
		cout << endl;
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
		count = 0;
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
			count--;
			return root;
		}
		Node* prev = Prev(node);			// Удаление промежуточного узла
		prev->next = node->next;
		delete node;
		count--;
		return prev;
	}

	void Сhange(int first, int last) {

		Node* p1, * p2, * tmp_pos;

		p1 = root;
		p2 = root;

		for (int i = 1; i < first; i++) {
			p2 = p2->next;
		}
		for (int i = 1; i < last; i++) {
			p1 = p1->next;
		}

		tmp_pos = p1->next;
		p1->next = p2->next;
		p2->next = tmp_pos;
	}

	void sortShell() {
		int n = getCount();
		if (n == 0)
			return;
		int step = n;
		int i, j;
		do {
			step = step / 3 + 1;
			for (i = step; i < n; i++) {
				int c = getElement(i)->inf;
				for (j = i - step; j >= 0 && getElement(j)->inf > c; j -= step)
					getElement(j + step)->inf = getElement(j)->inf;
				getElement(j + step)->inf = c;
			}

		} while (step != 1);

	}
};

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
	cout << "1  Create och" << endl;
	cout << "2. Add data in och" << endl;
	cout << "3.View och" << endl;
	cout << "4.Sort och" << endl;
	cout << "5.Delete elem" << endl;
	cout << "6 Clear och" << endl;
	cout << "7. Exit" << endl;
	Check(i);
	return i;
}
int main()
{
	/*try {										//обработка выделения памяти
		while (1) {
			Och* och1 = new Och[10000000];
		}

	}
	catch (bad_alloc e) {
		cout << "Error: " << e.what() << endl;
	}


	Och och;

	try {											// проверка на удаление узла, которго нет
		och.Delete(och.getLast());
	}
	catch (...) {
		cout << "is empty" << endl;
	}

	string n;
	int num;
	cout << "Enter count of values:\t";
	while (!CheckNum(n)) {							// проверка на ввод
		cin >> n;
	}
	num = stoi(n);

	cout << "Enter values:" << endl;
	for (int i = 0; i < num; i++) {

		string k;
		while (!CheckNum(k)) {						// проверка на ввод
			cin >> k;
		}
		int m = stoi(k);
		och.Add(m, och.getLast());					// добавление в очередь

	}

	och.Print();									// вывод очереди


	cout << "Sorting" << endl;
	och.sortShell();
	och.Print();

	cout << "Clearing..." << endl;
	och.Clear();									// очищаем очередь
	och.Print();									// вывод очереди*/

	Och och;
	string k;
	int i, m, num;

	while (true)
	{
		switch (menu())
		{
		case 1:
			if (och.isEmpty()) {
				cout << "Enter count of values:\t";
				while (!CheckNum(k)) {							// проверка на ввод
					cin >> k;
				}
				num = stoi(k);
				cout << "Enter values:" << endl;
				for (int i = 0; i < num; i++) {
					k.clear();
					while (!CheckNum(k)) {						// проверка на ввод
						cin >> k;
					}
					m = stoi(k);
					och.Add(m, och.getLast());					// добавление в очередь

				}
			}
			else
				cout << "Created" << endl;
			break;
		case 2:
			k.clear();
			cout << "Enter value:" << endl;
			while (!CheckNum(k)) {						// проверка на ввод
				cin >> k;
			}
			m = stoi(k);
			och.Add(m, och.getLast());		// добавление в очередь
			break;
		case 3:
			cout << "Your och:\t";
			och.Print();			// вывод очереди
			break;
		case 4:
			och.sortShell();// сотрировка очереди
			cout << "Sorting end..." << endl;
			break;
		case 5:
			cout << "Enter num elem" << endl;
			Check(i);
			try {
				och.Delete(och.getElement(i--));
			}
			catch (...) {}
			break;
		case 6:
			och.Clear();				// очищаем очередь
			break;
		case 7:
			system("pause");
			return 0;
		default:
			cout << "Try again!" << endl;
		}
	}

}
