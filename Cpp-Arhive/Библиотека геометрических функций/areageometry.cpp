#include "areageometry.h"
#include <cmath>;

areageometry::areageometry()
{
	this->a = 0.0;
	this->b = 0.0;
	this->c = 0.0;
	this->angle = 0.0;
	this->h = 0.0;
	this->l = 0.0;
	this->r = 0.0;
}

double areageometry::Area_of_​​a_triangle_across_two_sidesand_angle_between_them(double side_of_a_triangle_1, double side_of_a_triangle_2, double angle)
{
	a = side_of_a_triangle_1;
	b = side_of_a_triangle_2;
	this->angle = angle;
	return 0.5 * a * b * sin(angle * RADIAN);
}

double areageometry::The_area_of_​​the_triangle_through_the_baseand_the_height(double height, double base_of_triangle)
{
	a = base_of_triangle;
	h = height;
	return 0.5 * a * h;
}

double areageometry::Area_of_​​a_triangle_in_terms_of_radius_circumscribed_circle(double side_of_a_triangle_1, double side_of_a_triangle_2, double side_of_a_triangle_3, double radius)
{
	a = side_of_a_triangle_1;
	b = side_of_a_triangle_2;
	c = side_of_a_triangle_3;
	r = radius;
	
	if(check_existence_triangle(a,b,c) == true && check_radius_circle(a,b,c,r) == true) // проверка на существование этого треугольника или описанной окружности
		return (a * b * c) / (4 * r);
	else {
		return -1.0;
	}
}

double areageometry::Area_of_​​a_triangle_Herons_formula(double side_of_a_triangle_1, double side_of_a_triangle_2, double side_of_a_triangle_3)
{
	a = side_of_a_triangle_1;
	b = side_of_a_triangle_2;
	c = side_of_a_triangle_3;
	double p = (a + b + c) / 2;
	if(check_existence_triangle(a, b, c)== true)
		return sqrt(p*(p - a)*(p - b)*(p - c));
	else {
		return -1.0;
	}
}

double areageometry::Trapezium_area(double height, double side1, double side2)
{
	this->h = height;
	this->a = side1;
	this->b = side2;
	return ((a + b) / 2) * h;
}

double areageometry::The_area_of_​​the_parallelogram_across_the_sideand_height(double b, double h)
{
	this->b = b;
	this->h = h;

	return this->b*this->h;
}

double areageometry::Parallelogram_area_across_two_sides_and_the_angle_between_them(double a, double b, double angle)
{
	this->a = a;
	this->b = b;
	this->angle = angle;
	return this->a * this->b * sin(angle * RADIAN);
}

double areageometry::Area_circle(double R)
{
	return Pi * R * R;
}

double areageometry::Circular_sector_area(double R, double angle)
{
	return (Pi * R * R * angle) / 360;
}

double areageometry::The_lateral_surface_area_of_the_cone(double R, double h)
{
	return Pi * R * (sqrt((h * h) + (R * R)));
}

double areageometry::Cylinder_lateral_surface_area(double R, double h)
{
	return 2 * Pi * R * h;
}

double areageometry::Sphere_area(double R)
{
	return 4 * Pi * R * R;
}