#include "interface.cpp"

int main()
{
	setlocale(LC_ALL, "rus");
	Interface<int> interface;

	interface.menu();

	system("pause");
}