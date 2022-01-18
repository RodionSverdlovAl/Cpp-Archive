#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

int writeNumbers();
int chooseMenu(); // выбор пункта меню
int chooseUr(string*, int); // выбор уравнения

template <typename T>
class Uravnenie // класс над объекнтами которого выполняются транзакции
{
private:
	T a, b, c; // коэффиценты
	T disk; // дискриминант
	T x1;
	T x2;
public:
	// конструктор
	Uravnenie() {
		a = b = c = x1 = x2 = disk = 0; // инициализация полей объекта нулевыми значениями
	}
	// конструктор с параметрами
	Uravnenie(T a1, T b1, T c1) {
		a = a1;
		b = b1;
		c = c1;
		disk = b * b - 4 * a * c;
		x1 = (-b + sqrt(disk)) / (2 * a);
		x2 = (-b - sqrt(disk)) / (2 * a);
	}
	void show() {
		disk = b * b - 4 * a * c;
		x1 = (-b + sqrt(disk)) / (2 * a); // вычесляем х1
		x2 = (-b - sqrt(disk)) / (2 * a); // вычесляем х2
		cout << a << "x^2";
		if (b < 0) cout << b << "x";
		else cout << "+" << b << "x";
		if (c < 0) cout << c;
		else cout << "+" << c;
		cout << endl;
		T rav = 4 * a * c;
		if (rav < 0) cout << "D = " << b * b << "+" << -rav;
		else cout << "D = " << b * b << "-" << rav;
		cout << " = " << disk << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	Uravnenie<T>& operator*=(int abc) {
		a *= abc;
		b *= abc;
		c *= abc;
		return*this;
	}
	string getUravnenie() {
		string s;
		s = to_string(a) + "x^2";
		if (b < 0) s = s + to_string(b) + "x";
		else s = s + "+" + to_string(b) + "x";
		if (c < 0) s = s + to_string(c);
		else s = s + "+" + to_string(c);
		return s;
	}
	void setKeff() // установка коэффицентов
	{
		cout << "Введите a: ";
		a = writeNumbers();
		cout << "Введите b: ";
		b = writeNumbers();
		cout << "Введите c: ";
		c = writeNumbers();
	}
	T getA() {
		return a;
	}
	T getB() {
		return b;
	}
	T getC() {
		return c;
	}
	void changeA(T w) {
		a = w;
	}
	void changeB(T w) {
		b = w;
	}
	void changeC(T w) {
		c = w;
	}
};

template <typename T>
class Tranzktion // класс поддержки транзакций
{
public:
	// смарт указатели
	Uravnenie<T>* that; // текущее значение обекта
	Uravnenie<T>* previos; // предидущее значение объекта
public:
	Tranzktion() :previos(NULL), that(new Uravnenie<T>) {}; // конструктор
	Tranzktion(const Tranzktion<T>& _st) :that(new Uravnenie<T>(*(_st.that))), previos(NULL) {}; // конструктор копирования
	~Tranzktion()// деструктор
	{
		delete that;
		delete previos;
	};
	Tranzktion<T>& operator=(const Tranzktion<T>& _st) // перегрузка оператора присваивание
	{
		if (this != &_st) // проверка на случай st = st
		{
			delete that; // удаление текущего значения объекта
			that = new Uravnenie<T>(*(_st.that)); // создание и копирование
		}
		return *this; 
	};
	void BeginTrans() // начало транзакции
	{
		delete previos; // удаление предидущего значения
		previos = that; // текущее становится предидущим
		that = new Uravnenie<T>(*previos); // новое значение текущего значения
	};
	void Commit() // закрепление транзакции
	{
		delete previos;// удаление предидущего значения
		previos = NULL; // предидущего состояния нет
	};
	void Rollback() // отмена
	{
		if (previos != NULL)
		{
			delete that; // удаление текущего значения
			that = previos; // предидущее становится текущим
			previos = NULL; // предидущего состояния нет
		}
	};
	Uravnenie<T>* operator->() // перегрузка операции ->
	{ return that; };
};

int main() {
	setlocale(0, "rus");
	int nUr = 0;
	Tranzktion<double>* ur = new Tranzktion<double>[1]; // указываем тип данных с которым будем работать переменная УРАВНЕНИЯ
	while (true) {
		int choose = chooseMenu(); // выбор пункта меню
		if (choose == 0) // добавляем объект
		{
			nUr++;
			Tranzktion<double>* ptr = new Tranzktion<double>[nUr]; // указываем тип даннных для *ПТР*
			for (int i = 0; i < nUr - 1; i++)
				ptr[i] = ur[i];
			ur = ptr;
			ptr = NULL;
			delete[]ptr;
			ur[nUr - 1]->setKeff();
		}
		else
			if (choose == 1) // посмотреть и решить уравнение
			{
				for (int i = 0; i < nUr; i++) {
					ur[i]->show();
					cout << endl;
				}
				system("pause");
				system("cls");
			}
			else
				if (choose == 2) // умножаем коэффицент на число
				{
					string* aa = new string[nUr];
					for (int i = 0; i < nUr; i++)
						aa[i] = ur[i]->getUravnenie();
					int choose1 = chooseUr(aa, nUr);
					delete[]aa;
					if (choose1 == nUr) continue;
					cout << "Введите число на которое умножить коэффиценты: ";
					int a = writeNumbers();
					ur[choose1].BeginTrans(); // начало транзакции (изменения объекта)
					ur[choose1]->operator*=(a);
				}
				else
					if (choose == 3) // откат уравнения на предидущее (отмена транзакции)
					{
						string* aa = new string[nUr];
						for (int i = 0; i < nUr; i++)
							aa[i] = ur[i]->getUravnenie(); // получаем уравнение
						int choose1 = chooseUr(aa, nUr);
						delete[]aa;
						if (choose1 == nUr) continue;
						cout << "До умножения: " << ur[choose1]->getUravnenie() << endl;
						ur[choose1].Rollback(); // отмена транзакции
						cout << "После умножения: " << ur[choose1]->getUravnenie() << endl;
						system("pause");
						system("cls");
					}
					else
						if (choose == 4) // вычтание одного уравнения от другого
						{
							string* aa = new string[nUr];
							for (int i = 0; i < nUr; i++)
								aa[i] = ur[i]->getUravnenie();
							int choose1 = chooseUr(aa, nUr);
							if (choose1 == nUr) continue;
							int choose2 = chooseUr(aa, nUr);
							if (choose2 == nUr) continue;
							ur[choose1].BeginTrans(); // начало транзакции
							ur[choose1]->changeA(ur[choose1]->getA() - ur[choose2]->getA());
							ur[choose1]->changeB(ur[choose1]->getB() - ur[choose2]->getB());
							ur[choose1]->changeC(ur[choose1]->getC() - ur[choose2]->getC());
							delete[]aa;
							cout << "Вычетание прошло успешно!" << endl;
							system("pause");
							system("cls");
						}
						else break;
	}
	delete[]ur;
	return 0;
}

int chooseMenu() {
	int choose_menu = 0, key = 0;
	system("cls");
	while (true) {
		choose_menu = (choose_menu + 6) % 6;

		if (choose_menu == 0) cout << "**СОЗДАТЬ/ДОБАВИТЬ УРАВНЕНИЕ**" << endl;
		else cout << " создать/добавить уравнение" << endl;

		if (choose_menu == 1) cout << "**ПОСМОТРЕТЬ УРАВНЕНИЕ И РЕШИТЬ ЕГО**" << endl;
		else cout << " посмотреть уравнения и решить его" << endl;

		if (choose_menu == 2) cout << "**УМОЖИТЬ КОЭФИЦЕНТЫ НА ЧИСЛО**" << endl;
		else cout << " умножить коэфиценты на число" << endl;

		if (choose_menu == 3) cout << "**ОТКАТ УРАВНЕНИЯ НА ПРЕИДУЩЕЕ**" << endl;
		else cout << " откат уравнения на предыдущее" << endl;

		if (choose_menu == 4) cout << "**ОТНЯТЬ ОДНО УРАВНЕНИЕ ОТ ДРУГОГО**" << endl;
		else cout << " отнять одно уравнения от другого" << endl;

		if (choose_menu == 5) cout << "**ВЫХОД**" << endl;
		else cout << " выход" << endl;

		key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 72) choose_menu--;
			if (key == 80) choose_menu++;
		}
		if (key == 13) {
			system("cls");
			return choose_menu;
		}
		system("cls");
	}
}

