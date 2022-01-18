#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
typedef double (*uf)(double, double, int&);

void tabl(double, double, double, double, uf);
double y(double, double, int&);
double s(double, double, int&);

int main()
{
    cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl;
    tabl(0.1, 0.8, 0.1, 0.00001, y);
    cout << endl;
    cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
    tabl(0.1, 0.8, 0.1, 0.00001, s);
    return 0;
}

void tabl(double a, double b, double h, double eps, uf fun)
{
    int k = 0;
    double sum;
    for (double x = a; x < b + h / 2; x += h)
    {
        sum = fun(x, eps, k);
        cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;
    }
}

double y(double x, double eps, int& k)
{
    //return sin(x);
    return ((3*x*x)-(6*3.14*x)+(2*3.14*3.14))/12;
}


// здесь хз что делать нужно я в рядах не разбираюсь
double s(double x, double eps, int& k)
{
    double a, c, sum;
    sum = a = c = x;
    k = 1;
    while (fabs(c) > eps)
    {
        c = pow(x, 2) / (2 * k * (2 * k + 1));
        a *= -c;
        sum += a;
        k++;
    }
    return sum;
}