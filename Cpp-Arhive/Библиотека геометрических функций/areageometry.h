#pragma once
#include <cmath>
#include "check_error.h"

using namespace std;

class areageometry : public check_error
{
private:
	// стороны треугольника
	double a; 
	double b;
	double c;

	double angle; // угол
	double h; // высота треугольника/трапеции
	double l;
	double r; // радиус треугольника
	const double RADIAN = 0.0174533; // констранта радиана
	const double Pi = 3.141592653; // константа ПИ;


public:

	areageometry(); // конструктор

	double Area_of_​​a_triangle_across_two_sidesand_angle_between_them(double side_of_a_triangle_1, double side_of_a_triangle_2, double angle); // Площадь треугольника через две стороны и угол между ними

	double The_area_of_​​the_triangle_through_the_baseand_the_height(double height, double base_of_triangle); // Площадь треугольника через основание и высоту

	double Area_of_​​a_triangle_in_terms_of_radius_circumscribed_circle(double side_of_a_triangle_1, double side_of_a_triangle_2, double side_of_a_triangle_3, double radius ); // Площадь треугольника через радиус описанной окружности

	double Area_of_​​a_triangle_Herons_formula(double side_of_a_triangle_1, double side_of_a_triangle_2, double side_of_a_triangle_3); // Площадь треугольника (формула Герона)

	double Trapezium_area(double height, double side1, double side2); // площадь трапеции

	double The_area_of_​​the_parallelogram_across_the_sideand_height(double b, double h);  // Площадь параллелограмма через сторону и высоту

	double Parallelogram_area_across_two_sides_and_the_angle_between_them(double a, double b, double angle); // Площадь параллелограмма через две стороны и угол между ними

	double Area_circle(double R); // площадь круга

	double Circular_sector_area(double R, double angle); // площадь кругового сектора

	double The_lateral_surface_area_of_the_cone(double R, double h); // Площадь боковой поверхности конуса
	
	double Cylinder_lateral_surface_area(double R, double h); // Площадь боковой поверхности цилиндра

	double Sphere_area(double R); // площадь сферы
};

