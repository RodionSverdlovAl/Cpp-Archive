#pragma once
class check_error
{
private:
	double a, b, c; // стороны треугольника
public:

	bool check_existence_triangle(double side1, double side2, double side3); // проверка треугольника на существование

	bool check_radius_circle(double side1, double side2, double side3, double radius); // проверка реальности радиуса описанной окружности
	
	double Herone_formula(double side1, double side2, double side3); // формула герона

	bool Check_param(double p1);

	bool Check_param(double p1, double p2);

	bool Check_param(double p1, double p2, double p3);

	bool Check_param(double p1, double p2, double p3, double p4);

};

