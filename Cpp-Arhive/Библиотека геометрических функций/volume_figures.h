#pragma once

#include "check_error.h"
class volume_figures : public check_error
{
private:
	const double RADIAN = 0.0174533; // констранта радиана
	const double Pi = 3.141592653; // константа ПИ;
public:

	double Prism_volume(double S, double h); // обьем призмы

	double Cylinder_volume(double R, double h); // объем цилиндра

	double Pyramid_volume(double S, double h); //Объем пирамиды

	double Cone_volume(double R, double h); // объем конуса

	double Ball_volume(double R); // Объем шара
};

