#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct timeStop { // ��������� �������
	int hour; // ���
	int minute; // ������
};

struct busStop { // ��������� ��������� �� ��������
	vector<timeStop> Time; // ������ ���� ���������
	string stop; // �������� ���������
};

class Bus
{
private:
	int bus_number; // ����� ��������
	string routeName; // �������� ��������
	string type; // ��� ����������
	int size; // ����������� ���������
	vector<busStop> BusArray; // ���������

public:
	void add_route(); // �������� �������
	void view_route(); // �������� ���������
	void search(); // ����� ��������
	void sort(); // ���������� ���������
	void edit(); // �������������� ��������
	int bild_route(); // ��������� �������
	void delete_route(); // ������� �������

protected:
	string RouteInformation = "RouteInformation.txt"; // ���� ���� ������������ ����������
};