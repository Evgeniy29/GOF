#pragma once

#include <sstream>
#include "Plane.h"
#include "Bomb.h"
#include "MyTools.h"



class Visitor 
{
public:
	virtual void log(Plane* p) = 0;
	virtual void log(Bomb* b) = 0;
	virtual ~Visitor() {}
};

class LogVisitor : public Visitor
{
public:
	void log(Plane* p) override
	{
		std::stringstream str_p;
		str_p << " Plane Coord X " << p->GetX() << " Coord Y " << p->GetY() <<
			" Plane Speed " << p->Get_Speed() << " Plane Direction " <<
			p->Get_DirectionX() << " : " << p->Get_DirectionY();
		MyTools::WriteToLog(str_p.str());
	}
	void log(Bomb* b) override
	{
		std::stringstream str_b;
		str_b << " Bomb Coord X " << b->GetX() << " Coord Y " << b->GetY() <<
			" Bomb Speed " << b->Get_Speed() << " Bomb Direction " <<
			b->Get_DirectionX() << " : " << b->Get_DirectionY();
		MyTools::WriteToLog(str_b.str());
	}
};