#pragma once
#include "User.h"
class Admin : public User
{
public:
	void add_information();
	void MenuAmin();
	void Delete_information_about_films();
	void Delete_All_Users();
	void View_Users_Accounts();
	void DeteteUser();
};

