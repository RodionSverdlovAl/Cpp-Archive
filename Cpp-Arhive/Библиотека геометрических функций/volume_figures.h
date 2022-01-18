#pragma once

#include "check_error.h"
class volume_figures : public check_error
{
private:
	const double RADIAN = 0.0174533; // ���������� �������
	const double Pi = 3.141592653; // ��������� ��;
public:

	double Prism_volume(double S, double h); // ����� ������

	double Cylinder_volume(double R, double h); // ����� ��������

	double Pyramid_volume(double S, double h); //����� ��������

	double Cone_volume(double R, double h); // ����� ������

	double Ball_volume(double R); // ����� ����
};

