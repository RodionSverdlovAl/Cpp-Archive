// Вариант 18  (Дизайн - базовый класс)
// 1. Лабораторная работа выполняется в Visual Studio 2010-2017 версия.
// 2. Соблюдение основных принципов ООП и правил хорошего тона(не использовать глобальные переменные и т.д.).
// Общая часть задания :
// Реализовать базовый класс(указан в варианте) и унаследовать от него 3 разных дочерних класса(на свое усмотрение), 
// каждый из которых будет добавлять разные поля и методы к базовому классу.В каждом классе должно быть как 
// минимум 2 поля(в дочерних классах также должно быть как минимум 2 своих поля), характеризующие объект.
// Инициализация полей базового класса при создании объекта дочернего класса должна реализоваться через вызов конструктора базового класса.
// Реализовать возможность просмотра содержимого.Продемонстрировать создание, инициализацию полей и работу объектов дочерних классов.
// Также необходимо продемонстрировать диаграмму классов.
// Все возможные данные вводятся с клавиатуры с проверкой на корректность.
// Данные для объектов вводятся в main и передаются в объекты классов через конструкторы.
// Память выделять динамически.В случае отсутствия надобности в дальнейшем использовании выделенной памяти осуществлять освобождение памяти.

// Дочерние классы
// auto
// phone
// house

#include <iostream>
#include <string>
using namespace std;

class Design
{
public:
	Design(string col, string mat); // конструктор
	string GetColor();
	string GetMaterial();

private:
	string color;
	string material;
};

Design::Design(string col, string mat) // конструктор
{
	color = col;
	material = mat;
}

string Design::GetColor()
{
	return color;
}

string Design::GetMaterial()
{
	return material;
}

class Auto : public Design
{
public:
	Auto(int S, int P, string col, string mat) :Design(col, mat) {
		speed = S;
		power = P;
	};
	void PrintInfo();

private:
	int speed;
	int power;

};

class Phone : public Design
{
public:
	Phone(int BV, int SD, string col, string mat) : Design(col, mat) {
		BatteryVolume = BV;
		ScreenDiameter = SD;
	};
	void PrintInfo();

private:
	int BatteryVolume;
	int ScreenDiameter;
};

class House :public Design
{
public:
	House(int F, int R, string col, string mat) : Design(col, mat) {
		Floors = F;
		Rooms = R;
	};
	void PrintInfo();

private:
	int Floors;
	int Rooms;
};

int main()
{
	setlocale(LC_ALL, "ru");
	int exit = true;
	while (exit)
	{
		int menu;
		cout << "------------МЕНЮ------------" << endl;
		cout << "(1) Создать автомобиль" << endl;
		cout << "(2) Создать телефон" << endl;
		cout << "(3) Создать дом" << endl;
		cout << "(4) Выйти из программы" << endl;
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:// create auto
		{
			int S, P; string col, mat;
			cout << "Введите скорость авто:"; cin >> S;
			cout << "Введите мощьность авто:"; cin >> P;
			cout << "Укажите цвет:"; cin >> col;
			cout << "Укажите материал:"; cin >> mat;
			system("cls");
			Auto a1(S, P, col, mat);
			a1.PrintInfo();
			system("pause");
			system("cls");
		}; break;
		case 2:// create phone
		{
			int BV, SD; string col, mat;
			cout << "Введите объем аккумулятора:"; cin >> BV ;
			cout << "Введите диаметр дисплея:"; cin >> SD;
			cout << "Укажите цвет:"; cin >> col;
			cout << "Укажите материал:"; cin >> mat;
			system("cls");
			Phone p1(BV, SD, col, mat);
			p1.PrintInfo();
			system("pause");
			system("cls");
		}; break;
		case 3:// create house
		{
			int F, R; string col, mat;
			cout << "Введите колличесто этажей:"; cin >> F;
			cout << "Введите колличество комнат:"; cin >> R;
			cout << "Укажите цвет:"; cin >> col;
			cout << "Укажите материал:"; cin >> mat;
			system("cls");
			House h1(F, R, col, mat);
			h1.PrintInfo();
			system("pause");
			system("cls");
		}; break;
		case 4:// exit
		{
			exit = false;
		}; break;
		default:
			break;
		}

	}
}

void Auto::PrintInfo()
{
	cout << "-----Information about auto-------" << endl;
	cout << "Speed: " << speed << endl;
	cout << "Power: " << power << endl;
	cout << "Color: " << GetColor() << endl;
	cout << "Material: " << GetMaterial() << endl;
}

void Phone::PrintInfo()
{
	cout << "-----Information about Phone-------" << endl;
	cout << "Battery volume;: " << BatteryVolume << endl;
	cout << "Screen diameter: " << ScreenDiameter << endl;
	cout << "Color: " << GetColor() << endl;
	cout << "Material: " << GetMaterial() << endl;
}

void House::PrintInfo()
{
	cout << "-----Information about House-------" << endl;
	cout << "Floors: " << Floors << endl;
	cout << "Rooms: " << Rooms << endl;
	cout << "Color: " << GetColor() << endl;
	cout << "Material: " << GetMaterial() << endl;
}