#pragma once

#include "LevelGUI.h"

class LevelGUI;

class Mediator
{

	LevelGUI& LG;

public:
	Mediator(LevelGUI& lg) : LG(lg) {}

	void set_message(std::string str) 
	{

		LG.set_msg(str);
	}

	void set_print()
	{
		LG.pop_msg();
	}

};