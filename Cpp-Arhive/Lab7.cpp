// Написать программу по обработке файла, состоящего из структур,
//содержащих информацию задания 6. Средний балл рассчитать программно
//по введенным оценкам.Массив структур не использовать.

//В программе реализовать следующие действия по обработке файла :
//– создание;
//– просмотр;
//– добавление нового элемента;
//– удаление(редактирование);
//– решение индивидуального задания(первый уровень сложности
//    задания 6).
    //Результаты выполнения индивидуального задания записать в
    //текстовый файл.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student
{
    string FIO;
    int year;
    int group;
    int Physycs;
    int Math;
    int Prog;
    int Chemical;
    float MediumMark;
};

int main()
{
    string path = "students.txt";
    string path2 = "student2.txt";
    setlocale(LC_ALL, "ru");
    while (true)
    {
        cout << "[1] add student" << endl; // создание;  добавление нового элемента;
        cout << "[2] print students" << endl; // просмотр;
        cout << "[3] print student with group and medium mark" << endl; //  решение индивидуального задания(первый уровень сложности)
        cout << "[4] delete student" << endl;
        int menu; cin >> menu;
        switch (menu)
        {
        case 1: {
            system("cls");
            Student student{};
            ofstream InfFile;
            InfFile.open(path, ofstream::app);
            cout << "Введите ФИО: "; cin >> student.FIO; InfFile << student.FIO << endl;

            bool Ty = true;
            while (Ty)
            {
                cout << "Введите год рождения(1955-2005): "; cin >> student.year;
                if (student.year >= 1955 && student.year <= 2005) {
                    InfFile << student.year << endl;
                    Ty = false;
                }
            }
            cout << "Введите группу: "; cin >> student.group; InfFile << student.group << endl;
           
            bool Tp = true;
            while (Tp)
            {
                cout << "Оценка по физике(1-10): "; cin >> student.Physycs;
                if (student.Physycs >= 1 && student.Physycs <= 10) {
                    Tp = false;
                    InfFile << student.Physycs << endl;
                }
            }
            bool Tm = true;
            while (Tm)
            {
                cout << "Оценка по математике(1-10): "; cin >> student.Math;
                if (student.Math >= 1 && student.Math <= 10) {
                    Tm = false;
                    InfFile << student.Math << endl;
                }
            }
            bool Tpr = true;
            while (Tpr)
            {
                cout << "Оценка по програмированию(1-10): "; cin >> student.Prog;
                if (student.Prog >= 1 && student.Prog <= 10) {
                    Tpr = false;
                    InfFile << student.Prog << endl;
                }
            }
            bool Tc = true;
            while (Tc)
            {
                cout << "Оценка по химии(1-10): "; cin >> student.Chemical;
                if (student.Chemical >= 1 && student.Chemical <= 10) {
                    Tc = false;
                    InfFile << student.Chemical << endl;
                }
            }
            student.MediumMark = float(student.Physycs + student.Math + student.Prog + student.Chemical) / 4;
            InfFile << student.MediumMark << endl;
            InfFile.close();
            system("pause");
            system("cls");
        }break;
        case 2: {
            Student student;
            ifstream InfFile1;
            InfFile1.open(path);
            while (InfFile1.peek() != EOF) {
                InfFile1 >> student.FIO; InfFile1.get();
                InfFile1 >> student.year; InfFile1.get();
                InfFile1 >> student.group; InfFile1.get();
                InfFile1 >> student.Physycs; InfFile1.get();
                InfFile1 >> student.Math; InfFile1.get();
                InfFile1 >> student.Prog; InfFile1.get();
                InfFile1 >> student.Chemical; InfFile1.get();
                InfFile1 >> student.MediumMark; InfFile1.get();

                cout << "ФИО: " << student.FIO << endl;
                cout << "год: " << student.year << endl;
                cout << "группа: " << student.group << std::endl;
                cout << "Физ: " << student.Physycs << " Мат: " << student.Math << " Инф: " << student.Prog << " Хим: " << student.Chemical << endl;
                cout << "Средний балл: " << student.MediumMark << endl;
                cout << "********************" << endl;
            }
            InfFile1.close();
            system("pause");
            system("cls");
        }break;
        case 3: {
            float overall_average_score = 0.0;
            Student student;
            ifstream InfFile1;
            InfFile1.open(path);
            int size = 0;
            while (InfFile1.peek() != EOF) {
                InfFile1 >> student.FIO; InfFile1.get();
                InfFile1 >> student.year; InfFile1.get();
                InfFile1 >> student.group; InfFile1.get();
                InfFile1 >> student.Physycs; InfFile1.get();
                InfFile1 >> student.Math; InfFile1.get();
                InfFile1 >> student.Prog; InfFile1.get();
                InfFile1 >> student.Chemical; InfFile1.get();
                InfFile1 >> student.MediumMark; InfFile1.get();
                size++;
                overall_average_score += student.MediumMark;
            }
            cout << "Общий средний балл: " << overall_average_score/size << endl;
            cout << "Введите номер интересующей вас группы: "; int gr; cin >> gr;
            InfFile1.close();
            InfFile1.open(path);
            while (InfFile1.peek() != EOF) {
                InfFile1 >> student.FIO; InfFile1.get();
                InfFile1 >> student.year; InfFile1.get();
                InfFile1 >> student.group; InfFile1.get();
                InfFile1 >> student.Physycs; InfFile1.get();
                InfFile1 >> student.Math; InfFile1.get();
                InfFile1 >> student.Prog; InfFile1.get();
                InfFile1 >> student.Chemical; InfFile1.get();
                InfFile1 >> student.MediumMark; InfFile1.get();
                if (student.MediumMark > overall_average_score / 4 && gr == student.group) {
                    cout << "ФИО: " << student.FIO << endl;
                    cout << "год: " << student.year << endl;
                    cout << "группа: " << student.group << std::endl;
                    cout << "Физ: " << student.Physycs << " Мат: " << student.Math << " Инф: " << student.Prog << " Хим: " << student.Chemical << endl;
                    cout << "Средний балл: " << student.MediumMark << endl;
                    cout << "********************" << endl;

                    ofstream InfFile2;
                    InfFile2.open(path2);
                    InfFile2 << "ФИО: " << student.FIO << endl;
                    InfFile2 << "Год: " << student.year << endl;
                    InfFile2 <<"Группа: " << student.group << endl;
                    InfFile2 <<"Физика: "<< student.Physycs << endl;
                    InfFile2 <<"Математика: "<< student.Math << endl;
                    InfFile2 <<"Программирование: "<< student.Prog << endl;
                    InfFile2 <<"Химия: "<< student.Chemical << endl;
                    InfFile2 <<"Средний балл: "<< student.MediumMark << endl;
                    InfFile2.close();
                }
            }
            InfFile1.close();
            system("pause");
            system("cls");
        }break;
        case 4: {
            Student student;
            ifstream InfFile;
            InfFile.open(path);
            while (InfFile.peek() != EOF) {
                InfFile >> student.FIO; InfFile.get();
                InfFile >> student.year; InfFile.get();
                InfFile >> student.group; InfFile.get();
                InfFile >> student.Physycs; InfFile.get();
                InfFile >> student.Math; InfFile.get();
                InfFile >> student.Prog; InfFile.get();
                InfFile >> student.Chemical; InfFile.get();
                InfFile >> student.MediumMark; InfFile.get();

                cout << "ФИО: " << student.FIO << endl;
            }
            InfFile.close();

            string fio;
            cout << "Введите имя студента которого хотите удалить: " << endl;
            cin >> fio;
            string buff_file = "buffer_file.txt";
           
            //[1] - создаем буфферный файл
             ofstream buffFile;
             buffFile.open(buff_file);
            //----------------------------

            // [2] - заполняем буфферный файл структурами которые не удалены
             ifstream InfFile1;
             InfFile1.open(path);
             while (InfFile1.peek() != EOF) {
                 InfFile1 >> student.FIO; InfFile1.get();
                 InfFile1 >> student.year; InfFile1.get();
                 InfFile1 >> student.group; InfFile1.get();
                 InfFile1 >> student.Physycs; InfFile1.get();
                 InfFile1 >> student.Math; InfFile1.get();
                 InfFile1 >> student.Prog; InfFile1.get();
                 InfFile1 >> student.Chemical; InfFile1.get();
                 InfFile1 >> student.MediumMark; InfFile1.get();

                 if (fio != student.FIO) {
                     buffFile << student.FIO << endl;
                     buffFile << student.year <<endl;
                     buffFile << student.group << endl;
                     buffFile << student.Physycs << endl;
                     buffFile << student.Math << endl;
                     buffFile << student.Prog << endl;
                     buffFile << student.Chemical << endl;
                     buffFile << student.MediumMark << endl;
                 }
             }
             InfFile1.close();
             buffFile.close();
             // [3] чистим основной файл
                 ofstream InfFile3;
                 InfFile3.open(path, ios::trunc);
                 InfFile3.close();
                
            // [4] заполняем основной файл информацией из буферного файла
                 
                 // 1 открыть буфферный файл для чтения
                 ifstream buff;
                 buff.open(buff_file);
                 // 2 открыть основной файл для записи
                 ofstream file;
                 file.open(path, ofstream::app);
                 // 3 считать из буфферного файла структуру и записать ее в основной и все это в цикле
                 while (buff.peek() != EOF) {
                     buff >> student.FIO; buff.get();
                     buff >> student.year; buff.get();
                     buff >> student.group; buff.get();
                     buff >> student.Physycs; buff.get();
                     buff >> student.Math; buff.get();
                     buff >> student.Prog; buff.get();
                     buff >> student.Chemical; buff.get();
                     buff >> student.MediumMark; buff.get();

                     file << student.FIO << endl;
                     file << student.year << endl;
                     file << student.group << endl;
                     file << student.Physycs << endl;
                     file << student.Math << endl;
                     file << student.Prog << endl;
                     file << student.Chemical << endl;
                     file << student.MediumMark << endl;
                 }
                 // закрыть оба файла
                 buff.close();
                 file.close();
                 // чистим буферный файл
                 ofstream Buff;
                 Buff.open(buff_file, ios::trunc);
                 Buff.close();
        }break;
        default:
            break;
        }
    }
}