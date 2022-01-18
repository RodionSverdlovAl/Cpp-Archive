#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// 1 - Задание. Написать класс одномерного массива и реализовать методы нахождения минимального эллемента а также суммы эллементов между n и m
// конструктор диструктор конструктор копирования обработка исключений

bool CheckNum(string s) {
	if (!s.empty()) { // проверка если стр не пусто
		try
		{
			int num = stoi(s);// s-string переводим в инт
			return true;
		}
		catch (invalid_argument) // введено не число
		{
			cout << "Only numbers are allowed! \n";
		}
		catch (out_of_range) { // если число слишком большое
			cout << "Can't convert into int! \n";
		}
		catch(...){
			//Если будет выброшено неизвестное исключение
			cout << "Unknown error! \n";
		}
	}
}

template <class T>
class Array
{
private:
	T* arr;
	int size;

	bool CheckNum(string s) {
		if (!s.empty()) { // проверка если стр не пусто
			try
			{
				int num = stoi(s);// s-string переводим в инт
				return true;
			}
			catch (invalid_argument) // введено не число
			{
				cout << "Only numbers are allowed! \n";
			}
			catch (out_of_range) { // если число слишком большое
				cout << "Can't convert into int! \n";
			}
			catch (...) {
				//Если будет выброшено неизвестное исключение
				cout << "Unknown error! \n";
			}
		}
	}

public:
	Array() { // конструктор
		this->size = 0;
		arr = new T(size);
	}
	Array(int s) { // конструктор с параметрами
		this->size = s;
		arr = new T(size);
	}
	Array(Array& souse) { // конструктор копирования
		this->size = souse.size;
		arr = new T(size);
		for (int i = 0; i < size; i++) {
			arr[i] = souse.arr[i];
		}
	}
	~Array() {
		delete[] arr;
	}
	T min_element() {
		T min = arr[0];
		for (int i = 0; i < size; i++) {
			if (min > arr[i])
				min = arr[i];
		}
		return min;
	}
	T sum_elements(int n, int m) {
		T sum = 0;
		for (int i = n + 1; i < m; i++) {
			sum += arr[i];
		}
		return sum;
	}
	void set() {
		for (int i = 0; i < size; i++) {
			string element;
			while (!CheckNum(element)) {
				cout << "Enter " << i << " element "; cin >> element;
			};
			arr[i] = stoi(element);
		}
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << i << " element = " << arr[i] << endl;
		}
	}
	T& operator[](int index) {
		return arr[index];
	}

	
};
void print_first_menu() {
	cout << "1 - set array" << endl;
	cout << "2 - print array" << endl;
	cout << "3 - find min element" << endl;
	cout << "4 - find sum elements" << endl;
	cout << "5 - Exit" << endl;
}

// 2 - Задание. написать класс текстового файла (конструктор деструктор запись чтение ) поменять первую и последнюю строки файла использовать char а не стринг



int main()
{
    setlocale(LC_ALL, "ru");
    cout << "[1] First Task" << endl;
	cout << "[2] Second Task" << endl;
    int chouse; cin >> chouse;
	switch (chouse)
	{
	case 1: {
		cout << "Enter array size "; int size; cin >> size; Array<int> massiv(size);
		bool sost = true;
		while (sost)
		{
			print_first_menu();
			int menu_one; cin >> menu_one;
			system("cls"); system("pause");
			switch (menu_one)
			{
			case 1: massiv.set(); break;
			case 2: massiv.print(); break;
			case 3: cout << "minimal element array = " << massiv.min_element() << endl;; break;
			case 4: cout << "enter start index "; int n; cin >> n; cout << "enter finish index "; int m; cin >> m; cout << "Sum element = " << massiv.sum_elements(n, m) << endl;; break;
			case 5: sost = false;
			default: cout << "ERROR (Enter 1-5)" << endl;
				break;
			}
		}
	}break;
	case 2: {

	}
	default:
		break;
	}

}









void ReadFromFile() {
	ifstream File_Data("data.bin", ios::binary);
	if (!File_Data.is_open())
	{
		cout << "Error" << endl;
		return;
	}

	char buf[50];
	while (true)
	{
		File_Data.read(reinterpret_cast<char*>(&buf), sizeof(buf));
		string article = string(buf);

		File_Data.read(reinterpret_cast<char*>(&buf), sizeof(buf));
		string name = string(buf);

		int count;
		File_Data.read(reinterpret_cast<char*>(&count), sizeof(count));

		double price;
		File_Data.read(reinterpret_cast<char*>(&price), sizeof(price));
		if (File_Data.eof())
			break;
		else
			Add(article, name, count, price, getLast());
	}

	File_Data.close();
}

void WriteInFile() {
	ofstream File_Data("data.bin", ios::out | ios::binary);
	if (!File_Data.is_open())
	{
		cout << "Error!" << endl;
		return;
	}
	if (isEmpty()) { cout << "is Empty" << endl; return; }
	Node* p = root;
	do {
		char buf[50];

		string article = p->article;
		strcpy_s(buf, article.length() + 1, article.c_str());
		File_Data.write(reinterpret_cast<char*>(&buf), sizeof(buf));

		strcpy_s(buf, p->name.length() + 1, p->name.c_str());
		File_Data.write(reinterpret_cast<char*>(&buf), sizeof(buf));

		File_Data.write(reinterpret_cast<char*>(&p->count), sizeof(p->count));
		File_Data.write(reinterpret_cast<char*>(&p->price), sizeof(p->price));
		p = Next(p);
	} while (p != NULL);
	File_Data.close();
}

void ShowFile() {
	ifstream File_Data("data.bin", ios::binary);
	if (!File_Data.is_open())
	{
		cout << "Error" << endl;
		return;
	}

	char buf[50];
	while (true)
	{
		File_Data.read(reinterpret_cast<char*>(&buf), sizeof(buf));
		string article = string(buf);

		File_Data.read(reinterpret_cast<char*>(&buf), sizeof(buf));
		string name = string(buf);

		int count;
		File_Data.read(reinterpret_cast<char*>(&count), sizeof(count));

		double price;
		File_Data.read(reinterpret_cast<char*>(&price), sizeof(price));
		if (File_Data.eof())
			break;
		else
			cout << "Article: " << article << " " <<
			"Name: " << name << " " <<
			"Count: " << count << " " <<
			"Prise: " << price << endl;
	}

	File_Data.close();
}
};