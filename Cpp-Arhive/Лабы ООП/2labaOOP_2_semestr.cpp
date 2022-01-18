/* Реализовать классы, представляющие из себя определенные сущности,
в которых необходимо реализовать перегрузку операторов ввода и вывода, 
а также обработку ввода. В классе должны быть обязательно реализованы поля (не менее 7),
представляющие из себя числовые и текстовые данные.
Использовать динамические данные для полей, в которых это обоснованно.
*/
/* Вариант 17 */
/* Дикие животные */

#include <iostream>
#include <iostream>
#include<string>
#include <conio.h>
#include <Windows.h>
using namespace std;

class WildAnimal
{
public:
	WildAnimal(string name1, double Life_span1, string type1, int kol1, string family1, string Habitat1, string color1);// конструктор с параметрами
	WildAnimal(); // конструктор без параметров
	friend ostream& operator<< (ostream& out, const WildAnimal obj); // Перегрузка оператора ввода
	friend istream& operator>> (istream& in, WildAnimal& obj); // перегрузка оператора вывода


	string name; // название животного
	double Life_span; // Продолжительность жизни
	string type; // тип животных (млекопитающиеся, рыбы, насекомые и прочее)
	int kol; // колличество животных популяция
	string family; // семейство (например: кашачью собачью и к примеру еще парнокопытные и т.д)
	string Habitat; // среда обитания (Вода суша леса и в таком духе)
	string color; // Окраска цвет животного
};

WildAnimal::WildAnimal(string name1, double Life_span1, string type1, int kol1, string family1, string Habitat1, string color1)
{
	name = name1;
	Life_span = Life_span1;
	type = type1;
	kol = kol1;
	family = family1;
	Habitat = Habitat1;
	color = color1;
}

WildAnimal::WildAnimal() // конструктор который все задает нулевыми значениями
{
	name = " ";
	Life_span = 0;
	type = " ";
	kol = 0;
	family = " ";
	Habitat = " ";
	color = " ";
}

int main()
{
	setlocale(0, "rus");
	SetConsoleCP(1251); // Кирилица в консоли
	SetConsoleOutputCP(1251);
	WildAnimal Animal; // создаем объект класса Animal
	try {
		cin >> Animal; 
	}
	catch (const char* s)
	{
		cout << s;
	}
	cout << "********ВЫВОД ИНФОРМАЦИИ НА ЭКРАН********" << endl;;
	cout << Animal;
	system("pause");


	int num;
	cout << "Хотите отредактировать какое-то поле класса?" << endl;
	cout << "1-Da  2- Net" << endl;
	cin >> num;
	if (num == 1) {
		cout << "Что вы хотите отредактировать?" << endl;
		cout << "1.Название Животного: " << endl;
		cout << "2.Продолжительность жизни (в месяцах): " << endl;
		cout << "3.Тип животного: " << endl;
		cout << "4.Количество популяции: "<< endl;
		cout << "5.Семейство: " << endl;
		cout << "6.Среда обтания: " << endl;
		cout << "7.Цвет: " << endl;
		int num2;
		cin >> num2;
		switch (num2)
		{
		case 1:
			cout << "ВВедите новое название: ";
			cin >> Animal.name;
			cout << Animal; break;
		case 2:
			cout << "ВВедите новою продолжительность жизни: ";
			cin >> Animal.Life_span;
			cout << Animal; break;
		case 3:
			cout << "ВВедите новый тип животного: ";
			cin >> Animal.type;
			cout << Animal; break;
		case 4:
			cout << "ВВедите новую популяцию: ";
			cin >> Animal.kol;
			cout << Animal; break;
		case 5:
			cout << "ВВедите новое семейство : ";
			cin >> Animal.family;
			cout << Animal; break;
		case 6:
			cout << "ВВедите новую среду обитания: ";
			cin >> Animal.Habitat;
			cout << Animal; break;
		case 7:
			cout << "ВВедите новый цвет: ";
			cin >> Animal.color;
			cout << Animal; break;

		default:
			break;
		}

	}

	return 0;
}

ostream& operator<<(ostream& out, const WildAnimal obj)
{

	out << "Название Животного: " << obj.name << endl;
	out << "Продолжительность жизни (в месяцах): " << obj.Life_span << endl;
	out << "Тип животного: " << obj.type << endl;
	out << "Количество популяции: " << obj.kol << endl;
	out << "Семейство: " << obj.family << endl;
	out << "Среда обтания: " << obj.Habitat << endl;
	out << "Цвет: " << obj.color << endl;
	return out;
}

