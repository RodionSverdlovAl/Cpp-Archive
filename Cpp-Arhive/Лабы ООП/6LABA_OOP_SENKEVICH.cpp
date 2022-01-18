#include <iostream>
#include <string>
using namespace std;

class Isp {
private:
    
public:
    string FIO;
    string Country;
    string klassMI;
    int god;
    int pos;
    int getGod() {
        return god;
    }
    int getPos() {
        return pos;
    }
    string getFIO() {
        return FIO;
    }
    string getCountry() {
        return Country;
    }
    string getKlass() {
        return klassMI;
    }
    void changeGod(int god) {
        this->god = god;
    }
    void changePos(int pos) {
        this->pos = pos;
    }
    void changeFIO(string FIO) {
        this->FIO = FIO;
    }
    void changeCountry(string Country) {
        this->Country = Country;
    }
    void changeKlass(string Klass) {
        this->klassMI = Klass;
    }
    string getStr(int mn1) {
        if (mn1 == 0) return FIO;
        else
            if (mn1 == 1) return Country;
            else return klassMI;
    }
    int getInt(int mn1) {
        if (mn1 == 3) return god;
        else return pos;
    }
    void show() {
        cout << "ФИО: " << FIO << endl;
        cout << "Страна: " << Country << endl;
        cout << "Класс: " << klassMI << endl;
        cout << "Год: " << god << endl;
        cout << "Позиция: " << pos << endl;
    }

    bool operator<(Isp a) {
        return FIO < a.FIO;
    }

    bool operator<=(Isp a) {
        return FIO <= a.FIO;
    }

    bool operator>(Isp a) {
        return FIO > a.FIO;
    }

    void swap(Isp* b) {
        Isp c = *b;
        b->changeCountry(Country);
        b->changeFIO(FIO);
        b->changeGod(god);
        b->changeKlass(klassMI);
        b->changePos(pos);
        Country = c.Country;
        FIO = c.FIO;
        god = c.god;
        klassMI = c.klassMI;
        pos = c.pos;
    }
};

template <class T>
class Vector {
private:
    T* a;
  
public:
    int n;

    Vector() {
        a = new T[0];
        n = 0;
    }

    void clear() {
        delete[] a;
    }

    void push(T A) {
        T* b = new T[n + 1];
        for (int i = 0; i < n; i++)
            b[i] = a[i];
        delete[]a;
        a = b;
        b = NULL;
        a[n] = A;
        n++;
    }

    void show() {
        for (int i = 0; i < n; i++) {
            a[i].show();
        }
        system("pause");
    }

    Isp* begin() {
        return a;
    }

    Isp* end() {
        return a + n;
    }

    int size() {
        return n;
    }

    T& operator[](const int index) {
        return a[index];
    }

    void qsort(int fst, int last)
    {
        int i, j, pivot;
        T tmp;
        if (fst < last)
        {
            pivot = fst;
            i = fst;
            j = last;
            while (i < j)
            {
                while (a[i] <= a[pivot] && i < last)
                    i++;
                while (a[j] > a[pivot])
                    j--;
                if (i < j)
                {
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }
            tmp = a[pivot];
            a[pivot] = a[j];
            a[j] = tmp;
            qsort(fst, j - 1);
            qsort(j + 1, last);
        }
    }

};

class iteratorVector {
private:
    Isp* curr;
public:

    iteratorVector() {}

    void operator++() {
        curr++;
    }

    void operator--() {
        curr--;
    }

    void operator=(Isp* a) {
        curr = a;
    }

    bool operator!=(Isp* a) {
        return a != curr;
    }

    bool operator<(Isp* a) {
        return curr < a;
    }

    Isp*& operator*() {
        return curr;
    }

};

bool CheckNum(string str) {	// проверка строки на ввод числа
    if (!str.empty()) {
        try {
            int num = stoi(str);
            return true;
        }
        catch (invalid_argument)
        {
            // если введено не число
            cout << "Only numbers are allowed! \n";
        }
        catch (out_of_range)
        {
            //Если число слишком большое
            cout << "Can't convert into int! \n";
        }
        catch (...)
        {
            //Если будет выброшено неизвестное исключение
            cout << "Unknown error! \n";
        }
    }
    return false;
}

class Algorithm {

public:
    Vector<Isp> myVectorAL; // инициализируем первую коллекцию
    Vector<Isp> myVector2AL; // инициализируем вторую коллекцию
    iteratorVector itAL; // объявляем итератор

