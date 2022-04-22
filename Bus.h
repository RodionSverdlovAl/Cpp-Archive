#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct timeStop { // структура времени
	int hour; // час
	int minute; // минута
};

struct busStop { // структура остановок на маршруте
	vector<timeStop> Time; // массив всех остановок
	string stop; // название остановки
};

class Bus
{
private:
	int bus_number; // номер маршрута
	string routeName; // название маршрута
	string type; // тип транспорта
	int size; // колличество остановок
	vector<busStop> BusArray; // остановки

public:
	void add_route(); // добавить маршрут
	void view_route(); // просмотр маршрутов
	void search(); // поиск маршрута
	void sort(); // сортировка маршрутов
	void edit(); // редактирование маршрута
	int bild_route(); // построить маршрут
	void delete_route(); // удалить маршрут

protected:
	string RouteInformation = "RouteInformation.txt"; // файл куда записывается информация
};