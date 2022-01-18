#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;
const double pi = 3.14159;

class Shape  // абстрактный базовый класс
{
public:                	            // чисто виртуальные функции
    virtual void print() = 0;   // печать названия фигуры
    virtual void area() = 0;	   // вычисление площади фигуры
    virtual void volume() = 0;// вычисление объема фигуры     	
};

class TwoDShape : public Shape  	   // абстрактный производный класс
{
protected:
    float r;
public:
    TwoDShape(float r1)            	   // конструктор с параметрами
    {
        r = r1;
    }
    virtual void area() = 0;                // вычисление площади фигуры
    void volume() {}	                     // определение функции вычисления
                                                         // объема фигуры    	
};

class Circle : public TwoDShape   // класс «Окружность»
{
public:
    Circle(float r) :TwoDShape(r) {}
    void print()
    {
        cout << "Окружность" << endl;
    }
    void area()
    {
        cout << "Площадь окружности" << setw(10) << pi * r * r << endl;
    }
};

class Rectangle : public TwoDShape 	// класс «Квадрат»
{
public:
    Rectangle(float r) :TwoDShape(r) {}
    void print()
    {
        cout << "Квадрат" << endl;
    }
    void area()
    {
        cout << "Площадь квадрата" << setw(7) << r * r << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Shape* ptr[4]; //  массив указателей на абстрактный базовый класс
    Circle okr(5);      	       	// объект класса «Окружность»
    Rectangle pr(5);  	// объект класса «Прямоугольник»
    ptr[0] = &okr;         	// инициализация массива указателей ptr
    ptr[1] = &pr;
    for (int i = 0; i < 2; i++)
    {
        ptr[i]->print();     	// вывод названия фигуры
        ptr[i]->area();     	// вывод площади фигуры
        ptr[i]->volume();	// вывод объема фигуры
    }
    return 0;
}