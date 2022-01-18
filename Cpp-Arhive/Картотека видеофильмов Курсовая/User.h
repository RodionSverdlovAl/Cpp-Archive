#pragma once
#include "Films.h"
#include "Registration.h"
class User : public Films, public Registration
{
public:
	void User_Menu();
};