istream& operator>> (istream& in, WildAnimal& obj) // перегружаем оператор ввода
{
	string str;
	int n = 0;
	int work = 0;
	//cout << "Введите название животного:";
	//getline(in, obj.name); //  getline предназначена для ввода данных из потока, например, для ввода данных из консольного окна
	int work16 = 0;
	while (work16 != 1)
	{
		cout << "Введите название животного: "; // getline(in, obj.type);
		in >> str;
		in.ignore();
		try {
			int k = 0;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] > '0' && str[i] < '9')
				{
					k++;
					break;
				}
			}
			if (k != 0)
				throw "Ошибка! Нельзя вводить Числа!";
			if (k == 0) work16 = 1;
			obj.name = str;
		}
		catch (...)
		{
			cout << "Неизсвестная ошибка! НЕЛЬЗЯ ВВОДИТЬ ЧИСЛА ТОЛЬКО БУКВЫ" << endl;
		}
	}


	while (work != 1)
	{
		cout << "Введите Продолжительность жизни (в месяцах):";
		in >> str;
		in.ignore();
		try {
			int k = 0;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] < '0' || str[i]>'9') // проверка на ввод чисел
				{
					k++;
					break;
				}
			}
			if (k != 0)
				throw "Ошибка!Нужно вводить число!";
			if (k == 0) work = 1;
			obj.Life_span = stoi(str); // Извлекает знаковое целое число из строки str.
		}
		catch (const char* s)
		{
			cout << s << endl;
		}
		catch (invalid_argument)
		{
			cout << "Вводить можно только числа!" << endl;
		}
		catch (out_of_range)
		{
			cout << "Число слишком большое!" << endl;
		}
		catch (...)
		{
			cout << "Неизсвестная ошибка!" << endl;
		}
	}
	int work2 = 0;
	while (work2 != 1)
	{
		cout << "Введите количество популяции:";
		in >> str;
		in.ignore();
		try {
			int k = 0;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] < '0' || str[i]>'9')
				{
					k++;
					break;
				}
			}
			if (k != 0)
				throw "Ошибка!Нужно вводить число!";
			if (k == 0) work2 = 1;
			obj.kol = stoi(str); // Извлекает знаковое целое число из строки str.
		}
		catch (const char* s)
		{
			cout << s << endl;
		}
		catch (invalid_argument) //  Определяет исключение, которое должно быть брошено в случае неправильного аргумента.
		{
			cout << "Вводить можно только числа!" << endl;
		}
		catch (out_of_range) // Определяет исключение, которое должно быть брошено в том случае, когда происходит выход за пределы допустимого диапазона значений объекта.
		{
			cout << "Число слишком большое!" << endl;
		}
		catch (...)
		{
			cout << "Неизсвестная ошибка!" << endl;
		}
	}

	int work3 = 0;
	while (work3 != 1)
	{
		cout << "Введите тип животного:"; // getline(in, obj.type);
		in >> str;
		in.ignore();
		try {
			int k = 0;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] > '0' && str[i]<'9')
				{
					k++;
					break;
				}
			}
			if (k != 0)
				throw "Ошибка! Нельзя вводить Числа!";
			if (k == 0) work3 = 1;
			obj.type = str;
		}
		catch (...)
		{
			cout << "Неизсвестная ошибка! НЕЛЬЗЯ ВВОДИТЬ ЧИСЛА ТОЛЬКО БУКВЫ" << endl;
		}
	}
	//cout << "Введите тип животного:"; getline(in, obj.type);
	////////////////////////////////////////////////////////////////////
	int work4 = 0;
	while (work4 != 1)
	{
		cout << "Введите семейство:"; // getline(in, obj.type);
		in >> str;
		in.ignore();
		try {
			int k = 0;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] > '0' && str[i] < '9')
				{
					k++;
					break;
				}
			}
			if (k != 0)
				throw "Ошибка! Нельзя вводить Числа!";
			if (k == 0) work4 = 1;
			obj.family = str;
		}
		catch (...)
		{
			cout << "Неизсвестная ошибка! НЕЛЬЗЯ ВВОДИТЬ ЧИСЛА ТОЛЬКО БУКВЫ" << endl;
		}
	}

	///cout << "Введите семейство:"; getline(in, obj.family);

	int work5 = 0;
	while (work5 != 1)
	{
		cout << "Введите среду обитания:"; // getline(in, obj.type);
		in >> str;
		in.ignore();
		try {
			int k = 0;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] > '0' && str[i] < '9')
				{
					k++;
					break;
				}
			}
			if (k != 0)
				throw "Ошибка! Нельзя вводить Числа!";
			if (k == 0) work5 = 1;
			obj.Habitat = str;
		}
		catch (...)
		{
			cout << "Неизсвестная ошибка! НЕЛЬЗЯ ВВОДИТЬ ЧИСЛА ТОЛЬКО БУКВЫ" << endl;
		}
	}


	//cout << "Введите среду обитания:"; getline(in, obj.Habitat);

	int work6 = 0;
	while (work6 != 1)
	{
		cout << "Введите цвет окраски:"; // getline(in, obj.type);
		in >> str;
		in.ignore();
		try {
			int k = 0;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] > '0' && str[i] < '9')
				{
					k++;
					break;
				}
			}
			if (k != 0)
				throw "Ошибка! Нельзя вводить Числа!";
			if (k == 0) work6 = 1;
			obj.color = str;
		}
		catch (...)
		{
			cout << "Неизсвестная ошибка! НЕЛЬЗЯ ВВОДИТЬ ЧИСЛА ТОЛЬКО БУКВЫ" << endl;
		}
	}



	//cout << "Введите цвет окраски животного:"; getline(in, obj.color);
	return in;
}
