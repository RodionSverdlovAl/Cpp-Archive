// Класс-родитель «Детсад» с переменными «Название» и «Адрес» и класс-наследник «Группа» с переменными «Номер группы», «возраст детей», «количество детей»
#include <conio.h>
#include <iostream>

using namespace std;

class Detsad {
private:
	char Nazvanie[40];
	char Adrress[70];
public:
	void get_D() {
		cout << "Введите название: "; cin >> Nazvanie;
		cout << "Введите адрес: "; cin >> Adrress;
	}
	void post_D(){
		cout << Nazvanie << " - " << Adrress << endl;
	}
}d1;

class Gruppa : public Detsad 
{
private:
	int NumberGroup;
	int Age;
	int Count;
public:
	void get_G() {
		cout << "Введите номер группы: "; cin >> NumberGroup;
		cout << "Введите возраст: "; cin >> Age;
		cout << "Введите колличество детей: "; cin >> Count;
	}
	void post_G(){
		cout << "№" << NumberGroup << "   " << "Возраст: " << Age << " Кол-во: " << Count << endl;
	}
}g1;

int main() {
	setlocale(LC_ALL, "ru");
	d1.get_D();
	d1.post_D();
	cout << " _________________ " << endl;
	g1.get_D();
	g1.get_G();
	g1.post_D();
	g1.post_G();

	system("pause");
}
