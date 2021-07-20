#pragma once
#include "CAnimal.h"
class CCow : public CAnimal
{
public:
	CCow();
	~CCow();
	void tiengKeu();
	int tinhTuoiDoi();
	void choAn(float);
	void diChuyen(CCoor);
};