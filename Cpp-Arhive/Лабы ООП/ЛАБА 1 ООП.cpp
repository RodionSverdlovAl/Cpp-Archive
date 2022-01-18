// Вариант 6
// Написать программу решения линейного уравнения. Установить ширину поля в 10 символов.
// точность в 4 цифры, заполнить пробеллы символом %.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Выберите какое линейное уравнение вы хотите решить:" << endl;
	cout << "1 уравнение имеет вид: 2x-4=y" << endl;
	cout << "2 уравнение имеет вид: 8x-2=y" << endl;
	cout << "3 уравнение имеет вид: 19x+4=y" << endl;
	cout << "4 уравнение имеет вид: 7x+66=y" << endl;
	cout << "5-другое уравнение";
	int v, reshenie;
	cin >> v;
	double y, x, k, b;
	switch (v)
	{
	case 1: {
		cout << "Введите y:" << endl;
		cin >> y;
		cout << "Уравнение имеет вид: 2x-4=" << y << endl;
		cout << "Введите 1 чтобы решить данное уравнение" << endl;
		cin >> reshenie;
		if (reshenie == 1) {
			x = (y + 4) / 2;
			cout << "x=" << setw(10) << setfill('%') << setprecision(4) << x << endl;
		}
	}; break;
	case 2: {
		cout << "Введите y:" << endl;
		cin >> y;
		cout << "Уравнение имеет вид: 8x-2=" << y << endl;
		cout << "Введите 1 чтобы решить данное уравнение" << endl;
		cin >> reshenie;
		if (reshenie == 1) {
			x = (y + 2) / 8;
			cout << "x=" << setw(10) << setfill('%') << setprecision(4) << x << endl;
		}
	}; break;
	case 3: {
		cout << "Введите y:" << endl;
		cin >> y;
		cout << "Уравнение имеет вид: 19x+4=" << y << endl;
		cout << "Введите 1 чтобы решить данное уравнение" << endl;
		cin >> reshenie;
		if (reshenie == 1)
		{
			x = (y - 4) / 19;
			cout << "x=" << setw(10) << setfill('%') << setprecision(4) << x << endl;
		}
	}; break;
	case 4: {
		cout << "Введите y:" << endl;
		cin >> y;
		cout << "Уравнение имеет вид: 7x+66=" << y << endl;
		cout << "Введите 1 чтобы решить данное уравнение" << endl;
		cin >> reshenie;
		if (reshenie == 1) {
			x = (y - 66) / 7;
			cout << "x=" << setw(10) << setfill('%') << setprecision(4) << x << endl;
		}
	}; break;
	case 5:
	{
		cout << "Уравнение имеет вид: kx+b=y" << endl;
		cout << "Введите y:" << endl;
		cin >> y;
		cout << "Введите k:" << endl;
		cin >> k;
		cout << "Введите b:" << endl;
		cin >> b;
		cout << "Уравнение имеет вид: " << k << "*" << "x" << "+" << b << "=" << y << endl;
		cout << "Введите 1 чтобы решить данное уравнение" << endl;
		cin >> reshenie;
		if (reshenie == 1)
		{
			x = (y - b) / k;
			cout << "x=" << setw(10)<<setfill('%')<< x << endl;
		}
	}; break;
	default:
		cout << "Такого уравнения не найдено" << endl;
		break;

	}
}