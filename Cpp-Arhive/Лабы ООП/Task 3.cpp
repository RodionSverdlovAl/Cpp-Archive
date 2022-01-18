// создать шаблонный класс для работы с матрицами реализовать функцию сложения двух матриц предусмотреть обработку исключений

#include <iostream>
using namespace std;

template <class T>
class Matrix {
private:

	T** matrix;
	int col;
	int row;

public:

	Matrix() { // конструктор без параметров
		col = 0;
		row = 0;
		matrix = new T *[row];
		for (int i = 0; i < row; i++)
		{
			matrix[i] = new T[col];
		}
	}
	~Matrix() {
		delete[] matrix;
	}

	Matrix(int col, int row) { // конструктор с параметрами
		this->col = col;
		this->row = row;
		matrix = new T*[row];
		for (int i = 0; i < row; i++)
		{
			matrix[i] = new T[col];
		}
	}

	Matrix(Matrix& sourse) { // конструктор копирования
		this->row = sourse.row;
		this->col = sourse.col;
		matrix = new T * [row];
		for (int i = 0; i < row; i++)
		{
			matrix[i] = new T[col];
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matrix[i][j] = sourse.matrix[i][j];
			}
		}
	}

	void set_matrix() { // ввод значений матрицы
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				system("cls");
				cout << "Введите эллемент матрицы " << "[" << i << "]" << "[" << j << "]" << endl;
				cin >> matrix[i][j];
			}
		}
	}

	void print_matrix() { // вывод матрицы
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void sum_matrix(Matrix m1, Matrix m2) { // сумма двух одинаковых матриц
		if (m1.row == m2.row && m1.col == m2.col ) {
			for (int i = 0; i < m2.row; i++) {
				for (int j = 0; j < m2.col; j++) {
					matrix[i][j] = m2.matrix[i][j] + m1.matrix[i][j];
				}
			}
		}
		else {
			cout << "Обе матрицы должны быть одинакового размера!" << endl;
		}
	}

	//void sum_different_matrix(Matrix m1, Matrix m2) { // функция суммирования матриц (Функция требует доработки)
	//	if (m1.col>m2.col && m1.row >m2.row) { //  если 1 матрица больше чем вторая
	//		Matrix m3(m1.col, m1.row);
	//		for (int i = 0; i < m1.row; i++) {
	//			for (int j = 0; j < m1.col; j++) {
	//				m3.matrix[i][j] =  m1.matrix[i][j] + m2.matrix[i][j];
	//			}
	//		}
	//		return m3.print_matrix();
	//	}
	//	if (m1.col < m2.col && m1.row < m2.row) { // если 2 матрица больше чем первая
	//		Matrix m3(m2.col, m2.row);
	//		for (int i = 0; i < m2.row; i++) {
	//			for (int j = 0; j < m2.col; j++) {
	//				while (i<m1.col && j<m1.row)
	//				{
	//					m3.matrix[i][j] = m2.matrix[i][j] + m1.matrix[i][j];
	//				}
	//				m3.matrix[i][j] = m2.matrix[i][j];
	//			}
	//		}
	//		return m3.print_matrix();
	//	}
	//	if (m1.row == m2.row && m1.col == m2.col) { // если 1 и 2 матрица равны
	//		Matrix m3(m2.col, m2.row);
	//		for (int i = 0; i < m2.row; i++) {
	//			for (int j = 0; j < m2.col; j++) {
	//				m3.matrix[i][j] = m2.matrix[i][j] + m1.matrix[i][j];
	//			}
	//		}
	//		return m3.print_matrix();
	//	}
	//}

	Matrix& operator+(const Matrix& m1) {
		Matrix result(m1.col, m1.row);
		for (int i = 0; i < m1.row; i++)
			for (int j = 0; j < m1.row; j++)
				result.matrix[i][j] += m1.matrix[i][j];
		return result;
	}
};

int main() {
	setlocale(LC_ALL, "ru");
	int col, row;
	cout << "Введите колличество строк: "; cin >> row;
	cout << "Введите колличество колонок: "; cin >> col;
	Matrix<int> m1(col, row); // создаем первую матрицу
	m1.set_matrix(); // заполняем первую матрицу
	Matrix<int> m2(col, row); // создаем вторую матрицу
	m2.set_matrix(); // заполняем вторую матрицу
	Matrix<int> m3(col,row); // создаем 3 матрицу
	//m3.sum_matrix(m1, m2); // присваеваем третьей матрице значение суммы первой и второй матрицы
	cout << "First Matrix" << endl;
	m1.print_matrix();
	cout << "Second Matrix" << endl;
	m2.print_matrix();
	cout << "Matrix sum of Matrix1 and Matrix2:" << endl;
	m3 = m1 + m2;
	m3.print_matrix();
	//m3.print_matrix();
	system("pause");
}