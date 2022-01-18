#include <iostream>
using namespace std;

class Ya {
private:
    char Name[20];
    int Age;
    int Height;
    int Weight;
public:
    void Set() {
        cout << "Введите Имя: "; cin >> Name;
        cout << "Введите ваш возраст: "; cin >> Age;
        cout << "Введите рост: "; cin >> Height;
        cout << "Введите вес: "; cin >> Weight;
    }
    void Print() {
        cout << Name << endl;
        cout << Age << " лет" << endl;
        cout << Height << " см" << endl;
        cout << Weight << " кг" << endl;
    }

};

int main()
{
    setlocale(LC_ALL, "ru");
    Ya I;
    I.Set();
    system("pause");
    system("cls");
    I.Print();

    
}

