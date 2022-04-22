#pragma once
#include <string>
#include <fstream>
using namespace std;

class Registration
{
private:
	string LoginUser, PasswordUser;
	string LoginAdmin = "Admin", PasswordAdmin = "724";
	string RegDATA = "RegDATA.txt";

public:
	string LoginUser1, PasswordUser1; // нужны чисто для удаления пользователя
	void RegistrationFunction();
	void EnterToProgram();
	int Access, Role; // Доступ и Роль
	string getRegDATA();
};

