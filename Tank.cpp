
#include <iostream>
#include "Mediator.h"
#include "Tank.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

bool Tank::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void Tank::Draw() const
{
	MyTools::SetColor(CC_Brown);
	GotoXY(x, y - 3);
	cout << "    #####";
	GotoXY(x-2, y - 2);
	cout << "#######   #";
	GotoXY(x, y - 1);
	cout << "    #####";
	GotoXY(x,y);
	cout << " ###########";

	int var;
	var = rand() % 5;
	if (var < msg.size()) 
	{
		mediator.set_message(msg[var]);
	}
	mediator.set_print();
}
Tank::Tank(Mediator& m) : mediator(m) 
{
	msg.push_back("Penetration!!!");
	msg.push_back("Hello to sleepwalkers !!))");
	msg.push_back("Tanks are not afraid of mud");
	msg.push_back("They don't look at a loaded tank in the muzzle!");
	msg.push_back("Air,Air,Air!!!");
}