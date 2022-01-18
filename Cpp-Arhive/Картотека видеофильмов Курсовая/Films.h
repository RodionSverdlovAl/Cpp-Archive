#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Films
{
private:
	string FilmName; // название фильма
	string Year; // год выпуска в прокат
	int Timing; // хронометраж
	string Genre; // Жанр
	string DerectorName; // Имя режисера
	string Actors; // имена актеров
	int Eposodes; // кол-во серий
	
public:
	//string Information = "information.txt";
	void Films_to_file(string n,string y,int t, string g, string dn, string a, int e); // Запись информации о фильме в файл (большой сетр (бывший конструктор))
	void search_film();
	void DeleteOneFilm(); // функция удаления одного а не всех фильмов 
	void view_inf_about_films();
	void changeFilm();
	string GetFilmName();
	string GetYear();
	int GetTiming();
	string GetGenre();
	string GetDerectorName();
	string GetActors();
	int GetEposodes();
protected:
	string Information = "information.txt";
};

