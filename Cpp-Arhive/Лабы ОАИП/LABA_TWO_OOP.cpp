#include <iostream>
using namespace std;

//template <class T> // указываем что класс будет шабллонный чтобы можно было работать c вещественными типами данных
//// комплексное число будет структурой, содержащей два поля: действительную и мнимую часть. Сам класс complex должен быть шаблоном.
//// T может быть одним из действительных типов данных: float, double, long double.

class complex
{
private:
    int size; // размерность вектора
    float* VC; // переменная (массив) для вещественной части вектора
    float* VM; // переменная (массив) для мнимой части вектора
    float* SLV1; // массив для сложения вещественных частей вектора
    float* SLV2; // массив для сложения мнимых частей вектора
    float c, m; // вещественная и мнимая части
    float vuc1, vuc2; // комплексные числа получаемые в ходе сложения мнимых и вещественных частей комплексных чисел
public:
      complex(float d, float e) // конструктор с параметрами
      {
          c = d; // действительная часть
          m = e; // мнимая часть
      };
      complex() // конструктор по умолчанию 
      {}

      ~complex() // диструктор для освобождения памяти от динамически созданных массивов
      {
          delete[] VC, VM, SLV1,SLV2;
      };

      void vector(int size, float* vc1, float* vm1) {
          this->size = size;
          this->VC = new float(this->size);
          this->VM = new float(this->size); // задаем размеры массивам
          
          for (int i = 0; i < size; i++) {
              VC[i] = vc1[i]; // заполняем значениями из параметров функции (вещественные части)
          }
          for (int i = 0; i < size; i++) {
              VM[i] = vm1[i]; // заполняем значениями из параметров функции (мнимые части)
          }
          for (int i = 0; i < size; i++) {
              cout << "(" << VC[i] << "+" << "(" << VM[i] << ")" << "i,";
          }
          cout << "\n";
      }

      void VectorSum(complex x, complex Y, int size) {
          this->size = size;
          this->SLV1 = new float(this->size); // задаем размеры массивам
          this->SLV2 = new float(this->size);
          
          for (int i = 0; i < size; i++) {
              SLV1[i] = x.VC[i] + Y.VC[i]; // складываем вещественные части
          }
          for (int i = 0; i < size; i++) {
              SLV2[i] = x.VM[i] + Y.VM[i]; // складываем мнимые части
          }
          cout << "Полученный вектор: ";
          for (int i = 0; i < size; i++) {
              cout << "(" << SLV1[i] << ")" << SLV2[i] << ")" << "i" << ",";
          }
          cout << "\n";
      }
      void slog(complex x, complex Y) // функция сложения двух комплексных чисел
      {
          vuc1 = x.c + Y.c; // складываем вещественные части 
          vuc2 = x.m + Y.m; // складываем мнимые части
          cout << "Сложение равно: " << vuc1 << "+" << "(" << vuc2 << ")" << "i" << "\n"; // i это мнимая еденица 
      }
      void vuсh(complex x, complex Y)  // вычитание комплексных чисел
      {
          vuc1 = x.c - Y.c; // вычитаем вещественные части
          vuc2 = x.m - Y.m; // вычитаем мнимые части
          cout << "Вычитание равно: " << vuc1 << "+" << "(" << vuc2 << ")" << "i" << "\n"; // выводим результат вычитания
      }
      void ymnog(complex x, complex Y)  // умножение комплексных чисел
      {
          vuc1 = x.c * Y.c + x.m * Y.m;
          vuc2 = x.c * Y.m + x.m * Y.c;
          cout << "Умножение равно: " << vuc1 << "+" << "(" << vuc2 << ")" << "i" << "\n";
      }
      void delenie(complex x, complex Y) // деление комплексных чиселл
      {
          vuc1 = (x.c * Y.c + x.m * Y.m) / (Y.c * Y.c * Y.m * Y.m);
          vuc2 = (x.m * Y.c - x.c * Y.m) / (Y.c * Y.c * Y.m * Y.m);
          cout << "Деление равно: " << vuc1 << "+" << "(" << vuc2 << ")" << "i" << "\n";
      }
};
void main()
{
    setlocale(LC_ALL, "Russian");

    float dl, mnim, dl1, mnim1;
    complex Y;

    cout << "Введите вещественную часть: "; cin >> dl;
    cout << "Введите мнимую часть: "; cin >> mnim;
    complex x(dl, mnim);

    cout << "Введите вещественную часть: "; cin >> dl1;
    cout << "Введите мнимую часть: "; cin >> mnim1;
    complex x1(dl1, mnim1);

    x.slog(x, x1); // складываем комплексные числа
    cout << endl;

    x.vuсh(x, x1); // вычитаем комплексные числа
    cout << endl;

    x.ymnog(x, x1); // умножаем комплексные числа
    cout << endl;

    x.delenie(x, x1); // делим комплексные числа
    cout << endl;

    int N;
    cout << "Введите размерности векторов: "; cin >> N;
    float* VC = new float[N]; // создаем временные массивы для заполнения их значениями чтобы потом параметрами передать в функцию
    float* VM = new float[N];
    cout << "Создаем 1 вектор:  " << endl; // создаем первый вектор с размерностью SIZE
    for (int i = 0; i < N; i++) {
        cout << i + 1 << " вещественную часть: " << endl; cin >> VC[i]; // вводим вещественную часть
        cout << i + 1 << " мнимую часть: " << endl; cin >> VM[i]; // вводим мнимую часть
    }
    x.vector(N, VC, VM); // создаем объект класса

    cout << "Создаем 2 вектор:  " << endl; // создаем первый вектор с размерностью SIZE
    for (int i = 0; i < N; i++) {
        cout << i + 1 << " вещественную часть: " << endl; cin >> VC[i]; // вводим вещественную часть
        cout << i + 1 << " мнимую часть: " << endl; cin >> VM[i]; // вводим мнимую часть
    }
    x1.vector(N, VC, VM); // создаем объект класса

    complex sum;
    sum.VectorSum(x, x1, N); // передаем объекты класса в функцию и передаем размерность

    delete[] VC, VM; // чистим память
}