#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Design  // абстрактный базовый класс
{
public:                	            
    virtual void print() = 0;   // печать названия 	
};

class OneDesign : public Design  	   
{
protected:
    string color;
    string material;
public:
    OneDesign(string c,string m) // конструктор с параметрами
    {
        color = c;
        material = m;
    }
    virtual void print()
    {

    }
};


class Phone : public OneDesign
{
protected:
    int BatteryVolume;
    int ScreenDiameter;
public:
    Phone(int BV,int SD,string c,string m): OneDesign(c, m)
    {
        BatteryVolume = BV;
        ScreenDiameter = SD;
    }
    void print()
    {
        cout << "Телефон" << endl;
        cout << "Цвет: " << color << endl;
        cout << "Материал: " << material << endl;
        cout << "Объем батареи: " << BatteryVolume << endl;
        cout << "Диаметр экрана: " << ScreenDiameter << endl;
    }
};
class Auto : public OneDesign
{
protected:
    int speed;
    int power;
public:
    Auto(int p,int s, string c, string m) : OneDesign(c, m)
    {
        speed = s;
        power = p;
    }
    void print()
    {
        cout << "Автомобиль" << endl;
        cout << "Цвет: " << color << endl;
        cout << "Материал: " << material << endl;
        cout << "Скорость: " << speed << endl;
        cout << "Мощьность: " << power << endl;
    }
};

class House :public OneDesign
{
protected:
    int Floors;
    int Rooms;
public:
    House(int f, int r, string c, string m) : OneDesign(c, m)
    {
        Floors = f;
        Rooms = r;
    }
    void print()
    {
        cout << "Дом" << endl;
        cout << "Цвет: " << color << endl;
        cout << "Материал: " << material << endl;
        cout << "Колличество этажей: " << Floors << endl;
        cout << "Колличество комнат: " << Rooms << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int BV, SD, s, p, r, f;
    string c, m;
     Design* ptr[3];
     cout << "Создание авто" << endl;
     cout << "Введите скорость авто:"; cin >> s;
     cout << "Введите мощьность авто:"; cin >> p;
     cout << "Укажите цвет:"; cin >> c;
     cout << "Укажите материал:"; cin >> m;
     cout << "--------------------------" << endl;
     Auto Au(s, p, c, m);
     cout << "Создание телефона" << endl;
     cout << "Введите объем аккумулятора:"; cin >> BV;
     cout << "Введите диаметр дисплея:"; cin >> SD;
     cout << "Укажите цвет:"; cin >> c;
     cout << "Укажите материал:"; cin >> m;
     cout << "--------------------------" << endl;
     Phone  Ph(BV, SD, c, m);
     cout << "Создание дома" << endl;
     cout << "Введите колличесто этажей:"; cin >> f;
     cout << "Введите колличество комнат:"; cin >> r;
     cout << "Укажите цвет:"; cin >> c;
     cout << "Укажите материал:"; cin >> m;
     cout << "--------------------------" << endl;
     House Ho(f, r, c, m);
     ptr[0] = &Ph;
     ptr[1] = &Au; // инициализация массива указателей ptr
     ptr[2] = &Ho;
      for (int i = 0; i < 3; i++)
      {
             ptr[i]->print();
             cout << "--------------------------" << endl;
      }
    return 0;
}