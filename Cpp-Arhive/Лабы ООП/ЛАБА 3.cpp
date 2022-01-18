// Вариант 18(3)

// Создать класс, в котором перегрузить операторы:
// & для перемножения двух матриц;
// +для сложения двух матриц.
// Память под матрицы отводить динамически.Предоставить конструктор копирования.
// Определить friend функции для операций ввода - вывода в поток.

#include <iostream>
using namespace std;

class Matrix
{
public:
    Matrix(int N); // конструктор
    ~Matrix(); // диструктор
    Matrix(Matrix&); // конструктор копирования
    Matrix operator+ (const Matrix&); // перегруженный оператор 
    Matrix operator& (const Matrix&); // перегруженный оператор


private:
    int size; // размер массива
    int** matrix; // Двумерный динамический массив(матрица)
    friend void Show(Matrix&); // дружественная функция вывода
    friend void get_matrix(Matrix&); // дружественная функция ввода
};

Matrix::Matrix(int N) // конструктор
{
    size = N;
    matrix = new int* [size]; 
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
}

Matrix::Matrix(Matrix& obj) // конструктор копирования (в конструктор копирования передаем ссылку на обект который хотим скопировать и передаем в новый объект)
{
    size = obj.size; // обращаюсь к полю сайз объекта обдж
    matrix = new int* [size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = obj.matrix[i][j];
}

void Show(Matrix& Obj) // вывод матрицы
{
    for (int i = 0; i < Obj.size; i++) {
        for (int j = 0; j < Obj.size; j++)
        {
            cout << Obj.matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void get_matrix(Matrix& Obj) // заполнение матрицы
{
    for (int i = 0; i < Obj.size; i++)
        for (int j = 0; j < Obj.size; j++)
        {
            cout << "Введите[" << i + 1 << "][" << j + 1 << "] элемент матрицы: ";
            cin >> Obj.matrix[i][j];
        }
}

Matrix Matrix::operator+(const Matrix& Obj) //конст потому что обект не изменяется
{
    Matrix result(*this);// создание новой матрицы резалт с помощью конструктора копирования указатель зис указатеь на матрицу м1
    for (int i = 0; i < Obj.size; i++)
        for (int j = 0; j < Obj.size; j++)
            result.matrix[i][j] += Obj.matrix[i][j];
    return result;
}

Matrix Matrix::operator&(const Matrix& Obj) // перегрузка оператора умножения
{
    Matrix result(*this);
    for (int i = 0; i < Obj.size; i++)
        for (int j = 0; j < Obj.size; j++)
            result.matrix[i][j] *= Obj.matrix[i][j];
    return result;
}

Matrix::~Matrix()
{
    cout << "Пямять очищена" << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
//--------------------------------------------------------------------
    int N;
    cout << "Введите размер матрицы" << endl; // Задаем размер матрицы
    cin >> N;
//--------------------------------------------------------------------
    Matrix m1(N);
    get_matrix(m1);
    Show(m1);

    Matrix m2 = m1;
    get_matrix(m2);
    Show(m2);

    cout << endl;
    cout << " Первая матрица + вторая матрица" << endl;
    Matrix m3(N);
    m3 = m1 + m2;
    Show(m3);

    cout << endl;
    cout << "Первая матрица * вторая матрица" << endl;
    Matrix m4(N);
    m4 = m1 & m2;
    Show(m4);
}