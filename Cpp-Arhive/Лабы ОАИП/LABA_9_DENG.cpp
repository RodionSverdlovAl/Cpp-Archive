#include <iostream>
using namespace std;

//X2+Y-2, X=2, Y=1
class Uravnenie
{
private:
	int x;
	int y;

public:
	int solution(int x, int y);
	int solution();
	void setXY();
};

int Uravnenie::solution(int x, int y) // Для ввода програмно не с клавиатуры
{
	return (x*x)+(y-2);
}

int Uravnenie::solution() // для ввода через функцию SetXY
{
	return (x * x) + (y - 2);
}

void Uravnenie::setXY()
{
	cout << "Введите X: "; cin >> x;
	cout << "Введите Y: "; cin >> y;
}


int main() {
	setlocale(LC_ALL, "ru");
	Uravnenie urv;
	//urv.setXY();
	cout<<urv.solution(2, 1);

}