#pragma once
#include "CAnimal.h"
class CChicken : public CAnimal
{
public:
	CChicken();
	~CChicken();
	void tiengKeu();
	int tinhTuoiDoi();
	void choAn(float);
	void diChuyen(CCoor);
	//void addDisplay(Window);
};

