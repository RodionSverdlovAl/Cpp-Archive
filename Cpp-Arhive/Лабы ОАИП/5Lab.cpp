#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");

    // задаем размеры матрицы (двумерного динамического массива)
    int N,M;
    cout << "Введите колличество строк: "; cin >> N;
    cout << "Введите колличество столбцов: "; cin >> M;

    // создаем матрицу
    int** matrix;
    matrix = new int* [N];
    for (int i = 0; i < N; i++)
        matrix[i] = new int[M];

    // заполняем матрицу
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            matrix[i][j] = -100 + rand() % 200;;
        }
    // выводим матрицу до обработки
    cout << "матрица до обработки заполненная случайными числами от -100 до 100" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int temp, pos;
    for (int i = 0; i < N; i++) // перебор строк
    {
        temp = matrix[i][0]; pos = 0;
        for (int j = 0; j < M; j++)   // перебор столбцов
        {
            if (abs(matrix[i][j]) > abs(temp)) { temp = matrix[i][j]; pos = j; }
        }

        // устанавливаем максимальный на диагональ
        matrix[i][pos] = matrix[i][i];
        matrix[i][i] = temp;
    } 
    cout << "Матрица где максимальные по абсолютной величине числа выставлены в диагональ" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}
