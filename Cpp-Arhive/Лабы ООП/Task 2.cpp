// написать класс текстового файла (конструктор деструктор запись чтение ) поменять первую и последнюю строки файла использовать char а не стринг
 
#include <iostream>
#include <fstream>
#include <string>
#include <ostream>

using namespace std;

class TXTFILE {
private:
	char* filename;
public:
	ofstream File_write;
	ifstream File_read;

	TXTFILE(char* filename) { // конструктором открываем файлы
		this->filename = filename;
		File_write.open(filename, ios::app);

		File_read.exceptions(ifstream::badbit | ::ifstream::failbit);
		try
		{
			cout << "Попытка открыть файл." << endl;
			File_read.open(filename, ios::in);
			cout << "Файл успешно открыт!" << endl;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
			cout << "Ошибка открытия файла!" << endl;
		}
	}
	~TXTFILE() { // диструктором их закрываем
		File_write.close();
		File_read.close();
	}
	
	void append(const char* data) { // запись в конец файл
		if (File_write.is_open()) {
			File_write << data << endl;
		}
	}
	void write(const char* data) { // перезапись файла
		File_write.close();
		File_write.open(filename, ios::out);
		append(data);
	}
	void read() { // чтение файла
		char ch;
		if (File_read.is_open()) {
			while (File_read.get(ch))
			{
				cout << ch;
			}
		}
	}
	//void swapstr() {
	//	int size = 0;
	//	char st[250];
	//	string s; // сюда будем класть считанные строки

	//	while (getline(File_read, s)) { // пока не достигнут конец файла класть очередную строку в переменную (s)
	//		size++;
	//	}
	//	
	//	string *masstr = new string[size];
	//	for (int i = 0; i < size; i++) {
	//		while (getline(File_read, s)) { // пока не достигнут конец файла класть очередную строку в переменную (s)
	//			masstr[i] = s;
	//		}
	//	}
	//	string tmp;
	//	string tmp2;
	//	tmp = masstr[0];
	//	tmp2 = masstr[size];
	//	masstr[0] = tmp2;
	//	masstr[size] = tmp;
	//	for (int i = 0; i < size; i++) {
	//		if (File_write.is_open()) {
	//			File_write << masstr[i] << endl;
	//		}
	//	}
	//}
	friend ostream& operator<<(ostream& file, const char* data);
	friend istream& operator>>(istream& file, const char* data);
};

int main() {
	setlocale(LC_ALL, "ru");
	char name[] = "info.txt";
	TXTFILE F(name);
	char info[250];
	/*F.append("Some text about my 300 hundred bucks");
	F.append("Some text about my 100 hundred bucks");
	F.append("Some text about my 200 hundred bucks");
	F.append("Some text about my 111 hundred bucks");*/
	//char data[] = "Big COCK";
	/*F.File_write << "In Oral CumShot \n" << endl;
	F.read();*/
	/*while (!F.File_read.eof())
	{
		F.File_read >> info;
		cout << info;
	}*/
	/*F.File_read >> info;
	cout << info;*/
	//F.write("");
	//F.swapstr();
	F.read();
}

ostream& operator<<(ostream& file, const char* data) // перегрузка оператора вставки
{
	file << data << endl;
	return file;
}

istream& operator>>(istream& file, const char* data) // перегрузка оператора извлечения
{
	file >> data;
	return file;
}
