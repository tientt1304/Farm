#pragma once
#include "CAnimal.h"
class CSheep : public CAnimal
{
public:
	CSheep();
	~CSheep();
	void tiengKeu();
	int tinhTuoiDoi();
	void choAn(float);
	void diChuyen(CCoor);
	//void addDisplay(Window);
};

