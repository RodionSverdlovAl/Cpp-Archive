#include <cstdlib>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Stack {				// Декларация структурного типа
    int info;
    Stack* next;
} *begin, * t;

Stack* InStack(Stack* p, int in) {
    Stack* t = new Stack;			// Захватываем память для элемента
    t->info = in;			// Формируем информационную часть
    t->next = p;			// Формируем адресную часть
    return t;
}

int Size(Stack* p) {
    Stack* t = p;
    int size = 0;
    while (t != NULL) {
        size++;
        t = t->next;
    }
    return size;
}

int* GetValues(Stack* p) {
    int* arr = new int[Size(p)];
    Stack* t = p;
    int i = 0;
    while (t != NULL) {
        arr[i] = t->info;
        i++;
        t = t->next;
    }
    return arr;
}

void View(Stack* p) {
    Stack* t = p;
    while (t != NULL) {
        cout << "   " << t->info << endl;
        t = t->next;
    }
}

Stack* OutStack(Stack* p, int* out) {
    Stack* t = p;			// Устанавливаем указатель t на вершину p
    *out = p->info;
    p = p->next; 		// Переставляем вершину p на следующий
    delete t; 			// Удаляем бывшую вершину t
    return p; 			// Возвращаем новую вершину p
}

void Del_All(Stack** p) {
    Stack* t;
    while (*p != NULL) {
        t = *p;
        *p = (*p)->next;
        delete t;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int i, in, n;
    //В созданном списке определить максимальное значение и удалить его
    Stack* begin = nullptr;
    while (true)
    {
        cout << "[1] Создать стэк" << endl;
        cout << "[2] Добавить эллемент в стэк" << endl;
        cout << "[3] Просмотр стека" << endl;
        //Создать список из случайных чисел, определить количество
        //элементов, находящихся между минимальным и максимальным элементами,
            //и удалить их.
        cout << "[4] индивидуальное задание" << endl;
        int menu;
        cin >> menu;
        switch (menu)
        {
        case 1: {
            if (begin != NULL) {
                cout << "Clear Memory!" << endl;
                break;
            }
            cout << "Введите колличество первоначальных эллементов = "; cin >> n;
            for (i = 1; i <= n; i++) {
                in = -10 + rand() % 20;
                begin = InStack(begin, in);
            }
        }break;
        case 2: {
            cout << "Введите число: "; int num; cin >> num;
            begin = InStack(begin, num);
        }break;
        case 3: {
            if (!begin) {
                cout << "Стэк пуст!" << endl;
                break;
            }
            cout << "--- Stack ---" << endl;
            View(begin);
        }break;
        case 4: {
            // определить количество
        //элементов, находящихся между минимальным и максимальным элементами,
            //и удалить их.
            int* arr = new int[Size(begin)];
            arr = GetValues(begin);
            int max = arr[0];
            int max_index;
            for (int i = 0; i < Size(begin); i++) {
                //cout << arr[i] << endl;
                if (arr[i] > max || arr[i] == max) {
                    max = arr[i];
                    max_index = i;
                }
            }

            int min_index;
            int min = arr[0];
            for (int i = 0; i < Size(begin); i++) {
                //cout << arr[i] << endl;
                if (arr[i] < min || arr[i] == max) {
                    min = arr[i];
                    min_index = i;
                }
            }

            cout << "Колличество эллементов между максимальным и минимальным значениями: " << fabs(max_index - min_index) << endl;


            int arr_size = Size(begin);
            Del_All(&begin);


            if (max_index > min_index) {
                for (int i = 0; i < arr_size; i++) {
                    if (i <= min_index || i >= max_index) {
                        begin = InStack(begin, arr[i]);
                    }
                }
            }
            if (max_index < min_index) {
                for (int i = 0; i < arr_size; i++) {
                    if (i <= max_index || i >= min_index) {
                        begin = InStack(begin, arr[i]);
                    }
                }
            }

        }
        default:
            break;
        }
    }
}
