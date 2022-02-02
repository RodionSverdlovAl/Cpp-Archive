#include <cstdlib>
#include <iostream>
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

void Sort_p(Stack** p) {
    Stack* t = NULL, * t1, * r;
    if ((*p)->next->next == NULL) return;
    do {
        for (t1 = *p; t1->next->next != t; t1 = t1->next)
            if (t1->next->info > t1->next->next->info) {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
            }
        t = t1->next;
    } while ((*p)->next->next != t);
}

void Sort_info(Stack* p) {
    Stack* t = NULL, * t1;
    int r;
    do {
        for (t1 = p; t1->next != t; t1 = t1->next)
            if (t1->info > t1->next->info) {
                r = t1->info;
                t1->info = t1->next->info;
                t1->next->info = r;
            }
        t = t1;
    } while (p->next != t);
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
        cout << "[4] Первая сортировка стека" << endl;
        cout << "[5] Вторая сортировка стека" << endl;
        cout << "[6] Из созданного списка удалить каждый второй элемент." << endl;
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
            Sort_p(&begin);
            cout << "Стэк отсортирован по первой сортировке!! " << endl;
        }break;
        case 5: {
            Sort_info(begin);
            cout << "Стэк отсортирован по второй сортировке!! " << endl;
        }break;
        case 6: {
            //В созданном списке определить максимальное значение и удалить его
            //cout << "Размер стека " << Size(begin) << endl;
            int* arr = new int[Size(begin)];
            arr = GetValues(begin);
            int arr_size = Size(begin);
            Del_All(&begin);
            for (int i = 0; i < arr_size; i++) {
                if (i%2 == 0) {
                    begin = InStack(begin, arr[i]);
                }
            }
            cout << "Каждый второй эллемент стэка удален!!!" << endl;
        }
        default:
            break;
        }
    }
}