int writeNumbers() {
	string numbers;
	int d = 0;
	while (true) {
		int key;
		key = _getch(); // получение номера кнопки
		if (key == 224) {
			key = _getch(); // повторное получения номера кнопки
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					if (numbers[numbers.length() - 1] == ',') d = 0;
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0 && numbers != "-") break;
				else
					if ((key >= '0' && key <= '9') || (key == '-' && numbers.length() == 0) || (key == ',')) {
						if (key == ',' && numbers.length() != 0 && d == 0) {
							d = 1;
							numbers = numbers + (char)key;
							cout << (char)key;
						}
						else
							if (key != ',') {
								numbers = numbers + (char)key;
								cout << (char)key;
							}
					}
	}
	cout << endl;
	return stoi(numbers);
}

int chooseUr(string* a, int nUr) // функция выбора уравнения
{
	int choose_menu = 0, keyboard_button = 0; // номер кнопки
	while (true) {
		cout << "выберите уравнение" << endl;
		choose_menu = (choose_menu + (nUr + 1)) % (nUr + 1);

		for (int i = 0; i < nUr; i++)
			if (i == choose_menu) { cout << " ==> " << i + 1 << " - " << a[i] << endl; }
			else { cout << " " << i + 1 << " - " << a[i] << endl; }

		if (choose_menu == nUr) { cout << "**НАЗАД**" << endl; }
		else cout << " назад" << endl;

		keyboard_button = _getch(); // получаем номер кнопки
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}