    void case_9(Vector<Isp> myVector, Vector<Isp> myVector2, iteratorVector it) {
       
        // Если в обоих коллекциях есть одинаковые эллементы то из одной из коллекций удаляем этот дубликат

           // ищем дубликат

        int k = -1;
        int k2 = -1;
        for (int i = 0; i < myVector.size(); i++) {
            for (int j = 0; j < myVector2.size(); j++) {
                if (myVector[i].FIO == myVector2[j].FIO && myVector[i].Country == myVector2[j].Country && myVector[i].god == myVector2[j].god && myVector[i].klassMI == myVector2[j].klassMI && myVector[i].pos == myVector2[j].pos) {
                    k = j; // индекс дубликата во второй коллекции
                    k2 = i; // индекс дубликата в первой коллекции
                    cout << "Дубликаты найдены" << endl;
                }
            }
        }
        if (k == -1) {
            cout << "Дубликаты не найдены !" << endl;
        }
        if (k != -1) {
            cout << "Из какой коллекции вы хотите удалить дубликат? [1] или [2]" << endl;
            int chouse; cin >> chouse;
            switch (chouse)
            {
            case 1: { // удаление дубликата из первой коллекции
                Vector<Isp> NewVector9; // создаем буфферный вектор
                for (int i = 0; i < myVector.size(); i++) {// в буфферный массив записываем все эллементы кроме эллемента с индексом дубликата
                    if (i != k2) {
                        NewVector9.push(myVector[i]);
                    }
                }
                for (int i = 0; i < NewVector9.size(); i++) { // переписываем в наш вектор значения буфферного массива уже без дубликата
                    myVector[i] = NewVector9[i];
                }
                myVector.n = NewVector9.n; // уменьшаем размера вектора до размера буфферного вектора

                cout << "Дубликат Удален!" << endl;

            }break;
            case 2: {
                Vector<Isp> NewVector9; // создаем буфферный вектор
                for (int i = 0; i < myVector2.size(); i++) {// в буфферный массив записываем все эллементы кроме эллемента с индексом дубликата
                    if (i != k) {
                        NewVector9.push(myVector2[i]);
                    }
                }
                for (int i = 0; i < NewVector9.size(); i++) { // переписываем в наш вектор значения буфферного массива уже без дубликата
                    myVector2[i] = NewVector9[i];
                }
                myVector2.n = NewVector9.n; // уменьшаем размера вектора до размера буфферного вектора

                cout << "Дубликат Удален!" << endl;
            }
            default:
                break;
            }
        }
        this->myVectorAL = myVector;
        this->myVector2AL = myVector2;
   }
    void case_8(Vector<Isp> myVector, Vector<Isp> myVector2, iteratorVector it) {
        system("cls");
        cout << " 1-Delete dublicate in first colection" << endl;
        cout << " 2-Delete dublicate in second collection" << endl;
        int menu_8; cin >> menu_8;
        switch (menu_8)
        {
        case 1: {
            system("cls");
            int k = -1; // инициализируем переменную в которую закинем индекс дубликата
            Vector<Isp> NewVector8; // создаем буфферный вектор
            for (int i = 0; i < myVector.size() - 1; i++) { // в двойном цикле ищем дубликат (индекс дубликата)
                for (int j = i + 1; j < myVector.size(); j++) {
                    if (myVector[i].FIO == myVector[j].FIO && myVector[i].Country == myVector[j].Country && myVector[i].god == myVector[j].god && myVector[i].klassMI == myVector[j].klassMI && myVector[i].pos == myVector[j].pos) {
                        k = j;
                    }
                }
            }
            if (k != -1) {
                for (int i = 0; i < myVector.size(); i++) {// в буфферный массив записываем все эллементы кроме эллемента с индексом дубликата
                    if (i != k) {
                        NewVector8.push(myVector[i]);
                    }
                }
                for (int i = 0; i < NewVector8.size(); i++) { // переписываем в наш вектор значения буфферного массива уже без дубликата
                    myVector[i] = NewVector8[i];
                }
                myVector.n = NewVector8.n; // уменьшаем размера вектора до размера буфферного вектора
                cout << "Дубликаты успешно удалены!" << endl;
            }
            else {
                cout << "Дубликаты не найдены" << endl;
            }
        }break;
        case 2: {
            system("cls");
            int k = -1; // инициализируем переменную в которую закинем индекс дубликата
            Vector<Isp> NewVector8; // создаем буфферный вектор
            for (int i = 0; i < myVector2.size() - 1; i++) { // в двойном цикле ищем дубликат (индекс дубликата)
                for (int j = i + 1; j < myVector2.size(); j++) {
                    if (myVector2[i].FIO == myVector2[j].FIO && myVector2[i].Country == myVector2[j].Country && myVector2[i].god == myVector2[j].god && myVector2[i].klassMI == myVector2[j].klassMI && myVector2[i].pos == myVector2[j].pos) {
                        k = j;
                    }
                }
            }
            if (k != -1) {
                for (int i = 0; i < myVector2.size(); i++) {// в буфферный массив записываем все эллементы кроме эллемента с индексом дубликата
                    if (i != k) {
                        NewVector8.push(myVector2[i]);
                    }
                }
                for (int i = 0; i < NewVector8.size(); i++) { // переписываем в наш вектор значения буфферного массива уже без дубликата
                    myVector2[i] = NewVector8[i];
                }
                myVector2.n = NewVector8.n; // уменьшаем размера вектора до размера буфферного вектора
                cout << "Дубликаты успешно удалены!" << endl;
            }
            else {
                cout << "Дубликаты не найдены" << endl;
            }
        }break;
        default:
            break;
        }
        this->myVectorAL = myVector;
        this->myVector2AL = myVector2;
    }
    void case_4(Vector<Isp> myVector, Vector<Isp> myVector2, iteratorVector it) {
        system("cls");
        cout << " [1] - Отсортировать первую коллекцию по году" << endl;
        cout << " [2] - Отсортировать вторую коллекцию по году" << endl;
        int menu_4;
        cin >> menu_4;
        switch (menu_4)
        {
        case 1: {
            int num = myVector.size();
            for (int i = num - 1; i >= 0; i--)
            {
                for (int j = 0; j < i; j++)
                {
                    if (myVector[j].god > myVector[j + 1].god)
                    {
                        Isp tmp = myVector[j];
                        myVector[j] = myVector[j + 1];
                        myVector[j + 1] = tmp;
                    }
                }
            }
        }break;
        case 2: {
            int num = myVector2.size();
            for (int i = num - 1; i >= 0; i--)
            {
                for (int j = 0; j < i; j++)
                {
                    if (myVector2[j].god > myVector2[j + 1].god)
                    {
                        Isp tmp = myVector2[j];
                        myVector2[j] = myVector2[j + 1];
                        myVector2[j + 1] = tmp;
                    }
                }
            }
        }break;
        default:
            break;
        }
        this->myVectorAL = myVector;
        this->myVector2AL = myVector2;
    }
    void case_5(Vector<Isp> myVector, Vector<Isp> myVector2, iteratorVector it) {
        system("cls");
        bool id = false;
        int size = myVector.size();
        int size2 = myVector2.size();

        for (int i = 0; i < size; i++) {
            bool find = false;
            for (int j = 0; j < size2; j++)
            {
                if (myVector[i].FIO == myVector2[j].FIO && myVector[i].Country == myVector2[j].Country && myVector[i].god == myVector2[j].god
                    && myVector[i].klassMI == myVector2[j].klassMI && myVector[i].pos == myVector2[j].pos) {
                    find = true; break;
                }
            }
            if (find == false) {
                cout << "Первый отличающийся эллемент первой коллекции (первый уникальный) которого нету во второй коллекции:" << endl;
                cout << "ФИО: " << myVector[i].FIO << endl;
                cout << "Страна: " << myVector[i].Country << endl;
                cout << "Название класса: " << myVector[i].klassMI << endl;
                cout << "Год: " << myVector[i].god << endl;
                cout << "Позиция: " << myVector[i].pos << endl;
                break;
            }

        }


        size = myVector2.size();
        size2 = myVector.size();

        for (int i = 0; i < size; i++) {
            bool find = false;
            for (int j = 0; j < size2; j++)
            {
                if (myVector2[i].FIO == myVector[j].FIO && myVector2[i].Country == myVector[j].Country && myVector2[i].god == myVector[j].god
                    && myVector2[i].klassMI == myVector[j].klassMI && myVector2[i].pos == myVector[j].pos) {
                    find = true; break;
                }
            }
            if (find == false) {
                cout << "Первый отличающийся эллемент второй коллекции (первый уникальный) которого нету в первой коллекции:" << endl;
                cout << "ФИО: " << myVector2[i].FIO << endl;
                cout << "Страна: " << myVector2[i].Country << endl;
                cout << "Название класса: " << myVector2[i].klassMI << endl;
                cout << "Год: " << myVector2[i].god << endl;
                cout << "Позиция: " << myVector2[i].pos << endl;
                break;
            }

        }
        this->myVectorAL = myVector;
        this->myVector2AL = myVector2;
    }


};

int main() {
    setlocale(LC_ALL, "ru");
    Vector<Isp> myVector; // инициализируем первую коллекцию
    Vector<Isp> myVector2; // инициализируем вторую коллекцию
    iteratorVector it; // объявляем итератор

    while (true) {
        Isp myStruct; // объявляем буфферную структуру
        cout << " 1-ввести информацию в первую или вторую коллекцию" << endl;
        cout << " 2- Вывод коллекций" << endl;
        cout << " 3- скопировать эллементы в другую коллекцию" << endl;
        cout << " 4 - отсортировать коллекцию" << endl;
        cout << " 5 - сравнить коллекции" << endl;
        cout << " 6 - присваивание значения эллементам коллекции" << endl;
        cout << " 7-(ДЗ) перемещение элемента из одной коллекции в другую по условию в заданное место" << endl;
        cout << " 8- Удаление дубликатов из одной коллекции" << endl; // +++
        cout << " 9- Удаление дубликатов из разных коллекций" << endl;
        string Menu;
        while (!CheckNum(Menu)) { cin >> Menu; } // проверка на ввод
        switch (stoi(Menu))
        {
        case 1: {
            system("cls");

            cout << "[1] Добавить элемент в первую коллекцию" << endl;
            cout << "[2] Добавить элемент во вторую коллекцию" << endl;
            string menu_1;  while (!CheckNum(menu_1)) { cin >> menu_1; } // проверка на ввод
            switch (stoi(menu_1))
            {
            case 1: {
                system("cls");
                bool check = true;
                while (check)
                {
                    string FIO; FIO.clear();
                    cout << "Введите ФИО: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(std::cin, FIO);
                    myStruct.FIO = FIO;
                    check = false;
                }

                bool check_country = true;
                while (check_country)
                {
                    string COUNTRY;
                    cout << "Введите название страны: ";
                    getline(std::cin, COUNTRY);
                    myStruct.Country = COUNTRY;
                    check_country = false;
                }

                bool check_classname = true;
                while (check_classname)
                {
                    string CLNAME;
                    std::cout << "Введите название класса: ";
                    getline(std::cin, CLNAME);
                    myStruct.klassMI = CLNAME;
                    check_classname = false;
                }

                string k;
                cout << "Введите год: ";
                k.clear();
                while (!CheckNum(k)) {
                    cin >> k;
                }
                myStruct.god = stoi(k);

                cout << "Введите позицию: ";
                k.clear();
                while (!CheckNum(k)) {
                    cin >> k;
                }
                myStruct.pos = stod(k);

                myVector.push(myStruct);
                system("pause");
                system("cls");
            }break;
            case 2: {
                system("cls");
                bool check = true;
                while (check)
                {
                    string FIO; FIO.clear();
                    cout << "Введите ФИО: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(std::cin, FIO);
                    myStruct.FIO = FIO;
                    check = false;
                }

                bool check_country = true;
                while (check_country)
                {
                    string COUNTRY;
                    cout << "Введите название страны: ";
                    getline(std::cin, COUNTRY);
                    myStruct.Country = COUNTRY;
                    check_country = false;
                }

                bool check_classname = true;
                while (check_classname)
                {
                    string CLNAME;
                    std::cout << "Введите название класса: ";
                    getline(std::cin, CLNAME);
                    myStruct.klassMI = CLNAME;
                    check_classname = false;
                }

                string k;
                cout << "Введите год: ";
                k.clear();
                while (!CheckNum(k)) {
                    cin >> k;
                }
                myStruct.god = stoi(k);

                cout << "Введите позицию: ";
                k.clear();
                while (!CheckNum(k)) {
                    cin >> k;
                }
                myStruct.pos = stod(k);

                myVector2.push(myStruct);
                system("pause");
                system("cls");
            }break;
            default:
                break;
            }
        }break; // ввод в коллекции

        case 2: {
            system("cls");
            cout << " [1] - Посмотреть первую коллекцию" << endl;
            cout << " [2] - Посмотреть вторую коллекцию" << endl;
            string menu_2; while (!CheckNum(menu_2)) { cin >> menu_2; } // проверка на ввод
            switch (stoi(menu_2))
            {
            case 1: {
                system("cls");
                cout << "----Первая коллекция----" << endl;
                iteratorVector i;
                for (i = myVector.begin(); i < myVector.end(); ++i) {
                    (*i)->show();
                    cout << endl;
                }
                system("pause");
                system("cls");
            }break;
            case 2: {
                system("cls");
                cout << "----Вторая коллекция----" << endl;
                iteratorVector i;
                for (i = myVector2.begin(); i < myVector2.end(); ++i) {
                    (*i)->show();
                    cout << endl;
                }
                system("pause");
                system("cls");
            }break;
            default:
                break;
            }

        }break; // вывод коллекций

        case 3: {
            system("cls");
            cout << " [1] - Скопировкать эллементы первой коллекции во вторую" << endl;
            cout << " [2] - Скопировать эллементы второй коллекции в первую" << endl;
            int menu_3;
            cin >> menu_3;
            switch (menu_3)
            {
            case 1: {
                int size = myVector.size();
                for (int i = 0; i < size; i++) {
                    myVector2.push(myVector[i]);
                }
            }break;
            case 2: {
                int size = myVector2.size();
                for (int i = 0; i < size; i++) {
                    myVector.push(myVector2[i]);
                }
            }break;
            default:
                break;
            }
        }break; // копирование эллементов

        case 4: {
            Algorithm al;
            al.case_4(myVector, myVector2, it);
            myVector = al.myVectorAL;
            myVector2 = al.myVector2AL;
        }break; // сортировка

        case 5: {
            Algorithm al;
            al.case_5(myVector, myVector2, it);
            myVector = al.myVectorAL;
            myVector2 = al.myVector2AL;
        }break;

        case 6: {
            system("cls");
            system("cls");
            cout << "Выберите коллекцию 1 или 2" << endl;
            int menu_6;
            cin >> menu_6;
            switch (menu_6)
            {
            case 1: {
                system("cls");
                cout << "Введите название класса которому хотите присвоить позицию: " << endl;
                string KlassName;
                cin >> KlassName;
                cout << "Введите позицию которую хотите присвоить: " << endl;
                int pos;
                cin >> pos;
                for (int i = 0; i < myVector.size(); i++) {
                    if (myVector[i].klassMI == KlassName) {
                        myVector[i].pos = pos;
                    }
                }
            }break;
            case 2: {
                system("cls");
                cout << "Введите название класса которому хотите присвоить позицию: " << endl;
                string KlassName;
                cin >> KlassName;
                cout << "Введите позицию которую хотите присвоить: " << endl;
                int pos;
                cin >> pos;
                for (int i = 0; i < myVector2.size(); i++) {
                    if (myVector2[i].klassMI == KlassName) {
                        myVector2[i].pos = pos;
                    }
                }
            }break;
            default:
                break;
            }
        }break;

        case 7: {
            system("cls");
            cout << "Введите ФИО которого хотите переместить во вторую коллекцию: " << endl;
            string FIO;
            cin >> FIO;
            cout << "Введите ФИО эллемента второй коллекции после которого вы хотите переместить эллемент первой коллекции " << endl;
            string FIO_2;
            cin >> FIO_2;
            Isp New_Struct;
            Vector <Isp> NewVector;
            // копируем нужный нам эллемент
            for (int i = 0; i < myVector.size(); i++) {
                if (myVector[i].FIO == FIO) {
                    New_Struct.FIO = myVector[i].FIO;
                    New_Struct.Country = myVector[i].Country;
                    New_Struct.klassMI = myVector[i].klassMI;
                    New_Struct.god = myVector[i].god;
                    New_Struct.pos = myVector[i].pos;
                }
            }
            // --------------------------------------------------------------------
                            // здесь ловим индекс эллемента после которого хотим переместить.
            bool prov2 = false;
            int index = -1;
            for (int i = 0; i < myVector2.size(); i++) {
                if (myVector2[i].FIO == FIO_2) {
                    index = i;
                    prov2 = true;
                }
            }
            //-----------------------------------------------------------------------
                            // кидаем эллементы ДО нашего эллемента перемещения
            for (int i = 0; i < index + 1; i++) {
                NewVector.push(myVector2[i]);
            }
            NewVector.push(New_Struct);
            // -----------------------------------------------------------------------
            for (int i = index + 1; i < myVector2.size(); i++) {
                NewVector.push(myVector2[i]);
            }
            //-----------------------------------------
            //myVector2.clear();  
            for (int i = 0; i < myVector2.size(); i++) {
                myVector2[i] = NewVector[i];
            }
            myVector2.push(NewVector[NewVector.size() - 1]);
            /* for (int i = 0; i < NewVector.size(); i++) {
                 myVector2.push(NewVector[i]);
             }*/
            if (prov2 == false) {
                cout << "Не правильно введено Фио" << endl;
            }
            system("pause");
        }; break;

        case 8: {
            Algorithm al;
            al.case_8(myVector, myVector2, it);
            myVector = al.myVectorAL;
            myVector2 = al.myVector2AL;
        }break;// удаление дубликатов в одной коллекции
        case 9: {
            Algorithm al;
            al.case_9(myVector, myVector2, it);
            myVector = al.myVectorAL;
            myVector2 = al.myVector2AL;

       
        }break; // удаление дубликатов из разных коллекций
        }
    }
    return 0;
}