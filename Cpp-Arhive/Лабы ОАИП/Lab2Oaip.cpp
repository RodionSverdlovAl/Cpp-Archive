#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	while (true)
	{
		cout << "[1] задание 1" <<endl;
		cout << "[2] задание 2" <<endl;
		cout << "[3] задание 3" <<endl;
		cout << "[4] задание 4" <<endl;
		cout << "[5] задание 5" <<endl;
		int chouse;
		cin >> chouse;
		switch (chouse)
		{
		case 1: {
			double z1, z2 = 0;
			double angle; // угол
			const double RADIAN = 0.0174533;
			cout << "[1] z1" << endl;
			cout << "[2] z2" << endl;
			int menu1;
			cin >> menu1;
			switch (menu1)
			{
			case 1: {
				cout << "Введите угол: "; cin >> angle;
				if (angle < 0) {
					cout << "введенный вами угол меньше 0" << endl;
					break;
				}
				z1 = 1 - ((sin(2 * angle * RADIAN) * sin(2 * angle * RADIAN)) * 1 / 4) + cos(2 * angle * RADIAN);
				cout << z1 << endl;
				
			}break;
			case 2: {
				cout << "Введите угол: "; cin >> angle;
				if (angle < 0) {
					cout << "введенный вами угол меньше 0" << endl;
					break;
				}
				z2 = (cos(angle * RADIAN) * cos(angle * RADIAN)) + (cos(angle * RADIAN) * cos(angle * RADIAN) * cos(angle * RADIAN) * cos(angle * RADIAN));
				cout << z2 << endl;
			}break;
			default:
				break;
			}
		}break;
		case 2: {
			double x, y, z, angle;
			x = -15.246;
			y = 4.642 * 0.01;
			z = 20001;
			//angle = -182.036;
			double ln = pow(y, (-1 * sqrt(fabs(x))));
			angle = log(ln) * (x - (y / 2)) + pow(sin(atan(z)), 2);
			cout << "a= " << angle<<endl;

		}break;
		case 3: {
			const double e = 2.71828;
			double z;
			double x;
			double y;
			cout << "Введите z: "; cin >> z;
			if (z < -1) {
				cout << "вычисляем по x = -z/3" << endl;
				x = -z / 3;
				y = log(x + 0.5) + (pow(e, x) - pow(e, -x));
				cout << "y = " << y << endl;
			}
			if (z >= -1) {
				cout << "вычисляем по x = |z|" << endl;
				x = fabs(z);
				y = log(x + 0.5) + (pow(e, x) - pow(e, -x));
				cout << "y = " << y << endl;
			}
		}break;
		case 4: {
			double x, y, z;
			cout << "Введите x: "; cin >> x;
			cout << "Введите y: "; cin >> y;
			cout << "Введите z: "; cin >> z;
			if (x == y || x == z || z == y) {
				cout << "одно или несколько значений совпадают, введите значения заного чтобы все значения были уникальны" << endl;
				break;
			}
			double min;
			if (x < y) {
				min = x;
			}
			if (x > y) {
				min = y;
			}
			double max;
			if (min < z) {
				max = z;
			}
			if (min > z) {
				max = min;
			}
			double r = max / 3;
			cout << "r = " << r << endl;
		}break;
		case 5: {
			double m, t;
			double t2;
			cout << "Введите m: "; cin >> m;
			cout << "Введите t: "; cin >> t;
			if ((pow(m, 2) + pow(t, 2)) > 0.5) {
				
				cout << "решение по первой  ветви" << endl;
				t2 = atan((5 * pow(m, 2) * t) + 7 * m * pow(t, 2));
				cout << "t2 = " << t2 << endl;
			}
			if (((pow(m, 2) + pow(t, 2)) > 0.1 && ((pow(m, 2) + pow(t, 2)) <= 0.5))) {
				cout << "решение по второй  ветви" << endl;
				t2 = (int)asin((5 * pow(m, 2) * t) + (7 * m * pow(t, 2)));
				//(t2 % 2 == 0) ?? t2 = (int)t2;
				cout << "t2 = " << t2 << endl;
			}
			if ((pow(m, 2) + pow(t, 2)) < 0.1) {
				cout << "выражение не подпадает под условие" << endl;
			}
		}break;
		default:
			cout << "Неверно выбран пункт меню " <<endl;
			break;
		}
	}
}