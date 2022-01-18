#pragma once
#include <cmath>
#include "check_error.h"
class generalformulas : public check_error
{
private:
	const double RADIAN = 0.0174533; // ���������� �������
	const double Pi = 3.141592653; // ��������� ��;
public:
	double radius_circle_circumscribed_about_regular_triangle(double a); // ������ ����������, ��������� ����� ����������� ������������

	double radius_circle_inscribed_in_right_triangle(double a, double b, double c); // ������ ����������, ��������� � ������������� �����������

	double radius_circle_circumscribed_about_right_triangle(double c);// ������ ����������, ��������� ����� �������������� ������������

	double Circumference(double R); // ����� ����������

	double Circular_arc_length(double R, double angle); // ����� ���� ����������

	double Main_diagonal_of_a_cube(double a); // ������� ��������� ����
};

