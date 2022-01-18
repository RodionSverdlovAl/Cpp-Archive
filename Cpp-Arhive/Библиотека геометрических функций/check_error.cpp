#include "check_error.h"
#include <cmath>


bool check_error::check_existence_triangle(double side1, double side2, double side3) 
{
    this->a = side1; this->b = side2; this->c = side3;

    if (a + b > c && a + c > b && b + c > a) {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_error::check_radius_circle(double side1, double side2, double side3, double radius)
{
    this->a = side1; this->b = side2; this->c = side3;
    double R = radius;
    double R2;
    R2 = (a * b * c) / (4 * Herone_formula(a, b, c));
    if (R2 == R)
        return true;
    else
        return false;
}

double check_error::Herone_formula(double side1, double side2, double side3)
{
    this->a = side1; this->b = side2; this->c = side3;
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool check_error::Check_param(double p1)
{
    if (p1 < 0)
        return false;
    else return true;
}

bool check_error::Check_param(double p1, double p2)
{
    if (p1 < 0 || p2 < 0)
        return false;
    else return true;
}

bool check_error::Check_param(double p1, double p2, double p3)
{
    if (p1 < 0 || p2 < 0 || p3 < 0)
        return false;
    else return true;
}

bool check_error::Check_param(double p1, double p2, double p3, double p4)
{
    if (p1 < 0 || p2 < 0 || p3 < 0 || p4 < 0)
        return false;
    else return true;
}
