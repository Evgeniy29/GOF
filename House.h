#pragma once

#include <stdint.h>
#include "DestroyableGroundObject.h"

class House : public DestroyableGroundObject
{
public:
	House() {
		for (int i = 0; i < Y; ++i)
		{
			for (int j = 0; j < X; ++j) 
			{
				view[i][j] = ' ';
			}
		}
	}

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	friend class HouseBuilder;
private:
	const static int Y = 5;
	const static int X = 10;
	char view[Y][X];
	const uint16_t score = 40;
};

