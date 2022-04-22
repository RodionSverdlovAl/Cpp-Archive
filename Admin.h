#pragma once
#include "User.h"
class Admin : public User
{
public:
	void MenuAmin();
	void Delete_information_about_routes();
	void Delete_All_Users();
	void View_Users_Accounts();
	void DeteteUser();
};
