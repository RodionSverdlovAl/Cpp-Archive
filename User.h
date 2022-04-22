#pragma once
#include "Bus.h"
#include "Registration.h"
class User : public Bus, public Registration
{
public:
	void User_Menu();
};