// ЛАБА 2 ООП.cpp
/*
    Создать класс "Время" с полями часы(0-23) минуты(0-59) секунды(0-59). 
    В классе реализовать функции конструктора, диструктора, установки времени, получения часа,
    минуты и секунды, а также две функции члены-печати: печать по шаблону << 16 часов 18 минут 3 секунды >>
    и << 16:18:3 pm >>. Функции члены установки полей класса должны проверять корректность задаваемых параметров.
*/

#include <iostream>
#include <ctime>
using namespace std;

class Time
{
public:
    Time(int = 0, int=0, int=0);
    void setTime(int, int, int);
    void printTime();
    void printTime2();
    int Get_hour(); // функция получения часа
	~Time();

private:
    int hour;      // 0-23
    int minute;    // 0-59
    int second;    // 0-59

};

// конструктор Time инициализирует члены класса нулевыми значениями
Time::Time(int hr, int min, int sec)
{
    setTime(hr, min, sec);
}

void Time::setTime(int h, int m, int s)
{
    if (h >= 0 && h < 24)
        hour = h;
    else
        hour = 0;
    if (m >= 0 && m < 60)
        minute = m;
    else
        minute = 0;
    if (s >= 0 && s < 60)
        second = s;
    else
        second = 0;
}

//  печать по шаблону << 16 часов 18 минут 3 секунды >>
void Time::printTime()
{
    if (hour == 1)
        cout << hour << " час ";
    if (hour == 2 && hour == 3 && hour == 4)
        cout << hour << " часа ";
    if (hour == 22 && hour == 23)
        cout << hour << " часа ";
    else
        cout << hour << " часов ";

    switch (minute)
    {
    case 1:
        cout << minute << " минута "; break;
    case 2:
        cout << minute << " минуты "; break;
    case 3:
        cout << minute << " минуты "; break;
    case 4:
        cout << minute << " минуты "; break;
    case 21:
        cout << minute << " минута "; break;
    case 22:
        cout << minute << " минуты "; break;
    case 23:
        cout << minute << " минуты "; break;
    case 24:
        cout << minute << " минуты "; break;
    case 32:
        cout << minute << " минуты "; break;
    case 33:
        cout << minute << " минуты "; break;
    case 34:
        cout << minute << " минуты "; break;
    case 42:
        cout << minute << " минуты "; break;
    case 43:
        cout << minute << " минуты "; break;
    case 44:
        cout << minute << " минуты "; break;
    case 52:
        cout << minute << " минуты "; break;
    case 53:
        cout << minute << " минуты "; break;
    case 54:
        cout << minute << " минуты "; break;
    case 31:
        cout << minute << " минута "; break;
    case 41:
        cout << minute << " минута "; break;
    case 51:
        cout << minute << " минута "; break;

    default:
        cout << minute << " минут ";
        break;
    }


    switch (second)
    {
    case 1:
        cout << second << " секунда "; break;
    case 2:
        cout << second << " секунды "; break;
    case 3:
        cout << second << " секунды "; break;
    case 4:
        cout << second << " секунды "; break;
    case 21:
        cout << minute << " минута "; break;
    case 22:
        cout << second << " секунды "; break;
    case 23:
        cout << second << " секунды "; break;
    case 24:
        cout << second << " секунды "; break;
    case 32:
        cout << second << " секунды "; break;
    case 33:
        cout << second << " секунды "; break;
    case 34:
        cout << second << " секунды "; break;
    case 42:
        cout << second << " секунды "; break;
    case 43:
        cout << second << " секунды "; break;
    case 44:
        cout << second << " секунды "; break;
    case 52:
        cout << second << " секунды "; break;
    case 53:
        cout << second << " секунды "; break;
    case 54:
        cout << second << " секунды "; break;
    case 31:
        cout << second << " секунда "; break;
    case 41:
        cout << second << " секунда "; break;
    case 51:
        cout << second << " секунда "; break;
    default:
        cout << second << " секунд "; break;
        break;
    }
    cout << endl;

}

// << 16:18 : 3 pm >>
void Time::printTime2()
{
    cout << minute << ":" << second<<":";
    if (hour >= 0 && hour < 12)
        cout << hour << " am";
    else {
        switch (hour)
        {
        case 12:
            hour = 0;  cout << hour << " pm"; break;
        case 13:
            hour = 1;  cout << hour << " pm"; break;
        case 14:
            hour = 2;  cout << hour << " pm"; break;
        case 15:
            hour = 3;  cout << hour << " pm";  break;
        case 16:
            hour = 4;  cout << hour << " pm"; break;
        case 17:
            hour = 5;  cout << hour << " pm"; break;
        case 18:
            hour = 6;  cout << hour << " pm"; break;
        case 19:
            hour = 7;  cout << hour << " pm"; break;
        case 20:
            hour = 8;  cout << hour << " pm"; break;
        case 21:
            hour = 9;  cout << hour << " pm"; break;
        case 22:
            hour = 10;  cout << hour << " pm"; break;
        case 23:
            hour = 11;  cout << hour << " pm"; break;
        default:
            cout << hour << " am"; break;
            break;
        }
    }
}

int Time::Get_hour()
{
    return hour;
}



Time::~Time()
{
    cout << endl;
    cout << "Класс закончил работать. Память очищена" << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Time vremya;
    int h, m, c;
    
    bool exit = true;
    while (exit)
    {
        int menu;
        cout << "--------Меню-------" << endl;
        cout << "Выберите нужный вам пункт меню" << endl;
        cout << "1-Установка времени" << endl;
        cout << "2-Получение часа" << endl;
        cout << "3-Печать времени в русском формате" << endl;
        cout << "4-Печать времени в американском формате" << endl;
        cout << "5-Выход из программы" << endl;
        cin >> menu;
        switch (menu)
        {
            case 1: {
                cout << "Hour:"; cin >> h;
                cout << "Minute:"; cin >> m;
                cout << "Second:"; cin >> c;
                vremya.setTime(h, m, c);
                cout << "Время установлено!" << endl;
                system("pause");
                system("cls");
            }; break;

            case 2: {
                system("cls");
                int result = vremya.Get_hour();
                cout << "Час = " << result << endl;
                system("pause");
                system("cls");

            }; break;
            
            case 3: {
                system("cls");
                vremya.printTime();
                system("pause");
                system("cls");
            }; break;

            case 4: {
                system("cls");
                vremya.printTime2();
                cout << endl;
                system("pause");
                system("cls");
            }; break;

            case 5: {
                exit = false;
            }; break;

            default:
                cout << "Такого пункта меню нет!" << endl;
            break;
        }
    }
}