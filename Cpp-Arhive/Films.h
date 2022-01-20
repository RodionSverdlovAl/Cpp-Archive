#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Films
{
private:
	string FilmName;// название фильма (без изменений)
	string Year;// год выпуска в прокат (без изменений)
	int Timing;// хронометраж (без изменений)
	string Genre;// Жанр (без изменений)
	string SeanseData;// Имя режисера (дата сеанса)
	string SeanseTime;// имена актеров (время сеанса)
	int Cost;// кол-во серий (цена билета)

public:
	void Films_to_file(string n, string y, int t, string g, string dn, string a, int e);
	void search_film();
	void DeleteOneFilm(); 
	void view_inf_about_films();
	void changeFilm();
	void sortSeanse();
protected:
	string Information = "information.txt";
};