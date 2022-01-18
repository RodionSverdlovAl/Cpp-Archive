#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Films
{
private:
	string FilmName; // �������� ������
	string Year; // ��� ������� � ������
	int Timing; // �����������
	string Genre; // ����
	string DerectorName; // ��� ��������
	string Actors; // ����� �������
	int Eposodes; // ���-�� �����
	
public:
	//string Information = "information.txt";
	void Films_to_file(string n,string y,int t, string g, string dn, string a, int e); // ������ ���������� � ������ � ���� (������� ���� (������ �����������))
	void search_film();
	void DeleteOneFilm(); // ������� �������� ������ � �� ���� ������� 
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

