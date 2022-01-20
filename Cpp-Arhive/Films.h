#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Films
{
private:
	string FilmName;// �������� ������ (��� ���������)
	string Year;// ��� ������� � ������ (��� ���������)
	int Timing;// ����������� (��� ���������)
	string Genre;// ���� (��� ���������)
	string SeanseData;// ��� �������� (���� ������)
	string SeanseTime;// ����� ������� (����� ������)
	int Cost;// ���-�� ����� (���� ������)

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