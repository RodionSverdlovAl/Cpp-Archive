#include "volume_figures.h"
#include <cmath>

double volume_figures::Prism_volume(double S, double h)
{
	if (Check_param(S, h) == true)
		return S * h;
	else return -1.0;
}

double volume_figures::Cylinder_volume(double R, double h)
{
	if (Check_param(R, h) == true)
	return Pi*R*R*h;
	else return -1.0;
}

double volume_figures::Pyramid_volume(double S, double h)
{
	if (Check_param(S, h) == true)
	return (S*h)/3;
	else return -1.0;
}

double volume_figures::Cone_volume(double R, double h)
{
	if (Check_param(R, h) == true)
	return (Pi*R*R*h)/3;
	else return -1.0;
}

double volume_figures::Ball_volume(double R)
{
	if (Check_param(R) == true)
	return (3*(Pi*R*R*R))/4;
	else return -1.0;
}
