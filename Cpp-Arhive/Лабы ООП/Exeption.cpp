// Exeption.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>
#include<fstream>

using namespace std;

void set_array(int arr[5]) {
    for (int i = 0; i < 5; i++) {
        cout << "Enter " << i << " element array: "; cin >> arr[i];
        if (arr[i] < 5)
            throw "exeption";

    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    try {
        string name;
        cout << "Enter name: ";
        cin >> name;
        if (name.length() > 15) {
            throw - 1;
        }
    }
    catch(int a){
        cout << "Введенная вами длинна строки превышает 15 символов" << endl;
    }

    int a;
    cout << "enter a: "; cin >> a;
    try {
        if (a < 0) {
            throw "Can not take sqrt of negative number";

        }
        cout << a;
    }
    catch(const char* ex){
        cout << "number < 0" << endl;
    }

    int arr[5];
    try
    {
        set_array(arr);
    }
    catch (const char* ex)
    {
        cout << "Введенное вами число меньше 5" << endl;
    }

    const int MAX = 100;
    int buff[MAX];
    for (int i = 0; i < MAX; i++) {
        buff[i] = i;
    }

    ofstream os("data.txt", ios::binary);
    os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
    os.close();

    ifstream in("data.txt", ios::binary);
    in.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));
    cout << buff;
    in.close();

    
}
