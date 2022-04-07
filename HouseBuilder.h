#pragma once

#include "House.h"
#include <functional>
#include <unordered_map>


class HouseBuilder 
{

	House* house = nullptr;
public:
	virtual ~HouseBuilder() {}
	virtual void Create_House()
	{
		house = new House;
	}
	virtual void constructFloor()
	{
		for (int i = 1; i < House::X - 1; ++i) 
		{
			house->view[House::Y - 1][i] = '#';
		}
	}
	virtual void constructFence()
	{
		for (int i = 3; i < House::Y; ++i) 
		{
			house->view[i][0] = '#';
			house->view[i][House::X - 1] = '#';
		}
	}
	virtual void constructRoof() 
	{
		for (int i = 0; i < House::X; ++i)
		{
			house->view[3][i] = '^';
		}
		house->view[2][0] = '^';
		house->view[2][House::X - 1] = '^';
		for (int i = 1; i < House::X - 1; ++i)
		{
			house->view[1][i] = '^';
		}
	}
	virtual void constructPipe() 
	{
		house->view[0][6] = '"';
		house->view[0][7] = '"';

	}

	virtual void constructWindow()
	{
		house->view[4][6] = '|';
		house->view[4][7] = '|';
	}
	virtual House* getResult() { return house; }
};

class HouseBuilderJust_a_House : public HouseBuilder
{


};

class HouseBuilderFence : public HouseBuilder 
{

	void constructRoof() {}
	void constructPipe() {}
	void constructWindow() {}
};

class HouseBuilder_no_Pipe : public HouseBuilder
{

	void constructPipe() {}
};

class HouseBuilder_no_Window : public HouseBuilder
{

	void constructPipe() {}
};

class HouseDirector
{

	std::unordered_map< uint32_t, std::function< HouseBuilder* () > > map;
	std::shared_ptr<HouseBuilder> ptr(int id) {
		auto it = map.find(id);
		if (it != map.end())
		{
			return std::shared_ptr<HouseBuilder>{it->second()};
		}
		return nullptr;
	}

public:
	House* createHouse(int h)
	{
		std::shared_ptr<HouseBuilder> builder = ptr(h);
		if (builder == nullptr)
		{
			return new House;
		}
		builder->Create_House();
		builder->constructFloor();
		builder->constructFence();
		builder->constructRoof();
		builder->constructWindow();
		builder->constructPipe();
		return (builder->getResult());
	}
	HouseDirector()
	{
		map.emplace(1, [] {return new HouseBuilderFence; });
		map.emplace(2, [] {return new HouseBuilder_no_Pipe; });
		map.emplace(3, [] {return new HouseBuilder_no_Window; });
		map.emplace(4, [] {return new HouseBuilderJust_a_House; });
	}
};