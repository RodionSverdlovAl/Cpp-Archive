// Составить программу из задания 3 (второй уровень сложности), в
// которой для каждого x, изменяющегося от a до b с шагом h, вычисление
// значений Y(x) и S(x) оформить в виде функций пользователя.
// В основной функции реализовать следующие действия :
// -ввод исходных значений a, b, h и n;
// -обращение к функциям расчета Y(x) и S(x);
// -вывод результатов в виде таблицы.
// Если в задании используется значение факториала, его расчет также
// оформить функцией.

#include <iostream>
using namespace std;

double Y(double x) {
    return ((1 + (x * x)) / 2) * atan(x) - (x / 2);
}
double X(double x, double n) {

    double S = 0;

    for (int k = 1; k <= n; k++)
    {
        double ak;
        double A = pow(x, (2 * k) + 1);
        double B = (4 * k * k) - 1;

        ak = (A / B) * pow(-1, (k + 1));
        S += ak;
    }
    return S;
}

int main()
{
    int n;
    double a, b, h;

    cout << "Enter a,b,h,n:\n";

    cout << "a=", cin >> a;
    cout << "b=", cin >> b;
    cout << "h=", cin >> h;
    cout << "n=", cin >> n;

    cout << " x     Y(x)       S(x)       |Y(x)-S(x)|\n";
    for (double x = a; x <= b + h / 2.; x += h)
    {
        cout << x << "   " << Y(x) << "   " << X(x,n) << "   " << fabs(Y(x) - X(x,n)) << "\n";
    }
}