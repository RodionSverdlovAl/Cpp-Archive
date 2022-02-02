//  ----- Лабораторная работа 6 ------

// Вычислить общий средний балл всех студентов и распечатать список
// студентов интересующей вас группы, имеющих средний балл выше общего
// среднего балла.

#include <iostream>
#include <vector>
using namespace std;

struct Student
{
    char FIO[50];
    int year;
    int group;
    int Physycs;
    int Math;
    int Prog;
    int Chemical;
    int MediumMark;
};

int main()
{
    vector<Student> students;
    setlocale(LC_ALL, "ru");
    while (true)
    {
        system("cls");
        cout << "[1] Добавить студента" << endl;
        cout << "[2] Посмотреть всех студентов" << endl;
        cout << "[3] Посмотреть студентов определенной группы чей средний балл выше общего среднего балла" << endl;
        int menu;
        cin >> menu;

        switch (menu)
        {
        case 1: {
            system("cls");
            Student student{};
            cout << "Введите ФИО: "; cin >> student.FIO;

            bool Ty = true;
            while (Ty)
            {
                cout << "Введите год рождения: "; cin >> student.year;
                if (student.year >= 1955 && student.year <= 2005) {
                    Ty = false;
                }
            }
            cout << "Введите группу: "; cin >> student.group;
            bool Tp = true;
            while (Tp)
            {
                cout << "Оценка по физике: "; cin >> student.Physycs;
                if (student.Physycs >= 1 && student.Physycs <= 10) {
                    Tp = false;
                }
            }
            bool Tm = true;
            while (Tm)
            {
                cout << "Оценка по математике: "; cin >> student.Math;
                if (student.Math >= 1 && student.Math <= 10) {
                    Tm = false;
                }
            }
            bool Tpr = true;
            while (Tpr)
            {
                cout << "Оценка по програмированию: "; cin >> student.Prog;
                if (student.Prog >= 1 && student.Prog <= 10) {
                    Tpr = false;
                }
            }
            bool Tc = true;
            while (Tc)
            {
                cout << "Оценка по химии: "; cin >> student.Chemical;
                if (student.Chemical >= 1 && student.Chemical <= 10) {
                    Tc = false;
                }
            }

            students.push_back(student);
            system("pause");
        }break;
        case 2: {
            system("cls");
            for (int i = 0; i < students.size(); i++) {
                cout << "ФИО: " << students[i].FIO << endl;
                cout << "год: " << students[i].year << endl;
                cout << "группа: " << students[i].group << std::endl;
                cout << "Физ: " << students[i].Physycs << " Мат: " << students[i].Math << " Инф: " << students[i].Prog << " Хим: " << students[i].Chemical << endl;
                cout << "Средний балл: " << float(students[i].Physycs + students[i].Math + students[i].Prog + students[i].Chemical) / 4 << endl;
                cout << "********************" << endl;
            }
            system("pause");
        }break;
        case 3: {
            system("cls");
            float overall_average_score = 0.0;
            float score = 0.0;
            for (int i = 0; i < students.size(); i++) {
                 score += float(float(students[i].Physycs + students[i].Math + students[i].Prog + students[i].Chemical) / 4);
            }
            overall_average_score = score / float(students.size());
            cout << "Общий средний балл: "<<overall_average_score << endl;
            cout << "Введите номер интересующей вас группы: "; int gr; cin >> gr;
            for (int i = 0; i < students.size(); i++) {
                score = float((students[i].Physycs + students[i].Math + students[i].Prog + students[i].Chemical) / 4);
                if (score > overall_average_score && gr == students[i].group) {
                    cout << "ФИО: " << students[i].FIO << endl;
                    cout << "год: " << students[i].year << endl;
                    cout << "группа: " << students[i].group << std::endl;
                    cout << "Физ: " << students[i].Physycs << " Мат: " << students[i].Math << " Инф: " << students[i].Prog << " Хим: " << students[i].Chemical << endl;
                    cout << "Средний балл: " << float(students[i].Physycs + students[i].Math + students[i].Prog + students[i].Chemical) / 4 << endl;
                    cout << "********************" << endl;
                }
            }
            system("pause");
        }break;
        default:
            cout << "Error enter 1 -3" << endl;
            break;
        }
    }
}