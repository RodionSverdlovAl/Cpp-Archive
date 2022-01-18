#include "generalformulas.h"

double generalformulas::radius_circle_circumscribed_about_regular_triangle(double a)
{
    if (Check_param(a) == true)
        return (a * sqrt(3)) / 3;
    else
        return -1.0;
}

double generalformulas::radius_circle_inscribed_in_right_triangle(double a, double b, double c)
{
    if (Check_param(a,b,c) == true)
        return (a+b-c)/2;
    else
        return -1.0;
}

double generalformulas::radius_circle_circumscribed_about_right_triangle(double c)
{
    if (Check_param(c) == true)
        return c / 2;
    else
        return -1.0;
}

double generalformulas::Circumference(double R)
{
    if (Check_param(R) == true)
        return 2*Pi*R;
    else
        return -1.0;
}

double generalformulas::Circular_arc_length(double R, double angle)
{
    if (Check_param(R,angle) == true)
        return (Pi*R*angle)/180;
    else
        return -1.0;
}

double generalformulas::Main_diagonal_of_a_cube(double a)
{
    if (Check_param(a) == true)
        return a*sqrt(3);
    else
        return -1.0;
}
