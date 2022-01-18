#pragma once
#include <cmath>
#include "check_error.h"
class generalformulas : public check_error
{
private:
	const double RADIAN = 0.0174533; // констранта радиана
	const double Pi = 3.141592653; // константа ПИ;
public:
	double radius_circle_circumscribed_about_regular_triangle(double a); // Радиус окружности, описанной около правильного треугольника

	double radius_circle_inscribed_in_right_triangle(double a, double b, double c); // Радиус окружности, вписанной в прямоугольный треугольник

	double radius_circle_circumscribed_about_right_triangle(double c);// Радиус окружности, описанной около прямоугольного треугольника

	double Circumference(double R); // Длина окружности

	double Circular_arc_length(double R, double angle); // Длина дуги окружности

	double Main_diagonal_of_a_cube(double a); // Главная диагональ куба
};

