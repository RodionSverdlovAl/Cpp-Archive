#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <iomanip>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    while (true)
    {
        cout << "[1] задание 1" << endl;
        cout << "[2] задание 2" << endl;
        int chouse;
        cin >> chouse;
        switch (chouse)
        {
        case 1: {
            // задаем размеры матрицы (двумерного динамического массива)
            int N, M;
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
                    cout << "введите [" << i << "][" << j << "] элемент матрицы"; cin >> matrix[i][j];
                }
            // выводим матрицу до обработки
            cout << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }

            int minimum = matrix[0][0];
            int minimum_i = 0;
            int minimum_j = 0;

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++)
                {
                    if (minimum > matrix[i][j]) {
                        minimum = matrix[i][j];
                        minimum_i = i;
                        minimum_j = j;
                    }
                }
            }
            cout << "минимальный эллемент матрицы: " << minimum << endl;
            cout << "строка минимального эллемента: " << minimum_i + 1 << endl;
            cout << "столбец минимального эллемента: " << minimum_j + 1 << endl;
        }break;
        case 2: {
            // задаем размеры матрицы (двумерного динамического массива)
            int N, M;
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
                    cout << "введите [" << i << "][" << j << "] элемент матрицы"; cin >> matrix[i][j];
                }
            // выводим матрицу до обработки
            cout << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }

            for (int i = 0; i < M; i++) //считаем числа в колонках
            {
                int sum = 0;
                for (int j = 0; j < N; j++)
                {
                    if (matrix[j][i] < 0) //если в колонке есть число <0 подсчет прекращается
                    {
                        sum = 0;
                        break;
                    }
                    if (matrix[j][i] >= 0)
                    {
                        sum += matrix[j][i];
                    }

                }
                if (sum != 0)//выводим результат сложения для колонки с положительными числами
                {
                    cout<< setw(2)<< sum<< "\t";
                }
                if (sum == 0) //выводим прочерк для колонки имеющей отрицательное(-ые) число(-а)
                {
                    cout << setw(2)<< "-"<< "\t";
                }
            }
            cout<< endl;
            for (int i = 0; i < N; i++)//чистим динамическую память
            {
                delete[]matrix[i];
            }

        }break;
        default:
            break;
        }
    }

    

   
}