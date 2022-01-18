#include <iostream>
#include<string>
using namespace std;

template <class T>
class Array {
private:
	int size;
	T* arr;
public:
	Array() {
		this->size = 0;
		this->arr = new T(size);
	}
	Array(int s) {
		this->size = s;
		this->arr = new T(this->size);
	}
	Array(Array& sourse) {
		this->size = sourse.size;
		this->arr = new T(this->size);
		for (int i = 0; i < size; i++) {
			this->arr[i] = sourse.arr[i];
		}
	}
	~Array(){
		delete[] arr;
	}
	
	
	void SetDATA(){
		string inputNumber;

		for (int i = 0; i < size; i++) {
			bool chek = true;
			while (chek)
			{
				cout << "Введите " << i << " эллемент массива ";
				cin >> inputNumber;
				try
				{
					arr[i] = stoi(inputNumber);
					chek = false;
				}
				catch (invalid_argument)
				{
					cout << "Only numbers are allowed! \n";
				}
			}
			
		}
	}

	void print() {
		for(int i = 0; i<size; i++)
			cout << arr[i] << " ";
	}
	void min() {
		int i = 0;
		T min = arr[i];
		for (i = 0; i < size; i++) {
			if (min > arr[i]) {
				min = arr[i];
			}
		}
		cout << "Минимальный эллемент массива " << min << endl;
	}
	 
	void sum(int start_index, int finish_index) {
		T sum = 0;
		for (int i = start_index; i < finish_index; i++) {
			sum += arr[i];
		}
		cout << "Сумма: " << sum << endl;
	}
	T& operator[](int index) {
		if (index >= 0 && index < size)
			return arr[index];
	}
};

void main() {
	setlocale(LC_ALL, "ru");
	Array<int> mass(10);
	mass.SetDATA();
	mass.print();
	mass.min();
	mass.sum(3,8);
	cout << mass[4] << endl;
	system("pause");
}