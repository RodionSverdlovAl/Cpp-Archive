// LABA_8_DENG.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct LearningGroup {
    int number;
    char Name[20];
    char Surname[20];
    char FatherName[20];
    char addres[70];
    char PhoneNumber[15];
};

void SetDATA(LearningGroup* M, int N) {
    
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        system("cls");
        cout << "Номер по списку:"; cin >> M[i].number;
        cin.ignore();
        cout << "Имя: "; cin.getline(M[i].Name, 20);
        cout << "Фамилия: "; cin.getline(M[i].Surname, 20);
        cout << "Отчество: "; cin.getline(M[i].FatherName, 20);
        cout << "Адрес: "; cin.getline(M[i].addres, 70);
        cout << "Телефон: "; cin.getline(M[i].PhoneNumber, 15);
    }
}

void ShowDATA(LearningGroup* M, int N)
{
    system("cls");
    for (int i = 0; i < N; i++)
    {
        cout << "[" << i+1 << "]" << "---------------" << endl;
        cout << "Номер по списку: " << M[i].number << endl;
        cout << "Имя: " << M[i].Name << endl;
        cout << "Фамилия: " << M[i].Surname << endl;
        cout << "Отчество: " << M[i].FatherName << endl;
        cout << "Адрес: " << M[i].addres << endl;
        cout << "Телефон: " << M[i].PhoneNumber << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int N; cout << "Введите колличество позиций: "; cin >> N;
    LearningGroup* M = new LearningGroup[N];
    SetDATA(M, N);
    ShowDATA(M, N);
}
